# Add executable
add_executable(Tessellate main.cpp)

# Link the application with the source and includes directories
target_link_libraries(Tessellate PRIVATE MazeLibrary)
