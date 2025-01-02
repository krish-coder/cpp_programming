#include <iostream>
using namespace std;

// lvalue reference function variant in overloading
void print(int &x)
{
	cout << "print(int &x)" << endl;
}
// note that const qualifier variant can coexist with reference types only without ambiguity
void print(const int &x)
{
	cout << "print(const int &x)" << endl;
}
// rvalue reference
void print(int &&x)
{
	cout << "print(int &&x)" << endl;
}

//void print(const int &&x)
//{
//	cout << "print(const int &&x)" << endl;
//}


// note that const does not play a role in overloading normal arguments
// the following function conflicts with int x argument
//void print(int x)
//{
//	cout << "print(int x)" << endl;
//}
//
//
//void print(volatile int x)
//{
//	cout << "print(int x)" << endl;
//}
//void print(const int x)
//{
//	cout << "print(const int x)" << endl;
//}

int main()
{
	int r1 = 0;
	print(r1); //  print(int &x)

	const int r2 = 9; //print(const int &x)
	print(r2);

	int &&e = 8; //print(int &&x) else print(int &x)
	print(e); // 

	const int &&t = 9;
	print(t); // calls print(const int &&x) else calls print(const int &x)

	return 0;
}