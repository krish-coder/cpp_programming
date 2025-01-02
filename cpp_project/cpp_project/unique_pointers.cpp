#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> p1 = make_unique<int>(10); // create singel memory
	cout << p1 << endl;
	cout << *p1 << endl;
	*p1 = 12;

	// ownership transfer (equivalent to copy)
	unique_ptr<int> p2 = move(p1);

	// reassign new memory
	p1 = make_unique<int>(25);

	unique_ptr<int[]> p3 = make_unique<int[]>(5);
	for (int i = 0; i < 5; i++)
		cout << p3[i] << endl;

	return 0;
}