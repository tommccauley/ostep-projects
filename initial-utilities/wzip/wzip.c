#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

int i;
FILE *fp;
int count = 1; //always at least one letter 
char c;
char d;

if(argv[1] == NULL){
  printf("Please specify a file");
  exit(1);
}

for(i = 1; i<argc; i++){
  fp = fopen(argv[i], "r");

   if (fp == NULL){  //checking to see if the file is valid 
           printf("wzip: cannot open file.\n");
           exit(1);//error termination 
   }
  c = fgetc(fp);
  while (c != EOF){
	d = c;
        c = fgetc(fp);
  	if (d == c){
	   count++;
         
	}
	else{
	 fwrite(&count, sizeof(count), 1 , stdout);
	 fputc(d, stdout);
	 count = 1;

	}
}
  
fclose(fp);	      	
}

exit(0);

}
