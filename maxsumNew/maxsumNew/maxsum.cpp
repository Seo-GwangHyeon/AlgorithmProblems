#include <iostream>

using namespace std;

int Sumcount(int *array, int fir, int last);
int findFirst(int *arr, int fir, int last);
int findLast(int *arr, int fir, int last);


int main()
{
	int count = 0;
	int array[100000] = { 0 }; //������ �����ϴ� �迭 
	int *Maxsum; //����� ��� �迭

	cin >> count;

	Maxsum = new int[count];

	for (int i = 0; i<count; i++)
	{
		int length = 0;
		cin >> length;
		for (int j = 0; j<length; j++)
		{
			cin >> array[j];
			//�迭�� ���ڸ� �ִ´�.
		}
		//���⼭ �ִ����� ã������Ѵ�
		Maxsum[i] = Sumcount(array, 0, length);
	}

	// ������ �˰���
	//  �켱 ���� �߿��� Ű����� ��� �Լ��̴�
	//  �տ��� �ڷΰ��� ������ üũ�� ������ ������
	// �Է��� ù��ġ���� �������� ���� +- �Ǻ� �׸��� 
	// +�̸� ù��ġ �״�� -�� ù��ġ�� -������ġ��
	// �׸��� ��������ġ������ �Ȱ��� ��������ġ�� �缳���Ѵ�
	// �׸��� ������ ����Լ��� ����ϸ� 
	// �ִ� ���� ���ð��̴�.



	//��º�
	for (int i = 0; i<count; i++)
	{
		cout << Maxsum[i] << endl;
	}

	delete Maxsum;

}

int Sumcount(int *array, int fir, int last)
{
	int F = findFirst(array, fir, last);
	int L = findLast(array, F, last);
	int sum = 0;
	cout << F << " " << L << endl;
	for (int i = F; i<L; i++)
		sum += array[i];
	return sum;
}

int findFirst(int *arr, int fir, int last)
{   //last��  �迭�� ���� 
	int sum;
	for (int i = fir; i<last; i++)
	{
		if (arr[i]<0)
		{
			sum = 0;
			for (int j = fir; j<i + 1; j++)
			{
				sum += arr[j];
			}
			if (sum<0)
				return findFirst(arr, i + 1, last);
			else if (sum >= 0)
				return fir;
		}

	}
	return fir;
}

int findLast(int *arr, int fir, int last)
{
	int sum;
	for (int i = last - 1; i >= fir; i--)
	{
		if (arr[i]<0)
		{
			sum = 0;
			for (int j = last - 1; j >= i; j--)
			{
				sum += arr[j];
			}
			if (sum<0)
				return findLast(arr, fir, i);
			else if (sum >= 0)
				return last;
		}
	}
	return last;
}
