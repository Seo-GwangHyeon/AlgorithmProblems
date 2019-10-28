#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	map<string, string> idmap;
	vector < pair<string, string>>talkmap;
	vector<string> split_str;
	
	for (int i = 0; i<record.size(); ++i)
	{
		int k = 0;
		for (int j = 0; j<record[i].length(); ++j)
		{
			if (record[i][j] == ' ')
			{
				split_str.push_back(record[i].substr(k, j - k));
				k = j + 1;
			}
		}
		split_str.push_back(record[i].substr(k, record[i].length()-1));

		if (split_str[0] == "Enter")
		{
			pair<string, string> temp;
			temp.first = split_str[1];
			temp.second = "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			talkmap.push_back(temp);

			pair<string, string> temp2;
			temp2.first = split_str[1];
			temp2.second = split_str[2];
			idmap.erase(temp2.first);
			idmap.insert(temp2);
		}
		else if (split_str[0] == "Leave")
		{
			pair<string, string> temp;
			temp.first = split_str[1];
			temp.second = "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			talkmap.push_back(temp);
		}
		else if (split_str[0] == "Change")
		{
			idmap.at(split_str[1]) = split_str[2];
		}
		split_str.clear();
	}

	vector<string> answer;

	for (auto& x : talkmap) {
		string msg = idmap.at(x.first) + x.second;
		answer.push_back(msg);
	}
	
	return answer;
}

int main()
{
	vector<string> str1;
	str1.push_back("Enter uid1234 Muzi");
	str1.push_back("Enter uid4567 Prodo");
	str1.push_back("Leave uid1234");
	str1.push_back("Enter uid1234 Prodo");
	str1.push_back("Change uid4567 Ryan");
	str1=solution(str1);
	for (int i = 0; i < str1.size(); ++i)
	{
		cout << str1[i] << endl;
	}

	int a = 0;
	cin >> a;
	return 0;
}
