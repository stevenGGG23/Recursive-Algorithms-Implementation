# Recursive Algorithms Implementation 
A comprehensive C++ program demonstrating four essential recursive algorithms for mathematical computation, array analysis, and image processing applications.

## 🎯 Project Overview

This project implements four recursive functions that solve common computational problems:
1. **Mathematical Series Computation** - Sum of consecutive integers
2. **Array Analysis** - Finding Kth largest elements
3. **Pattern Recognition** - Longest positive subsequences
4. **Image Processing** - Connected component detection (Eagle Detection)

## 🔧 Features

- **Pure Recursive Implementation** - All algorithms use recursion without iteration
- **Efficient Array Processing** - Handles both positive and negative integer arrays
- **2D Grid Analysis** - Processes multiple photographs from file input
- **Connected Component Detection** - Identifies and counts connected regions in 2D grids
- **Robust Error Handling** - File validation and boundary checking

## 📁 File Structure

```
Project_2/
├── Project_2.cpp      # Main implementation file
├── parameters.h       # Test data constants
├── eagle.dat         # Input data file for eagle detection
└── README.md         # This file
```

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++, or Visual Studio)
- Text editor or IDE (VS Code recommended)

### Compilation and Execution
```bash
# Compile the program
g++ Project_2.cpp -o Project_2

# Run the executable
./Project_2
```

## 📊 Input Format

### Eagle Detection Data File (`eagle.dat`)
```
3 4
0 0 1 2
1 0 0 0
1 0 5 1
5 5
0 0 0 1 1
0 1 8 1 9
0 0 0 0 0
1 0 0 2 1
1 3 1 9 1
```
- First line: `rows columns` (grid dimensions)
- Following lines: Grid data (0 = empty, 1-9 = filled cells)
- Multiple grids can be processed sequentially

## 💻 Sample Output

```
Problem 1 - Sum Function:
Sum(13) = 91

Problem 2 - KthLargest Function:
Array: 10 -4 3 7 8 0 10 2 22 14 -5 -2 7 
2nd largest value: 14
4th largest value: 10

Problem 3 - Longest Function:
Array1: 10 -4 3 7 8 0 10 2 22 14 -5 -2 7 
Longest substring of positive numbers: 4
Array2: -10 -4 3 7 0 30 10 2 22 13 0 -5 6 2 -7 
Longest substring of positive numbers: 5

Problem 4 - Eagle Detection:
0 0 1 2 
1 0 0 0 
1 0 5 1 
An eagle size 2 is found.
An eagle size 2 is found.
An eagle size 2 is found.
3 eagle(s) found in the picture.

0 0 0 1 1 
0 1 8 1 9 
0 0 0 0 0 
1 0 0 2 1 
1 3 1 9 1 
An eagle size 6 is found.
An eagle size 8 is found.
2 eagle(s) found in the picture.
```

## 🔍 Algorithm Details

### 1. Sum Function
**Purpose**: Calculates sum of integers from 1 to n
**Recurrence**: `sum(n) = n + sum(n-1)`
**Use Case**: Mathematical series computation, factorial-related calculations

### 2. KthLargest Function
**Purpose**: Finds the Kth largest element in an unsorted array
**Method**: Recursive sorting and selection
**Use Case**: Statistical analysis, ranking systems, data analysis

### 3. Longest Function
**Purpose**: Finds the longest consecutive subsequence of positive numbers
**Method**: Dynamic programming with recursion
**Use Case**: Pattern recognition, data trend analysis, signal processing

### 4. FindEagle Function
**Purpose**: Detects and counts connected components in a 2D grid
**Method**: Depth-first search with recursive flood fill
**Use Case**: Image processing, object detection, computer vision applications

## 🎯 Why This Project Matters

### Educational Value
- **Recursion Mastery**: Demonstrates proper recursive thinking and implementation
- **Algorithm Design**: Shows how to break complex problems into smaller subproblems
- **Data Structures**: Practical application of arrays and 2D grids

### Real-World Applications
- **Image Processing**: Eagle detection simulates object recognition in satellite imagery
- **Data Analysis**: KthLargest is fundamental to statistical computing
- **Pattern Recognition**: Longest positive subsequence applies to trend analysis
- **Computer Vision**: Connected component detection is crucial for object identification

### Technical Skills Developed
- Recursive algorithm design and implementation
- File I/O operations and data parsing
- 2D array manipulation and boundary checking
- Memory management and efficient data processing

## 📈 Performance Characteristics

| Algorithm | Time Complexity | Space Complexity | Use Case |
|-----------|----------------|------------------|----------|
| Sum | O(n) | O(n) | Mathematical computation |
| KthLargest | O(n²) | O(n) | Statistical analysis |
| Longest | O(n²) | O(n) | Pattern detection |
| FindEagle | O(m×n) | O(m×n) | Image processing |

## 🤝 Contributing

This project was completed as part of CSCI 3110 coursework. The implementation focuses on educational value and demonstrates core recursive programming concepts.

## 📝 License

This project is for educational purposes as part of computer science curriculum.

---

*Developed as part of CSCI 3110 - Data Structures and Algorithms*
