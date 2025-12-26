#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
  echo "Fetch not needed"
}


# Test the project
test() {
echo "No tests available yet"
# echo "Running 01-vec3.c ..."
# clang -I. -o 01.exe examples/01-vec3.c    && ./01.exe && echo -e "\n"
# echo "Running 02-vec4.c ..."
# clang -I. -o 02.exe examples/02-vec4.c    && ./02.exe && echo -e "\n"
# echo "Running 03-mat4x4.c ..."
# clang -I. -o 03.exe examples/03-mat4x4.c  && ./03.exe && echo -e "\n"
# echo "Running 04-quat.c ..."
# clang -I. -o 04.exe examples/04-quat.c    && ./04.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
