# from 2.8.5 support complation database
cmake_minimum_required(VERSION 2.8.5)

project(dsa-btree)

# to debug cmake: --trace / --trace-expand
set(CMAKE_VERBOSE_MAKEFILE true) 

# compliation database
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# Options: None / Debug / Release / RelWithDebInfo / MinSizeRel
set(CMAKE_BUILD_TYPE Release)

# Default value can be seen by: cmake --trace
# CMAKE_C_FLAGS_DEBUG = -g
# CMAKE_C_FLAGS_REALEASE = -O3 -DNDEBUG
# to add OpemMP support: -fopemmp
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Run make in subdir
# add_custom_target(
#    extern_lib
#    COMMAND make
#    WORKING_DIRECTORY full_path to where Makefile is located
# )
# add_executable(myexecutable myexcutable.c)
# target_link_libraries(myexecutable full_path_to_generated_library)
# add_dependencies(myexecutable extern_lib)


# executables save at project root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

set(LIBAVL avl-2.0.3)
set(SRCS "${LIBAVL}/avl.c" "${LIBAVL}/bst.c" "${LIBAVL}/rb.c" tree.c)

# options:
# target_include_directories
# target_link_libraries
# target_compile_definitions
# target_compile_options


set(TARGET avl-demo)
add_executable("${TARGET}" avl-demo.c "${LIBAVL}/avl.c")
target_include_directories("${TARGET}" PRIVATE "${LIBAVL}")


set(TARGET hw6_2_1)
add_executable("${TARGET}" main1.c "${SRCS}")
target_include_directories("${TARGET}" PRIVATE "${LIBAVL}")

set(TARGET completeavl)
add_executable("${TARGET}" completeavl.c "${SRCS}")
target_include_directories("${TARGET}" PRIVATE "${LIBAVL}")

set(TARGET hw6_2_2)
add_executable("${TARGET}" main2.c "${SRCS}")
target_include_directories("${TARGET}" PRIVATE "${LIBAVL}")

set(TARGET hw6_2_3)
add_executable("${TARGET}" main3.c "${SRCS}")
target_include_directories("${TARGET}" PRIVATE "${LIBAVL}")

