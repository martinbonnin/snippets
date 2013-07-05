#include <glib.h>
#include "stdio.h"
#include <unistd.h>

GMainLoop *main_loop;

void _destroy(gpointer user_data)
{
    g_print("destroy notified\n");
#if 0
    g_print("sleep....");
    usleep(4*1000*1000);
    g_print("okp\n");
#endif
}

gboolean _cb(gpointer user_data)
{
    int *c = (int*)user_data;
    
    (*c)++;
    g_print("counter is %d\n", *c);
    
    if (*c == 1) {
        g_print("stop now\n");
        return FALSE;
    }
    
    return TRUE;
}

static gpointer _thread(gpointer data)
{
    int counter = 0;
    GSource *source;
    source = g_timeout_source_new (1000);

    g_source_set_callback (source, _cb, &counter, _destroy);

    g_source_attach (source, NULL);
    
#if 1
    g_print("sleep\n");
    usleep(4*1000*1000);
#endif

    g_print("unref source\n");
    g_source_unref (source);

    g_print("exiting thread\n");
    return NULL;
}

int main(int argc, char **argv)
{
    GThread *thread;
    GError *error;
    
    g_thread_init(NULL);
    g_print("starting...\n");
    
    main_loop = g_main_loop_new(NULL, FALSE);
        
    thread = g_thread_create(_thread, NULL, FALSE, &error);
    
    g_main_loop_run(main_loop);
    
    return 0;
}
