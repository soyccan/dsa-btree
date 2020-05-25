cmake_minimum_required(VERSION 2.6)
project(dsa-btree)
set(CMAKE_VERBOSE_MAKEFILE true) # to debug cmake: --trace / --trace-expand

set(CMAKE_BUILD_TYPE Debug)
# None : 編譯器預設值
# Debug ： 產生除錯資訊
# Release ： 進行執行速度最佳化
# RelWithDebInfo ： 進行執行速度最佳化，但仍然會啟用 debug flag
# MinSizeRel ： 進行程式碼最小化

# Default are: (TODO: exactly what? See documentation)
# CMAKE_C_FLAGS_DEBUG = -g
# CMAKE_C_FLAGS_REALEASE = -O3 -DNDEBUG
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
# set(CMAKE_C_FLAGS_REALEASE "${CMAKE_CXX_FLAGS_REALEASE} -DNDEBUG -O2")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

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


set(LIBAVL avl-2.0.3)

add_executable(avl-demo avl-demo.c "${LIBAVL}/avl.c")
target_include_directories(avl-demo PRIVATE "${LIBAVL}")
# target_include_directories
# target_link_libraries
# target_compile_definitions
# target_compile_options


