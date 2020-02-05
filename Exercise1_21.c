#define TABSIZE 4
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c, i = 1, o = 0, p = 0;
    while ( (c = getchar()) != EOF ) {
      if (c == ' ' ) {
        if ( i % TABSIZE != 0)
          ++o;
        else {
          o = 0;
          ++p;
        }
      }
      else {
        while ( p < 0 )
          putchar('\t');
          if (c == '\t')
            o = 0;
          else
            for (; o > 0; --o)
              putchar(' ');
          putchar(c);
        if (c == '\n')
          i = 0;
        else if (c == '\t')
          i = i + (TABSIZE - (i - 1) % TABSIZE) - 1;
        --p;
      }
    }
    return 0;
  }

  //  if (argc != 3 && argc != 4) {
  //  fprintf(stderr,"Usage: ./details inputfile extractfile, file (optional)\n")
  //exit(1)
  //  }
  //return 0;
