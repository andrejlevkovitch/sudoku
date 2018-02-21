#cmake file

cmake_minimum_required (VERSION 3.5)

project (sudoku)

set (LIBRARY_PR "sud")
set (LIBRARY_IO "io")
set (SRC_MAIN sources/main.c)
file (GLOB SRC_LIB_PR "sources/libsud/*.c")
file (GLOB SRC_LIB_IO "sources/libio/*.c")

set (CMAKE_CXX_COMPILER clang)
add_definitions (-Wall -std=c11 -g)

include_directories (include)

add_library (${LIBRARY_PR} SHARED ${SRC_LIB_PR})
add_library (${LIBRARY_IO} SHARED ${SRC_LIB_IO})

add_executable (${PROJECT_NAME} ${SRC_MAIN})

target_link_libraries (${PROJECT_NAME} ${LIBRARY_PR} ${LIBRARY_IO} ncurses)

install (TARGETS ${LIBRARY_PR} ${LIBRARY_IO} DESTINATION /usr/lib)
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
