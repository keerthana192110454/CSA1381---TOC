#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isLanguageAccepted(char *string, int start, int end) {
    if (start > end) {
        return true;
    }
    if (string[start] == '0' && string[end] == '1') {
        for (int i = start + 1; i < end; i++) {
            if (isLanguageAccepted(string, start + 1, i - 1) && isLanguageAccepted(string, i, end - 1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);
    int length = strlen(string);
    if (isLanguageAccepted(string, 0, length - 1)) {
        printf("String belongs to the language.\n");
    } else {
        printf("String does not belong to the language.\n");
    }
    return 0;
}
