#include <stdio.h>
int main()
{
	int in_arr[100000] = { 0, };
	int count = 0, sum;
	int start = 0, end = 0, temp = 0;
	scanf("%s", (in_arr));
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &start); scanf("%d", &end);
		if (start > end)
		{
			temp = start;
			start = end;
			end = temp;
		}
		sum = in_arr[start];
		for (int j = start; j <= end; j++)
		{
			if (sum != in_arr[j])
			{
				sum = -1;
				break;
			}
		}
		if (sum==-1)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}