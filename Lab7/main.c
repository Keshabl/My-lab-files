#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_char_regular(char c) {
    putchar(c);
}

void print_char_reversed(char c) {
    char *p = (char *) malloc(sizeof(char) * 2);
    if (p == NULL) {
        printf("?????? ????????? ??????\n");
        exit(1);
    }
    p[0] = c;
    p[1] = '\0';
    strcat(p, "\033[7m \033[0m");
    print_string(p);
    free(p);
}

void print_char_alternating(char c) {
    static int mode = 0;
    if (mode == 0) {
        putchar(c);
    } else {
        char *p = (char *) malloc(sizeof(char) * 2);
        if (p == NULL) {
            printf("?????? ????????? ??????\n");
            exit(1);
        }
        p[0] = c;
        p[1] = '\0';
        strcat(p, "\033[7m \033[0m");
        print_string(p);
        free(p);
    }
    mode = (mode + 1) % 2;
}

void print_string(char *s, void (*print_char)(char)) {
    if (*s) {
        print_char(*s);
        print_string(s + 1, print_char);
    }
}

int main() {
    char *h = "??????, ";
    char *w = "???";
    char *s = "!";
    char *p = (char *) malloc(strlen(h) + strlen(w) + strlen(s) + 1);

    if (p == NULL) {
        printf("?????? ????????? ??????\n");
        return 1;
    }

    strcpy(p, h);
    strcat(p, w);
    strcat(p, s);
    strcat(p, "\n");

    void (*print_char_functions[])(char) = {print_char_regular, print_char_reversed, print_char_alternating};

    int print_char_index = rand() % 3;

    int len = strlen(p);
    int *indices = (int *) malloc(sizeof(int) * len);
    if (indices == NULL) {
        printf("?????? ????????? ??????\n");
        exit(1);
    }

	int i;
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    for (i = 0; i < len; i++) {
        int j = rand() % len;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    for (i = 0; i < len; i++) {
        int index = indices[i];
        print_string(p + index, print_char_functions[index % 3]);
    }

    free(p);
    free(indices);
    return 0;
}
