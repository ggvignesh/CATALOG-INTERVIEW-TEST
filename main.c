#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string number from a given base to decimal
long long base_to_decimal(int base, const char* value) {
    return strtoll(value, NULL, base);
}

// Function to perform Lagrange interpolation
double lagrange_interpolation(long long x_points[], long long y_points[], int k, int x) {
    double result = 0.0;
    for (int i = 0; i < k; i++) {
        double term = y_points[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (double)(x - x_points[j]) / (x_points[i] - x_points[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Test Case 1
    int k1 = 3;
    long long x_points1[3] = {1, 2, 3};
    long long y_points1[3] = {
        base_to_decimal(10, "4"),
        base_to_decimal(2, "111"),
        base_to_decimal(10, "12")
    };
    double result1 = lagrange_interpolation(x_points1, y_points1, k1, 0);
    printf("Test Case 1: The polynomial at x=0 is: %.2f\n", result1);

    // Test Case 2
    int k2 = 6;
    long long x_points2[6] = {1, 2, 3, 4, 5, 6};
    long long y_points2[6] = {
        base_to_decimal(10, "28735619723837"),
        base_to_decimal(16, "1A228867F0CA"),
        base_to_decimal(12, "32811A4AA0B7B"),
        base_to_decimal(11, "917978721331A"),
        base_to_decimal(16, "1A22886782E1"),
        base_to_decimal(10, "28735619654702")
    };
    double result2 = lagrange_interpolation(x_points2, y_points2, k2, 0);
    printf("Test Case 2: The polynomial at x=0 is: %.2f\n", result2);

    return 0;
}
