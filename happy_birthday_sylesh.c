#include <stdio.h>

#define R (5)
#define C (3)

char *e[] = {
    "_-_|_| - | |  _",
    "_ _|  _-_|_|_- ",
    " -_|___ _|_  -_",
    "_  _ |_-_|_|_-_",
    "_- |_ _-_| _ -_",
    "_-_|   - |   _ ",
    " -_| __-_| | -_",
    " __|_|_- |_| __",
    "_ _|____ |_  __",
    "    _|  ___| -_",
    " __| | -_|_|___",
    "  _|   _ | _ -_",
    " -   |_-  _|_-_",
    " __ _ _- | | __",
    " - | |__ |_|_- ",
    "_- |_| -_|     ",
    " - | | -_  |  _",
    "____ __-_| __  ",
    " -_|__ - __| - ",
    "_  | __-_|___-_",
    "_  |_| __|_|_- ",
    "_ __ _ _ | | - ",
    "_-_|___-_| __- ",
    "_  | |_-_| |  _",
    "___|_|_- __|_- ",
    "_-_  |_-_|__ - ",
    " _       _ _ _ ",
    "________ _ _   ",
    "   _  ___   __ ",
    " ____  ___ ___ ",
    "    __  _ _   _",
    "__ _   _____ __",
    "_-_|_|_-_|_|__ ",
    "_ _|   - |_|_-_",
    " - |_ _  |_ _- ",
    "   _ | -_| |_-_",
    " -_|_  -_| __- ",
    " -_| _ - |   _ ",
    " - |_ _-_|_|_- ",
    "  _|_| -_| |_ _",
    "   |___  | ___ ",
    " _ __|  ___|_- ",
    "___| | -_| |__ ",
    "__ |____ |   - ",
    " -   |_- _ |_-_",
    " __ ___- | | __",
    " -_|_| __|_|_-_",
    " - | |_- |____ ",
    " - |_|_-  _|__ ",
    "____  _- |__   ",
    " -_|  _-  _| - ",
    "  _|__ - |_  -_",
    " _ | |  _|_| -_",
    "_   ___ _| | -_",
    "_-_|___-_|_ _-_",
    "__ |_| -_| |_  ",
    "_  |_|_- _ |_-_",
    "_-_  |_- | __-_",
};

void p(char *s) {
    for (int i = 0; i < R; ++i) {
        for (char *p = s; *p != '\0' || !putchar('\n'); ++p) {
            int x = *p - 'A';
            char c;
            for (int j = 0; j < C || !putchar(' '); ++j) {
                putchar((0 <= x && x < sizeof(e)/sizeof(char*) && (c = e[x][i*3+j])) ? (c == '_' ? ' ' : c) : ' ');
            }
        }
    }
}

int main(int c, char **v) {
    p(c > 1 ? v[1] : v[0]);
    return 0;
}
