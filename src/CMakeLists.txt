add_library(yourlib
    ${CMAKE_CURRENT_SOURCE_DIR}/yourlib.cpp)
add_library(yourlib::yourlib ALIAS yourlib)

option(BUILD_SHARED_LIBS "Build shared library" ON)
include(GenerateExportHeader)
generate_export_header(yourlib
    EXPORT_MACRO_NAME YOURLIB_API
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/yourlib/core/common.hpp)

target_compile_features(yourlib PUBLIC cxx_std_17)
target_compile_options(yourlib PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
    -pipe -march=native
    $<$<CONFIG:Debug>:-O0 -Wall -Wextra>>
    $<$<CXX_COMPILER_ID:MSVC>:
    $<$<CONFIG:Debug>:/Od /Wall /Zi>>
    )

target_include_directories(yourlib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE:
    ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(yourlib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
