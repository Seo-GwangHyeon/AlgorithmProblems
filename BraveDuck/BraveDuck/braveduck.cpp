#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

double distance(int a_x, int b_x, int a_y, int b_y)
{
	int x = a_x > b_x ? a_x - b_x : b_x - a_x;
	int y = a_y > b_y ? a_y - b_y : b_y - a_y;
	return sqrt(x*x + y*y);
}

int main()
{
	ifstream cin;
	cin.open("Text.txt");
	int cases = 0, stone_num = 0, \
		start_x = 0, start_y = 0, \
		end_x = 0, end_y = 0;
	int max_jump=0;
	int stone_x[100] = { 0, };
	int stone_y[100] = { 0, };
	int visited[100] = { 0, };
	int select[100] = { 0, };

	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> max_jump;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		cin >> stone_num;
		for (int j =0; j <stone_num; j++)
			cin >> stone_x[j] >> stone_y[j];
		int a=1;
		visited[0] = 1;
		double min = 3000;
		int temp_x = start_x;
		int temp_y = start_y;
		int min_pp = 0;
		while (1)
		{
			if (distance(start_x, end_x, start_y, end_y) <= max_jump)
			{
				cout << "YES" << endl;
				break;
			}

			else
			{
				int sel_num = 0;
				for (int k = 0; k < stone_num; k++)
				{
					if (distance(start_x, stone_x[k], start_y, stone_y[k]) <= max_jump&&!visited[k])
					{//�湮���� ���� ���� �Ÿ��� �������ɰŸ����� ���� �͵��� �̴´�.
						select[sel_num] = k;
						sel_num++;
					}
				}
				if (sel_num == 0)
				{
					cout << "NO"<<endl;
					break; break;
				}
				//end for
				//���������� ���� ���� select
				//select���� end�� �����ŷ� ����
				for (int kk = 0; kk < sel_num; kk++)
				{
					if (distance(end_x, stone_x[select[kk]], end_y, stone_y[select[kk]]) < min)
					{
						min = distance(end_x, stone_x[select[kk]], end_y, stone_y[select[kk]]);
						start_x = stone_x[select[kk]];
						start_y = stone_y[select[kk]]; min_pp = select[kk];
					}
				}
				visited[min_pp] = 1;
			//	cout << start_x << " " << start_y << endl;

				//�ּ� ����
			}
			
		}
	}
}