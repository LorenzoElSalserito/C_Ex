#include <stdio.h>

char *scut_last_word(char s[]){
	if(s != NULL){
		char *c;
		
		//porto il puntatore in fondo all'array
		while(*c++ != '\0')
			c++;
			
		//elimino eventuali spazi bianchi in fondo alla linea
		c--;
		while (c != s-1 && *c == ' ')
			c--;
		
		if(c != (s-1) {
		    c--;
		    while(c != (s-1) && *c != ' ')
		        c--;
		        
		    if(c != (s-1)
				*c = '\0';
		    else
				*s = '\0';
			}
		}
		return s;
	}
	
int main (){
	char word[21];	
	printf("Inserisci una stringa\n");
	while(scanf("%s", word) != EOF){
		printf("%d\n", slength(word));
		}
	return 0;
	}
