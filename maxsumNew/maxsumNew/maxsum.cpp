#include <iostream>

using namespace std;


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

	
	//��º�
	for (int i = 0; i<count; i++)
	{
		cout << Maxsum[i] << endl;
	}

	delete Maxsum;

}

i