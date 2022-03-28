#include <stdio.h>
#define is_whitespace(c) ( (c)==' ' || (c)=='\t' || (c)=='\r' || (c)=='\n' )

int slength(char s[]){
    int r=-1;
    if (s!=NULL){
        r=0;
        while (*s++!='\0')
           r++;
    }
    return r;
}

int string_is_empty(char s[]){
   return s!=NULL ? *s=='\0' : -1 ;
}

char *scut_last_word(char s[]){

  
  char * s1 = NULL;
  if(s != NULL){
    s1 = s;
    
    while(*s1 != '\0')
      s1++;
      
    s1--;
    
    while((s1>=s) && !isWhiteSpace(*(s1)))
      s1--;
        
    *s1 = '\0';  
  
  }
  
  return s;
}

int string_is_palindrome(char s[]){
   // cond: s!=NULL
   char *e=s+slength(s)-1;
  
   while ( s<e && *s==*e ){
         s++;
         e--;
   }

   return s>=e;
}

int string_how_many(char c, char s[]){
   int cnt=0;
   if (s!=NULL){
      char e;
      while ((e=*s++)!='\0')
         if (e==c)
            cnt++;
   }
   return cnt;
}


void string_wipe_whitespaces(char s[]){
}

int string_compare(char s1[], char s2[]){
   char c1, c2;
   
   do{   
      c1=*s1++;
      c2=*s2++;
   }while ( c1==c2 && c1!='\0' && c2!='\0' );
   // in questo punto vale: c1 è diverso da c2 oppure, c1 o c2 sono caratteri di fine stringa
   
   return c1==c2 ? 0 : ( c1<c2 ? 1 : -1 );
}
