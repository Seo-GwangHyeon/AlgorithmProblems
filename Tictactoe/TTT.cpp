#include<iostream>
using namespace std;

class TTT
{
private:

public:
	char GameBoard[3][3];//게임판을 나타내는 2차원 배열
	int whoTurn;  //누구의 차례인지 
				  //0= o(영어 오) 
				  //1= x(영어 엑스)
	TTT();
	int TurnCount();//누구의 턴인지 계산하는 함수
	void whoWin(); // 누가이길지 판단하는 함수
};

TTT::TTT()
{
	{
		GameBoard[3][3] ;
		whoTurn = 1;//X가 선이므로 
	}
}

inline int TTT::TurnCount()
{
	int Ocount = 0, Xcount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ( GameBoard[i][j] == 'O'|| GameBoard[i][j] == 'o')
				Ocount++;
			if ( GameBoard[i][j] == 'X'|| GameBoard[i][j] == 'x')
				Xcount++;
		}
	}
	if (Ocount + 1 == Xcount)
		return 0;//O의 차례이다.
	if (Xcount == Ocount)
		return 1;//X의 차례
	else
		//cerr << "입력오류" << endl;//X가 선이므로 다른경우는 모두 오류이다.
	return -1;//차례를 판별할 수 없을때.
}




void TTT::whoWin()
{	
	char EX = 'x';
	char OE = 'o';
	if (TurnCount() == 0)
	{
		
		for (int i = 0; i < 3; i++)
		{
			//가로 O . O 나 일경우
			if ((GameBoard[i][0] == 'O' || GameBoard[i][0] == 'o') && GameBoard[i][1] == '.')
			{
				if (GameBoard[i][0] == GameBoard[i][2])
				{
					cout << OE << endl;
					return;
				}
			}

			//가로 OO.|| .OO 일경우
			if ((GameBoard[i][1] == 'O' || GameBoard[i][1] == 'o') && (GameBoard[i][0] == '.' || GameBoard[i][2] == '.') && !(GameBoard[i][0] == '.' && GameBoard[i][2] == '.'))
			{
				if (GameBoard[i][0] == GameBoard[i][1] || GameBoard[i][1] == GameBoard[i][2])
				{
					cout << OE << endl; return;
				}
			}

			//세로 O . O 나 일경우
			if ((GameBoard[0][i] == 'O' || GameBoard[0][i] == 'o') &&GameBoard[1][i] == '.')
			{
				if (GameBoard[0][i] == GameBoard[2][i])
				{
					cout << OE << endl; return;
				}
			}
		
		
			//세로 OO.|| .OO 일경우
			if ((GameBoard[1][i] == 'O' || GameBoard[1][i] == 'o') && (GameBoard[0][i] == '.' || GameBoard[2][i] == '.') && !(GameBoard[0][i] == '.' && GameBoard[2][i] == '.'))
			{
				if (GameBoard[0][i] == GameBoard[1][i] || GameBoard[1][i] == GameBoard[2][i])
				{
					cout << OE << endl; return;
				}
			}
		}

		//대각선 O.O 
		if (((GameBoard[0][0] == 'O' || GameBoard[0][0] == 'o')|| (GameBoard[0][2] == 'O' || GameBoard[0][2] == 'o')) &&GameBoard[1][1]=='.')
		{
			if (GameBoard[0][0] == GameBoard[2][2] || GameBoard[0][2] == GameBoard[2][0])
			{
				cout << OE << endl; return;
			}
		}
		//대각선 OO. .OO
		if ((GameBoard[1][1] == 'O' || GameBoard[1][1] == 'o') &&(GameBoard[0][0] == '.' || GameBoard[0][2] == '.' || GameBoard[2][0] == '.' || GameBoard[2][2] == '.')\
			&&!(GameBoard[0][0] == '.' && GameBoard[0][2] == '.') && !(GameBoard[2][0] == '.' && GameBoard[0][2] == '.'))
		{
			if (GameBoard[0][0] == GameBoard[1][1] || GameBoard[0][2] == GameBoard[1][1] || GameBoard[2][0] == GameBoard[1][1] || GameBoard[1][1] == GameBoard[2][2])
			{
				cout << OE << endl; return;
			}
		}
		//cout << "TIE" << endl;
	}
	else if (TurnCount() == 1)
	{

		for (int i = 0; i < 3; i++)
		{
			//가로 X . X 나 일경우
			if ((GameBoard[i][0] == 'X' || GameBoard[i][0] == 'x') && GameBoard[i][1] == '.')
			{
				if (GameBoard[i][0] == GameBoard[i][2])
				{
					cout << EX << endl; return;
				}
			}

			//세로 X . X  일경우
			if ((GameBoard[0][i] == 'X' || GameBoard[0][i] == 'x') && GameBoard[1][i] == '.')
			{
				if (GameBoard[0][i] == GameBoard[2][i])
				{
					cout << EX << endl; return;
				}
			}

			//가로 XX.|| .XX 일경우
			if ((GameBoard[i][1] == 'X' || GameBoard[i][1] == 'x') && (GameBoard[i][0] == '.' || GameBoard[i][2] == '.') && !(GameBoard[i][0] == '.' && GameBoard[i][2] == '.'))
			{
				if (GameBoard[i][0] == GameBoard[i][1] || GameBoard[i][1] == GameBoard[i][2])
				{
					cout << EX << endl; return;
				}
			}


			//세로 XX.|| .XX 일경우
			if ((GameBoard[1][i] == 'X' || GameBoard[1][i] == 'x') && (GameBoard[0][i] == '.' || GameBoard[2][i] == '.') && !(GameBoard[0][i] == '.' && GameBoard[2][i] == '.'))
			{
				if (GameBoard[0][i] == GameBoard[1][i] || GameBoard[1][i] == GameBoard[2][i])
				{
					cout << EX << endl; return;
				}
			}
		}

		//대각선 X.X 
		if (((GameBoard[0][0] == 'X' || GameBoard[0][0] == 'x') || (GameBoard[0][2] == 'X' || GameBoard[0][2] == 'x')) && GameBoard[1][1] == '.')
		{
			if (GameBoard[0][0] == GameBoard[2][2] || GameBoard[0][2] == GameBoard[2][0])
			{
				cout << EX << endl; return;
			}
		}
		//대각선 XX. .XX
		if ((GameBoard[1][1] == 'X' || GameBoard[1][1] == 'x') && (GameBoard[0][0] == '.' || GameBoard[0][2] == '.' || GameBoard[2][0] == '.' || GameBoard[2][2] == '.')\
			&&!(GameBoard[0][0] == '.' && GameBoard[0][2] == '.') && !(GameBoard[2][0] == '.' && GameBoard[0][2] == '.'))
		{
			if (GameBoard[0][0] == GameBoard[1][1] || GameBoard[0][2] == GameBoard[1][1] || GameBoard[2][0] == GameBoard[1][1] || GameBoard[1][1] == GameBoard[2][2])
			{
				cout << EX << endl; return;
			}
		}
		//cout << "TIE" << endl;
	}
	//if (TurnCount() == -1)
	//{
	//	cout << "입력오류" << endl; return;
	//}
	cout << "TIE" << endl;
	return;
}

//
// Tictactoe Program
// 진행중인 Tactactoe 판을 입력하면 어떤 말이 승리하는지
// 말은 O와 X (대문자 알파벳 오 와 엑스임
// 예상하는 프로그램 


int main()
{
	int count = 0;//테스트 케이스 수
	TTT Cases[50];//테스트 케이스 배열 최대 50개의 테스트 케이스
	
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				cin >> Cases[i].GameBoard[a][b];//게임판 입력
			}
		}
	}
	
	for (int i = 0; i < count; i++)
	{
		Cases[i].whoWin();
	
	}
	return 0;
}
