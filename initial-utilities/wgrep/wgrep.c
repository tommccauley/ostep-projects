#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){

 char *buf = NULL;//the line gets copied into this string
 size_t bufsize;//buffersize for getline
 ssize_t linesize;//total amount of chars in the line 

 FILE *fp;
 char *key = argv[1];//keyword specified on the command line 
 int i;

 if (argv[1] == NULL){//error message for nothing on the command line 
   printf("Error: please specify an argument on the command line.\n");
   exit(1);
 }


 for(i = 2; i< argc; i++){//starts at i=2, where the file is located 
        fp = fopen(argv[i], "r");

        if (fp == NULL){//invalid file case
          printf("Cannot open file.");
          exit(1);
        }
        linesize = getline(&buf, &bufsize, fp);//gets line of the file 
        while (linesize >= 0){
          if (strstr(buf, key) != NULL){//will return the key if found in the line
                printf("%s", buf);
          }
          linesize = getline(&buf, &bufsize, fp);//gets next line

        }
        free(buf);//frees the buffer
        buf = NULL;
        fclose(fp);
 }
exit(0);//successful termination
}
