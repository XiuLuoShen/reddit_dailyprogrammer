/* This program is used to solve the problem posted at https://www.reddit.com/r/dailyprogrammer/comments/8jcffg/20180514_challenge_361_easy_tally_program/
 * [2018-05-14] Challenge #361 [Easy] Tally Program */
 

#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	char input[1024];
	int players[26]={0}; // Used to keep track of players and rankings. 
	int numberOfPlayers = 0; 
	int score[26]={0};
	
	int entry=0;;
	fgets(input, sizeof(input), stdin); //Input
	
	
	while (isalpha(input[entry])){
		int player=(tolower(input[entry])-'a');
		
		//Registering players
		if (players[player]==0){
			players[player]=player+1; //Players are numbered from 1.
			numberOfPlayers++;
		}
		
		// Tallying scores
		if (islower(input[entry]))
			score[player]++;
		else
			score[player]--;
		
		entry++;
	}
	
	//Bubble sort the players from highest score to lowest. Array index is the rank of player X.
	for (int i=numberOfPlayers; i>0; i--){
		for (int j=0; j<(i-1); j++){
			if (score[j]<score[j+1]){
				int temp = players[j];
				players[j]=players[j+1];
				players[j+1]=temp;
				
				temp = score[j];
				score[j]=score[j+1];
				score[j+1]=temp;
				
			}
		}
	}
	
	//Printing the output
	for (int i=0; i<numberOfPlayers-1; i++){
		printf("%c:%d, ", players[i]+'a'-1, score[i]);
	}
	
	printf("%c:%d\n", players[numberOfPlayers-1]+'a'-1, score[numberOfPlayers]);
	return 0;
}
