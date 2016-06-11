#include <stdio.h>
#include <stdlib.h>

__inline double factorial(int ab,int a, int b)
{
	double result = 1;
	int i = 1;
	for (; i <= a ; i++)
	{
		result *= i;
		result /= i;
	}
	for (int j = 1; j <= b; j++, i++)
	{
		result *= i;
		result /= j;
	}
	return result;
}

void swap(int *a, int *b)
{
	int temp=0;
	temp = *a;
	*a = *b;
	*b = temp  ;;
}
char str[1000000000] = { 0 };
int strI = 0;

void Find(int n, int m, unsigned long k) {
	if (k == 1) {
		while (n--)
		{
			str[strI] = '-';
			strI++;
		}
		while (m--)
		{
			str[strI] = 'o';
			strI++;
		}
		return;
	}

	double num = factorial(n + m , m,n);
	if (num >= k) {
		str[strI] = '-';
		strI++;
		return Find(n - 1, m, k);
	}

	str[strI] = 'o';
	strI++;
	return Find(n, m - 1, k - num);
}
int main(void)
{
	int count = 0;
	char result[50][10000000] = { 0 };
	int resultCounts[50] = { 0 };
	int m = 0, n = 0, choose = 0;;
	char str[200]="";
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &m); scanf("%d", &n); scanf("%d", &choose);
		Find(m, n, choose);
		resultCounts[i] = m + n;
		strcpy( result[i],str);
		strI = 0;

	}
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < resultCounts[i]; j++)
		{
			printf("%c", result[i][j]);

		}
		puts("");
	}
	

	//printf("%.0lf\n",factorial(50,10,40));
	
}