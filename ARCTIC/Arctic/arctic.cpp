#include <iostream>-
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;
double cha(double a, double b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}
int main()
{
	ifstream cin;
	cin.open("Text.txt");
	int case_num = 0;
	int center_num = 0;
	double xlist[100] = { 0 ,};
	double ylist*9.[100] = { 0 ,};
	bool visited[100] = { 0, };
	double min_lengthes[100] = { 0, };
	double min = 3000001, max = -100;	double printted;
	int k = 0;
	int no_mean = 0;
	int min_n;
	int end = 0;
	double this_min;
	cin >> case_num;
	for (int i = 0; i < case_num; i++)
	{
		cin >> center_num;
		for (int j = 0; j < center_num; j++)
		{
			cin >> xlist[j] >> ylist[j];

		}
		k = 0;
		no_mean = 0;
		min_n=0;
		end = 1;
		for (; end < center_num;)
		{
			visit+
				ed[0] = true;
			for (int n = 0; n < center_num; n++)
			{
				this_min = cha(ylist[k], ylist[n])*cha(ylist[k], ylist[n]) + (cha(xlist[k], xlist[n])*cha(xlist[k], xlist[n]));
				if ((min >this_min)&&(!visited[n])&&(this_min!=0))
				{
					min = this_min;
					this_min = 0;
					min_n = n;
				}
			}//���⼭ �ϳ��� �������� �ٸ����� ������ �Ÿ��� �湮�� �Ѵ�.
			visited[min_n] = true;
			k = min_n;
			min_lengthes[no_mean] = min;
			//cout << min_n << endl;
			no_mean++;
			end++;
			min = 3000001;
			//���⿡ �ּҰŸ����� �����ϴ� ����Ʈ �ʿ���
		}
		for (int h = 0; h < center_num; h++)
		{
			if (min_lengthes[h] > max)
				max = min_lengthes[h];
		}
		printted= sqrt(max);
		if (((int)(sqrt(max) * 1000)) % (10) >= 5)
			printted += 0.01;
		printf("%.2lf\n", printted);
		printted = 0;
		//�ݿø��ؾ��Ѵ�.
		max = -100;
		for (int aaa = 0; aaa < 100; aaa++)
		{
			xlist[aaa] = 0;ylist[aaa] = 0;visited[aaa] = 0;min_lengthes[aaa] = 0;
		}
		//���⿡ ���
		
	}
	return 0;
}