Fist Fit Best Fit
Program: Memory Simulation

Developer : Nhat Ho 

The project was to simulate memory allocation and deallocation using link list. The program is made of functions to produce link list and test both Best Fit and First Fit.

File manifest : list.cpp README

Compile instructions : run a3.cpp
Operating instructions  : execute exe and simulations will run

List/description of novel/significant design decisions: 
mergeHole() function had to be created for merging fragments by checking the memory (link list) for any consecutive fragments and combining the size while deleting the excess node. 
insertAfter() Function checks if after a  process entered the memory  has any excess size and creates a node after.
Creating 2 list with the same initial static memory and running both algorithm on the same memory made it clearer to see which algorithm was best under our simulation
Using a random deallocation per loop made it the simulation unpredictable as depending on the process chose there could be deallocation and process could enter the memory.

List/description of any extra features/algorithms/functionality:
Program prints the initial memory in an organize fashion where the user could see what processes has been allocated or deallocated. Extra stats will be printed out as well such how many allocations, deallocations, merged fragments, how many fragments where available in the life span of the simulation. 

List/description of all known deficiencies or bugs :
There is a bug where two nodes in the link list might occur where it both has Null id, Null size, and Null flags. We implemented a condition to check for these cases so it would not interrupt our counter when this happens in mergeHole function. The allocation and deallocation rate is reliant on how many process gets allocated so testing different version of an deallocation algorithm would be help understand when either Best fit and First Fit is preferred.

Lessons Learned:
Our team had to learn different ways to implement link list in both C and C++. It took us some time to break down every process that like page 192 from the text and implement such ass though linked list functions.
