#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
	int case_num = 0, Fnum = 0, count_num = 0, family[100000] = { 0, }, cntA = 0, cntB = 0;
	stack<int> ListA,ListB;
	int   numA = 0, numB = 0,u=0;
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
			
			if (cntA == cntB)
			{
				;
			}
			else if (cntA == 0 )
			{
				while (cntB != 0)
				{
					ListB.push(cntB);
					cntB = family[cntB];
				}
				numB = ListB.size();
			}
			else if (cntB == 0)
			{
				while (cntA != 0)
				{
					ListA.push(cntA);
					cntA = family[cntA];
				}
				numA = ListA.size();
			}
			else {
				while (cntA != 0)
				{
					ListA.push(cntA);
					cntA = family[cntA];
				}
				while (cntB != 0)
				{
					ListB.push(cntB);
					cntB = family[cntB];
				}
				u = 0;
				numA = ListA.size();
				numB = ListB.size();
				while (ListA.top() == ListB.top())
				{
					++u;
					ListA.pop();
					ListB.pop();
				}
			}
			//새 알고리즘 두개 다 찾아서 공통인 수 중 가장 작은수 찾으면 끝 
		
			printf("%d\n", (numA - u+numB - u));
			u = 0;
			numB = 0;
			numA = 0;
			while (!ListA.empty() )
				ListA.pop();
			while (!ListB.empty())
				ListB.pop();
		}
	}
}