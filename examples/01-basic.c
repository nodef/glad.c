#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>


int main(void) {
  int version = gladLoadGL();
  if (version == 0) return -1;
  return 0;
}
