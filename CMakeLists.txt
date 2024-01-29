cmake_minimum_required(VERSION 3.10)

project(
    Tessellate
    VERSION 0.1
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Required for clangd to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Run clang-tidy on the project
set(CMAKE_CXX_CLANG_TIDY
    "clang-tidy;-header-filter=.;-checks=-*,clang-analyzer-alpha.*,cppcoreguidelines.*,google-*,performance-*,readability-*,modernize-*"
)

# Add clang-format target
find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)
if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(
        format ALL
        COMMAND ${CMAKE_SOURCE_DIR}/run-clang-format.sh
        COMMENT "Running clang-format on all source files"
    )
endif()

# Add cpp check target
find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)
if(CPPCHECK_EXECUTABLE)
    set(CPPCHECK_CMD ${CPPCHECK_EXECUTABLE}
        --enable=warning,performance,portability,style
        --std=c++17
        --template=gcc
        --verbose
        --force
        --quiet
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/apps)

    # Run cppcheck as a post-build step
    add_custom_target(cppcheck ALL
        COMMAND ${CPPCHECK_CMD}
        COMMENT "Running cppcheck"
    )
endif()

add_subdirectory(src)
add_subdirectory(apps)
