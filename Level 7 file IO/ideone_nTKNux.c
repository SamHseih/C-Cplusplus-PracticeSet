#include <stdio.h>
#include <assert.h>
int main(void)
{
  FILE *fp;
  char string[128];
  fp = fopen("print-file-by-line.c", "r"); 
  assert(fp != NULL);
  while (fgets(string, 128, fp) != NULL)
    fputs(string, stdout);
  fclose(fp);
  return 0;
}
