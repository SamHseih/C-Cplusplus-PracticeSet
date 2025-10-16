#include <stdio.h>
#include <assert.h>
int main(void)
{
  FILE *fp1;
  FILE *fp2;
  int sum = 0;
  int i;
  int another_sum;
 
  fp1 = fopen("file1", "w");
  assert(fp1 != NULL);
  for (i = 0; i < 10; i++)
    fprintf(fp1, "%d\n", i);
  fclose(fp1);
 
  fp1 = fopen("file1", "r");
  assert(fp1 != NULL);
  while ((fscanf(fp1, "%d", &i)) != EOF)
    sum += i;
  fclose(fp1);
 
  fp2 = fopen("file2", "w");
  assert(fp2 != NULL);
  fprintf(fp2, "%d\n", sum);
  fclose(fp2);
 
  fp2 = fopen("file2", "r");
  assert(fp2 != NULL);
  fscanf(fp2, "%d", &another_sum);
  fprintf(stdout, "%d", another_sum);
  fclose(fp2);
 
  return 0;
}
