#include <stdio.h>

int string_is_empty(char s[]){
	int res = -1;
	
	if(s != NULL){
		if(s[0] == '\0') res = 1;
		else res = 0;
	}
	
	return res;
}

int main(){

	return 0;
}
