cmake_minimum_required(VERSION 3.10)
project(OpenGlGameProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("D:/OpenGL_Dev/include")

add_executable(${PROJECT_NAME} 
    main.cpp
    MainShader.cpp 
    stb_image.cpp
    "D:/OpenGL_Dev/glad.c"
)

target_link_libraries(${PROJECT_NAME} 
    "D:/OpenGL_Dev/glfw3.lib"
    opengl32.lib
)

target_link_options(${PROJECT_NAME} PRIVATE "/NODEFAULTLIB:MSVCRT")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/Tile.png"
        "${CMAKE_CURRENT_SOURCE_DIR}/shader.vert"
        "${CMAKE_CURRENT_SOURCE_DIR}/shader.frag"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)