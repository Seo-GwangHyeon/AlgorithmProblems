#include <stdio.h>
int main()
{
	int case_num = 0, Fnum = 0, count_num = 0, family[100000] = { 0, }, cntA = 0, cntB = 0;
	int count_list[100000] = { 0, }, target = 0, non_t = 0, ii = 0;
	int find_num = 0,finded = 0, num = 0,zero = 0;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; ++i)
	{
		scanf("%d", &Fnum);
		scanf("%d", &count_num);
		for (int k = 1; k < Fnum; ++k)
		{
			scanf("%d", &family[k]);
		}
		for (int n = 0; n < count_num; ++n)
		{
			scanf("%d", &cntA); scanf("%d", &cntB);
			target = cntA > cntB ? cntB: cntA;// target이 작은거
			zero = target==0? 1 :0;
			non_t = cntA > cntB ? cntA : cntB;
			num = 0;
			while (target != 0)
			{
				count_list[num++] = target;
				target = family[target];
			}
			++num;
			ii = 0;
			find_num = 0;
			finded = 0;
			while (!finded)
			{
				for (int nn = 0; nn < num;++nn)
				{
					if (non_t == count_list[nn])
					{
						finded = 1;
						find_num = nn;
						break;
					}
				}
				non_t = family[non_t];
				++ii;
				if (zero && (non_t == 0))
				{
					++ii;
					break;
				}	
			}
			printf("%d\n", (ii-1+ find_num));
		}
	}
}