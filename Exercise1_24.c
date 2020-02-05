#define MAXIMUM 1000

#include <stdio.h>

int main(int argc, char * argv[]) {
  int c, i = 0, bracecount = 0, parenthesis = 0, quotes = 1, singlequotes = 1, brackets = 0;
  char input[MAXIMUM];

  while ((c = getline(input, MAXIMUM)) > 0) {
    while (i < c) {
        if (input[i] == '{')
          ++bracecount;
        if (input[i] == '}')
          --bracecount;
        if (input[i] == '[')
          ++brackets;
        if (input[i] == ']')
          --brackets;
        if (input[i] == '(')
          ++parenthesis;
        if (input[i] == ')')
          --parenthesis;
        if (input[i] == "'")
          singlequotes *= -1;
        if (input[i] == '"')
          quotes *= -1;
        i++;
    }
  }
  if (bracecount != 0 || parenthesis != 0 || quotes != 1 || singlequotes != 1 || brackets != 0)
    printf("There seems to be a problem with the syntax of this program.\n");
  else
    printf("The program seems to not have any syntax errors.\n");
  printf("Program complete\n");
}

int getline(void)
 {
   int c, i;
   extern char line[];
   for (i = 0; i < MAXIMUM - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
      line[i] = c;
   if (c == '\n') {
     line[i] = c;
     ++i;
   }
   line[i] = '\0';
   return i;
 }
