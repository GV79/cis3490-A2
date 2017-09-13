************************************************
Gia Vinh Lam             0925571
CIS3490                  A2
05/02/2017               glam01@mail.uoguelph.ca
************************************************

***********
Compilation
***********
Assuming that you are in the main folder's directory in the terminal:
make

******************
Running and Usage
******************
Assuming that you are in the main folder's directory in the terminal:
./main data_1.txt data_2.txt
(second and third part are the input files which serves as arguments for the program)

************************
How the Program(s) Works
************************
After running the main file, you will be given a menu where you have three choices.
If you enter 1, the program will calculate the number of inversions in the first data file using
both the brute force method (P11.c) and the mergesort method (P12.c). It'll list the number of inversions found from each method, their execution times, and the difference in their execution times.

If 2 is entered, the program will calculate the convex hull set of all the coordinates given in the second data file with a brute-force and quick-sort approach. It'll return the coordinates along with the number of elements in the convex hull set found, their execution times, and the difference in their execution times.

*********************************
Known Limitations or Assumptions
*********************************
My array sizes will limit certain data files if they're very large (ex. in the first problem, if the data file contained 200000 integers).
Defensive programming is not implemented, therefore the program will not work as intended if the user enters a string instead of an integer at the beginning of the program.
Assumes format from each data file will remain the same along with the size
