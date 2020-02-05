#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define LIM 10000

void readin(char input[]);
void removecom(char input[],char fixed[]);
void display(char fixed[]);

int main ( int argc, char * argv[] ) {
  char input[LIM],
       fixed[LIM];
  readin(input);
  removecom(input, fixed);
  display(fixed);
   // Testing this
  return 0;
}

void readin(char input[]) {
  int i = 0, c = 0;
  while ((c = getchar()) != EOF){
        input[i] = c;
        ++i;
  }
  input[i] = '\0';
}

void removecom( char input[], char fixed[]) {
int n = 0,
    j = 0,
    test = FALSE;
while (input[n] != '\0') {
  if (input[n] == '/' && input[n + 1] == '*')
    test = TRUE;
  if (input[n] == '*' && input[n + 1] == '/') {
    test = FALSE;
    n = n + 2;
  }
  if (test)
    ++n;
  else {
    fixed[n] = input[j];
    ++n;
    ++j;
  }
  }
}

void display(char fixed[]) {
  printf("---------\n");
  int inc = 0;
  while (fixed[inc] != '\0') {
    putchar(fixed[inc]);
    ++inc;
}
}
