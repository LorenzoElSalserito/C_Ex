#include <stdio.h>

int isPrintable(char *c) {
  int result = - 1;
  if (c != NULL) result = (*c >= 32 && *c <= 126);
  return result;
}

void clearString(char *c) {
  if (c != NULL) {
    int i = 0;
    int found = 0;
    while (i++ < 80) {
      (found == 0) ? (found = !isPrintable(c)) : (*c = '\0');
      c++;
    }
  }
}

int main(int argc, char const *argv[]) {
  char s1[80];
  char s2[80];

  printf("\ninserisci la prima  stringa: ");
  fgets(s1, sizeof(s1), stdin);
  printf("inserisci la seconda stringa: ");
  fgets(s2, sizeof(s2), stdin);

  clearString(s1);
  clearString(s2);

  int found = -1;
  int index1 = 0;

  while (isPrintable(&s1[index1]) && found == -1 && index1 < 80) {
    int subIndex1 = index1;
    int subIndex2 = 0;

		while (s1[subIndex1] == s2[subIndex2] && found == -1 && subIndex1 < 80 && subIndex2 < 80) {
			subIndex1++;
			subIndex2++;
			if (!isPrintable(&s2[subIndex2])) found = index1 + subIndex2;
		}
    index1++;
  }

  printf("\n");
  if (found > 0) while (isPrintable(&s1[found])) printf("%c", s1[found++]);
  else printf("not found");
  printf("\n");

  return 0;
}
