#include <iostream>
using namespace std;

int a;
int b = 10;
static int c;
static int d = 14;

int main()
{
	int *ptr{};
	{
		static int y = 2;
		ptr = &y;
	}
	{
		static int r;
		ptr = &r;
	}
	ptr = &a;
	ptr = &b;
	ptr = &c;
	ptr = &d;
	return 0;
}