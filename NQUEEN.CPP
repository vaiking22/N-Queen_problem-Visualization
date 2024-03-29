/* C/C++ program to solve N Queen Problem using
   backtracking */
#define N 8
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
//using namespace std ;
void draw_board()
{
	for(int i=0 ;i<=N; i++) //horizontal lines
	{
		line(0,i*50,N*50,i*50);
	}
	for( i=0 ; i<=N ;i++)
	{
		line(i*50,0,i*50,N*50);
	}
}
int getPos( int i)
{
	return (i*50 + (i+1)*50)/2;
}
void putQueens(int board[N][N])
{       clrscr();
	draw_board();
	for(int i = 0; i<N ;i++)
	{
		for(int j= 0 ;j<N ;j++)
		{//               cout<<board[i][j];
				if(board[j][i]==1){//delay(500);
				outtextxy(getPos(i),getPos(j),"Q");}

		}
      //		cout<<endl;
	}
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
	for (int j = 0; j < N; j++)
	    printf(" %d ", board[i][j]);
	printf("\n");
    }
}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
int isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
	if (board[row][i])
	    return 0;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
	if (board[i][j])
	    return 0;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
	if (board[i][j])
	    return 0;

    return 1;
}

/* A recursive utility function to solve N
   Queen problem */
int solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
      then return true */
      delay(1000);
     // clrscr();
     draw_board();
     putQueens(board);
    if (col >= N)
	return 1;

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++)
    {
	/* Check if queen can be placed on
	  board[i][col] */
	if ( isSafe(board, i, col) )
	{
	    /* Place this queen in board[i][col] */
	    board[i][col] = 1;
	    putQueens(board);
	   // outtextxy(getPos(col),getPos(i),"Q");
	    delay(100);
	    /* recur to place rest of the queen
	    s */
	    if ( solveNQUtil(board, col + 1) )
		return 1;

	    /* If placing queen in board[i][col]
	       doesn't lead to a solution, then
	       remove queen from board[i][col] */
	    board[i][col] = 0  ;
	    putQueens(board);
	   // outtextxy(getPos(col),getPos(i)," ");
	    delay(100); // BACKTRACK
	}
    }

     /* If queen can not be place in any row in
	this colum col  then return false */
   // clrscr();
    draw_board();
    putQueens(board);
    delay(500);
    return 0;
}

/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
int solveNQ()
{
    int board[N][N]   ;
    for(int i=0;i<N;i++)
    {
	for(int j=0;j<N;j++)
	{
		board[i][j]=0;
	 }

     }

    if ( solveNQUtil(board, 0) ==0 )
    {
      printf("Solution does not exist");
      return 0 ;
    }

    putQueens(board);
    return 1;
}

// driver program to test above function
int main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
       //	clrscr();
      //	draw_board();
	solveNQ();
	getch();
    return 0;
}
