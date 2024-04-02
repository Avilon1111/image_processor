cmake_minimum_required(VERSION 3.22)

project(image_processor)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-std=c++23)

add_executable(
        ${PROJECT_NAME}
        image_processor.cpp)

set(SOURCE_FILES
        src/data/color.cpp
        src/data/image.cpp
        src/data/matrix.cpp
        src/filters/crop.cpp
        src/filters/edge_detection.cpp
        src/filters/gaussian_blur.cpp
        src/filters/grayscale.cpp
        src/filters/matrix_filter.cpp
        src/filters/negative.cpp
        src/filters/point_filter.cpp
        src/filters/sharpening.cpp
        src/io/bmp.cpp
        src/utils/args_processor.cpp
        src/pipeline.cpp
)

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/include/data"
        "${PROJECT_SOURCE_DIR}/include/filters"
        "${PROJECT_SOURCE_DIR}/include/utils"
        "${PROJECT_SOURCE_DIR}/include/io"
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/src/data"
        "${PROJECT_SOURCE_DIR}/src/filters"
        "${PROJECT_SOURCE_DIR}/src/utils"
        "${PROJECT_SOURCE_DIR}/src/io")

add_library(LIB ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC LIB)
