add_library(common INTERFACE)

target_sources(common INTERFACE
    core_to_ui/screensnapshot.h
    core_to_ui/payloads/payload_main.h
    core_to_ui/payloads/payload_setting.h
    core_to_ui/payloads/payload_start.h
    ui_to_core/commandmessage.h
    ui_to_core/payloads/payload_create_task.h
    ui_to_core/payload_ui.h
    commands_id.h
    header_message.h
)

target_include_directories(common 
    INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/core_to_ui
        ${CMAKE_CURRENT_SOURCE_DIR}/ui_to_core
        ${CMAKE_CURRENT_SOURCE_DIR}/ui_to_core/payloads
        ${CMAKE_CURRENT_SOURCE_DIR}/core_to_ui/payloads
)