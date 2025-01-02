#include <iostream>
using namespace std;

int main()
{
	int data[2][2][3] = {
		{
			1,2,3,
			4,5,6
		},
		{
			7,8,9,
			10,11,12
		}
	};
	int ch = 2, r = 2, c = 3;
	int*** p_ch = new int**[ch];
	for (int i = 0; i < ch; i++)
	{
		p_ch[i] = new int*[r];
		for (int j = 0; j < r; j++)
		{
			p_ch[i][j] = new int[c];
		}
	}

	// populate values
	for (int k = 0; k < ch; k++)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				p_ch[k][i][j] = data[k][i][j];

	for (int k = 0; k < ch; k++)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cout << p_ch[k][i][j] << " ";

	for (int i = 0; i < ch; i++)
	{
		for (int j = 0; j < r; j++)
		{
			delete[] p_ch[i][j];
		}
		delete[] p_ch[i];
	}
	delete[] p_ch;
	return 0;
}