/* This is a program developed to solve Reddit's r/dailyprogrammer challenge 362 which can be found at 
 * https://www.reddit.com/r/dailyprogrammer/comments/8n8tog/20180530_challenge_362_intermediate_route/ */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxStrLength 1024

void cwSpiral(char** grid, int topRow, int rightColumn, int bottomRow, int leftColumn);
void ccwSpiral(char** grid, int topRow, int rightColumn, int bottomRow, int leftColumn);
int travelDown(char **grid, int row, int column, int bottomRow);
int travelUp(char **grid, int row, int column, int topRow);
int travelRight(char **grid, int row, int column, int rightColumn);
int travelLeft(char **grid, int row, int column, int leftColumn);

int main(int argc, char **argv)
{
	char message[maxStrLength];
	char c;
	
	// Enter message
	int messageLength = 0;
	while(messageLength < maxStrLength && (c = getchar()) != '\n'){
		if ((c>='A' && c<='Z') || (c>='a' && c<='z')){
			message[messageLength]=toupper(c);
			messageLength+=1;
		}
	}
	message[messageLength]='\0';
	
	// Entering of grid
	int gridColumns, gridRows;
	scanf("(%d, %d)", &gridColumns, &gridRows);
	
	// Allocating memory to create grid
	char **grid=(char **) malloc(sizeof(char *)*gridRows);
	if (grid!=NULL){
		for (int i=0; i<gridRows; i++){
			grid[i]=(char *) malloc(sizeof(char)*gridColumns);
		}
	}
	else {
		printf("Error");
		return 1;
	}
	
	int messageLengthInGrid=0;
	for (int i=0; i<gridRows; i++){
		for (int j=0; j<gridColumns; j++){
			if (messageLengthInGrid < messageLength){
				grid[i][j]=toupper(message[messageLengthInGrid]);
				messageLengthInGrid++;
			}
			else
				grid[i][j]='X';
		}
	}
	
	// Determine direction for the route
	char direction[18];
	scanf("%s", direction);
	
	//Starting position at the top right of the grid
	int firstColumn=gridColumns-1, topRow=0;
	int lastColumn=0, bottomRow=gridRows-1;
	
	if (strcmp(direction, "clockwise")==0){
		cwSpiral(grid, topRow, firstColumn, bottomRow, lastColumn);
	}
	else if(strcmp(direction, "counter-clockwise")==0){
		ccwSpiral(grid, topRow, firstColumn, bottomRow, lastColumn);
	}
	printf("\n");
	
	
	// Freeing memory allocated
	for(int freeRows=0; freeRows<gridRows; freeRows++){
		free(grid[freeRows]);
	}
	free(grid);
	
	return 0;
}

void cwSpiral(char** grid, int topRow, int rightColumn, int bottomRow, int leftColumn){
	// Right and left column respectively refer to rightmost and leftmost columns in the cycle.
	int row=topRow, column=rightColumn;
	
	if (rightColumn > leftColumn && topRow < bottomRow){
		row=travelDown(grid, row, column, bottomRow);
		
		column=travelLeft(grid, row, column, leftColumn);
		
		row=travelUp(grid, row, column, topRow);
		
		column=travelRight(grid, row, column, rightColumn);
		
		cwSpiral(grid, topRow+1, rightColumn-1, bottomRow-1, leftColumn+1);
	}
	else if (topRow == bottomRow){
		while(column >= leftColumn){
			printf("%c", grid[row][column]);
			column--;
		}
	}
	else if(rightColumn == leftColumn){
		while(row <= bottomRow){
			printf("%c", grid[row][column]);
			row++;
		}
	}
}

void ccwSpiral(char** grid, int topRow, int rightColumn, int bottomRow, int leftColumn){
	// Right and left column respectively refer to rightmost and leftmost columns in the cycle.
	int row=topRow, column=rightColumn;
		if ((rightColumn > leftColumn) && (topRow < bottomRow)){
		
		column=travelLeft(grid, row, column, leftColumn);
		
		row=travelDown(grid, row, column, bottomRow);
		
		column=travelRight(grid, row, column, rightColumn);
		
		row=travelUp(grid, row, column, topRow);
		
		ccwSpiral(grid, topRow+1, rightColumn-1, bottomRow-1, leftColumn+1);
	}
	
	else if (topRow == bottomRow){
		while(column >= leftColumn){
			printf("%c", grid[row][column]);
			column--;
		}
	}
	
	else if(rightColumn == leftColumn){
		while(row <= bottomRow){
			printf("%c", grid[row][column]);
			row++;
		}
	}
}

int travelDown(char **grid, int row, int column, int bottomRow){
	while(row < bottomRow){
		printf("%c", grid[row][column]);
		row++;
	}
	return row;
}

int travelUp(char **grid, int row, int column, int topRow){
	while (row > topRow){
		printf("%c", grid[row][column]);
		row--;
	}
	return row;
}

int travelRight(char **grid, int row, int column, int rightColumn){
	while(column < rightColumn){
		printf("%c", grid[row][column]);
		column++;
	}
	return column;
}

int travelLeft(char **grid, int row, int column, int leftColumn){
	while(column > leftColumn){
		printf("%c", grid[row][column]);
		column--;
	}
	return column;
}
