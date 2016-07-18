#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int matrix[100][100];
bool matrix_enable[100][100];
bool Check(int size);
int main()
{
	int count = 0, size=0;
	matrix[100][100] = { 0 };

	bool result[50] = { 0 };//YES면 1 NO면 0
	ifstream cin;
	cin.open("input.txt");
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++)
		{
			for (int m = 0; m < size; m++)
			{
				cin >> matrix[j][m];
				matrix_enable[j][m] = true;
			}
		}

		//여기서 결과 입력
		result[i] = Check(size);
		cout << endl;
	}

	for (int i = 0; i < count; i++)
	{
		if (result[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


}
struct xy
{
	int x;
	int y;
	
};

bool Check(int size)
{
	int current_y = 0;//행
	bool down_en = true;
	int current_x = 0;//열
	bool right_en = true;
	int counter = 0;
	stack<xy> stk;
	xy temp;
	temp.x = current_x;
	temp.y = current_y;
	stk.push(temp);
	int i = 0;
	while ((matrix[current_y][current_x] !=0)&&!stk.empty())
	{
		if (current_x + matrix[stk.top().y][stk.top().x] >= size&&current_y + matrix[stk.top().y][stk.top().x] >= size)
		{
			stk.pop();

			matrix_enable[stk.top().y][stk.top().x] = false;
			down_en = true;
			right_en = true;
			continue;
		}
		if (current_x + matrix[stk.top().y][stk.top().x] >= size)
		{
			//current_x -= matrix[stk.top().y][stk.top().x];
		//	matrix_enable[stk.top().y][stk.top().x] = false;

		//	stk.pop();
			down_en = true;
			right_en = false;
		//	continue;
		}
		if (current_y + matrix[stk.top().y][stk.top().x] >= size)
		{
		//	current_y -= matrix[stk.top().y][stk.top().x];
		//	matrix_enable[stk.top().y][stk.top().x] = false;
		//	stk.pop();
			right_en = true;
			down_en = false;
		//	continue;
		}
		if (right_en && (matrix_enable[stk.top().y][stk.top().x]))
		{
			current_x += matrix[stk.top().y][stk.top().x];
			temp.x = current_x;
			temp.y = current_y;
			stk.push(temp);
		}
		else if (down_en && (matrix_enable[stk.top().y][stk.top().x]))
		{
			current_y += matrix[stk.top().y][stk.top().x];
			temp.x = current_x;
			temp.y = current_y;
			stk.push(temp);
		}
		if (i < 100)
		{
			cout << "(" << stk.top().y << " " << stk.top().x << ") ";
		}
		i++;
		
	}
	if ((matrix[current_y][current_x] == 0))
	{
		return true;
	}
	else if(stk.empty())
		return false;
	
}