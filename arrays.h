#pragma once

/**
 * @brief Sorts an array of integers in ascending order.
 *
 * This function takes a pointer to an array of integers and its length,
 * sorting the elements in place.
 *
 * @param arr Pointer to the array of integers to be sorted.
 * @param arrLength Number of elements in the array.
 */
void arrSort(int *arr, int arrLength);

/**
 * @brief Generates an array of random integers within a specified range.
 * 
 * This function dynamically allocates an array of `size` integers, 
 * each randomly chosen within the range [`minValue`, `maxValue`].
 * 
 * @param size The number of elements in the array (must be > 0).
 * @param minValue The minimum possible value for generated numbers.
 * @param maxValue The maximum possible value for generated numbers.
 * @return int* Pointer to the dynamically allocated array, or NULL if 
 *         allocation fails or input parameters are invalid.
 * 
 * @note The caller is responsible for freeing the allocated memory.
 */
int* arrGenerateRandom(int size, int minValue, int maxValue);

/**
 * @brief Prints an array with a limit on the number of elements displayed.
 * 
 * This function prints up to `limit` elements of the array. If the array has 
 * more elements than `limit`, it displays the first half of `limit/2`, 
 * followed by `"(...)"`, and then the last half.
 * 
 * @param arr Pointer to the array of integers.
 * @param arrLength Total number of elements in the array.
 * @param limit Maximum number of elements to display.
 * 
 * @note If `arr` is NULL, or `arrLength` is 0 or negative, `"Invalid array"` is printed.
 * @note If `limit` is greater than or equal to `arrLength`, the whole array is printed.
 */
void arrPrintWithLimit(int *arr, int arrLength, int limit);

