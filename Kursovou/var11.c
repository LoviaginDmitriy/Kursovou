#include <stdio.h>
#define _USE_MATH_DEFINES 
#include<math.h>
#include<locale.h>

void PrintTeam(int team[25][4]); //Печать данных

void PrintRes(int team[25][4], int Perv, int Vtor, int Tret); //печать итогов

void SortBkm(int team[25][4]); //Сортировка от большего к меньшему

void SortMkb(int team[25][4]); // сортировка от меньшего к большему

void SaveRes(int team[25][4], int Perv, int Vtor, int Tret); //печать итогов в файл

//11. Хоккей: Таблица соревнований в которой приняли участие 25 команд, задана 2 -
//мерным массивом из 25 строк и 4 столбцов, в котором значения(количество
//забитых шайб, количество пропущенных шайб, количество штрафных минут,
//количество бросков по воротам) элементов заданы в файле данных.

void main()
{
	setlocale(LC_ALL, "RUS");

	int team[25][4] = { { 45,14,3,1 },
											{ 30,2,3,2 },
											{ 68,1,2,1 } ,
											{ 45,14,3,5 } ,
											{ 45,43,1,3} ,
											{ 30,14,3,1 } ,
											{ 45,14,0,0 } ,
											{ 2,67,7,0 } ,
											{ 45,14,3,1 },
											{ 70,4,3,4 } ,
											{ 45,14,0,1 } ,
											{ 25,5,3,1 } ,
											{ 45,14,0,3 } ,
											{ 12,6,3,4 },
											{ 60,7,3,1 },
											{ 42,14,3,5 },
											{ 32,5,3,1 },
											{ 43,14,0,0 },
											{ 34,23,3,2 },
											{ 23,14,3,2},
											{ 50,14,0,0 },
											{ 45,23,7,1 },
											{ 10,14,3,2 },
											{ 12,43,0,0 },
											{ 22,14,3,1 } };
	int Perv = 0, Vtor = 0, Tret = 0;

	puts("Добрый день.Что сделать с исходными данными?");

	for (int cicl = 0;cicl <= 2;cicl += 1) {
		for (int g = 0;g < 25;g++) {
			if ((team[g][0] * 3) >= Perv) {
				Vtor = Perv;
				Perv = team[g][0] * 3;
			}
			else if ((team[g][0] * 3) >= Vtor) {
				Tret = Vtor;
				Vtor = team[g][0] * 3;
			}
			else if ((team[g][0] * 3) >= Tret) Tret = team[g][0] * 3;
		}
		int Menu;
		printf("1)Исходная таблица\n2)Редактирование таблицы\n3)Итоговая таблица\n4)Поиск\n5)Сортировка\n6)Запись Итоговой таблицы\n7)Выход\n>");
		scanf("%d", &Menu);
		switch (Menu) {
		case 1:
		{
			PrintTeam(team);
			cicl = 0; break;
		}
		case 2:
		{
			printf("Изменить какую команду?\n>");
			int teamedit;
			scanf("%d", &teamedit);
			printf("Изменить (1)забитые шайбы (2) Пропущенные шайбы (3) Штрафные минуты (4)Шайбы в штраф.мин.\n>");
			int teamedit2;
			scanf("%d", &teamedit2);
			printf("На какое значение заменить?\n>");
			scanf("%d", &team[teamedit - 1][teamedit2 - 1]);
			printf("\n");
			cicl = 0; break;
		}
		case 3:
		{
			PrintRes(team, Perv, Vtor, Tret);

			cicl = 0; break;
		}
		case 4:
		{
			printf("Устроить поиск по:\n 1)Номер команды\n 2)Забитым шайбам\n");
			int nsII;
			scanf("%d", &nsII);
			switch (nsII)
			{
			case 1:
			{
				printf("Какой номер команды выдать?\n");
				int komd;
				scanf("%d", &komd);
				printf("---------------------------------------------------------------------\n");
				printf("|  № Команды   |Забит. Шайб|Пропущ. Шайб|Штраф. Мин.|Шайбы в Штр. М.|\n");
				printf("---------------------------------------------------------------------\n");
				printf("|  Команда №%-2d |    %3d    |    %3d     |   %3d     |       %2d      | \n", komd, team[komd - 1][0], team[komd - 1][1], team[komd - 1][2], team[komd - 1][3]);
				printf("---------------------------------------------------------------------\n\n");
				cicl = 0;
				break;
			}
			case 2:
			{
				printf("Искать команду со сколькью забитыми шайбами?\n");
				int shaib;
				scanf("%d", &shaib);
				printf("---------------------------------------------------------------------\n");
				printf("|  № Команды   |Забит. Шайб|Пропущ. Шайб|Штраф. Мин.|Шайбы в Штр. М.|\n");
				printf("---------------------------------------------------------------------\n");
				for (int i = 0;i < 25;i++)
				{
					if (shaib == team[i][0])
					{
						printf("|  Команда №%-2d |    %3d    |    %3d     |   %3d     |       %2d      | \n", i + 1, team[i][0], team[i][1], team[i][2], team[i][3]);
						printf("---------------------------------------------------------------------\n");
					}
				}
				printf("\n");
				cicl = 0;
				break;
			}
			default:
			{
				printf("ok\n");
				break;
			}
			}
			cicl = 0; break;
		}
		case 5:
		{
			printf("Сортировать по очкам от большего к меньшему(1) или от меньшего к большему(2)?\n");
			int filtr;
			scanf("%d", &filtr);
			switch (filtr)
			{
			case 1:
			{
				SortBkm(team);
				cicl = 0;break;
			}
			case 2: {
				SortMkb(team);
				cicl = 0;break;
			}
			}
			cicl = 0;break;
		}
		case 6: {
			SaveRes(team, Perv, Vtor, Tret);
			cicl = 0;break;
		}
		case 7:
		{
			printf("Конец программы");
			cicl = 3; break;
		}

		}
	}
}

// определение функций

void PrintTeam(int team[25][4])
{
	printf("---------------------------------------------------------------------\n");
	printf("|  № Команды   |Забит. Шайб|Пропущ. Шайб|Штраф. Мин.|Шайбы в Штр. М.|\n");
	for (int n = 0;n < 25;n++) {
		printf("---------------------------------------------------------------------\n");
		printf("|  Команда №%-2d |   %4d    |   %4d     |  %4d     |      %3d      | \n", n + 1, team[n][0], team[n][1], team[n][2], team[n][3]);
	}
	printf("---------------------------------------------------------------------\n\n");
	return 0;
}

void PrintRes(int team[25][4], int Perv, int Vtor, int Tret)
{
	printf("Очки = Каждая забитая шайба * 3 + забитая шайба в штрафные минутые * 2 - штрафные минуты - пропущенные шайбы\n\n");
	printf("----------------------------------------------------\n");
	printf("|Команда|Всего Бросков|Всего Забитых| Очки | Место |\n");
	printf("----------------------------------------------------\n");

	for (int n = 0;n < 25;n++)
	{
		printf("| %3d   |", n + 1);
		printf("    %3d      |", team[n][0] + team[n][1] + team[n][3]);
		printf("     %3d     |", team[n][0] + team[n][3]);
		printf("%  4d  |", team[n][0] * 3 + team[n][3] * 2 - team[n][1] - team[n][2]);

		if ((team[n][0] * 3) == Perv) printf("  1-ое |\n");
		else if ((team[n][0] * 3) == Vtor) printf("  2-ое |\n");
		else if ((team[n][0] * 3) == Tret) printf("  3-ье |\n");
		else printf("       |\n");

		printf("----------------------------------------------------\n");

	}
	return 0;
}

void SortBkm(int team[25][4])
{
	int teamcopy[25][5];
	for (int n = 0;n < 25;n++)
	{
		teamcopy[n][0] = n + 1;
		teamcopy[n][1] = team[n][0];
		teamcopy[n][2] = team[n][1];
		teamcopy[n][3] = team[n][2];
		teamcopy[n][4] = team[n][3];
	}
	for (int i = 0;i < 24;i++)
		for (int n = 0;n < 24;n++)
		{
			if (teamcopy[n][1] < teamcopy[n + 1][1])
			{
				for (int a = 0;a < 5;a++) {
					int TEMP;
					TEMP = teamcopy[n][a];
					teamcopy[n][a] = teamcopy[n + 1][a];
					teamcopy[n + 1][a] = TEMP;
				}
			}
		}
	printf("---------------------------------------------------------------------\n");
	printf("|  № Команды   |Забит. Шайб|Пропущ. Шайб|Штраф. Мин.|Шайбы в Штр. М.|\n");
	printf("---------------------------------------------------------------------\n");
	for (int n = 0;n < 25;n++) {
		printf("|  Команда №%-2d |    %3d    |    %3d     |   %3d     |       %2d      | \n", teamcopy[n][0], teamcopy[n][1], teamcopy[n][2], teamcopy[n][3], teamcopy[n][4]);
		printf("---------------------------------------------------------------------\n");
	}
	return 0;
}

void SortMkb(int team[25][4])
{
	int teamcopy[25][5];
	for (int n = 0;n < 25;n++)
	{
		teamcopy[n][0] = n + 1;
		teamcopy[n][1] = team[n][0];
		teamcopy[n][2] = team[n][1];
		teamcopy[n][3] = team[n][2];
		teamcopy[n][4] = team[n][3];
	}
	for (int i = 0;i < 24;i++)
		for (int n = 0;n < 24;n++)
		{
			if (teamcopy[n][1] < teamcopy[n + 1][1])
			{
				for (int a = 0;a > 5;a++) {
					int TEMP;
					TEMP = teamcopy[n][a];
					teamcopy[n][a] = teamcopy[n + 1][a];
					teamcopy[n + 1][a] = TEMP;
				}
			}
		}
	printf("---------------------------------------------------------------------\n");
	printf("|  № Команды   |Забит. Шайб|Пропущ. Шайб|Штраф. Мин.|Шайбы в Штр. М.|\n");
	printf("---------------------------------------------------------------------\n");
	for (int n = 0;n < 25;n++) {
		printf("|  Команда №%-2d |    %3d    |    %3d     |   %3d     |       %2d      | \n", teamcopy[n][0], teamcopy[n][1], teamcopy[n][2], teamcopy[n][3], teamcopy[n][4]);
		printf("---------------------------------------------------------------------\n");
	}
	return 0;
}

void SaveRes(int team[25][4], int Perv, int Vtor, int Tret)
{
	char fname[20] = "chart_result.txt";
	FILE* out;
	puts("\nСоздание файла\n");
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	fprintf(out, "----------------------------------------------------\n");
	fprintf(out, "|Команда|Всего Бросков|Всего Забитых| Очки | Место |\n");
	fprintf(out, "----------------------------------------------------\n");
	for (int n = 0;n < 25;n++)
	{
		fprintf(out, "| %3d   |", n + 1);
		fprintf(out, "    %3d      |", team[n][0] + team[n][1] + team[n][3]);
		fprintf(out, "     %3d     |", team[n][0] + team[n][3]);
		fprintf(out, "%  4d  |", team[n][0] * 3 + team[n][3] * 2 - team[n][1] - team[n][2]);

		if ((team[n][0] * 3) == Perv) fprintf(out, "  1-ое |\n");
		else if ((team[n][0] * 3) == Vtor) fprintf(out, "  2-ое |\n");
		else if ((team[n][0] * 3) == Tret) fprintf(out, "  3-ье |\n");
		else fprintf(out, "       |\n");

		fprintf(out, "----------------------------------------------------\n");
	}
	puts("Данные записаны по адресу C:\\Users\\User\\source\\repos\\Kursovoi\\Kursovoi\n");

	fclose(out);
}