#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin;
	cin.open("Text.txt");
	int cases = 0, n = 0, vs = 0, vm = 0;
	int v[50] = { 0, };
	int sum = 0;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> n;
		cin >> vs;
		cin >> vm;
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}
		for (int k = 0; k < n; k++)
		{
			if (sum + v[k] < vm)
			{
				sum += v[k];
				cout << sum << " ";
			}
			else if(sum-v[k]>0)
			{
				sum -= v[k];
				cout << sum << " ";
			}
			else
			{
				sum = -1;
				break;
			}
		}
		cout << endl;
		cout << sum<<endl;
		sum = 0;
	}
}