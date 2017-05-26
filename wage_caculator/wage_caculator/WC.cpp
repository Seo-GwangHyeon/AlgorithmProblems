

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //윤년판정매크로 

struct day_wage
{
	int year;//
	int month;
	int start_time;//시작시간
	int end_time;//끝난시간
	int date;//그날 날짜
	int doweek;//요일
};
void print_calendar(int day,int dow);
int str_to_int(char* str1, int a, int b);
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {

	int year, month; // 연도와 월을 저장할 변수 
	struct day_wage days[31];
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 총일 수 (첫번째 수는 제외) 
	int lastyear, day, i;
	int key, select;
	int temp_day,temp_year,temp_month;
	char str1[10]="";
	char str2[15] = "";
	select = 1;//초기 선택값 1로설정
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 7);
	system("cls");
	while (1)
	{
		printf("몇년 몇월의 임금을 측정하시겠습니까?(YYYY/MM)\n");
		scanf("%s", str1);
		if (str1[0] == 48)
		{
			break;
		}
		year = str_to_int(str1, 0, 3);
		month = str_to_int(str1,5,6);
		//달력 만들기
		if (month == 2 && leapyear(year))// 해당년도가 윤년이면, 2월은 총 29일 
		{
			totalday[2] = 29;
		}
		lastyear = year - 1; // 작년 말까지 진행된 요일을 계산하기 위해 lastyear를 선언 
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;
		/* lastyear : 1년은 365일, 1년이 지날때마다 요일이 한번 늘어난다 (365를 7로 나누면 1이기 때문)
		+(lastyear/4)-(lastyear/100)+(lastyear/400) : 윤년의 다음연도는 요일이 두번 늘어므로,
		lastyear까지 있던 모든 윤년을 더한다 +1 : 1년 1월 1일은 일요일이 아니라 월요일이므로 1을 더한다 (0년은 없다)
		%7 : 요일은 7가지 이므로, 앞의 계산값을 7로 나눈 나머지가 year년 1월의 첫요일 뜻한다 나머지값에 따라
		0:일요일, 1:월요일, 2:화요일, 3:수요일, 4:목요일, 5:금요일, 6:토요일 */
		for (i = 1; i < month; i++) // year년 month월 직전까지의 총 일 수를 구하기 위한 for문 
		{
			day += totalday[i];
			day %= 7; // year년 month월 1일의 시작 요일 
		}
		for (i = -day; i < totalday[month]; i++)
		{
			if (i < 0)
			{
				days[i].date = -1;//일
			}
			else
			{
				days[i].date = i + 1;//일
			}
			days[i].start_time = 0;
			days[i].end_time = 0;
			days[i].year = year;
			days[i].month = month;
			days[i].doweek = (i + day)%7;//일별 요일 입력
		}
		_getch();
		//여기서부터 달력 출력
		while (1)
		{
			//----여기 days 초기화 해야함
			

			system("cls");
			printf("\n %d년/ %d월\n\n", year, month); // year년 month월 타이틀 출력 

			if (select == 1)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(1)날짜계산 \t ");
			if (select == 1)
			{
				SetConsoleTextAttribute(hc, 7);
			}


			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(2)월급계산\n");
			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 7);
			}
			print_calendar(day, totalday[month]);
			//if (kbhit())
			{
				key = _getch();
				
				if (key == 224)
				{
					key = _getch();
					if (key == 75)
					{//left
						select = 1;
						Sleep(100);
					}
					else if (key == 77)
					{//right
						select = 2;
						Sleep(100);
					}
				}
				else if (key == 13)
				{
					
					if (select == 1)
					{//날짜입력 받기
						printf("근무한 날짜입력 (YYYY/MM/DD):");
						scanf("%s", str2);
						temp_year = str_to_int(str2, 0, 3);
						temp_month = str_to_int(str2, 5, 6);
						temp_day = str_to_int(str2, 8, 9);
						//printf("%d", temp_day);
						for (i = 0; i < 31; i++)
						{
							if (days[i].date == temp_day)
							{
								printf("시작시간: \n");
								printf("끝난시간: ");
								gotoxy(10,14);
								_getch();
								gotoxy(10, 15);
								_getch();
								
							}
						}
					}
					else if (select == 2)
					{
						system("cls");
					}
				}
			}
			//_getch();
			

			//임금 입력 넣을곳
			

		}
		
	
	}

	return 0;
}
void print_calendar(int day, int dow)
{
	printf("\n  일  월  화  수  목  금  토"); // 요일 리스트 출력 
	for (int i = -day; i < dow; i++)
	{
		if ((i + day) % 7 == 0) // 출력될 차례가 일요일이면, 개행 
		{
			printf("\n");
		}
		if (i < 0) // month월 1일이 출력되기 이전의 날짜는 공백으로 채운다. 
		{
			printf("    ");
		}
		else
		{
			printf("%4d", i + 1);
		}
	}
	printf("\n\n");
}
int str_to_int(char* str1, int a, int b)
{
	int result = 0;
	int ten = 1;
	for (int i = b; i >= a; i--)
	{
		result += (str1[i]-48) * ten;
		ten *= 10;
	}
	return result;
}