#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bof(char *str) {
    char buffer[24];  // Буфер фиксированного размера 24 байта
    strcpy(buffer, str);  // Уязвимое копирование без проверки длины
    return 1;
}

int main(int argc, char **argv) {
    char str[517];
    FILE *badfile = fopen("badfile", "r");
    if (badfile) {
        fread(str, sizeof(char), 517, badfile);
        bof(str);
        printf("Returned Properly\n");
        fclose(badfile);
    }
    return 1;
}

