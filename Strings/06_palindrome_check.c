#include <stdio.h>
#include <string.h>

int stringLength(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int isPalindrome(const char *str) {
    int len = stringLength(str);
    int left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    printf("=== Palindrome Check ===\n");
    
    printf("'racecar': %s\n", isPalindrome("racecar") ? "Palindrome" : "Not Palindrome");
    printf("'hello': %s\n", isPalindrome("hello") ? "Palindrome" : "Not Palindrome");
    printf("'12321': %s\n", isPalindrome("12321") ? "Palindrome" : "Not Palindrome");
    printf("'madam': %s\n", isPalindrome("madam") ? "Palindrome" : "Not Palindrome");
    
    return 0;
}
