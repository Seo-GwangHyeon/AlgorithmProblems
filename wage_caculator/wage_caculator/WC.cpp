

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //윤년판정매크로 

struct day_wage
{//구조체 사용
	int yr;//
	int mon;
	int start_time;//시작시간
	int end_time;//끝난시간
	int wage;
	int date;//그날 날짜
	int doweek;//요일
};
void print_calendar(int day,int dow);
int str_to_int(char* str1, int a, int b);
void gotoxy(int x, int y)//커서위치 바꾸는 함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {

	int year, month; // 연도와 월을 저장할 변수 
	struct day_wage days[31];//구조체 배열 사용
	int MIN_MONEY = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 총일 수 (첫번째 수는 제외)  
	double nights[48];
		//0-1, 5-6,
	int lastyear, day, i;
	int key, select;
	int temp_day, temp_year, temp_month;
	char str1[10] = "";
	char str2[15] = "";
	for (int k = 0; k < 48; k++)
	{//야간 수당 매핑
		if (k % 24 < 6 || k % 24 >= 22)
		{
			nights[k] = 0.5;
		}
		else
		{
			nights[k] = 0;
		}
	}
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);//글자색 바꾸기 위해서
	SetConsoleTextAttribute(hc, 7);//글자와 배경색을 default로 바꿈
	system("cls");//새로고침
	while (1)
	{
		select = 1;	//초기 선택값 1로설정
		key = 0;
		i = 0;
		MIN_MONEY = 0;
		for (i = 0; i < 31; i++)
		{
			days[i].start_time = -1;
			days[i].end_time = -1;
		}
		system("cls");
		printf("몇년 몇월의 임금을 측정하시겠습니까?(YYYY/MM)\n");
		scanf("%s", str1);
		printf("시간당 임금은 얼마인가요?(2017년 대한민국 최저임금 6470원)\n");
		scanf("%d", &MIN_MONEY);
		if (str1[0] == 48)
		{
			break;
		}
		year = str_to_int(str1, 0, 3);
		month = str_to_int(str1, 5, 6);
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
			if (i >= 0)
			{
				days[i].date = i + 1;//일

				days[i].start_time = -1;
				days[i].end_time = -1;
				days[i].yr = year;
				days[i].mon = month;
				days[i].doweek = (i + day) % 7;//일별 요일 입력
			}
		}
		//여기서부터 달력 출력
		while (1)
		{
			//----여기 days 초기화 해야함
			system("cls");
			printf("\n %d년/ %d월", year, month); // year년 month월 타이틀 출력 
			puts("(뒤로가기 ESC, 뒤로가면 임금 초기화)\n");
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
			printf("(2)월급계산\t");
			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 7);
			}
			if (select == 3)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(3)근무시간 확인\n");
			if (select == 3)
			{
				SetConsoleTextAttribute(hc, 7);
			}
			 print_calendar(day, totalday[month]);

			key = _getch();

			if (key == 224)
			{
				key = _getch();
				if (key == 75)
				{//left
					if(select>1)//counter 사용
						select --;
					Sleep(100);
				}
				else if (key == 77)
				{//right
					if(select<3)//counter 사용
						select ++;
					Sleep(100);
				}
			}
			else if (key == 13)
			{

				if (select == 1)
				{//날짜입력 받기
					system("cls");
					printf("근무한 날짜입력 (YYYY/MM/DD):");
					scanf("%s", str2);
					temp_year = str_to_int(str2, 0, 3);
					temp_month = str_to_int(str2, 5, 6);
					temp_day = str_to_int(str2, 8, 9);
					int start, end;
					//printf("%d", temp_day);
					for (i = 0; i < 31; i++)
					{
						if (days[i].date == temp_day&&days[i].yr == temp_year&&days[i].mon == temp_month)
						{
							printf("TIME :    ~    \n");
							gotoxy(8, 2);
							scanf("%d", &start);
							gotoxy(13, 2);
							scanf("%d", &end);
							days[i].start_time = start;
							days[i].end_time = end;
						}
					}
				}

				else if (select == 2)
				{//총임금 계산
					int over_money = 0;
					int weekend_money = 0;
					int night_money = 0;
					int base_money = 0;
					int work_time_today = 0;
					int work_time_tomorrow = 0;
					int work_time_total = 0;
					int work_time_sum = 0;
					system("cls");
					for (i = 0; i < 31; i++)
					{
						if (days[i].date != -1 && days[i].start_time != -1 && days[i].end_time != -1)
						{//유효한 날짜 를 찾기위해searching 사용
							if (days[i].end_time>days[i].start_time)
							{
								work_time_today = days[i].end_time - days[i].start_time;
								work_time_tomorrow = 0;
							}
							else
							{
								work_time_today = 24 - days[i].start_time;
								work_time_tomorrow = days[i].end_time;
							}
							work_time_total = work_time_today + work_time_tomorrow;
							work_time_sum += work_time_total;// total 사용
							if (work_time_total > 0)
							{//일 한날만 계산
								base_money += work_time_total*MIN_MONEY;
								if (work_time_total > 8)
								{//초과수당 계산을위해 searching 사용
									over_money += 0.5*(work_time_total - 8)*MIN_MONEY;
								}
								if (days[i].doweek == 5 && work_time_tomorrow > 0)
								{//금요일 수당
									weekend_money += 0.5*work_time_tomorrow*MIN_MONEY;
								}
								if (days[i].doweek == 6)
								{//토요일 수당
									weekend_money += 0.5*work_time_total*MIN_MONEY;
								}
								if (days[i].doweek == 0)
								{//일요일 수당
									weekend_money += 0.5*work_time_today*MIN_MONEY;
								}

								//야간수당
								int t_end_time = days[i].end_time;
								if (days[i].start_time > days[i].end_time)
								{
									t_end_time += 24;
								}
								for (int m = days[i].start_time; m < t_end_time; m++)
								{
									night_money += nights[m] * MIN_MONEY;
								}

							}
						}
					}//end for

					printf("     총 일한시간 :%10d시간\n", work_time_sum);
					printf("     기본 월급   :%10d원\n", base_money);
					printf("  초과 수당 합계 :%10d원\n", over_money);
					printf("  야간 수당 합계 :%10d원\n", night_money);
					printf("  휴일 수당 합계 :%10d원\n", weekend_money);
					printf("-------------------------------\n");
					printf("         총 월급 :%10d원\n", base_money + over_money + night_money + weekend_money);// total 사용
					printf("프로그램 종료 ESC, 계속하기 ENTER\n");
					key=_getch();
					if (key == 27)
					{//press esc
						return 0;
					}



				}//end select 2
				else if (select == 3)
				{//근무시간 확인
					system("cls");
					printf("%d년 %d월 근무시간 확인\n", year, month);
					int j = 1;
					for (i = 0; i < 31; i++)
					{
						if (days[i].date != -1 && days[i].start_time != -1 && days[i].end_time != -1)
						{
							printf("%d) %d/%2d/%2d %2d시 ~ %2d시\n", j, year, month, days[i].date, 
								days[i].start_time, days[i].end_time);
							j++;//counter 사용
						}
					}
					printf("Pres any key to continue...\n");
					_getch();
					
				}
			}//end enter

			else if (key==27)
			{//press esc
				break;
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
{//char array 입력을 위해 포인터 사용
	int result = 0;
	int ten = 1;
	for (int i = b; i >= a; i--)
	{
		result += (str1[i]-48) * ten;
		ten *= 10;
	}
	return result;
}