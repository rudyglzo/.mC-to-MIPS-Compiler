CS4318 Assignment 4: MIPS Code Generator Documentation

1. Student Information
   Name: Rudy Garcilazo
   Course ID: CS4318

2. Project Planning
   I worked on the project individually, dedicating focused time throughout the weeks to implement the code generator. I used Git for version control and organized my development process to systematically implement each required functionality.

3. Work Implementation
   I implemented the following components for the MIPS code generator:
   - Basic arithmetic operations (+, -, *, /)
   - Variable declarations and assignments
   - Function call implementation
   - Output function integration
   - Error handling for basic cases
   
4. Testing Strategy Examples
   I developed two primary test cases to verify the core functionality of my compiler:

   Test Case 1: Arithmetic Operations and Output
   ```c
   void main() {
     int x;
     x = 2 + 2;
     x = 55 - 10;
     x = 4 * 5;
     x = 108 / 2;
     output(x);
   }
   ```
   This test verifies:
   - Integer variable declaration
   - All four arithmetic operations
   - Variable assignment
   - Output function integration

   Test Case 2: Multiple Function Definitions
   ```c
   void main() {
     int b;
     b = 5;
     output(b);
   }

   int main() {
     int a;
     a = 10;
     output(a);
   }
   ```
   This test verifies:
   - Multiple function handling
   - Local variable scope
   - Variable assignment and output in different functions

5. Known Issues and Debugging Process
   During development, I encountered several challenges:
   - Limited success in implementing all test cases
   - Used compile_tests.sh script for automated testing
   - Utilized SPIM for assembly code verification
   
   Important Note: The testFunc.s file contains incomplete implementation and should not be executed. Running this file will result in errors and undefined behavior.
   
6. Calling Convention Details
   The implemented MIPS calling convention includes:
   - Stack-based parameter passing
   - Basic register saving mechanisms
   - Local variable storage in stack frames
   - Return value handling through appropriate registers

7. Execution Instructions
   To compile and run the compiler:
   ```bash
   cd assgn4
   make clean
   make
   ```

   To run automated tests:
   ```bash
   ./compile_tests.sh
   ```

   To compile and run a single file:
   ```bash
   ./obj/mcc < input.mC > output.s
   spim -file output.s
   ```

   WARNING: Do not attempt to run testFunc.s as it contains incomplete implementation and will not execute correctly.