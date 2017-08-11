/*
 * Scrolling 7 Segment Display Terminal Emulator
 *
 * Happy 16th Birthday Sylesh!
 *
 * Copyright 2017 Preetam J. D'Souza
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PANEL_WIDTH  (80)
#define PANEL_HEIGHT (5)
#define DISP_ROWS (PANEL_HEIGHT)
#define DISP_COLS (4)
#define PANEL_MAX_CHARS (PANEL_WIDTH/DISP_COLS)
#define USPF (250000)

// ASCII -> seven segment
char *ascii[] = {
    " -- |  | -- |  |    ", // A
    "    |    -- |  | -- ", // B
    " -- |       |    -- ", // ...
    "       | -- |  | -- ",
    " -- |    -- |    -- ",
    " -- |    -- |       ",
    " -- |    -- |  | -- ",
    "    |  | -- |  |    ",
    "    |       |       ",
    "       |       | -- ",
    "    |  | -- |  |    ",
    "    |       |    -- ",
    " --    | --    | -- ",
    "         -- |  |    ",
    " -- |  |    |  | -- ",
    " -- |  | -- |       ",
    " -- |  | --    |    ",
    "         -- |       ",
    " -- |    --    | -- ",
    "    |    -- |    -- ",
    "    |  |    |  | -- ",
    "            |  | -- ",
    " -- |    -- |    -- ",
    "    |  | -- |  |    ",
    "    |  | --    | -- ",
    " --    | -- |    -- ", // Z
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    " -- |  | -- |  |    ", // a
    "    |    -- |  | -- ", // b
    " -- |       |    -- ", // ...
    "       | -- |  | -- ",
    " -- |    -- |    -- ",
    " -- |    -- |       ",
    " -- |    -- |  | -- ",
    "    |  | -- |  |    ",
    "    |       |       ",
    "       |       | -- ",
    "    |  | -- |  |    ",
    "    |       |    -- ",
    " --    | --    | -- ",
    "         -- |  |    ",
    " -- |  |    |  | -- ",
    " -- |  | -- |       ",
    " -- |  | --    |    ",
    "         -- |       ",
    " -- |    --    | -- ",
    "    |    -- |    -- ",
    "    |  |    |  | -- ",
    "            |  | -- ",
    " -- |    -- |    -- ",
    "    |  | -- |  |    ",
    "    |  | --    | -- ",
    " --    | -- |    -- ", // z
};

// Obfuscated ASCII map
//char eascii[sizeof(ascii)/sizeof(char*)][20];
char *eascii[] = {
    "_--_|_ | -- |  |__ _",
    "  __|__  --_|__|_-- ",
    "_--_|  __  _| ___--_",
    "__ _ __| --_| _|_--_",
    " -- |    -- |_  _-- ",
    "_--_|_  _-- |____ _ ",
    "_--_|_ __--_|__| --_",
    "  __|  | -- |_ | ___",
    " _ _|_  ____|_  _   ",
    "_  _ _ |   _  _|_--_",
    " __ |_ |_-- |  |__  ",
    " __ |__ _ _ |_   -- ",
    " --    |_--    |_--_",
    "___ ___ _--_|  | ___",
    " -- |__|  _ |  |_--_",
    "_--_|__|_--_|  _ ___",
    "_-- |_ |_--_ _ |_   ",
    " ______ _--_| _   __",
    " -- | ___--___ |_--_",
    "_ __|  __--_|_   --_",
    "    |  | _ _| _| --_",
    "_______ _ _ |  | -- ",
    " --_|  __--_|   _--_",
    "  __|__| -- |__|_ __",
    "_   |  |_--_  _| --_",
    " --  __|_-- |_   --_",
    "____ __________ _ _ ",
    "   ___  _ _  _ _    ",
    "_  _ __ __  _ __  _ ",
    "_     _   _ ____   _",
    "_ _ _ _   ___   ___ ",
    " _ __  ____ ___  _ _",
    "_-- |__| --_|__|_   ",
    "    |  _ --_| _|_-- ",
    "_--_| ___   |__ _--_",
    " _____ | -- |_ |_--_",
    "_--_|   _--_|  __--_",
    " --_|___ -- |_ __   ",
    " --_|  _ -- |_ | -- ",
    " ___|  |_-- | _| _  ",
    "  __| __   _|__ _  _",
    "_______| ____ _| --_",
    " _  |_ | --_|_ |_ __",
    "__  |_  ____| ___--_",
    "_--  _ |_--____| --_",
    "_   _  _ --_|_ |___ ",
    "_--_|  | __ |__|_-- ",
    " --_|_ |_-- | __ __ ",
    " --_|  | -- __ |_ __",
    "_  _  ___--_|__  ___",
    " -- |___ --_ _ |_--_",
    " _  |_   -- | ___--_",
    " _ _|__|    |__|_-- ",
    " _ __  _ _  |  | -- ",
    " -- |____--_|___ -- ",
    "____| _|_--_|  |_  _",
    "__ _|_ | --_   | -- ",
    " --   _|_-- |__  --_",
};

// Simple encryption function to obfuscate the ASCII -> seven segment map
void __encrypt() {
    char pool[] = {' ', '_'};
    fprintf(stderr, "char *e[] = {\n");
    for (int i = 0; i < sizeof(ascii)/sizeof(char*); ++i) {
        char *from = ascii[i];
        char *to = eascii[i];
        for (; *from != '\0'; ++from, ++to) {
            if (*from == ' ') { // randomly map whitespace to pool
                *to = pool[rand()%sizeof(pool)];
            } else {
                *to = *from;
            }
        }
        fprintf(stderr, "\"%s\",\n", eascii[i]);
    }
    fprintf(stderr, "};\n");
}

void print_seven_segment(char *s) {
    for (int i = 0; i < DISP_ROWS; ++i) {
        for (char *p = s; *p != '\0'; ++p) {
            int idx = *p - 'A';
            for (int j = 0; j < DISP_COLS ; ++j) {
                if (0 <= idx && idx < sizeof(eascii)/sizeof(char*)) {
                    char c = eascii[idx][i * DISP_COLS + j];
                    putchar(c == '_' ? ' ' : c);
                } else {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
}

void scroll_print_seven_segment(char *s) {
    char buf[PANEL_MAX_CHARS + 1] = { 0 };
    int slen = strlen(s);
    buf[PANEL_MAX_CHARS] = '\0';
    for (int offset = -PANEL_MAX_CHARS; offset <= slen; ++offset) {
        for (int i = 0; i < PANEL_MAX_CHARS; ++i) {
            if (i + offset < 0 || i + offset >= slen) {
                buf[i] = ' ';
            } else {
                buf[i] = s[i + offset];
            }
        }
        print_seven_segment(buf);
#ifndef DEBUG
        usleep(USPF);
        printf("\e[%dA\r", DISP_ROWS);
#endif
    }
}

int main(int argc, char **argv) {
    //__encrypt();
    scroll_print_seven_segment(argc > 1 ? argv[1] : argv[0]);
    return 0;
}
