#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x = 10;
	int &r = x;

	int &&ref_r = 10;

	cout << &ref_r << endl;

	int arr[2] = { 1,2};
	int(&ref)[2] = arr;

	int *ptr = &x;


	vector<int> v;
	vector<int>& vref = v;

	unique_ptr<int> p1;
	unique_ptr<int>& ref_p = p1;

	int const* const & p3 = ptr;
	int * const p4 = ptr;


	
	return 0;
}