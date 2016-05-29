#include <iostream>

using namespace std;
int sumCount(int *arr,int length);

int main()
{
	int count = 0;
	int array[100000] = { 0 }; //������ �����ϴ� �迭 
	int *Maxsum; //����� ��� �迭
	int length;
	
		cin >> count;

	Maxsum = new int[count];

	for (int i = 0; i<count; i++)
	{
		length= 0;
		do {
		cin >> length;
		} while (!(length <= 10000 && length >= 1));
		for (int j = 0; j<length; j++)
		{
			do {
			cin >> array[j];
			} while (!(array[j] <= 100 && array[j] >= -100));
			//�迭�� ���ڸ� �ִ´�.
		}
		//���⼭ �ִ����� ã������Ѵ�
		Maxsum[i] = sumCount(array,length);
	}
	//������� ��� ���� ���ϴµ� �ϴٰ� ���� ������ ������ �����Ѱ� 
	
	//��º�
	for (int i = 0; i<count; i++)
	{
		cout << Maxsum[i] << endl;
	}

	delete Maxsum;
	return 0;
}

int sumCount(int *arr, int length)
{
	int fir = 0, last = length, sum = 0, maxSum = 0;
	bool check = false; //���� ���� ���� üũ
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 0)
		{
			check = true;//���� �����̸� false 
		}
	}
	if (check)
	{
		for (int i = 0; i < length; i++)
		{
			if (arr[i] > 0)
			{
				fir = i; break;
			}
		}
		for (int i = length - 1; i >= 0; i--)
		{
			if (arr[i] > 0)
			{
				last = i; break;
			}
		}
		for (int i = fir; i <= last; i++)
		{
			sum += arr[i];
			if (sum < 0)
			{
				sum = 0;
			}
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
		return maxSum;
	}
	else
		return 0;
}