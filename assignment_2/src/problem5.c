#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 26

// since a = 3, from extended euclidean algorithm, we could get that a inverse is 9
// so we could try b from 0 to 25, to see the 26 possibilities.
int main(void) {	
	char* cipher_text = "tcabtiqmfheqqmrmvmtmaq";
	
	int len = strlen(cipher_text);
	// int char_to_num[len];
	int i, j;
	int a_inverse = 9;
	/*
	for (i = 0; i < len; i++) {
		char_to_num[i] = *(cipher_text + i) - 'a';
	}
	*/
	for (i = 0; i < NUM; i++) {
		printf("The %d possibility is: \n", i);
		for (j = 0; j < len; j++) {
			printf("%c", (((*(cipher_text + j) - 97 - i + NUM) * a_inverse) % NUM) + 97);	
		}
		printf("\n");
	}
	return 0;
}
