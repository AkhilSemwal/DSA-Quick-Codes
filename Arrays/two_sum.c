#include <stdio.h>
#include <stdlib.h>

/* Two Sum: Find two numbers that sum up to target in sorted array (Two Pointers): O(n) */
int twoSumSorted(int arr[], int n, int target, int *idx1, int *idx2) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            *idx1 = left;
            *idx2 = right;
            return 1; // Found
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return 0; // Not found
}

/* Two Sum: Hash Map / Frequency based for unsorted array: O(n) */
int twoSumUnsorted(int arr[], int n, int target, int *num1, int *num2) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                *num1 = arr[i];
                *num2 = arr[j];
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    printf("=== Two Sum Problem in Arrays ===\n\n");
    
    int sortedArr[] = {2, 7, 11, 15, 20, 28};
    int n = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int target = 22;
    
    int idx1, idx2;
    if (twoSumSorted(sortedArr, n, target, &idx1, &idx2)) {
        printf("Target %d found in sorted array: %d (index %d) + %d (index %d)\n", 
               target, sortedArr[idx1], idx1, sortedArr[idx2], idx2);
    }
    
    int unsortedArr[] = {8, 14, 3, 2, 9, 1};
    int n2 = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    int target2 = 11;
    int num1, num2;
    if (twoSumUnsorted(unsortedArr, n2, target2, &num1, &num2)) {
        printf("Target %d found in unsorted array: %d + %d\n", target2, num1, num2);
    }
    
    return 0;
}
