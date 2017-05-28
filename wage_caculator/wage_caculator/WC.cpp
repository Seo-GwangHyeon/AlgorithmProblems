

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //����������ũ�� 

struct day_wage
{//����ü ���
	int yr;//
	int mon;
	int start_time;//���۽ð�
	int end_time;//�����ð�
	int wage;
	int date;//�׳� ��¥
	int doweek;//����
};
void print_calendar(int day,int dow);
int str_to_int(char* str1, int a, int b);
void gotoxy(int x, int y)//Ŀ����ġ �ٲٴ� �Լ�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {

	int year, month; // ������ ���� ������ ���� 
	struct day_wage days[31];//����ü �迭 ���
	int MIN_MONEY = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // �� ���� ���� �� (ù��° ���� ����)  
	int lastyear, day, i;
	int key, select;
	int temp_day, temp_year, temp_month;
	char str1[10] = "";
	char str2[15] = "";
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);//���ڻ� �ٲٱ� ���ؼ�
	SetConsoleTextAttribute(hc, 7);//���ڿ� ������ default�� �ٲ�
	system("cls");//���ΰ�ħ
	while (1)
	{
		select = 1;	//�ʱ� ���ð� 1�μ���
		key = 0;
		i = 0;
		MIN_MONEY = 0;
		for (i = 0; i < 31; i++)
		{
			days[i].start_time = -1;
			days[i].end_time = -1;
		}
		system("cls");
		printf("��� ����� �ӱ��� �����Ͻðڽ��ϱ�?(YYYY/MM)\n");
		scanf("%s", str1);
		printf("�ð��� �ӱ��� ���ΰ���?(2017�� ���ѹα� �����ӱ� 6470��)\n");
		scanf("%d", &MIN_MONEY);
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
			printf("(2)���ް��\t");
			if (select == 2)
			{
				SetConsoleTextAttribute(hc, 7);
			}
			if (select == 3)
			{
				SetConsoleTextAttribute(hc, 12);
			}
			printf("(3)�ٹ��ð� Ȯ��\n");
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
					if(select>1)//counter ���
						select --;
					Sleep(100);
				}
				else if (key == 77)
				{//right
					if(select<3)//counter ���
						select ++;
					Sleep(100);
				}
			}
			else if (key == 13)
			{

				if (select == 1)
				{//��¥�Է� �ޱ�
					system("cls");
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
						{//��ȿ�� ��¥ �� ã������searching ���
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
							work_time_sum += work_time_total;// total ���
							if (work_time_total > 0)
							{//�� �ѳ��� ���
								base_money += work_time_total*MIN_MONEY;
								if (work_time_total > 8)
								{//�ʰ����� ��������� searching ���
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
									else
									{
										if (days[i].start_time <= 6&& days[i].end_time<22)
										{
											night_money += 0.5*(6 - days[i].start_time)*MIN_MONEY;
										}
										else if (days[i].start_time > 6 && days[i].end_time>=22)
										{
											night_money += 0.5*(2-(24- days[i].end_time))*MIN_MONEY;
										}
									}
								}
							}
						}
					}//end for

					printf("     �� ���ѽð� :%10d�ð�\n", work_time_sum);
					printf("     �⺻ ����   :%10d��\n", base_money);
					printf("  �ʰ� ���� �հ� :%10d��\n", over_money);
					printf("  �߰� ���� �հ� :%10d��\n", night_money);
					printf("  ���� ���� �հ� :%10d��\n", weekend_money);
					printf("-------------------------------\n");
					printf("         �� ���� :%10d��\n", base_money + over_money + night_money + weekend_money);// total ���
					printf("���α׷� ���� ESC, ����ϱ� ENTER\n");
					key=_getch();
					if (key == 27)
					{//press esc
						return 0;
					}



				}//end select 2
				else if (select == 3)
				{//�ٹ��ð� Ȯ��
					system("cls");
					printf("%d�� %d�� �ٹ��ð� Ȯ��\n", year, month);
					int j = 1;
					for (i = 0; i < 31; i++)
					{
						if (days[i].date != -1 && days[i].start_time != -1 && days[i].end_time != -1)
						{
							printf("%d) %d/%2d/%2d %2d�� ~ %2d��\n", j, year, month, days[i].date, 
								days[i].start_time, days[i].end_time);
							j++;//counter ���
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


			//�ӱ� �Է� ������


		}


	}

	return 0;
}
void print_calendar(int day, int dow)
{
	printf("\n  ��  ��  ȭ  ��  ��  ��  ��"); // ���� ����Ʈ ��� 
	for (int i = -day; i < dow; i++)
	{
		if ((i + day) % 7 == 0) // ��µ� ���ʰ� �Ͽ����̸�, ���� 
		{
			printf("\n");
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
}
int str_to_int(char* str1, int a, int b)
{//char array �Է��� ���� ������ ���
	int result = 0;
	int ten = 1;
	for (int i = b; i >= a; i--)
	{
		result += (str1[i]-48) * ten;
		ten *= 10;
	}
	return result;
}