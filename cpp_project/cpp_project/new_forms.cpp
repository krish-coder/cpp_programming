#include <iostream>
using namespace std;
int main()
{
	int (*p1) = new int; // uninitialized int memory
	delete p1;
	p1 = nullptr;

	int(*p2) = new int{ 10 }; // initialized int memory to 10
	delete p2;
	p2 = nullptr;

	int (*p3) = new int[2]{ 1,2};
	*(p3 + 0); // access value 1
	*(p3 + 1); // access value 2
	p3[0]; // access value 1
	p3[1]; // access value 2
	delete[] p3;
	p3 = nullptr;

	// string requires one extra memory for terminating null
	char(*str) = new char[4]{ "c++" };
	cout << str[0] << str[1] << str[2] << endl;

	// how to store a pointer inside another pointer
	int* *p4 = new int*;
	int *p6 = new int{8};
	cout << *p6 << endl;
	*p4 = p6;
	delete *p4;
	*p4 = nullptr;
	delete p4;
	p4 = nullptr;

	// how to store two pointers inside another pointer
	int* *p7 = new int*[2];
	p7[0] = new int{10};
	p7[1] = new int{ 11 };
	delete p7[0];
	delete p7[1];
	delete[]p7;

	// 2D array on stack that can provide row-column indexing access to 1D memory
	int ar[2][3] = {
		1,2,3,
		4,5,6
	};
	// 2D memory for heap 
	int rows = 2;
	int cols = 3;
	int* *arr = new int*[rows];
	arr[0] = new int[cols] {1,2,3};
	arr[1] = new int[cols] {4,5,6};
	for (int i = 0 ; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
	// dereferencing operator based access can be confusing
	cout << *(*(arr + 0) + 0) << endl; // **arr
	delete[] arr[0];
	delete[] arr[1];
	delete[] arr;

	// 3D image 
	rows = 3;
	cols = 4;
	int ch = 2;
	// stack memory
	int ar3D[2][3][4] = { 
		{
		1,2,3,4,
		5,6,7,8,
		9,10,11,12
		},
		{
			13,14,15,16,
			17,18,19,20,
			21,22,23,24
		} 
	};
	// one matrix is int* type
	int** *arr3D = new int**[ch];
	// for each channel
	for (int ch_i = 0; ch_i < ch; ch_i++)
	{
		// allocate a matrix int*
		arr3D[ch_i] = new int*[rows];
		for (int r = 0; r < rows; r++)
		{
			arr3D[ch_i][r] = new int[cols] {};
		}
	}

	for (int ch_i = 0; ch_i < ch; ch_i++)
	{
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				arr3D[ch_i][r][c] = ar3D[ch_i][r][c];
			}

		}
	}
	for (int ch_i = 0; ch_i < ch; ch_i++)
	{
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				cout << arr3D[ch_i][r][c] << ", ";
			}
			cout << endl;
		}
		cout << endl;
	}

	for (int ch_i = 0; ch_i < ch; ch_i++)
	{
		for (int r = 0; r < rows; r++)
		{
			delete[] arr3D[ch_i][r];
		}
		delete[] arr3D[ch_i];
	}

	delete[] arr3D;
	return 0;
}