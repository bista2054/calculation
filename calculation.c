#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate mean
double calculate_mean(int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate median
double calculate_median(int arr[], int size) {
    // Sort the array (using bubble sort for simplicity)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate mode
void calculate_mode(int arr[], int size, int modes[], int *mode_count) {
    int max_count = 0;
    *mode_count = 0;

    // Count occurrences of each number
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            *mode_count = 1;
            modes[0] = arr[i];
        } else if (count == max_count) {
            // Check if this number is already in modes
            int exists = 0;
            for (int k = 0; k < *mode_count; k++) {
                if (modes[k] == arr[i]) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                modes[*mode_count] = arr[i];
                (*mode_count)++;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print statistics
    printf("Mean: %.2f\n", calculate_mean(arr, size));
    printf("Median: %.2f\n", calculate_median(arr, size));

    int *modes = (int*)malloc(size * sizeof(int));
    int mode_count;
    calculate_mode(arr, size, modes, &mode_count);

    if (mode_count == size) {
        printf("Mode: No mode (all numbers occur equally)\n");
    } else {
        printf("Mode: ");
        for (int i = 0; i < mode_count; i++) {
            printf("%d ", modes[i]);
        }
        printf("\n");
    }

    free(arr);
    free(modes);
    return 0;
}