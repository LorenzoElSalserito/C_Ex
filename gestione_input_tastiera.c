#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* parse_nome(char* stringa_completa){
	char* my_name = malloc (strlen(stringa_completa)+1);
	char *ptr = my_name;
	
	while(*stringa_completa != ' '){
		*ptr = *stringa_completa;
		ptr++;
		stringa_completa++;
	}
	return my_name;
}

int main(int argc, char const *argv[]) {
	char s [101];
	char *nome;
	printf("Dammi nome e cognome: \n");
	fgets (s , sizeof (s), stdin);
	nome = parse_nome(s);
	printf("il nome è: %s\n", nome);
}
