#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 26

int main(void) {
	char* cipher_text = "BEEAKFYDJXUQYHYJIQRYHTYJIQFBQDUYJIIKFUHCQD";
	
	int len = strlen(cipher_text);	
	int i, j;
	// assume only shift to the right
	for (i = 0; i < 26; i++) {
		printf("The %d possible plaintext: \n", i);
		for (j = 0; j < len; j++) {
			printf("%c", (*(cipher_text + j) - 65 + i) % NUM + 65);
		}
		printf("\n");

	}
	return 0;
}
