#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//ifstream cin;
//	cin.open("Text.txt");
	string team_names[8] ;
	string left_games[50];
	int game_num[8] = { 0, };
	int wingame_num[8] = { 0, };
	int top_team = 0;
	int cheer_team_num = 0;
	string cheer_team = "";
	double cheerteam_winper=0;
	int count = 0, left_game_num = 0,win, draw, loss;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		
		for (int j = 0; j < 8; j++)
		{
			draw = 0, loss = 0;
			cin >> team_names[j] >> win >> draw >> loss;
			game_num[j] = win + draw + loss;
			wingame_num[j] = win;
		}
		cin >> cheer_team;
		for (int m = 0; m < 8; m++)
		{
			if (team_names[m].compare(cheer_team) == 0)
			{
				cheer_team_num = m;
				//cout << cheer_team << endl; //찾았다
				break;
			}
		}
		cin >> left_game_num;
		for (int k = 0; k < left_game_num * 2; k += 2)
			cin >> left_games[k] >> left_games[k + 1];
		for (int k = 0; k < left_game_num * 2; k ++)
		{
			if (left_games[k].compare(cheer_team)==0)
			{
				wingame_num[cheer_team_num]++;
				game_num[cheer_team_num]++;
				//cout << wingame_num[cheer_team_num] << endl;//비교된다.
			}//end if
			else
			{
				for (int n = 0; n < 8; n++)
				{
					if (left_games[k].compare(team_names[n]) == 0)
					{
						game_num[n]++;
					}//end if
				}//end for
			}//end else
		}//end for
	
		cheerteam_winper =( wingame_num[cheer_team_num] / (double)game_num[cheer_team_num]);
		top_team = 0;
		for (int a = 0; a < 8; a++)
		{
			if (cheerteam_winper <(wingame_num[a] / (double)game_num[a]))
			{
				top_team++;
			}
			if (top_team >= 4)
				break;
		}
		if (top_team >= 4)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}//end for i
}//end main