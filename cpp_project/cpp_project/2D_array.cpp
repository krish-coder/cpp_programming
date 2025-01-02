#include <iostream>
using namespace std;

int main()
{
	int r = 2, c = 3;
	int data[2][3] = {
		1,2,3,
		4,5,6
	}; // 1,2,3,4,5,6
	int **p_rows = new int*[r];
	for (int i = 0; i < r; ++i)
	{
		p_rows[i] = new int[c]; // *(p_rows+i)
	}
	/// initialize values to it
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			p_rows[i][j] = data[i][j]; // *(*(p_rows+i)+j)

	for (int i = 0; i < r; i++)
		delete[] p_rows[i]; // *(p_rows+i)
	delete[]p_rows;
	return 0;
}