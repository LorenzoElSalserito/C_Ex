#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE 100

pid_t fork(void);
char** leggi_lista(FILE *file_in, int* nof_elements);
void stampa_lista(char** mio_ar, int n_elem);

int main(int argc, char const *argv[]){
	
	FILE *file_in;
	char *f_name = "prova.txt";
	char** char_ar;
	int num_elementi = 0;
	int status;
	
	file_in = fopen("prova.txt","w");
	
	pid_t pid;
  
	printf("Prima della fork. pid = %d, pid del genitore = %d\n", getpid(), getppid());
  
	pid = fork();
		if ( pid < 0 )
			perror("fork error"); // stampa la descrizione dell'errore
		else if (pid == 0) { // figlio
			printf("[Figlio] pid = %d, pid del genitore = %d\n", getpid(), getppid());
			printf("... Il figlio scrive nel file ...\n");
			fprintf(file_in, "Porca Pupazza!");
			fclose(file_in);
			exit(1);
		}
		else { // genitore
			printf("[Genitore] pid = %d, pid del mio genitore = %d\n", getpid(), getppid());
			printf("[Genitore] Mio figlio ha pid = %d\n",pid);
            wait(&status);
            file_in = fopen("prova.txt","r");
            char_ar = leggi_lista(file_in, &num_elementi);
            stampa_lista(char_ar, num_elementi);
            exit(1);
		}
  // entrambi i processi
  printf("PID %d termina.\n", getpid());
}
char** leggi_lista(FILE *file_in, int* nof_elements){
	char buf[SIZE];
	char** new_ar = NULL;
	int n_righe = 0;
	while(fgets(buf, SIZE, file_in)){
		++n_righe;
	}
	*nof_elements = n_righe;
	printf("sono presenti %d righe \n", n_righe);
	rewind(file_in);
	
	if((new_ar = malloc(sizeof(char*) * n_righe)) == NULL){
		fprintf(stderr, "errore durante l'allocazione dell'array\n");
		exit(1);
	}
	
	while(fgets(buf, SIZE, file_in)){
		int i = 0;
		new_ar[i++] = strdup(buf);
	}
	
	return new_ar;
}
void stampa_lista(char** mio_ar, int n_elem){
	printf("==============STAMPO==============\n");
	for(int i = 0; i < n_elem; i++){
		printf("%s", mio_ar[i]);
	} 
}
