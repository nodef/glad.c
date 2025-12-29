#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
  echo "Fetch not needed"
}


# Test the project
test() {
echo "Running 01-basic-opengl.c ..."
clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 01.exe examples/01-basic-opengl.c           && ./01.exe && echo -e "\n"
echo "Running 02-texture-mapping.c ..."
clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 02.exe examples/02-texture-mapping.c        && ./02.exe && echo -e "\n"
echo "Running 03-3d-cube.c ..."
clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 03.exe examples/03-3d-cube.c                && ./03.exe && echo -e "\n"
echo "Running 04-vulkan-triangle.c ..."
clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -I"node_modules/vulkan.c" -o 04.exe examples/04-vulkan-triangle.c        && ./04.exe && echo -e "\n"
echo "Running 05-multiple-lights.c ..."
clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 05.exe examples/05-multiple-lights.c        && ./05.exe && echo -e "\n"
# echo "Running 06-egl-headless-rendering.c ..."
# clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 06.exe examples/06-egl-headless-rendering.c && ./06.exe && echo -e "\n"
# echo "Running 07-glx-rendering.c ..."
# clang -I. -I"node_modules/glfw3.c" -I"node_modules/stb.c" -o 07.exe examples/07-glx-rendering.c          && ./07.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
