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
			}//여기서 하나의 기지에서 다른기지 까지의 거리와 방문을 한다.
			visited[min_n] = true;
			k = min_n;
			min_lengthes[no_mean] = min;
			//cout << min_n << endl;
			no_mean++;
			end++;
			min = 3000001;
			//여기에 최소거리들을 저장하는 리스트 필요함
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
		//반올림해야한다.
		max = -100;
		for (int aaa = 0; aaa < 100; aaa++)
		{
			xlist[aaa] = 0;ylist[aaa] = 0;visited[aaa] = 0;min_lengthes[aaa] = 0;
		}
		//여기에 계산
		
	}
	return 0;
}