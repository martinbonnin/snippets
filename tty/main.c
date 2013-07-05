int main(int argc, char **arv)
{
change_term_size (int fd, int x, int y)
{
#ifdef TIOCGSIZE
    struct ttysize win;

#elif defined(TIOCGWINSZ)
    struct winsize win;

#endif

#ifdef TIOCGSIZE
    if (ioctl (fd, TIOCGSIZE, &win))
        return;
    if (y && y>24)
        win.ts_lines = y;
    else
        win.ts_lines = 24;
    if (x && x>80)
        win.ts_cols = x;
    else
        win.ts_cols = 80;
    ioctl (fd, TIOCSSIZE, &win);
}
