// Cpp_features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int add(int *a, int* b)
{
	if (nullptr != a && nullptr != b)
	{
		return (*a + *b);
	}
	return -1;
}
void add(int* a, int* b, int* result)
{
	if (nullptr != a && nullptr != b && nullptr != result)
	{
		*result = *a + *b;
	}
}

void factorial(int* a, int* result)
{
	if (result == nullptr || a == nullptr)
	{

	}
	else
	{
		*result = 1;
		if (1 == *a || 0 == *a)
		{

		}
		else
		{
			for (int i = *a; i > 1; i--)
			{
				*result *= i;
			}
		}
	}
}

void print(const int *ptr)
{
	if (ptr != nullptr)
		std::cout << *ptr << std::endl;
}

void print(const int &p)
{
	// you can pass any constant or literal to it and doesnot have to be lvalue
	// no need of dereferencing syntax
	// no need to check for nullptr
	std::cout << p << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";
	const int &t = 9; // you may have  a const reference with literal or constant and not necessarily a lvalue
	int a = 5, b = 10, c=0;
	const int *ptr1 = &a;
	int * const ptr2 = &b;
	*ptr2 = 9;
	std::cout << add(&a, &b) << std::endl;
	add(&a, &b, &c);
	std::cout << c << std::endl;
	factorial(&a, &c);
	std::cout << c << std::endl;



	int x = 5;
	const int MAX = 12;
	int &ref_x1 = x;
	const int &ref_x2 = x;
	const int *ptr11 = &x;
	int *const ptr22 = &x;
	const int * const ptr33 = &x;

	const int *ptr34 = &MAX;
	//int *ptr4 = &MAX;

	const int &r1 = ref_x1;
	//int &r2 = ref_x2;

	//int *&p_ref1 = ptr1;
	//const int*&p_ref2 = ptr2;
	void(*pfn)(const int &) = &print;
	(*pfn)(500);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
