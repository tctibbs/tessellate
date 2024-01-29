#!/bin/zsh

# Directory paths to format
SRC_DIRS=("src" "apps")

# Enable extended globbing. This allows for more advanced pattern matching.
setopt EXTENDED_GLOB

# Find and format each .cpp and .h file
for DIR in $SRC_DIRS; do
    echo "Formatting files in directory: $DIR"
    find $DIR \( -iname '*.cpp' -o -iname '*.h' \) -exec clang-format -i -style=file {} +
done
