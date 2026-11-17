cmake_minimum_required(VERSION 3.15)
project(OpenGlGameProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Определяем исходники проекта (используем вашу текущую структуру)
set(SOURCES
    main.cpp
    main_shader.cpp
    stb_image.cpp
)

# На Windows берём glad.c 
if(WIN32)
    list(APPEND SOURCES "D:/OpenGl_Dev/glad.c")
else()
    # На Linux/macOS предполагаем, что glad лежит в локальной папке проекта
    list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/glad.c")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})

# Подключаем заголовочные файлы точечно к таргету (вместо глобального include_directories)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE "D:/OpenGl_Dev/include")
endif()

# Кроссплатформенное подключение системного OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

# Подключение GLFW и специфичных флагов для каждой ОС
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE "D:/OpenGl_Dev/glfw3.lib")
    target_link_options(${PROJECT_NAME} PRIVATE "/NODEFAULTLIB:MSVCRT")
elseif(APPLE)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
elseif(UNIX)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw dl pthread)
endif()

# Копируем текстуры из папки Images/ и шейдеры рядом с .exe после сборки
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/Images/Tile.png"
        "${CMAKE_CURRENT_SOURCE_DIR}/Images/Awesomeface.png"
        "${CMAKE_CURRENT_SOURCE_DIR}/Shader/colors.vert"
        "${CMAKE_CURRENT_SOURCE_DIR}/Shader/colors.frag"
        "${CMAKE_CURRENT_SOURCE_DIR}/Shader/lamp.frag"
        "${CMAKE_CURRENT_SOURCE_DIR}/Shader/lamp.vert"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)