# Define a library target for your source files
add_library(MazeLibrary cell.cpp)

# Link the library with the includes directory
target_include_directories(MazeLibrary PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
