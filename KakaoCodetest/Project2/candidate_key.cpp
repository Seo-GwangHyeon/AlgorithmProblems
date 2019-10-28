#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> g_com;
void Combination(int* set, int set_size, int n, int k, int index)
{
	if (set_size == k)
	{
		vector<int> temp;
		for (int i = 0; i < set_size; ++i)
		{
			temp.push_back(set[i]);
		}
		g_com.push_back(temp);	
		return;
	}
	if (n == index)
	{
		return;
	}

	set[set_size] = index;
	Combination(set, set_size + 1, n, k, index + 1);
	Combination(set, set_size, n, k, index + 1);
}
int check_minimum(vector<int>  columns, int j)
{
	int flag = 1;
	for (int i = 0; i < g_com[j].size(); ++i)
	{
		if (columns[g_com[j][i]] == 1)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void change_minimum(vector<int> columns, int j)
{
	int flag = 1;
	for (int i = 0; i < g_com[j].size(); ++i)
	{
		columns[g_com[j][i]] = 1;
	}	
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int row = relation.size();
	int col = relation[0].size();
	vector<int> colums = vector<int> (col);
	
	int* val = new int(col);
	for (int i = 1; i <= col;++i)
	{
		Combination(val, 0, col, i, 0);
		for (int j = 0; j < g_com.size(); ++j)
		{//조합 선택
			map<string, string> map1;
			for (int t = 0; t < row; ++t)
			{			
				for (int k = 0; k < g_com[j].size(); ++k)
				{//조합 내부 돌기 (0,1)
					map1.insert(make_pair(relation[t][g_com[j][k]],""));
				}
			}
			if (map1.size() == row && check_minimum(colums,j))
			{
				change_minimum(colums, j);
				answer++;
			}
		}
		g_com.clear();
		
	}

	return answer;
}


int main()
{
	vector<vector<string>> str1 = { {"100", "ryan", "music", "2"}
						,{"200", "apeach", "math", "2"}
						,{"300", "tube", "computer", "3"}
						,{"400", "con", "computer", "4"}
						,{"500", "muzi", "music", "3"}
						,{"600", "apeach", "music", "2"} };
	
	cout << solution(str1) << endl;
	vector<string> temp = { "x","a","b","c","d" };
	vector<string> emp ;
	


	int a = 0;
	cin >> a;


	return 0;
}

