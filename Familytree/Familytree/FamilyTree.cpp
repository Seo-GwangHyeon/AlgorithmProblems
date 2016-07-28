#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int case_num = 0;
	int Fnum = 0;
	int count_num = 0;
	int family[100000] = { 0, };
	int cntA = 0, cntB = 0;
	int count_list[100000] = { 0, };
	int target = 0;
	int non_t = 0;
	int ii = 0;
	int find_num = 0;
	bool finded = false;
	int num = 0;
	cin >> case_num;
//	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		//scanf("%d", &Fnum);
		cin >> Fnum;
		//scanf("%d", &count_num);
		cin >> count_num;
		for (int k = 1; k < Fnum; k++)
		{
			//scanf("%d", &family[k]);
			cin >> family[k];
		}
		for (int n = 0; n < count_num; n++)
		{
			//scanf("%d", &cntA); scanf("%d", &cntB);
			cin >> cntA >>cntB;
			//여기에 계산하는 함수 사용 해야한다.
			target = cntA > cntB ? cntB: cntA;// target이 작은거
			bool zero = target==0? true :false;
	
			non_t = cntA > cntB ? cntA : cntB;
			num = 0;
			while (target != 0)
			{
				count_list[num] = target;
				num++;
				target = family[target];
			}
			num++;
			ii = 0;
			find_num = 0;
			finded = false;
			while (!finded)
			{
				for (int nn = 0; nn < num;nn++)
				{
					if (non_t == count_list[nn])
					{
						finded = true;
						find_num = nn;
						break;
					}
				}
				non_t = family[non_t];
				ii++;
				if (zero && (non_t == 0))
				{
					ii++;
					break;
				}	
			}
			printf("%d\n", (ii-1+ find_num));
		}
	}
}