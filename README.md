# Goldbachs Conjecture 
The Goldbach conjecture was conjectured by Christian Goldbach in 1742.  
It states that any even number can be the sum of any 2 prime numbers, however it is  
still unproven. Source > https://en.wikipedia.org/wiki/Goldbach's_conjecture  
This program tests Goldbach's conjecture up to a given number.  
Do `python3 run.py` to run, then enter a number. The program will test the  
conjecture on all even numbers up to the provided number.  

## C++ Version:
The C++ version is about 5 times faster than the Python version, averaging  
1,000,000 numbers tested every 2.8 seconds. However it's compiled on Linux, so 
you will only be able to run it on Linux or a Linux virtual machine. 
To run it, either do `./gbc` or `run.py`. When running it from the Python file,  
The program keeps track of the execution time. It also counts the time it takes  
you to enter a number, just keep that in mind if comparing the execution time of this  
program, to that of the Python version of this program.
