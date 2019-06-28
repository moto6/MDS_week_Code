#include "myh.h"

int main(void) {
  char *cwd;
  char wd[BUFSIZ];

  cwd = getcwd(NULL, BUFSIZ);
  printf("1.current DIr : %s\n",cwd);

  chdir("hanbit");

  getcwd(wd, BUFSIZ);
  printf("2.Curr DIr : %s\n",wd);
  printf(" BUFSIZ : %d\n",BUFSIZ);
  return 0;

}

