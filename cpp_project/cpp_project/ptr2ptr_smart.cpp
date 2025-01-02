#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int data[2][3] = {
		1,2,3,
		4,5,6
	}; //1,2,3,4,5,6
	unique_ptr<unique_ptr<int []>[]> p_rows = make_unique<unique_ptr<int[]>[]>(2);
	for (int i = 0; i < 2; i++)
	{
		p_rows[i] = make_unique<int[]>(3);
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			p_rows[i][j] = data[i][j];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cout << p_rows[i][j] << endl;

	return 0;
}