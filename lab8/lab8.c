// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
#define NUMCOLS 100
#define NUMROWS 72

// Character definitions
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

// Maze array
char MAZE[NUMROWS][NUMCOLS];

// Function declarations
int close_to(double tolerance, double point, double value);
void generate_maze(int difficulty);
void draw_maze(void);
void draw_character(int x, int y, char use);
float calc_roll(float x_mag);

// main, use with ./ds4rd.exe -t -g -b
int main(int argc, char* argv[])
{
	if (argc <2) {
		printf("Input difficulty\n");
		return 1;
	}
	int difficulty = atoi(argv[1]);

	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze
	generate_maze(difficulty);
	draw_maze();

	// Read gyroscope data to get ready for using moving averages.    
	double gx, gy, gz;
	int t, button_T, button_C, button_S, button_X;

	int curx = NUMCOLS/2;
	int cury = 0;
	int nextx = curx;
	int win = -1;
	int failCount = 0;
	int nextT =1000;
	int first =1;
	int count = 0;
	
	do {
		if (first){
			draw_character(curx, cury, AVATAR);
			first = 0 ;
		}

		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &button_T, &button_C, &button_X, &button_S);

		if (gx > 0.25){
			nextx = curx+1;
		} else if (gx < -0.25){
			nextx = curx-1;
		} else {
			nextx = curx;
		}
		
		if (t % 10 == 0){
			if (cury+1 >= 71) {
				win = 1;
				break;
			}
			else if (MAZE[cury+1][nextx] == EMPTY_SPACE){
				draw_character(nextx, cury+1, AVATAR);
				draw_character(curx, cury, EMPTY_SPACE);
				curx = nextx;
				cury = cury+1;
				failCount =0;
			}
			else if(MAZE[cury+1][curx] == EMPTY_SPACE){
				draw_character(curx,cury+1, AVATAR);
				draw_character(curx,cury, EMPTY_SPACE);
				cury = cury+1;
				failCount=0;
			}
			else if (MAZE[cury][nextx] == EMPTY_SPACE){
				draw_character(nextx,cury, AVATAR);
				draw_character(curx,cury, WALL);
				curx = nextx;
				failCount=0;
			}
			else {
				failCount++;
				if (failCount > 5 || // lose if surrounded and cannot move or if fail 5 times
					(MAZE[cury + 1][curx] != EMPTY_SPACE && 
					MAZE[cury][nextx] != EMPTY_SPACE &&
					MAZE[cury + 1][nextx] != EMPTY_SPACE)) { 
					win = 0;  
					break;    
				}
		}

	} while(cury <= 71);
	
	if (win == -1){
		printf("ERROR. YOU DIDNT WIN OR LOSE\n");
	}
	else if (win == 1){
		printf("YOU WIN!!!!!!\n");
	}
	else {
		printf("YOU LOSE\n");
	}
	return 0;
}

// Draw the entire maze to the screen
void draw_maze(void){
	for (int row = 0; row < NUMROWS; row++) {
		for (int col = 0; col < NUMCOLS; col++) {
			draw_character(col, row, MAZE[row][col]);
		}
	}
	refresh();
}

// Generate a random maze based on difficulty
void generate_maze(int difficulty){
	for (int row = 0; row < NUMROWS; row++) {
		for (int col = 0; col < NUMCOLS; col++) {
			if (rand() % 100 < difficulty) {
				MAZE[row][col] = WALL;
			} else {
				MAZE[row][col] = EMPTY_SPACE;
			}
		}
	}
}

// Check if a value is close to a target point within a tolerance
int close_to(double tolerance, double point, double value){
	double upTol = tolerance + point;
	double downTol = point - tolerance;
	if ((value > downTol) && (value < upTol)){
		return 1;
	}
	else {
		return 0;
	}
}


float calc_roll(float x_mag) {
	return x_mag;
}

// Draw character at specific screen position given in lab instructions
void draw_character(int x, int y, char use)
{
	mvaddch(y, x, use);    
	refresh();
}
