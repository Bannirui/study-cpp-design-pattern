cmake_minimum_required(VERSION 3.21)
option(USE_PROXY "Enable proxy for FetchContent for file download" ON)
if (USE_PROXY)
    message(STATUS "Proxy is enabled")
    set(ENV{http_proxy} "http://127.0.0.1:7890")
    set(ENV{https_proxy} "http://127.0.0.1:7890")
    set(CMAKE_TLS_VERIFY OFF)
    set(CMAKE_DOWNLOAD_AGENT "curl")
endif ()

# 输出详细日志
set(CMAKE_VERBOSE_MAKEFILE ON)

# 项目信息
project(study_cpp_design_pattern VERSION 1.0 LANGUAGES C CXX)

# 平台判断并设置默认编译器 仅在未手动指定时生效
if (NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
    message(STATUS "No platform default compiler, setting user-defined compiler")
    if (APPLE)
        message(STATUS "Detected Apple platform")
        set(CMAKE_C_COMPILER /usr/bin/clang CACHE STRING "C compiler" FORCE)
        set(CMAKE_CXX_COMPILER /usr/bin/clang++ CACHE STRING "C++ compiler" FORCE)
    elseif (UNIX)
        message(STATUS "Detected Linux platform")
        set(CMAKE_C_COMPILER /usr/bin/gcc CACHE STRING "C compiler" FORCE)
        set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE STRING "C++ compiler" FORCE)
    else ()
        message(FATAL_ERROR "Unsupported platform")
    endif ()
endif ()
message(STATUS "Using compiler: ${CMAKE_C_COMPILER}, ${CMAKE_CXX_COMPILER}")

# c/cpp标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Werror)
add_compile_options(-Wno-deprecated-declarations)
# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# dep
set(lib_directory ${CMAKE_SOURCE_DIR}/lib)

# 源文件
file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# 添加头文件的目的仅仅是为了让IDEA识别到 新建文件的时候添加索引
add_library(${PROJECT_NAME} ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)

include(CTest)
enable_testing()
add_subdirectory(tests)