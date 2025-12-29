// 07-glx-rendering.c
// Demonstrates rendering using GLX on an X11 window.

#include <glad/glx.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Failed to open X display\n");
        return -1;
    }

    int screen = DefaultScreen(display);

    GLint glxAttribs[] = {
        GLX_RGBA,
        GLX_DEPTH_SIZE, 24,
        GLX_DOUBLEBUFFER,
        None
    };

    XVisualInfo* visual = glXChooseVisual(display, screen, glxAttribs);
    if (!visual) {
        fprintf(stderr, "No appropriate visual found\n");
        return -1;
    }

    Window root = DefaultRootWindow(display);

    XSetWindowAttributes swa;
    swa.colormap = XCreateColormap(display, root, visual->visual, AllocNone);
    swa.event_mask = ExposureMask | KeyPressMask;

    Window win = XCreateWindow(display, root, 0, 0, 800, 600, 0, visual->depth, InputOutput, visual->visual, CWColormap | CWEventMask, &swa);

    XMapWindow(display, win);
    XStoreName(display, win, "GLX Rendering");

    GLXContext glc = glXCreateContext(display, visual, NULL, GL_TRUE);
    glXMakeCurrent(display, win, glc);

    if (!gladLoaderLoadGLX(display, screen)) {
        fprintf(stderr, "Failed to initialize GLAD for GLX\n");
        return -1;
    }

    printf("GLX initialized successfully\n");

    while (1) {
        XEvent xev;
        XNextEvent(display, &xev);

        if (xev.type == Expose) {
            glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glXSwapBuffers(display, win);
        } else if (xev.type == KeyPress) {
            break;
        }
    }

    glXMakeCurrent(display, None, NULL);
    glXDestroyContext(display, glc);
    XDestroyWindow(display, win);
    XCloseDisplay(display);

    return 0;
}
