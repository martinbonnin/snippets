#include <GL/glx.h>
#include <GL/gl.h>
#include <unistd.h>
#include <iostream>
    
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    
#define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092
typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
    
int main (int argc, char ** argv)
{
    Display *display = XOpenDisplay(0);
    
    glXCreateContextAttribsARBProc glXCreateContextAttribsARB = NULL;
    
    const char *extensions = glXQueryExtensionsString(display, DefaultScreen(display));
    std::cout << extensions << std::endl;
    
    static int visual_attribs[] =
    {
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_DOUBLEBUFFER, true,
        GLX_RED_SIZE, 1,
        GLX_GREEN_SIZE, 1,
        GLX_BLUE_SIZE, 1,
        None
        };
    
    std::cout << "Getting framebuffer config" << std::endl;
    int fbcount;
    GLXFBConfig *fbc = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &fbcount);
    if (!fbc)
    {
        std::cout << "Failed to retrieve a framebuffer config" << std::endl;
        return 1;
    }
    
    std::cout << "Getting XVisualInfo" << std::endl;
    XVisualInfo *vi = glXGetVisualFromFBConfig(display, fbc[0]);
    
    XSetWindowAttributes swa;
    std::cout << "Creating colormap" << std::endl;
    swa.colormap = XCreateColormap(display, RootWindow(display, vi->screen), vi->visual, AllocNone);
    swa.border_pixel = 0;
    swa.event_mask = StructureNotifyMask;
    
    std::cout << "Creating window" << std::endl;
    Window win = XCreateWindow(display, RootWindow(display, vi->screen), 0, 0, 100, 100, 0, vi->depth, InputOutput, vi->visual, CWBorderPixel|CWColormap|CWEventMask, &swa);
    if (!win)
    {
        std::cout << "Failed to create window." << std::endl;
        return 1;
    }
    
    std::cout << "Mapping window" << std::endl;
    XMapWindow(display, win);
    
    std::cout << "Creating context" << std::endl;
    GLXContext ctx = glXCreateNewContext (display, fbc[0], GLX_RGBA_TYPE, NULL, True);
    if (!ctx)
    {
        std::cout << "Failed to create GL3 context." << std::endl;
        return 1;
    }
    
    std::cout << "Making context current" << std::endl;
    glXMakeCurrent(display, win, ctx);
    
    while(1) {
        glClearColor (0, 0, 1, 1);
        glClear (GL_COLOR_BUFFER_BIT);
        glXSwapBuffers (display, win);
    
        sleep(1);
    
        glClearColor (1, 0, 0, 1);
        glClear (GL_COLOR_BUFFER_BIT);
        glXSwapBuffers (display, win);
    
        sleep(1);
    }

    ctx = glXGetCurrentContext();
    glXMakeCurrent(display, 0, 0);
    glXDestroyContext(display, ctx);
}


