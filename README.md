## 💡 Features
<!-- Features section listing out key capabilities of the program -->
- **Gaussian Elimination**: Uses Gaussian Elimination to solve systems of equations.
- **Back Substitution**: Once the upper triangular matrix is formed, the program applies back substitution to compute the solution.
- **Matrix Operations**: Handles reading from files, matrix manipulation, and printing matrices to the console.
- **Error Handling**: Ensures matrix files are properly loaded and checks for invalid matrices.

## 📁 Files
- **`main.c`**: The main file that takes function from other files and solves the problem.
- **`gauss.c`**: Contains functions that implement Gaussian Elimination.
- **`backsubstr.c`**: Implements back substitution which is a mathematical operation.
- **`math_io.c`**: Reads from files and checks if they are all right. 

## 💻 Compilation
1. Compile the program:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c

## 🔨 Usage
1. Compile the files first and then run the program:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c
   ./mazeSolver <maze_name>
2. Example of a maze:
   ```bash
   ######
   P    #
   # ## #
   #  # #
   ####K#
P is the beggining of the maze and K is the ending.    
   

## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
