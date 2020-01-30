#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

FILE *fp;
int i;
int j;
int count;
char c;

for (i=1; i< argc;i++){
  fp = fopen(argv[1],"r");
  if (fp == NULL){
	printf("Error opening file");
	exit(1);
  }
  while (1){
  	count = fread(stdout, 4 , 1, fp);
	printf("%d", count);
	c = fgetc(fp);

	if (feof(fp)){//checks for end of the file 
	   break;
	}
	for (j = 0; j<count; j++){
	   fputc(c, stdout);
	} 	
  }
  fclose(fp);

}
exit(0);


}
