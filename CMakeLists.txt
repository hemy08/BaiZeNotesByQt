cmake_minimum_required(VERSION 3.31)
project(HemyMarkdownEditorQt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.9.1/mingw_64/")

set(QT_LIBS Core Gui Quick Qml Widgets)
message("QT_LIBS ${QT_LIBS}")

find_package(Qt6 COMPONENTS
        ${QT_LIBS}
        REQUIRED)

set(RESOURCES res/resources.qrc)
qt6_add_resources(RES_SOURCES ${RESOURCES})

add_executable(
        ${PROJECT_NAME}
        main.cpp
        # 后续可添加其他文件
        ${RESOURCES}
)

foreach(lib ${QT_LIBS})
    list(APPEND QT_LINK_LIBS "Qt6::${lib}")
endforeach()
message("QT_LINK_LIBS ${QT_LINK_LIBS}")

target_link_libraries(${PROJECT_NAME}
        ${QT_LINK_LIBS}
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    # 设置部署目录
    set(DEPLOY_DIR ${PROJECT_SOURCE_DIR}/deploy)
    # 删除旧目录，创建新目录
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E remove_directory ${DEPLOY_DIR}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    )

    # debug模式dll文件前缀
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()

    # 获取其他安装路径
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    # 获取绝对路径
    get_filename_component(QT_INSTALL_PATH "${QT_INSTALL_PATH}" ABSOLUTE)

    # 拷贝可执行文件路径到部署目录
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:${PROJECT_NAME}>" ${DEPLOY_DIR}
    )

    # 找到并且拷贝qwindows.dll到可执行文件路径
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory "${DEPLOY_DIR}/plugins/platforms/"
        )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "${DEPLOY_DIR}/plugins/platforms/"
        )
    endif ()

    # 拷贝必须的库文件
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll" ${DEPLOY_DIR}
        )
    endforeach (QT_LIB)


    message("QT_INSTALL_PATH ${QT_INSTALL_PATH}")
    # 查找windeployqt
    find_program(WINDEPLOYQT_EXE windeployqt
            PATHS "${QT_INSTALL_PATH}/bin" DOC "Qt deployment tool" REQUIRED
    )

    # 添加部署命令
    message("CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${WINDEPLOYQT_EXE}"
            --verbose 1
            --no-compiler-runtime
            --no-translations
            --dir ${DEPLOY_DIR}
            --qmldir "${CMAKE_CURRENT_SOURCE_DIR}/res"
            "$<TARGET_FILE:${PROJECT_NAME}>"
            COMMENT "Deploying Qt dependencies..."
    )

    # 复制QML文件到部署目录
    file(GLOB QML_FILES "res/qml/*.qml")
    message("QML_FILES ${QML_FILES}")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E remove_directory "${DEPLOY_DIR}/res"
            COMMAND ${CMAKE_COMMAND} -E make_directory "${DEPLOY_DIR}/res"
            COMMAND ${CMAKE_COMMAND} -E copy ${QML_FILES} "${DEPLOY_DIR}/res"
            COMMENT "Copying QML files..."
    )
endif ()
