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
		//-----------------���˰���
		//ũ��ū Ʈ����ġ�� ��ͷ� 
		// ������ ���ö����� +/-�� ����� Ʈ���� ��ģ��.
		// Ʈ�� ��ġ�ٰ� �װ��� 0���� �۰ų� max_a�� ���� ũ�� Ʈ���� ���̻� ��ġ�� �ʴ´�.
		// �׸��� �������� ���°����� �ִ밪�� ����Ѵ�. 

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