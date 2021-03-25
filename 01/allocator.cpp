#include <iostream>
class Allocator
{
	public:
		void makeAllocator(size_t maxSize) 
		{
			if (allocated == true)
			{
				delete[] memory;
			}
			allocated = true;
			memory = new char[maxSize];
			offset = 0;
			allocated_size = maxSize;
		}
        	char* alloc(size_t size) 
		{
			size_t new_offset = offset + size;
			if (new_offset > allocated_size)
			{
				return nullptr;
			}
			char *block = &memory[offset];
			offset = new_offset;
			return block;
		}
		void reset()
		{
			offset = 0;
		}
		~Allocator()
		{
			delete[] memory;
		}

	private:
		bool allocated = false;
		size_t allocated_size;
		size_t offset;
		char *memory;
};
