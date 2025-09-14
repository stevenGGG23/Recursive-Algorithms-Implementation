/* A.I. Disclaimer: All work for this assignment was completed by myself and entirely without the use
 of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc.

 * Author: Steven Gobran
 * Program Description: This program implements four recursive functions:
 * 1. Sum - calculates sum of integers from 1 to n
 * 2. KthLargest - finds the kth largest element in an array
 * 3. Longest - finds longest substring of positive numbers
 * 4. FindEagle - counts connected cells in a 2D grid (eagle detection)
 */

#include <iostream>
#include <fstream> 
#include <cassert>
#include <algorithm>
#include "parameters.h"

using namespace std;

// Function prototypes
int Sum(int n);
int KthLargest(int arr[], int size, int k);
int Longest(int arr[], int lower, int upper);
int FindEagle(int grid[][50], int rows, int cols, int x, int y);
void sortArray(int arr[], int size);

int main() {
    
    // Problem 1: Test Sum function
    cout << "Problem 1 - Sum Function:" << endl;
    int sumResult = Sum(SumVal);
    cout << "Sum(" << SumVal << ") = " << sumResult << endl << endl;
    
    // Problem 2: Test KthLargest function
    cout << "Problem 2 - KthLargest Function:" << endl;
    cout << "Array: ";
    for(int i = 0; i < 13; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    
    int secondLargest = KthLargest(const_cast<int*>(array1), 13, 2);
    cout << "2nd largest value: " << secondLargest << endl;
    
    int fourthLargest = KthLargest(const_cast<int*>(array1), 13, 4);
    cout << "4th largest value: " << fourthLargest << endl << endl;
    
    // Problem 3: Test Longest function
    cout << "Problem 3 - Longest Function:" << endl;
    cout << "Array1: ";
    for(int i = 0; i < 13; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    int longest1 = Longest(const_cast<int*>(array1), 0, 12);
    cout << "Longest substring of positive numbers: " << longest1 << endl;
    
    cout << "Array2: ";
    for(int i = 0; i < 15; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
    int longest2 = Longest(const_cast<int*>(array2), 0, 14);
    cout << "Longest substring of positive numbers: " << longest2 << endl << endl;
    
    // Problem 4: Process eagle photographs from file
    cout << "Problem 4 - Eagle Detection:" << endl;
    ifstream inputFile("eagle.dat");
    assert(inputFile && "Error: Could not open eagle.dat file");
        
    int rows, cols;
    while (inputFile >> rows >> cols) {
        int grid[50][50];
        
        // Read the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                inputFile >> grid[i][j];
            }
        }
        
        // Display the original grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        
        int eagleCount = 0;
        
        // Search for eagles in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    int eagleSize = FindEagle(grid, rows, cols, i, j);
                    cout << "An eagle size " << eagleSize << " is found." << endl;
                    eagleCount++;
                }
            }
        }
        
        cout << eagleCount << " eagle(s) found in the picture." << endl << endl;
    }
    
    inputFile.close();
    return 0;
}

// Problem 1: Recursive sum function
int Sum(int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    // Recursive case: n + sum(n-1)
    return n + Sum(n - 1);
}

// Helper function to sort array for KthLargest
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Problem 2: Find kth largest element recursively
int KthLargest(int arr[], int size, int k) {
    // Create a copy to avoid modifying original array
    int tempArr[20];
    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }
    
    // Sort the array in descending order
    sortArray(tempArr, size);
    
    // Base case: if k is 1, return the largest (first) element
    if (k == 1) {
        return tempArr[0];
    }
    
    // Recursive case: find (k-1)th largest in the remaining array
    return KthLargest(tempArr + 1, size - 1, k - 1);
}

// Problem 3: Find longest substring of positive numbers
int Longest(int arr[], int lower, int upper) {
    // Base cases
    if (lower > upper) {
        return 0;
    }
    
    if (lower == upper) {
        return (arr[lower] > 0) ? 1 : 0;
    }
    
    // Calculate longest substring starting at current position
    int currentLength = 0;
    int i = lower;
    while (i <= upper && arr[i] > 0) {
        currentLength++;
        i++;
    }
    
    // Recursively find longest in the rest of the array
    int restLength = Longest(arr, lower + 1, upper);
    
    // Return the maximum of current substring length and rest
    return max(currentLength, restLength);
}

// Problem 4: Find and erase connected eagle cells
int FindEagle(int grid[][50], int rows, int cols, int x, int y) {
    // Base cases: out of bounds or empty cell
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0) {
        return 0;
    }
    
    // Mark current cell as visited by setting it to 0
    grid[x][y] = 0;
    int count = 1;  // Count current cell
    
    // Recursively check all 8 adjacent cells
    // Check vertically, horizontally, and diagonally adjacent cells
    count += FindEagle(grid, rows, cols, x - 1, y - 1);  // top left
    count += FindEagle(grid, rows, cols, x - 1, y);      // top
    count += FindEagle(grid, rows, cols, x - 1, y + 1);  // top right
    count += FindEagle(grid, rows, cols, x, y - 1);      // left
    count += FindEagle(grid, rows, cols, x, y + 1);      // right
    count += FindEagle(grid, rows, cols, x + 1, y - 1);  // bottom left
    count += FindEagle(grid, rows, cols, x + 1, y);      // bottom
    count += FindEagle(grid, rows, cols, x + 1, y + 1);  // bottom right
    
    return count;
}