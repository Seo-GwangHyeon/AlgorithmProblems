#include <iostream>
#include <fstream>
using namespace std;
int v[50] = { 0, };
int n = 0;
int vm = 0;
int max_a;
void treee(int seed, int next);
int main()
{
	ifstream cin;
	cin.open("Text.txt");
	int cases = 0, vs = 0 ;
	
	int sum = 0;
	max_a = 0;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> n;
		cin >> vs;
		cin >> vm;
		sum = vs;
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}


	//	cout << treee(vs, 0) << endl;
		treee(vs, 0);
		if (max_a == 0)
			cout <<-1 << endl;
		else
			cout << max_a << endl;
		//-----------------새알고리즘
		//크나큰 트리펼치기 재귀로 
		// 값들이 들어올때마다 +/-로 나누어서 트리를 펼친다.
		// 트리 펼치다가 그값이 0보다 작거나 max_a값 보다 크면 트리를 더이상 펼치지 않는다.
		// 그리고 최종으로 나온값들중 최대값을 출력한다. 

		max_a = 0;
	}
	return 0;
}

void treee(int seed,int next)
{
	if (seed >= 0 && seed <= vm)
	{
		if (next >= n)
		{
			if (max_a < seed)
				max_a = seed;
		}
		else
		{
			treee(seed + v[next], next + 1);
			treee(seed - v[next], next + 1);
		}
	}
	
}