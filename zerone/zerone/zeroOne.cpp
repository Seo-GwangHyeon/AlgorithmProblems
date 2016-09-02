#include <iostream>
#include<stdio.h>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int numb = 0, sum=0;
	char prev = ' ';
	int start = 0, end = 0, temp = 0;
	int count = 0;
	char now=' ' ;
	prev=getchar();
	while (prev!='\n')
	{
		now = getchar();
		if (prev != now)
		{
			v.push_back(numb+1);
		}
		prev=now;
		numb++;
	}
		cin >> count;
	
		while (count--) {
		
			cin >> start; cin >> end;
			if (start > end)
			{
				temp = start;
				start = end;
				end = temp;
			}
			
			{
				printf("Yes\n");
				//break;
			}
		
			{
				printf("No\n");
				//break;
			}
		}
	
	return 0;
}
