#include <iostream>
using namespace std;


void add(int a, int b)
{
	cout << "sum is :" << a + b << endl;
}

int main()
{

	void (*pfn)(int, int);
	pfn = &add;
	(*pfn)(2, 3);
	int *p = new int[5]{ 1};
	delete[]p;
	return 0;
}