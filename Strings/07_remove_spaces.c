#include <stdio.h>
#include <string.h>

#define MAX_STR 1000

void removeSpaces(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[MAX_STR];
    strcpy(str, "H e l l o   W o r l d");
    
    printf("=== Remove Spaces ===\n");
    printf("Original: %s\n", str);
    
    removeSpaces(str);
    printf("After removing spaces: %s\n", str);
    
    return 0;
}
