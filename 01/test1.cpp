#include <iostream>
#include <cassert>
#include "allocator.cpp"
void memoryOverflowTest() 
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char *mem1 = allocator.alloc(10);
    char *mem2 = allocator.alloc(20);
    char *mem3 = allocator.alloc(100);   
    assert(mem3 == nullptr && mem2 != nullptr && mem1 != nullptr);
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
    assert(f1 == 20 && f2 == 10);
}

void resetMethodTest() 
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char* mem1 = allocator.alloc(10);
    allocator.reset();
    char* mem3 = allocator.alloc(50);
    assert(mem1 == mem3);
}

void newSpaceTest()
{
    Allocator allocator;
    allocator.makeAllocator(100);
    char* mem1 = allocator.alloc(50);
    allocator.makeAllocator(150);
    char* mem2 = allocator.alloc(50);
    assert(mem1 != mem2);
}

int main()
{	
	memoryOverflowTest();
	defaultWorkTest();
	resetMethodTest();
	newSpaceTest();
	std::cout<<"Success"<<std::endl;
	return 0;
}
