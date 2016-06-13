#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int count = 0, size=0;
	int matrix[100][100] = { 0 };
	int result[50] = { 0 };
	ifstream fin;
	fin.open("input.txt");
	fin >> count;
	fin >> size;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int m = 0; m < size; m++)
			{
				fin >> matrix[j][m];
			}
		}

		//여기서 결과 입력
	}



}