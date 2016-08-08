#include <iostream>
#include <string>
#include <deque>
#include <fstream>
using namespace std;
void func(int input);

string words[100];
int visited[100] = { 0, };
deque<string> dwords;
int word_num = 0;
int main()
{
	ifstream cin;
	cin.open("Text.txt");
	int cases = 0;
	word_num = 0;


	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> word_num;
		for (int j = 0; j < word_num; j++)
		{
			cin >> words[j];
		}
		int num;
		for ( num = 0; num < word_num; num++)
		{
			func(num);
			if (word_num == dwords.size())
			{
				while (!dwords.empty())
				{
					cout << dwords.front() << " ";
					dwords.pop_front();
				}
				cout << endl;
				break;
			}
			else
			{
				for (int mm = 0; mm < word_num; mm++)
				{
					visited[mm] = 0;
				}
				while (!dwords.empty())
				{
					dwords.pop_front();
				}
			}
		}
		
		if(num==word_num)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		for (int mm = 0; mm < word_num; mm++)
		{
			words[mm] = "";
			visited[mm] = 0;
		}
		while (!dwords.empty())
		{
			dwords.pop_front();
		}
	}
}

void func(int input)
{
	dwords.push_front(words[input]);
	visited[input] = 1;
	int front_back = 0;
	for (int i = 0; i < word_num; i++)
	{
		if (dwords.size() == word_num)
			break;
		else if (words[i][words[i].length() - 1] == dwords.front()[0] && !visited[i])
		{
			dwords.push_front(words[i]);
			front_back = 0;
			visited[i] = 1;
			i = 0;
		}
		else if (words[i][0] == dwords.back()[dwords.back().length() - 1] && !visited[i])
		{
			dwords.push_back(words[i]);
			front_back = 1;
			visited[i] = 1;
			i = 0;
		}
	}

}