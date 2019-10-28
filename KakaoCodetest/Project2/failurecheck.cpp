#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>   
using namespace std;


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	sort(stages.begin(), stages.end());
	vector<int> map1(501);
	vector<int> map2(501);
	vector<int> map3(501);
	
	for (int i = 0; i < stages.size(); ++i)
	{
		map1[stages[i]] += 1;
		for (int j = 0; j < N ; ++j)
		{
			if (stages[i] > j)
			{
				map2[j+1]++;
			}
		}
	}
	vector<double> answer2(N + 1);
	map<double, int> ans3;
	for (int i = 0; i < N + 1; ++i)
	{
		if (map2[i] == 0)
			map2[i] = 1;
		answer2[i]=(double)map1[i] /map2[i];
	}
	sort(answer2.begin(), answer2.end());


	for (int i = N; i >= 1; --i)
	{
		for (int j = 1; j < N + 1;++j)
		{
			if (answer2[i] == (double)map1[j] / map2[j] && map3[j] == 0)
			{
				answer.push_back(j);
				map3[j] = 1;
			}
		}		
	}
	return answer;
}
int main()
{
	vector<int> str1;
	str1.push_back(2);
	str1.push_back(1);
	str1.push_back(2);
	str1.push_back(6);
	str1.push_back(2);
	str1.push_back(4);
	str1.push_back(3);
	str1.push_back(3);

	str1 = solution(5,str1);
	for (int i = 0; i < str1.size(); ++i)
	{
		cout << str1[i] << endl;
	}

	int a = 0;
	cin >> a;
	return 0;
}

