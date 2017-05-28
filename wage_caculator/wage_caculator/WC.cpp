

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //����������ũ�� 
#define MIN_MONEY 6470
struct day_wage
{
	int yr;//
	int mon;
	int start_time;//���۽ð�
	int end_time;//�����ð�
	int wage;
	int date;//�׳� ��¥
	int doweek;//����
};
int print_calendar(int day,int dow);
int str_to_int(char* str1, int a, int b);
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {

	int year, month; // ������ ���� ������ ���� 
	struct day_wage days[31];
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // �� ���� ���� �� (ù��° ���� ����)  
	int lastyear, day, i;
	int key, select;
	int temp_day, temp_year, temp_month,line_num;
	char str1[10] = "";
	char str2[15] = "";
	//�ʱ� ���ð� 1�μ���
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 7);
	system("cls");
	while (1)
	{
		select = 1;
		line_num = 0;
		system("cls");
		printf("��� ����� �ӱ��� �����Ͻðڽ��ϱ�?(YYYY/MM)\n");
		scanf("%s", str1);
		if (str1[0] == 48)
		{
			break;
		}
		year = str_to_int(str1, 0, 3);
		month = str_to_int(str1, 5, 6);
		//�޷� �����
		if (month == 2 && leapyear(year))// �ش�⵵�� �����̸�, 2���� �� 29�� 
		{
			totalday[2] = 29;
		}
		lastyear = year - 1; // �۳� ������ ����� ������ ����ϱ� ���� lastyear�� ���� 
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;
		/* lastyear : 1���� 365��, 1���� ���������� ������ �ѹ� �þ�� (365�� 7�� ������ 1�̱� ����)
		+(lastyear/4)-(lastyear/100)+(lastyear/400) : ������ ���������� ������ �ι� �þ�Ƿ�,
		lastyear���� �ִ� ��� ������ ���Ѵ� +1 : 1�� 1�� 1���� �Ͽ����� �ƴ϶� �������̹Ƿ� 1�� ���Ѵ� (0���� ����)
		%7 : ������ 7���� �̹Ƿ�, ���� ��갪�� 7�� ���� �������� year�� 1���� ù���� ���Ѵ� ���������� ����
		0:�Ͽ���, 1:������, 2:ȭ����, 3:������, 4:�����, 5:�ݿ���, 6:����� */
		for (i = 1; i < month; i++) // year�� month�� ���������� �� �� ���� ���ϱ� ���� for�� 
		{
			day += totalday[i];
			day %= 7; // year�� month�� 1���� ���� ���� 
		}
		for (i = -day; i < totalday[month]; i++)
		{
			if (i >= 0)
			{
				days[i].date = i + 1;//��

				days[i].start_time = -1;
				days[i].end_time = -1;
				days[i].yr = year;
				days[i].mon = month;
				days[i].doweek = (i + day) % 7;//�Ϻ� ���� �Է�
			}
		}
		//���⼭���� �޷� ���
		while (1)
		{
			//----���� days �ʱ�ȭ �ؾ���
			system("cls");
			printf("\n %d��/ %d��", year, month); // year�� month�� Ÿ��Ʋ ��� 
			puts("(�ڷΰ��� ESC, �ڷΰ��� �ӱ� �ʱ�ȭ)\n");
			if (select == 1)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(1)��¥��� \t ");
			if (select == 1)
			{
				SetConsoleTextAttribute(hc, 7);
			}

			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(2)���ް��\n");
			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 7);
			}
			
			line_num = print_calendar(day, totalday[month]);

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
				{//��¥�Է� �ޱ�
					printf("�ٹ��� ��¥�Է� (YYYY/MM/DD):");
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
							gotoxy(8, 9+ line_num);
							scanf("%d", &start);
							gotoxy(13, 9+ line_num);
							scanf("%d", &end);
							days[i].start_time = start;
							days[i].end_time = end;
						}
					}
				}

				else if (select == 2)
				{//���ӱ� ���
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
						{
							if (days[i].end_time>days[i].start_time)
							{//
								work_time_today = days[i].end_time - days[i].start_time;
								work_time_tomorrow = 0;
							}
							else
							{
								work_time_today = 24 - days[i].start_time;
								work_time_tomorrow = days[i].end_time;
							}
							work_time_total = work_time_today + work_time_tomorrow;
							work_time_sum += work_time_total;
							if (work_time_total > 0)
							{//�� �ѳ��� ���
								base_money += work_time_total*MIN_MONEY;
								if (work_time_total > 8)
								{//�ʰ�����
									over_money += 0.5*(work_time_total - 8)*MIN_MONEY;
								}
								if (days[i].doweek == 5 && work_time_tomorrow > 0)
								{//�ݿ��� ����
									weekend_money += 0.5*work_time_tomorrow*MIN_MONEY;
								}
								if (days[i].doweek == 6)
								{//����� ����
									weekend_money += 0.5*work_time_total*MIN_MONEY;
								}
								if (days[i].doweek == 0)
								{//�Ͽ��� ����
									weekend_money += 0.5*work_time_today*MIN_MONEY;
								}
								if (days[i].start_time <= 6 || days[i].start_time >= 22
									|| days[i].end_time <= 6 || days[i].end_time >= 22)
								{//�߰�����
									if (days[i].start_time <= 6 && days[i].end_time <= 6)
									{//s<6 e<6
										if (work_time_tomorrow == 0)
										{//�Ϸ�
											night_money += 0.5*work_time_today*MIN_MONEY;
										}
										else
										{//��Ʋ
											night_money += 0.5*(6 - work_time_today)*MIN_MONEY;
											night_money += 0.5*(work_time_tomorrow)*MIN_MONEY;
										}
									}
									else if (days[i].start_time <= 6 && days[i].end_time >= 22)
									{//s<6 e>22
										night_money += 0.5*(6 - days[i].start_time + 24 - days[i].end_time)*MIN_MONEY;
									}
									else if (days[i].start_time >= 22 && days[i].end_time <= 6)
									{//s>22 e<6
										night_money += 0.5*(24 - days[i].start_time + days[i].end_time)*MIN_MONEY;
									}
									else if (days[i].start_time >= 22 && days[i].end_time >= 22)
									{//s>22 e>>22
										if (work_time_tomorrow == 0)
										{//�Ϸ�
											night_money += 0.5*work_time_today*MIN_MONEY;
										}
										else
										{//��Ʋ
											night_money += 0.5*(work_time_today)*MIN_MONEY;
											night_money += 0.5*(24 - days[i].end_time)*MIN_MONEY;
										}

									}
								}
							}
						}
					}//end for

					printf("     �� ���ѽð� : %d\n", work_time_sum);
					printf("     �⺻ ����   : %d\n", base_money);
					printf("  �ʰ� ���� �հ� : %d\n", over_money);
					printf("  �߰� ���� �հ� : %d\n", night_money);
					printf("  ���� ���� �հ� : %d\n", weekend_money);
					printf("-------------------------------\n");
					printf("         �� ���� : %d\n", base_money + over_money + night_money + weekend_money);
					printf("���α׷� ���� ESC, ����ϱ� ENTER\n");
					key=_getch();
					if (key == 27)
					{//press esc
						return 0;
					}



				}
			}//end enter

			else if (key==27)
			{//press esc
				break;
			}

			//_getch();


			//�ӱ� �Է� ������


		}


	}

	return 0;
}
int print_calendar(int day, int dow)
{
	int line_count = 0;
	printf("\n  ��  ��  ȭ  ��  ��  ��  ��"); // ���� ����Ʈ ��� 
	for (int i = -day; i < dow; i++)
	{
		if ((i + day) % 7 == 0) // ��µ� ���ʰ� �Ͽ����̸�, ���� 
		{
			printf("\n");
			line_count++;
		}
		if (i < 0) // month�� 1���� ��µǱ� ������ ��¥�� �������� ä���. 
		{
			printf("    ");
		}
		else
		{
			printf("%4d", i + 1);
		}
	}
	printf("\n\n");
	return line_count;
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