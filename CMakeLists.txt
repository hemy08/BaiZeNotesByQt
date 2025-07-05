cmake_minimum_required(VERSION 3.31)
project(MdEditorByQt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.10.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(
        src/mainwindow
        src/common/
        src/mainwindow/menubar
        src/mainwindow/menubar/base
        src/mainwindow/menubar/m_file
        src/mainwindow/menubar/m_edit
        src/mainwindow/menubar/m_coding
        src/mainwindow/menubar/m_view
        src/mainwindow/menubar/m_insert
        src/mainwindow/menubar/m_settings
        src/mainwindow/menubar/m_tools
        src/mainwindow/menubar/m_plugins
        src/mainwindow/menubar/m_online
        src/mainwindow/menubar/m_links
        src/mainwindow/menubar/m_help
        src/mainwindow/status_bar
        src/mainwindow/menubar/plugins
        src/style_def
        src/mainwindow/menubar/tools/local
        src/mainwindow/menubar/tools/online
        src/mainwindow/menubar/tools/web
        src/workbench/compose_bar
        src/workbench/edit_toolbar
        src/workbench/markdown_edit
        src/workbench/markdown_preview
)

set(SRC_FILES "")
file(GLOB_RECURSE  MENU_SRCS src/mainwindow/menubar/*.cpp src/mainwindow/status_bar/*.cpp)
file(GLOB_RECURSE  MAIN_WINDOW_SRCS src/mainwindow/*.cpp src/workbench/*.cpp)
file(GLOB_RECURSE  COMMON_SRCS src/common/*.cpp src/style_def/*.cpp)
file(GLOB_RECURSE  PLG_TOOL_SRCS src/mainwindow/menubar/plugins/*.cpp src/mainwindow/menubar/tools/*.cpp)
list(APPEND SRC_FILES ${MENU_SRCS} ${MAIN_WINDOW_SRCS} ${COMMON_SRCS} ${PLG_TOOL_SRCS})
message("SRC_FILES ${SRC_FILES}")

set(HEAD_FILES "")
file(GLOB_RECURSE  MENU_HEAD src/mainwindow/menubar/*.h src/mainwindow/status_bar/*.h)
file(GLOB_RECURSE  MAIN_WINDOW_HEAD src/mainwindow/*.h src/workbench/*.h)
file(GLOB_RECURSE  COMMON_HEAD src/common/*.h src/style_def/*.h)
file(GLOB_RECURSE  PLG_TOOL_HEAD src/mainwindow/menubar/plugins/*.h src/mainwindow/menubar/tools/*.h)
list(APPEND HEAD_FILES ${MENU_HEAD} ${MAIN_WINDOW_HEAD} ${COMMON_HEAD} ${PLG_TOOL_HEAD})
message("HEAD_FILES ${HEAD_FILES}")

add_executable(MdEditorByQt main.cpp ${SRC_FILES} ${HEAD_FILES})

target_link_libraries(MdEditorByQt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

# 添加资源文件
# set(RESOURCE_FILES res/resources.qrc)
# target_sources(${PROJECT_NAME} PRIVATE ${RESOURCE_FILES})

# 设置翻译文件
# set(TS_FILES
#         translations/app_en_US.xml
#         translations/app_zh_CN.xml
# )

# 自定义函数处理翻译
# include(cmake/FindQtI18n.cmake)
# qt_add_translation(QM_FILES ${TS_FILES})

# 添加自定义目标用于更新翻译
# add_custom_target(update_translations
#         COMMAND Qt6::lupdate ${SOURCE_FILES} menu/*.cpp menu/*.h -ts ${TS_FILES}
#         COMMENT "Updating translation files"
# )

# 安装规则
# install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# install(FILES ${QM_FILES} DESTINATION translations)