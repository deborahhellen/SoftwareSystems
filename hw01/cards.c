/* Modified card counting example from Head First C p. 37
refactored into four separate functions to improve code
readability and quality

functions: update_count()

Deborah Hellen 2014
*/

#include <stdio.h>
#include <stdlib.h>

/* Updates the current count given the value of the current card 
and the current count 
The count increases if the card value is between 2 and 7 and 
decreases if the value is 10
Otherwise it does not change
*/
void update_count(int *current_count, int card_val) 
{
	if ((card_val > 2) && (card_val <7)) {
		*current_count = *current_count + 1;
	} else if (card_val == 10 && *current_count > 0) {
		*current_count = *current_count - 1;
	}
	printf("Current count: %i\n", *current_count);
}

/*Checks if the given integer is a valid (number) card value 
between 1 and 10
*/
int is_valid_card(int val) {
	if ((val < 1) || (val > 10)) {
		puts("I don't understand that value!");
		return 0;
	}
	else {
		return 1;}
}

/*This is the honorary daniel function, which is run when
a bucket flipping joke occurs

It will be called when the user indicates that he/she 
wants to end the card counting game. 
*/
void daniel(bucket_flip_joke)
{
	if (bucket_flip_joke) {
		puts("THANK YOU BASED GOD");
	}
}

/*This is the main function which includes the main card value 
assignment and gameplay structure
*/
int main()
{
	char card_name[3];
	int count = 0;
	int you_flipped_the_bucket = 1;
	puts("Enter a card value 2,3,4,5,6,7,8,9,10,J,Q,K or A. Enter X to quit.");
	while (card_name[0] != 'X') {
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val = 0;
		switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				update_count(&count, val);
				break;
			case 'A':
				val = 11;
				update_count(&count, val);
				break;
			case 'X':
				daniel(you_flipped_the_bucket);
				continue;
			default:
				val = atoi(card_name);
				if (is_valid_card(val) != 0) {
					update_count(&count, val);
				} else {
					continue;}
		}
	}
	return 0;
}