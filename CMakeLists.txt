#cmake file

cmake_minimum_required (VERSION 3.5)

project (sudoku)

set (LIBRARY_NAME "sud")
set (SRC_MAIN sources/main.c)
file (GLOB SRC_LIB "sources/libsud/*.c")

set (CMAKE_CXX_COMPILER clang)
add_definitions (-Wall -std=c11 -g)

include_directories (include)

add_library (${LIBRARY_NAME} SHARED ${SRC_LIB})

add_executable (${PROJECT_NAME} ${SRC_MAIN})

target_link_libraries (${PROJECT_NAME} ${LIBRARY_NAME} ncurses)

install (TARGETS ${LIBRARY_NAME} DESTINATION /usr/lib)
install (TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin)

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
