cmake_minimum_required(VERSION 3.10)

project(mini_sort)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# --------------
# directories
# --------------

set(INC_DIR include)
set(SRC_DIR src)
set(APP_DIR app)
set(TEST_DIR tests)

# --------------
# library
# --------------

set(LIB_SOURCES
    ${SRC_DIR}/config.c
    ${SRC_DIR}/io.c
    ${SRC_DIR}/compare.c
    ${SRC_DIR}/sort.c
)

add_library(mini_sort_lib STATIC ${LIB_SOURCES})

target_include_directories(mini_sort_lib
    PUBLIC
    ${INC_DIR}
)

# --------------
# main_executable
# --------------

add_executable(mini_sort 
    ${APP_DIR}/main.c
)

target_link_libraries(mini_sort
    PRIVATE
    mini_sort_lib
)


# --------------
# tests
# --------------

add_executable(test_config
    ${TEST_DIR}/test_config.c
)

target_link_libraries(test_config
    PRIVATE
    mini_sort_lib
)   

add_executable(test_io
    ${TEST_DIR}/test_io.c
)

target_link_libraries(test_io
    PRIVATE
    mini_sort_lib
)

add_executable(test_sort
    ${TEST_DIR}/test_sort.c
)

target_link_libraries(test_sort
    PRIVATE
    mini_sort_lib
)