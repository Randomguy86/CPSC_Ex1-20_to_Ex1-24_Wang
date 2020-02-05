#include <stdio.h>

#define TAB 4

int main(int argc, const char * argv[])
{
    int c, i = 0, tabs;
    while((c = getchar())!= EOF) {
		    if(c == '\n') {
            putchar(c);
            i = 0;
        }
		    else if (c == '\t') {
			       tabs = TAB - i % TAB;
			       while(tabs != 0) {
				           putchar(' ');
				           i++;
                   --tabs;
			       }
		    }
		    else {
			       putchar(c);
			       i++;
		    }
    }
  return 0;
}
