// Happy 16th Birthday Sylesh!
// Copyright 2017 Preetam J. D'Souza
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define PW   (80)
#define PH   (5)
#define DR   (PH)
#define DC   (4)
#define PMC  (PW/DC)
#define USPF (250000)
char *E[] = {
"_--_|_ | -- |  |__ _",                              "  __|__  --_|__|_-- ",
"_--_|  __  _| ___--_",                            "__ _ __| --_| _|_--_",
" -- |    -- |_  _-- ",                          "_--_|_  _-- |____ _ ",
"_--_|_ __--_|__| --_",                        "  __|  | -- |_ | ___",
" _ _|_  ____|_  _   ",                      "_  _ _ |   _  _|_--_",
" __ |_ |_-- |  |__  ",                    " __ |__ _ _ |_   -- ",
" --    |_--    |_--_",                  "___ ___ _--_|  | ___",
" -- |__|  _ |  |_--_",                "_--_|__|_--_|  _ ___",
"_-- |_ |_--_ _ |_   ",              " ______ _--_| _   __",
" -- | ___--___ |_--_",            "_ __|  __--_|_   --_",
"    |  | _ _| _| --_",          "_______ _ _ |  | -- ",
" --_|  __--_|   _--_",        "  __|__| -- |__|_ __",
"_   |  |_--_  _| --_",       " --  __|_-- |_   --_",
"____ __________ _ _ ",      "   ___  _ _  _ _    ",
"_  _ __ __  _ __  _ ",     "_     _   _ ____   _", "_ _ _ _   ___   ___ ",
" _ __  ____ ___  _ _",     "_-- |__| --_|__|_   ",   "    |  _ --_| _|_-- ",
"_--_| ___   |__ _--_",     " _____ | -- |_ |_--_",     "_--_|   _--_|  __--_",
" --_|___ -- |_ __   ",     " --_|  _ -- |_ | -- ",      " ___|  |_-- | _| _  ",
"  __| __   _|__ _  _",     "_______| ____ _| --_",      " _  |_ | --_|_ |_ __",
"__  |_  ____| ___--_",     "_--  _ |_--____| --_",      "_   _  _ --_|_ |___ ",
"_--_|  | __ |__|_-- ",     " --_|_ |_-- | __ __ ",      " --_|  | -- __ |_ __",
"_  _  ___--_|__  ___",      " -- |___ --_ _ |_--_",    " _  |_   -- | ___--_",
" _ _|__|    |__|_-- ",       " _ __  _ _  |  | -- ",  " -- |____--_|___ -- ",
"____| _|_--_|  |_  _",        "__ _|_ | --_   | -- "," --   _|_-- |__  --_",
};
void p(char *s) { for (int i=0; i<DR; ++i)
for (char *p=s,c; *p!='\0'||!putchar('\n'); ++p)
for (int j=0,k=*p-(1<<6|1); j<DC; ++j)
putchar(0<=k&&k<sizeof(E)/sizeof(char*)&&(c=E[k][i*DC+j])
? (c=='_' ? ' ' : c) : ' '); }
void sp(char *s) { char b[PMC+1]={0}; b[PMC]='\0';
for (int o=-PMC, l=strlen(s); o<=l; ++o) {
for (int i=0; i<PMC; ++i)
b[i]=i+o<0||i+o>=l ? ' ' : s[i+o];
p(b);
#ifndef DEBUG
usleep(USPF); printf("\e[%dA\r", DR);
#endif
}}
int main(int c, char **v) { sp(*(v+(c>1))); return 0; }
