#include <iostream>
#include <string>
using namespace std;

void FailFunc(string input)
{
	int length = input.length();
	int *f = new int[length];
	
	f[0] = -1;
	for (int j = 1; j < length; j++)
	{
		int i = f[j - 1];
		while ((input[j] != input[i + 1]) && (i >= 0))//'i' is upper than -1 두개가 같아지면 
			// 루프를 빠져나가서 if 조건에서 같으면 0이상인 i에 1을 더해줌
			i = f[i];

		
		if (input[j] == input[i + 1])//input[j] == input[i + 1] jth f array is i+1 
			f[j] = i + 1;
		else f[j] = -1;
	}
	for (int a = 0; a < length; a++)
	{
		cout << f[a]<<" ";
	}
	cout << endl;
}

int main()
{
	string str = "abcabcacab";
	FailFunc(str);
	return 0;
}
