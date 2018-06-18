/* This is a program developed to solve Reddit's r/dailyprogrammer challenge 364 Easy which can be found at 
 * https://www.reddit.com/r/dailyprogrammer/comments/8s0cy1/20180618_challenge_364_easy_create_a_dice_roller/ 
 * The goal is to develop a problem that takes in an input of the form <integer>'d'<integer> and generates a dice roll
 * based on the two integers*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diceRoll(int dice, int sides){
	int total = 0; // Total of the roll
	int rolls[dice]; //Array to keep track of each roll
	for (int i=0; i<dice; i++){
		rolls[i] = rand()%sides+1;
		total += rolls[i];
	}
	
	printf("%d:", total);
	for(int i=0; i<dice; i++){
		printf(" %d", rolls[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int dice, sides;
	srand(time(NULL)); 
	/* Making the program more random by seeding the time as just rand() will result in the same outputs if same inputs are 
	 * given each time the program is run*/
	while(scanf("%dd%d", &dice, &sides) == 2){
		diceRoll(dice, sides);
	}
	return 0;
}
