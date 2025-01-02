#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int const *ptr{};
	int * const ptr1{};
	int * const p3 = new int{ 5 };
	int a = 6;
	ptr = &a;
	// *ptr = 7;  Error
	// ptr1 = &a; Error
	int x = 2, y = 5;
	int &ref = x;
	const int & ref_2ref = ref;
	cout << x << " " << y << endl;
	//swap(&x, &y);
	swap(x, y);
	cout << x << " " << y << endl;
	const int &ref_rval = 5;
	const int &ref_rval2 = x;
	cout << ref_rval2 << endl;

	int *p5 = new int{ 10 };
	// reference to pointer
	int* &ref_p5 = p5;
	*ref_p5 = 11;
	cout << *p5 << endl;
	delete p5;
	ref_p5 = &a;
	cout << *p5 << endl;

	const int * p6 = new int{ 8 };
	const int* const & ref_p6 = p6;
	delete p6;

	int *p7 = new int{ 6 };
	const int *p8 = new int{ 6 };
	int *const p9 = new int{ 6 };
	const int *const p10 = new int{ 6 };
	//const int* & ref_p7 = p7;
	int* const & ref_p7_1 = p7;
	const int * const & ref_p7_2 = p10;
	delete p7;
	const int *ptr11 = &x;
	int *const ptr12 = &x;
	const int *&p_ref1 = ptr11;
	const int*const &p_ref2 = ptr12;

	return 0;
}