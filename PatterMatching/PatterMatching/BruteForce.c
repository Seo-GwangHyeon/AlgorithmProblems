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
		if (j >= PatternSize)//루프를 다 마친경우,
			return i;//패턴이 발견된 첫 index를 반환한다.
	}
	return -1;//일치하는 것이 없는경우
}