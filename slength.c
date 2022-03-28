#include <stdio.h>

int slength (char s[]){
	int n = -1;
	char *sptr = s;
	
	if(s != NULL){
		n = 0;
		while (*sptr++ != '\0'){
			n++;
			}
		}
	return n;
	}

int main (){
	char word[21];	
	printf("Inserisci una stringa\n");
	while(scanf("%s", word) != EOF){
		printf("%d\n", slength(word));
		}
	return 0;
	}
