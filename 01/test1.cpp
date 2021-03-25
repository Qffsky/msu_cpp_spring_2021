#include <iostream>
#include "allocator.hpp"
void memoryOverflowTest() 
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char *mem1 = allocator.alloc(10);
    char *mem2 = allocator.alloc(20);
    char *mem3 = allocator.alloc(100);   
    if (mem3 == nullptr)
    {
        std::cout<<"memoryOverflowTest: Success"<<std::endl;	    
    }	    

}

void defaultWorkTest()
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char *mem1 = allocator.alloc(10);
    char *mem2 = allocator.alloc(20);
    char *mem3 = allocator.alloc(50);
    ptrdiff_t f1 = mem3 - mem2;
    ptrdiff_t f2 = mem2 - mem1;
    if (f1 == 20 && f2 == 10)
    {
        std::cout<<"defaultWorkTest: Success"<<std::endl;	    
    }    
}

void resetMethodTest() 
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char* mem1 = allocator.alloc(10);
    char* mem2 = allocator.alloc(20);
    allocator.reset();
    char* mem3 = allocator.alloc(50);
    if (mem1 == mem3)
    {
        std::cout<<"resetMethodTest: Success"<<std::endl;
    }
}

void newSpaceTest()
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char* mem1 = allocator.alloc(50);
    allocator.makeAllocator(150);
    char* mem2 = allocator.alloc(50);
    if (mem1 != mem2)
    {
        std::cout<<"newSpaceTest: Success"<<std::endl;
    }
}

int main()
{	
	memoryOverflowTest();
	defaultWorkTest();
	resetMethodTest();
	newSpaceTest();
	return 0;
}
