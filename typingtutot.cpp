#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/*Variable declaration*/
int score = 0;
int missedCounter = 0;
int levelChoice = 0;
int wrongKeyCounter = 0;
int speedChoice = 0;
char startingIntroString[] = "\n\n\t\t\t\tGame Developed by Muhammad Huzaifa Tariq";
char startNewGameString[] = "\n\t\n\n\t\t\t\t\tStart New Game  \n\n\n\t\t\t\tSelect Game Level \n\n\t\t\t\t(1) Capital Alphabet Mode (A-Z)\n\t\t\t\t(2) Digits Mode (0-9)\n\n\t\t\t\tYour Choice is -------------->  ";
char selectLevelString[] = "\n\n\n\t\t\t\t\tSelect Speed Level\n\n\t\t\t\t(1) Speed Level One\n\t\t\t\t(2) Speed Level Two\n\n\t\t\t\tYour Choice is -------------->   ";
char helpString[] = "\n\t\t\tTyping Tutor\n\n\nThis game helps to improve your typing speed and sharpens your brain. Game has  three modes for the players. First is Begineers mode which is for basic typing,  next one is Learner mode which is designed for Medium typing speed and last one  is Expert Mode which is designed to sharpen your skills at their best\n\nSpeed Level 1 : 1 second time delay\nSpeed Level 2 : 500 milisecond time delay\nSpeed level 3 : 300 milisecond time delay\n\nGame consits of Capital Alphabets, Small Alphabets, and Numbers (0-9) which varies with different difficulty level\n\nThis game also consist of Score Card which displays your currant Score and also Consists of Missing Alphabets Counter displayed in the game.\n\n\t\t\tBackSpace to return to Main Menu.\n\n\t\t\t\tESC to Exit Game.\n";
int choice = 0;
int t = 100;
int  delayTime = 0;
int missedNum[100];

/*Node declaration*/
struct node
{
    int x;
    int data;
    int y;
    node *next;
} *first, *l, *temp;

/*Function prototypes*/
void gotoxy(int, int);
void InsertNode(int, int, int);
void deleteNode(int);
int searchInLinkList(int);

int randX();
void capitalAlphabet();
void digits();

void startingScreen();
void levelSelection();
void helpScreen();

void printChar();
void scorescreen();
void keyPressed();
void gameLost();
void winningScreen();

/*Functions*/
void gotoxy(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;

	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void InsertNode(int data, int x, int y )
{
	if(first == NULL)
	{
		first = new node();
		first->data = data;
    	first->x = x;
    	first->y = y;
		first->next = NULL;
		l = first;
    }
    else
	{
		while(l->next != NULL)
			l = l->next;

		temp = new node();
    	temp->data = data;
    	temp->x = x;
		temp->y = y;
    	temp->next = NULL;
    	l->next = temp;
    	l = temp;
   }
}

void deleteNode(int data)
{
    struct node *p;

	if(first==NULL)
        return;

	temp = first;
	p = temp;

	while(temp != NULL)
	{
		if(temp->data == data)
		{
			if(temp == first)
			{
				first = temp->next;
            	free(temp);
            	return;
	        }
	        else if(temp->next == NULL){
	    		p->next = NULL;
				l = p;
				free(temp);
			}
			else if(temp->next != NULL)
	        {
	            p->next = temp->next;
	            free(temp);
	            return;
	        }
		}
		p = temp;
		temp = temp->next;
	}
}

int searchInLinkList(int data)
{
	int search = 0;
	l = first;
	while(l)
	{
		if(l->data == data)
		{
			search = 1;
			return search;
		}
		l = l->next;
	}
	return search;
}

int randX()
{
	int x = 0 ;
	x = (rand() % 80) + 1;  /*x-axis is between 1-80*/
	return x;
}

void capitalAlphabet()
{
	int randNum = 0;
	randNum = 65 + (rand() % (int)(90 - 65 + 1));

	InsertNode(randNum, randX(), 0);
	printChar();
}

void digits()
{
	int randNum = 0;
	randNum = 48 + (rand() % (int)(57 - 48 + 1)); /*random number formula between 48-57 for (0-9)*/

	InsertNode(randNum,randX(),0);
	printChar();
}

void startingScreen()
{
	choice = 0;
	system("cls");
	for (int i=0; startingIntroString[i] != '\0'; i++)
	{
		printf("%c", startingIntroString[i]);
		Sleep(100);
	}

	Sleep(100);
	printf("\n\n\n\n\t\t\t\t\tTyping Tutor Game\n\n\n\t\t\t\t(1) To Start Game\n\t\t\t\t(2) To Help\n\t\t\t\t(3) Exit Game\n\n\t\t\t\tEnter your option -------> ");
	fflush(stdin);
	scanf("%d", &choice);

	if(choice == 1)
		levelSelection();
	else if(choice == 2)
		helpScreen();
	else if (choice == 3)
		exit(0);
	else
		startingScreen();
}

void levelSelection()
{
	system("cls");
	for (int i = 0; startNewGameString[i] != '\0'; i++)
	{
		printf("%c", startNewGameString[i]);
		Sleep(10);
	}
	fflush(stdin);
	scanf("%d", &levelChoice);

	system("cls");
	for (int j=0; selectLevelString[j] != '\0'; j++)
	{
		printf("%c", selectLevelString[j]);
		Sleep(10);
	}
	fflush(stdin);
	scanf("%d", &speedChoice);

	if (levelChoice >= 1 && levelChoice <= 3 && speedChoice >= 1 && speedChoice <= 2)
	{
		if (speedChoice == 1)
		{
			delayTime = 1000;
		}
		else if (speedChoice == 2)
		{
			delayTime = 500;
		}
		keyPressed();
	}
	else
	{
		levelSelection();
	}

}

void helpScreen()
{
	char k;
	int key;
	system("cls");

	for (int i = 0 ; helpString[i]; i++)
	{
		printf("%c",helpString[i]);
		Sleep(25);
	}
	do
	{
		k = getch();
		key = k;
		if(key == 8) /*backspace key ascii.*/
			startingScreen();
	} while(key != 27); /*escape key ascii.*/
}

void printChar()
{
	system("cls");

	struct node* c;
	c = first;

    if(c->next==NULL)
        return;
    else
        c=c->next;

	while(c->next)
	{
		gotoxy(c->x, c->y++);
		printf("%c", c->data);

		if(c->y <= 18)
			c = c->next;
		else
		{
			missedNum[missedCounter++] = c->data ;
			deleteNode(c->data);

			if(missedCounter + wrongKeyCounter >= 10)
		    {
				gameLost();
		        return;
		    }
			printChar();
		}
	}
	scorescreen();
}

void scorescreen()
{
    gotoxy(l->x, l->y++);
	printf("%c\n",l->data);

	gotoxy(1, 20);
	printf("______________________________________________________________________________");

	gotoxy(1, 22);
	printf("Score : %d", score);

	gotoxy(27, 22);
	printf("Time Left : %d ", t--);

	gotoxy(60, 22);
	printf("Digits Missed : %d", missedCounter);

	gotoxy(1, 24);
	printf("Characters Missed : ");

	for (int i = 0 ; i < missedCounter; i++)
		printf("%c ", missedNum[i]);

	gotoxy(60, 24);
	printf("Wrong Key Hits : %d", wrongKeyCounter);
}

void keyPressed()
{
	int key=0;
	do
	{
		while(!kbhit() && t > 0)
        {
            if (levelChoice == 1)
				capitalAlphabet();
			else if(levelChoice == 2)
				digits();
			Sleep(delayTime);
		}

		if(kbhit())
		{
			char k = toupper(getch());
			key = k;
			if(searchInLinkList(key) == 1)
			{
				score++;
				deleteNode(key);
			}
			else
			{
				wrongKeyCounter++;
				missedCounter++;
			}
		}
	} while(key != 27 && ((missedCounter + wrongKeyCounter) < 10) && t > 0); /*escape key.*/

	if(missedCounter + wrongKeyCounter >= 10)
		gameLost();
	if (t <= 0)
		winningScreen();
}

void gameLost()
{
	system("cls");

	Sleep(1000);
	printf("\n\n\t\t\t\t\tSummary");
	Sleep(1000);

	printf("\n\n\t\t\t\tYou Have Lost the Game");
	Sleep(1000);

	printf("\n\n\t\t\t\tScore : %d", score);
	Sleep(1000);

	printf("\n\n\t\t\t\tNumber of Wrong Keys Hit : %d", wrongKeyCounter);
	Sleep(1000);

	printf("\n\n\t\t\t\tNumber of Character Missed : %d", missedCounter);

	printf("\n\n\t\t\t\tCharacters Missed : ");

	for (int i = 0; i < missedCounter; i++)
	{
		printf("%c  ", missedNum[i]);
		Sleep(100);
	}

	Sleep(1000);
	printf("\n\n\t\t\t\t\tBetter Luck Next Time");
	Sleep(1000);
	printf("\n\n\t\t\t\tYou should try again to increase your score.");
	Sleep(1000);
	printf("\n\nYou will be redirected to Exit after 4 Second ........... Please Wait");
	Sleep(4000);

	exit(0);
}

void winningScreen()
{
	system("cls");

	Sleep(1000);
	printf("\n\t\t\t\t\tCongratulations :) ");

	Sleep(1000);
	printf("\n\n\t\t\t\t\tYou Have Won the Game !!!!");

	Sleep(1000);
	printf("\n\n\n\t\t\t\tYou scored : %d ", score);

	Sleep(1000);
	printf("\n\t\t\t\tNumber of Wrong key Hits : %d ", wrongKeyCounter);

	Sleep(1000);
	printf("\n\t\t\t\tNumber of Character Missed : %d ", missedCounter);

	Sleep(1000);
	printf("\n\n\t\t\t\tCharacters Missed : ");

	for (int i = 0; i< missedCounter ; i++)
	{
		printf("%c ",missedNum[i]);
		Sleep(100);
	}

	Sleep(1000);
	printf("\n\n\t\t\t\tTry Again to Increase your Score.");

	Sleep(1000);
	printf("\n\nYou will be redirected to Exit after 2 Seconds.");

	Sleep(2000);
	exit(0);
}

int main()
{
	system("cls");

	srand ( time(NULL) );
	startingScreen();
	//keyPressed();
	getch();
	return 0;
}
