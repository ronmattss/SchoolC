/*
Group 3
Names:
Rivera                   Activity: Basketball Menu
Pagulayan                Date: 1/21/19
BSCS 1-1
*/

//Headers used
#include<stdio.h>		// For standard C functions
#include<conio.h>		// For writing/reading to the console
#include<stdlib.h>		// For exit function
#include<dos.h>			// For delay function
#include<string.h>		// For memcpy to copy memory address of a given array


int T1[2][12]={0};		// Declaring the 2d array to a global variable so that it can be access easily
// function declarations
void InputScores();
void mvpteam();
void winner();
void Hpointer();
void SortAndSearch();
void DrawBox(int pdelay);
int BinarySearch(int _arrayToSearch[2][12], int target,int d);
void LinearSearch(int target,int d);

int main(void)
{
    clrscr();
	DrawBox(0);
    int choice;
    gotoxy(30,3);
    printf("BASKETBALL MENU");
    gotoxy(30,5);
    cprintf("(1) INPUT SCORES");
    gotoxy(30,6);
    cprintf("(2) MVP ON EACH TEAM");
    gotoxy(30,7);
    cprintf("(3) WINNING TEAM");
    gotoxy(30,8);
    cprintf("(4) HIGHEST POINTER");
    gotoxy(30,9);
    cprintf("(5) EXIT");
    gotoxy(30,12);
    cprintf("ENTER CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
	{
	    case 1:
		InputScores();
		break;
	    case 2:
		mvpteam();
		break;
	    case 3:
		winner();
		break;
	    case 4:
		Hpointer();
		break;
	    case 5:
		exit(0);
		break;
	    default:
		{
		    textcolor(RED);
		    cprintf("                              INVALID INPUT");
		    getch();
		    main();
		}
	}
return 0;

}

void InputScores()
{
int diff=0;
int team, player, score, temp1=0, temp2=0, mvp1=0, mvp2=0, T1score=0, T2score=0;
int invalid=0;
do
{
/* For gotoxyPrints: */
int z=4;
//TABLE
clrscr();
textcolor(WHITE);
gotoxy(15,1);cprintf("  Team:1                      Team:2\n");
gotoxy(14,3);cprintf("Player     Score          Player      Score\n");
for(int j=0;j<12;j++)
{
textcolor(BROWN);
	if(T1[0][j] == 0)
	{
		gotoxy(14,z);
		printf("%d\t\tNo Score\n",j+1);
	}
	else
	{
		gotoxy(14,z);
		printf("%d\t\t%d",j+1,T1[0][j]);
	}

	if(T1[1][j] == 0)
	{
		gotoxy(40,z);
		printf("%d\t   No Score\n",j+1);
	}
	else
	{
		gotoxy(40,z);
		printf("%d\t   %d\n",j+1,T1[1][j]);
	}
z++;
}
//INPUTS
textcolor(BLUE);
invalid=0;
	{
		gotoxy(10,17);
		cprintf("          Team 1 or 2?:");
		scanf("%d",&team);
	}
	{
		gotoxy(10,18);
		cprintf("                Player:");
		scanf("%d",&player);
	}
	{
		gotoxy(10,19);
		cprintf("                 Score:");
		scanf("%d",&score);
	}
		if(team<1||team>2)
			invalid=1;
		if(player<1||player>12)
			invalid=1;
		if(score<1||score>3)
			invalid=1;

	if(team==0&&player==0&&score==0)
	{
		textcolor(YELLOW);
		gotoxy(25,20);
		cprintf("TABULATION ENDED\n");
	}
	else if(invalid==0)
		T1[team-1][player-1]+= score;
	else
	{
		textcolor(RED);
		gotoxy(25,20);
		cprintf("Invalid Entry!\n");
	}

	{
		textcolor(GREEN);
		gotoxy(25,21);
		cprintf("Press Enter");
	}
getch();
}
while(!(team==0&&player==0&&score==0));
clrscr();
gotoxy(30,10);
printf("RETURNING TO MAIN MENU");
delay(1000);
gotoxy(30,12);
main();
}
void mvpteam()
{
	//Sorting the arrays
	// find the player/s that has the most points. per team
	clrscr();
	DrawBox(0);
	gotoxy(30,10);
	SortAndSearch();
	getch();

clrscr();
gotoxy(30,10);
printf("RETURNING TO MAIN MENU");
delay(1000);
gotoxy(30,12);
main();
}

void winner()
{
clrscr();
DrawBox(0);
int T1score=0, T2score=0, diff=0;
	textcolor(YELLOW);
	for(int i=0; i<12; i++)
	{
	    T1score+=T1[0][i];
	    T2score+=T1[1][i];
	}
    if (T1score==0&&T2score==0)
	{
		gotoxy(30,10);
		textcolor(RED);
		cprintf(" NO SCORE TABULATED");
	}
    else
	{

		if (T1score>T2score)
			{
				diff=T1score-T2score;
				gotoxy(20,10);
				cprintf("Team 1 Winner! Score:  %d By %d point/s! %d-%d",T1score,diff,T1score,T2score);
			}
		if (T1score<T2score)
			{
				int diff=T2score-T1score;
				gotoxy(20,10);
				cprintf("Team 2 Winner! Score:  %d By %d point/s! %d-%d",T2score,diff,T2score,T1score);
			}
		if (T1score==T2score)
			{
				gotoxy(20,10);
				cprintf("Both Teams Tied! %d - %d\n ",T1score,T2score);
			}
	}
textcolor(GREEN);
gotoxy(33,15);
printf("PRESS ENTER");
    getch();
clrscr();
gotoxy(30,10);
printf("RETURNING TO MAIN MENU");
delay(1000);
gotoxy(30,12);
main();
}
void Hpointer()
{
clrscr();
DrawBox(0);
textcolor(BROWN);
int temp1=0,temp2=0,mvp1=0,mvp2=0;
    for(int i=0;i<12;i++)
	       {
		   if(T1[0][i]>temp1)
			{
				temp1=T1[0][i];
				mvp1=i+1;
			}
		   if(T1[1][i]>temp2)
			{
				temp2=T1[1][i];
				mvp2=i+1;
			}
	       }
//MVP AND HIGHEST POINTER
	if(temp1!=temp2)
	{
	    if(temp1!=0)
		{
		    gotoxy(30,10);
		   // cprintf("MVP Team1: Player %d",mvp1);
		    if(temp1>temp2)
			{
			    gotoxy(30,13);
			    cprintf("Highest Pointer: Player %d of Team 1",mvp1);
			}
		}
	    else
		{
		    textcolor(RED);
		    gotoxy(30,10);
		//    cprintf("MVP Team1: NONE");
		}
	    if(temp2!=0)
		{
		    gotoxy(30,11);
		//    cprintf("MVP Team2: Player %d",mvp2);
		    if(temp2>temp1)
			{
			    gotoxy(20,13);
			    printf("Highest Pointer: Player %d of Team 2",mvp2);
			}
		}
	    else
		{
		    textcolor(RED);
		    gotoxy(30,11);
		 //   cprintf("MVP Team2: NONE");
		}
	}

    else if (temp1==0&&temp2==0)
	{
	    textcolor(RED);
	    gotoxy(30,10);
	    cprintf("NO SCORE TABULATED");
	}

    else if(temp1==temp2)
	{
	    gotoxy(30,11);
	    printf("Tied For Most Points:\n                   Player %d of Team 1 and Player %d of Team 2\n",mvp1,mvp2);
	}
textcolor(GREEN);
gotoxy(33,15);
printf("PRESS ENTER");
    getch();
clrscr();
gotoxy(30,10);
printf("RETURNING TO MAIN MENU");
delay(1000);
gotoxy(30,12);
main();
}



void SortAndSearch()
{

		int i, temp, j;		
		
		int tempArray[2][12] = {0};
		
		// copy the 2d Array T1 to tempArray so that it can be sorted
		memcpy(tempArray,T1,sizeof(tempArray));

	//placeHolder for the target values
	int target[2] = {0};
	// insertion Sort	
	for(int h = 0; h<2; h++){
		for (i = 1; i < 12; i++)
		{
			temp = tempArray[h][i];
			j = i - 1;
				while (j >= 0 && tempArray[h][j] > temp)
					{
						tempArray[h][j + 1] = tempArray[h][j];
						j = j - 1;
					}
			tempArray[h][j + 1] = temp;
		}
	}

	
	//set target[] to the highest points per team
	target[0] = tempArray[0][11];	
	target[1] = tempArray[1][11];
	
	if (target[0]!=0&&target[1]!=0)
		{
			//printf("Target 1: %d Target 2: %d \n",target[0],target[1]);
		}
	//getch();
	// Main Algo for Team MVP
	int highestPoint[2] = {0};
	int teamMvp[2] = {0};
    for(int w = 0; w<2;w++)
	{
		
	highestPoint[w] = BinarySearch(tempArray,target[w],w);
	}
	   for(int y = 0; y<2;y++)
	{
	LinearSearch(highestPoint[y],y);
	}



}



int BinarySearch(int _arrayToSearch[2][12], int target,int d)
{
	int arraySize = 12;
	int first = 0;
	int last = arraySize -1;
	int mid = (first +last) /2;
	int loct= 0;
	int found =0;
	int yCor = 1;


		while(first <= last)
	   {

					gotoxy(30,10+yCor);
					if(target> _arrayToSearch[d][mid])
						{
						///	printf("first: %d middle: %d last: %d \n",_arrayToSearch[d][first],_arrayToSearch[d][mid],_arrayToSearch[d][last]);
							first = mid +1;
							
						}
				    else if(_arrayToSearch[d][mid] == target)
				    {
					//printf(" Highest Pointer of Team %d: ", d+1, mid+1);
					// return the highest point
					//printf("first: %d middle: %d last: %d \n",_arrayToSearch[d][first],_arrayToSearch[d][mid],_arrayToSearch[d][last]);
					return _arrayToSearch[d][mid];
					}
					else
					{
					//	printf("first: %d middle: %d last: %d \n",_arrayToSearch[d][first],_arrayToSearch[d][mid],_arrayToSearch[d][last]);
						last = mid -1;
						
					}
					mid = (first + last)/2;
					yCor++;

	   }
	   if(first > last)
	   {
	   	printf("target not found!\n");
	   }

	
	return found;

	}

	
	void LinearSearch(int target,int d)
{
	// j = to the length of the array
	int j = 12;
	int looper= 0;
	
	if(target==0)
	{
		gotoxy(30,8);
		textcolor(RED);
		cprintf(" NO SCORE TABULATED");
	}
	else
	{
		for(int i = 0; i<j;i++)
		{	
			if (T1[d][i] == target)
			{
				gotoxy(20,17+i);
				printf(" MVP of Team %d is Player %d with %d Points!",d+1, i + 1,target);
			}
	
		}
	}

}

// Draws a box
void DrawBox(int pdelay)
{
	int lay =pdelay;
  int x = 0, y = 0;
   for(x = 3; x < 78 ;x++)
  {
   gotoxy(x,1);
   printf("*");
   delay(lay);
   gotoxy(x,25);
   delay(lay);
   printf("*");
  }
  for( y = 2; y< 25; y++)
  {
 textcolor(2);
   gotoxy(3,y);
  cprintf("°");
   gotoxy(77,y);
  cprintf("°");
  delay(lay);
  }
  delay(lay);

}


	


