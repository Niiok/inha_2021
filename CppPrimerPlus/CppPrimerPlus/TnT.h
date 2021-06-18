#ifndef ___TIME_N_TEST_H___
#define ___TIME_N_TEST_H___

#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<Windows.h>

class StopWatch {
	
public:
	StopWatch() : start_time_{ clock() }, end_time_ { clock() } {}

private:
	clock_t start_time_ = 0;
	clock_t end_time_ = 0;


public:
	inline void Start() { start_time_ = clock(); }
	inline void Stop() 
	{
		end_time_ = clock();
		printf("\n StopWatch : %ld.%03ld second \n", (end_time_ - start_time_)/1000, (end_time_ - start_time_)%1000);
		//std::cout << "\n StopWatch started : " << start_time_ << "    stopped : " << end_time_ << "\n"; 
	}
	inline time_t ElapsedTime() { return clock() - start_time_; }
};


template<typename T>
class TestArray {

public:

	TestArray()
	{
		array_ = (T*)malloc(10000 * sizeof(T));
		assert(array_);
		size_ = 10000;
		shake();
	}

	TestArray(int num) 
	{
		array_ = (T*)malloc(num * sizeof(T));
		assert(array_);
		size_ = num;
		shake();
	}

	TestArray(const TestArray& ob)
	{
		array_ = (T*)malloc(ob.size() * sizeof(T));
		assert(array_);
		size_ = ob.size();
		memcpy(array_, ob.arr(), size_ * sizeof(int));
	}

	~TestArray()
	{
		free(array_);
	}

private:
	T* array_ = 0;
	int size_ = 0;

public:
	int size() const
	{
		return size_;
	}
	T* arr() const
	{
		return array_;
	}

	void shake()
	{
		for (int i = 0; i < size_; ++i)
		{
			//if (i % 10 == 0)
				//srand(time(NULL));
			//Sleep(1);
			array_[i] = (T)rand();
		}
	}

	void scale(int num)
	{
		for (int i = 0; i < size_; ++i)
		{
			array_[i] = array_[i] % num;
		}
	}

	void MakeStr()
	{
		for (int i = 0; i < size_; ++i)
		{
			array_[i] = (array_[i] % 26) + 97;
		}

		array_[size_ - 1] = 0;
	}
};

#endif
