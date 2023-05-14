cmake_minimum_required(VERSION 3.0)

project(FractionNumberApplication)

# Установка стандарта языка C++
set(CMAKE_CXX_STANDARD 11)

# Добавление исходных файлов
set(SOURCES
    src/fraction_number.cpp
    src/fraction_number_application.cpp
    src/main.cpp
)

# Добавление исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

# Добавление пути для заголовочных файлов
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Добавление меток для исходных файлов
set_source_files_properties(
    src/fraction_number.cpp
    src/fraction_number_application.cpp
    PROPERTIES
        LABELS "${PROJECT_NAME};FractionNumberLibrary"
)
set_source_files_properties(
    src/main.cpp
    PROPERTIES
        LABELS "${PROJECT_NAME};Application"
)

# Добавление библиотеки FractionNumber
add_subdirectory(lib/fraction_number)
target_link_libraries(${PROJECT_NAME} FractionNumber)

# Добавление тестов
add_subdirectory(test)