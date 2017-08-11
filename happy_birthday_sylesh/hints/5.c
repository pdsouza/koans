#include <stdio.h>
#include <stdlib.h>

#define ROWS (5)
#define COLS (3)

// ASCII -> seven segment
char *ascii[] = {
    " - | | - | |   ",
    "   |   - | | - ",
    " - |     |   - ",
    "     | - | | - ",
    " - |   - |   - ",
    " - |   - |     ",
    " - |   - | | - ",
    "   | | - | |   ",
    "   |     |     ",
    "     |     | - ",
    "   | | - | |   ",
    "   |     |   - ",
    " -   | -   | - ",
    "       - | |   ",
    " - | |   | | - ",
    " - | | - |     ",
    " - | | -   |   ",
    "       - |     ",
    " - |   -   | - ",
    "   |   - |   - ",
    "   | |   | | - ",
    "         | | - ",
    " - |   - |   - ",
    "   | | - | |   ",
    "   | | -   | - ",
    " -   | - |   - ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    " - | | - | |   ",
    "   |   - | | - ",
    " - |     |   - ",
    "     | - | | - ",
    " - |   - |   - ",
    " - |   - |     ",
    " - |   - | | - ",
    "   | | - | |   ",
    "   |     |     ",
    "     |     | - ",
    "   | | - | |   ",
    "   |     |   - ",
    " -   | -   | - ",
    "       - | |   ",
    " - | |   | | - ",
    " - | | - |     ",
    " - | | -   |   ",
    "       - |     ",
    " - |   -   | - ",
    "   |   - |   - ",
    "   | |   | | - ",
    "         | | - ",
    " - |   - |   - ",
    "   | | - | |   ",
    "   | | -   | - ",
    " -   | - |   - ",
};

// Obfuscated ASCII map
char eascii[sizeof(ascii)/sizeof(char*)][15];

// Simple encryption function to obfuscate the ASCII -> seven segment map
void encrypt() {
    char pool[] = {' ', '_'};
    printf("char *e = {\n");
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
        printf("\"%s\",\n", eascii[i]);
    }
    printf("};\n");
}

// Print a string, emulating a seven segment display
void segprint(char *s) {
    for (int i = 0; i < ROWS; ++i) {
        for (char *p = s; *p != '\0'; ++p) {
            int idx = *p - 'A';
            for (int j = 0; j < COLS ; ++j) {
                if (0 <= idx && idx < sizeof(eascii)/sizeof(char*)) {
                    char c = eascii[idx][i*3+j];
                    putchar(c == '_' ? ' ' : c); // decrypt whitespace
                } else {
                    putchar(' ');
                }
            }
            putchar(' '); // space between letters
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    encrypt();
    segprint(argc > 1 ? argv[1] : argv[0]);
    return 0;
}
