Game of Life for Cilk++
========================

By Arne Bjune and Vegar Engen

This implementation of Conways Game of Life is written in Cilk++ in CS140 at UCSB winter 2013. 


How does it run on Triton?
--------------------------



![Efficiency/CPU](/path/to/img.jpg "Efficiency/CPU")
![CUPS/CPU](/path/to/img.jpg "CUPS/CPU")



How to Compile
---------------

By running `make` you will get 5 executable files: `life`, `life_debug`, `life-memopt`, `life_debug-memopt` and `validate`.


`life` is the main program, and only print the time it used calculate the game of life to stdout.  
`life_debug` prints the number of cells for every 1/10th iteration  
`life-memopt` is a implementation we did trying to minimize the memory usage  
`life_debug-memopt` combination of the two above
`validate' takes a debug output and checks if it is correct



Edited in harness
------------------

For `life` and `life_debug` we changed the int array used to store the world into a char array, this simple operation saved us 1/4 of the memory. We also made a secondary array that we could save the new state to. 

For `life-memopt` and `life_deug-memopt` we try to minimalize the use of memory by splitting one char into 4 pieces, 2 bit in each piece, which we tough were a good aproach. But the complications and extended computation time by using bitwise manipulation was a huge disappointment.   



Problems
---------

We wasted a lot of time we could have used on optimalizing how to split the matrix between the CPUs, to doing bitwise operations.


