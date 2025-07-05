# 自定义函数处理Qt翻译
function(qt_add_translation out_files)
    # 查找lrelease工具
    get_target_property(LRELEASE_EXECUTABLE Qt6::lrelease IMPORTED_LOCATION)

    if(NOT LRELEASE_EXECUTABLE)
        message(FATAL_ERROR "Qt6::lrelease not found")
    endif()

    set(qm_files)

    foreach(ts_file ${ARGN})
        # 获取文件名和路径
        get_filename_component(ts_name ${ts_file} NAME_WE)
        set(qm_file ${CMAKE_CURRENT_BINARY_DIR}/${ts_name}.qm)

        # 添加自定义命令生成qm文件
        add_custom_command(
                OUTPUT ${qm_file}
                COMMAND ${LRELEASE_EXECUTABLE} ${ts_file} -qm ${qm_file}
                DEPENDS ${ts_file}
                COMMENT "Generating ${ts_name}.qm"
        )

        list(APPEND qm_files ${qm_file})
    endforeach()

    # 添加自定义目标
    add_custom_target(generate_qm_files ALL DEPENDS ${qm_files})

    # 设置输出变量
    set(${out_files} ${qm_files} PARENT_SCOPE)
endfunction()