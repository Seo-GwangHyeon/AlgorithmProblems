#include "BruteForce.h"

int BruteForce(char* Text, int TextSize, int Start,
	char* Pattern, int PatternSize)
{
	int i = 0;
	int j = 0;

	for (i = Start; i <= TextSize - PatternSize; i++)
	{
		for (j = 0; j < PatternSize; j++)
		{
			if (Text[i + j] != Pattern[j])
				break;//
		}
		if (j >= PatternSize)//������ �� ��ģ���,
			return i;//������ �߰ߵ� ù index�� ��ȯ�Ѵ�.
	}
	return -1;//��ġ�ϴ� ���� ���°��
}