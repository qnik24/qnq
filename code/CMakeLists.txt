file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(qnq ${SRC_FILES})

target_link_libraries(qnq 
    PRIVATE glfw
)

target_include_directories(qnq
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
