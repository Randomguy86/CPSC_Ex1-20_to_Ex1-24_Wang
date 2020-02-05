#define TABSIZE 4
#define MAXIMUM 10

#include <stdio.h>

int main ( int argc, const char * argv[] )
{
  int c, i = 0, n = 0, j = 0, u = 0;
  char input[MAXIMUM];
  while ((c = getchar()) != EOF) {
    input[i] = c;
    if (c == '\t') {
      input[i] = ' ';
      for (++i; (i < MAXIMUM) && (i % TABSIZE != 0); ++i)
        input[i] = ' ';
      if (i < MAXIMUM)
        break;
      else
        i = 0;
    }
    else if (c == '\n')
      i = 0;
    for ( u = 0; u < i; ++i)
      putchar(input[u]);
    if ( i > 0 )
      putchar('\n');
    else if ( i >= MAXIMUM ) {
      for (; (i > 0) && input[i] != ' ';)
        --i;
      if (i == 0)
        i = MAXIMUM;
      else
        i = i + 1;
      for ( u = 0; u < i; ++i)
        putchar(input[u]);
      if ( i > 0 )
        putchar('\n');
      if ( i <= 0 || i >= MAXIMUM)
        i = 0;
      else {
        for ( j = i; j < MAXIMUM; ++j) {
          input[n] = input[j];
          ++n;
        }
      }
    }
  }
  return 0;
}
