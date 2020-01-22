#include <stdio.h>
#include <stdlib.h> //for exit codes

int main(int argc, char **argv){

FILE *fp;
int i; //for incrementing 
char c;


for(i=1;i < argc; i++){  //for loop using argc in case multiple files are on the command line
	fp = fopen(argv[i], "r");

	if (fp == NULL){  //checking to see if the file is valid 
		printf("wcat: cannot open file.\n");
		exit(1);//error termination
}
	c = fgetc(fp); //this method reads by individual chars. it is terminated with EOF
	while(c != EOF){
		printf("%c", c);//prints file by each char 
		c = fgetc(fp);//reads the next char on the file
}
	fclose(fp);
} 
exit(0);	//successful termination
}

 
