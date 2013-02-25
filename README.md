Game of Life for Cilk++
========================

By Arne Bjune and Vegar Engen

To read this report in a nicer view goto: http://github.com/vegaen/cilk-game-of-life

This implementation of Conways Game of Life is written in Cilk++ in CS140 at UCSB winter 2013. 


How does it run on Triton?
--------------------------

For `life` we were able to run a matrix with n = 65500 without segfaulting.  
But we do not do as good as we hoped when it comes to time it, . 


![Speedup](https://raw.github.com/vegaen/cilk-game-of-life/master/img/speedup-nprocs.png "Speedup")

As we can tell from fig 1, the scalability of our code is really good (almost perfect linear). This is not supprising though, because in the way we wrote the code every opperation in each iteration is independent and can be done in any order. 

![Cups / Problem size](https://raw.github.com/vegaen/cilk-game-of-life/master/img/cups-problem-size.png "Cups / Problem size")

For this graph we can see that the number of Cells UPdated by Second is quite low for smaller problem sizes, but as the problem sizes grows it converges towards 3.5e4, which makes sense since smaller problems will use some time on the startup-process.




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


For all of them we also moved the countlive into submit.cpp and made a getter and setter which gets or set the array.


Problems
---------

We wasted a lot of time we could have used on optimalizing how to split the matrix between the CPUs, to doing bitwise operations.


