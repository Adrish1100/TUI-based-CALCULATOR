#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//system independent clears
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

#define FALSE 0
#define TRUE 1

#define gotoxy(x, y) printf("\033[%d;%dH", y, x)

void start();
int menu();
void result(float num1, float num2, float x, int choice);
int end();

enum op
{
	ADD = 1,
	SUB = 2,
	MULTI = 3,
	DIV = 4,
	SQR = 5,
	SROOT = 6,
	CUBE = 7,
	CROOT = 8,
	GPOW = 9,
	CLOG = 10,
	NLOG = 11,
	BLOG = 12
};

int main()
{
	start();

	float num1, num2, x;
	int choice, endout;

	do
	{
		num1 = 0, num2 = 0, x = 0;

		CLEAR;

		choice = menu();

		//decides whether to input two numbers or only one
		if (choice < SQR)
		{
			printf("\n\n\tENTER FIRST NUMBER: ");
			if (scanf("%f", &num1) != 1)
				exit(1);
			fflush(stdout);
			printf("\n\tENTER SECOND NUMBER: ");
			if (scanf("%f", &num2) != 1)
				exit(1);
			fflush(stdout);
		}
		else if (choice >= SQR && choice <= BLOG)
		{
			printf("\tENTER A NUMBER: ");
			if (scanf("%f", &x) != 1)
				exit(1);
		}

		result(num1, num2, x, choice);

		printf("\n\n\tPRESS ENTER TO CONTINUE: ");
		getchar();

		CLEAR;

		endout = end();

	} while (endout == TRUE);
}

void start()
{
	gotoxy(15, 7); //moves the cursor to a specified position
	printf("***********************************");
	gotoxy(15, 8);
	printf("*\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n\t      *\t\t\t\t\t*\n");
	gotoxy(21, 10);
	printf("WELCOME TO MY CALCULATOR\n        \t\tmade by Adrish Datta\n       \t \tPRESS ENTER TO CONTINUE: ");
	gotoxy(15, 15);
	printf("***********************************");
	gotoxy(30, 13);
	while (!(getchar() == '\n'))
		;
	sleep(1);
	CLEAR;
}

int menu()
{
	CLEAR;
	int choice, tryagain = TRUE;
	char input[100];
	gotoxy(10, 0);
	printf("■ NOTE:- THE PROGRAM EXITS ON UNDEFINED ALPHABETICAL INPUTS!");
	gotoxy(10, 10);
	printf("□□□□□□□□□□□□□□□□□□CALCULATOR□□□□□□□□□□□□□□□□□□\n");
	gotoxy(10, 12);
	printf("\n\t 1) ADDITION\n\t 2) SUBTRACT\n\t 3) MULTIPLY\n\t 4) DIVIDE\n\t 5) SQUARE\n\t 6) SQUARE ROOT\n\t 7) CUBE\n\t 8) CUBE ROOT\n\t 9) GENERAL POWER\n\t10) COMMON LOG\n\t11) NATURAL LOG\n\t12) BINARY LOG\n\n");

	// error handling and edge case checking
	while (tryagain == TRUE)
	{
		printf("\tEnter your choice: ");
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d", &choice) != 1 || choice < ADD || choice > BLOG)
		{
			tryagain = TRUE;
			printf("\n\tInvalid choice! Please enter 1-12 only.\n");
		}
		else
			tryagain = FALSE;
	}
	return choice;
}

void result(float num1, float num2, float x, int choice)
{
	float ans, y;
	switch (choice)
	{
	case ADD:
		ans = (num1 + num2);
		printf("\tTHE SUM OF %g AND %g IS %g", num1, num2, ans);
		break;
	case SUB:
		ans = (num1 - num2);
		printf("\tTHE DIFFERENCE OF %g AND %g IS %g:", num1, num2, ans);
		break;
	case MULTI:
		ans = (num1 * num2);
		printf("\tTHE PRODUCT OF %g AND %g IS %g", num1, num2, ans);
		break;
	case DIV:
		if (num2 == 0)
		{
			printf("\n\tSYNTAX ERROR!!\n\tCan't divide %g by %g", num1, num2);
			break;
		}
		ans = (num1 / num2);
		double rem = fmod(num1, num2);
		printf("\n\tTHE QUOTIENT OF %g / %g IS %g", num1, num2, ans);
		printf("\n\tTHE REMAINDER OF %g / %g IS %g", num1, num2, rem);
		break;
	case SQR:
		ans = pow(x, 2);
		printf("\tTHE SQUARE OF %g IS %g", x, ans);
		break;
	case SROOT:
		if (x < 0)
		{
			printf("\n\tMATH ERROR!!");
			break;
		}
		ans = sqrt(x);
		printf("\tTHE SQUARE ROOT OF %g IS %g:", x, ans);
		break;
	case CUBE:
		ans = pow(x, 3);
		printf("\tTHE CUBE OF %g IS %g", x, ans);
		break;
	case CROOT:
		ans = cbrt(x);
		printf("\n\tTHE CUBE ROOT OF %g IS %g", x, ans);
		break;
	case GPOW:
		printf("\n\tENTER THE EXPONENT: ");
		scanf("%f", &y);
		ans = pow(x, y);
		if (y == 1)
			printf("\tTHE %gST POWEROF %g IS %g:", y, x, ans);
		else if (y == 2)
			printf("\tTHE %gND POWEROF %g IS %g:", y, x, ans);
		else if (y == 3)
			printf("\tTHE %gRD POWEROF %g IS %g:", y, x, ans);
		else
			printf("\tTHE %gTH POWEROF %g IS %g:", y, x, ans);
		break;
	case CLOG:
		if (x <= 0)
		{
			printf("\n\tMATH ERROR!!");
			break;
		}
		ans = log10(x);
		printf("\tTHE COMMON LOG OF %g IS %g", x, ans);
		break;
	case NLOG:
		if (x <= 0)
		{
			printf("\n\tMATH ERROR!!");
			break;
		}
		ans = log(x);
		printf("\tTHE NATURAL LOG OF %g IS %g:", x, ans);
		break;
	case BLOG:
		if (x <= 0)
		{
			printf("\n\tMATH ERROR!!");
			break;
		}
		ans = log2(x);
		printf("\tTHE BINARY LOG OF %g IS %g:", x, ans);
		break;
	}
	getchar();
}

int end()
{
	int tryinput = 0, tryagain = TRUE, trymain = TRUE;
	char input[100];

	while (trymain == TRUE)
	{
		gotoxy(15, 7); //moves the cursor to a specified position
		printf("***********************************************\n");
		gotoxy(15, 8);
		printf("*                                             *\n");
		gotoxy(15, 9);
		printf("*                                             *\n");
		gotoxy(15, 10);
		printf("*                                             *\n");
		gotoxy(15, 11);
		printf("*                                             *\n");
		gotoxy(15, 12);
		printf("*                                             *\n");
		gotoxy(15, 13);
		printf("*                                             *\n");
		gotoxy(15, 14);
		printf("*                                             *\n");
		gotoxy(15, 15);
		printf("*                                             *\n");
		gotoxy(15, 16);
		printf("*                                             *\n");
		gotoxy(15, 17);
		printf("*                                             *\n");
		gotoxy(15, 18);
		printf("***********************************************\n");

		gotoxy(17, 10);
		printf("WOULD YOU LIKE TO CONTINUE OUR SERVICES ?\n\t\t\t\t1 -> YES\n\t\t\t\t2 -> NO");
		gotoxy(20, 14);
		printf("ENTER YOUR CHOICE (1/2): \033[K");
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d", &tryinput) != 1 || tryinput <= 0 || tryinput > 2)
		{
			tryagain = TRUE;
			gotoxy(20, 15);
			printf("INVALID CHOICE!! PLEASE ENTER 1-2 ONLY\n");
			sleep(1);
			gotoxy(19, 15);
			printf("\033[K");
			trymain = TRUE;
		}
		else if (!(tryinput == 1))
		{
			tryagain = FALSE;
			trymain = FALSE;
		}
		else
		{
			tryagain = TRUE;
			trymain = FALSE;
		}
		sleep(1);
		gotoxy(43, 14);
		printf("     ");
	}
	return tryagain;
}
//---------------------------------------------------------------------------------------