#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin;
	cin.open("Text.txt");
	string in_arr = "";
	cin >> in_arr;
	int count = 0, sum;
	bool result[100000] = { 0, };
	cin >> count;
	int start = 0, end = 0, temp = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> start; cin >> end;
		if (start > end)
		{
			temp = start;
			start = end;
			end = temp;
		}
		sum = 0;
		for (int j = start; j <= end; j++)
		{
			if (in_arr[j] == '1')
				sum += 1;
		}
		if (sum == 0 || sum == end-start+1)
			result[i] = true;
		else
			result[i] = false;
	}
	for (int i = 0; i < count; i++)
	{
		if (result[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}