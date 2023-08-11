#include <stdio.h>
#include <string.h>
int isMember(char* str, int start, int end) {
    if (start > end) {
        return 1;
    }
    if (str[start] == '0' && str[end] == '0') {
        int i;
        for (i = start + 1; i <= end - 1; i++) {
            if (isMember(str, start + 1, i - 1) && isMember(str, i + 1, end - 1)) {
                return 1;
            }
        }
    }
    if (str[start] == '1' && isMember(str, start + 1, end)) {
        return 1;
    }
    return 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    if (isMember(input, 0, length - 1)) {
        printf("Given string belongs to the CFG.\n");
    } else {
        printf("Given string does not belong to the CFG.\n");
    }
    return 0;
}
