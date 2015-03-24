#ifndef _DynamicArray_H_
#define _DynamicArray_H_

#include <stdlib.h>

template <class TYPE>

class DynamicArray{

private:

	TYPE* data;//Points the direction of its information
	unsigned int memAlloc;//Number of memory reserved
	unsigned int nElements; //Number of elements inside the array

public:
	//Constructors
	DynamicArray()
	{
		data = NULL;
		memAlloc = 0;
		nElements = 0;
	}

	DynamicArray(unsigned int minSize)
	{
		ReAllocate(minSize);
	}

	//Destructor
	~DynamicArray()
	{
		if (data != NULL){
			delete[]data;
		}
	}

	//Getters
	unsigned int GetCapacity() const
	{
		return memAlloc;
	}

	unsigned int GetnElements() const
	{
		return nElements;
	}

	//Methods
	void ReAllocate(const unsigned int newMemory)
	{
		TYPE* tmp = data;

		memAlloc = newMemory;
		data = new TYPE[memAlloc];

		if (nElements > memAlloc)
		{
			nElements = memAlloc;
		}

		if (tmp != NULL)
		{
			for (int i = 0; i < nElements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

	void PushBack(const TYPE& value)
	{
		if (value != NULL && memAlloc >= nElements + 1)
		{
			nElements++;
			data[nElements] = value;
		}
		else
		{
			ReAllocate(nElements + 1);
			nElements++;
			data[nElements] = value;
		}
	}

	void Pop()
	{
		if (nElements > 0)
		{
			nElements--;
		}
	}

	void Clear()
	{
		while (nElements > 0) // It's the same as doing nElements = 0;
		{
			Pop();
		}
	}

	void Insert(const TYPE& value, int position)
	{
		if (position < nElements)
		{
			if (nElements >= memAlloc)
			{
				ReAllocate(nElements + 10)
			}

			for (int i = nElements; i > position; --i)
			{
				data[i] = data[i - 1];
			}

			data[position] = value;
			nElements++;
		}

		if (position == nElements)
		{

			if (nElements >= memAlloc)
			{
				ReAllocate(nElements + 10)
			}

			PushBack(element); //NO need to nElements++ cause it's done inside PushBack() function
			return true;

		}
		else
		{
		}
	}

	// Operators
	TYPE& operator[](unsigned int index)
	{
		if (index < nElements)
		{
			return data[index];
		}
	}

	const TYPE& operator[](unsigned int index) const
	{
		if (index < nElements)
		{
			return data[index];
		}
	}
};

#endif