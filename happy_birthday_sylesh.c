#include <stdio.h>

#define ROWS (5)
#define COLS (3)

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

void print_seven_segment(char *s) {
    for (int i = 0; i < ROWS; ++i) {
        for (char *p = s; *p != '\0'; ++p) {
            int idx = *p - 'A';
            for (int j = 0; j < COLS ; ++j) {
                if (0 <= idx && idx < sizeof(ascii)/sizeof(char*)) {
                    putchar(ascii[idx][i * 3 + j]);
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
    print_seven_segment(argc > 1 ? argv[1] : argv[0]);
    return 0;
}
