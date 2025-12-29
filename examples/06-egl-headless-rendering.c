// 06-egl-headless-rendering.c
// Demonstrates headless rendering using EGL.
#define GLAD_EGL_IMPLEMENTATION
#include <glad/egl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        fprintf(stderr, "Failed to get EGL display\n");
        return -1;
    }

    if (!eglInitialize(display, NULL, NULL)) {
        fprintf(stderr, "Failed to initialize EGL\n");
        return -1;
    }

    EGLConfig config;
    EGLint numConfigs;
    EGLint configAttribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_NONE
    };

    if (!eglChooseConfig(display, configAttribs, &config, 1, &numConfigs) || numConfigs < 1) {
        fprintf(stderr, "Failed to choose EGL config\n");
        return -1;
    }

    EGLint pbufferAttribs[] = {
        EGL_WIDTH, 256,
        EGL_HEIGHT, 256,
        EGL_NONE
    };

    EGLSurface surface = eglCreatePbufferSurface(display, config, pbufferAttribs);
    if (surface == EGL_NO_SURFACE) {
        fprintf(stderr, "Failed to create EGL surface\n");
        return -1;
    }

    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
    if (context == EGL_NO_CONTEXT) {
        fprintf(stderr, "Failed to create EGL context\n");
        return -1;
    }

    if (!eglMakeCurrent(display, surface, surface, context)) {
        fprintf(stderr, "Failed to make EGL context current\n");
        return -1;
    }

    printf("EGL headless rendering initialized successfully\n");

    // Perform rendering here (e.g., OpenGL calls)

    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    return 0;
}
