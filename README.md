# 🧮 Gauss Matrix Calculator

## 📝 Overview
This C program is a **Gauss Matrix Calculator** designed to solve linear equations using **Gauss Elimination**. It can be used to find solutions to systems of linear equations where matrix \(A\) and matrix \(B\) are provided as input. The calculations are designed like matrixes **`Ax = B`**.

The program reads matrix data from files, performs Gaussian Elimination to solve for the unknowns, and prints the result (matrix \(X\)) to the console. It also uses back substitution to derive the solution vector.

## 💡 Features
- **Gaussian Elimination**: Uses Gaussian Elimination to solve systems of equations.
- **Back Substitution**: Once the upper triangular matrix is formed, the program applies back substitution to compute the solution.
- **Matrix Operations**: Handles reading from files, matrix manipulation, and printing matrices to the console.
- **Error Handling**: Ensures matrix files are properly loaded and checks for invalid matrices.

## 📁 Files
- **`main.c`**: The main file that takes function from other files and solves the problem.
- **`gauss.c`**: Contains functions that implement Gaussian Elimination.
- **`backsubstr.c`**: Implements back substitution which is a mathematical operation.
- **`math_io.c`**: Reads from files and checks if they are all right. 

## 🔨 Usage
1. Compile the files first and then run the program:
   ```bash
   gcc -o gaussCalc main.c gauss.c backsubst.c math_io.c
   ./gaussCalc <matrix_A_file> <matrix_B_file>
2. Example of a matrix:
   ```bash
   3 3
   1 2 3
   4 5 6
   7 8 9
Top 2 numbers say how many rows and columns matrix mas. 
   
## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
