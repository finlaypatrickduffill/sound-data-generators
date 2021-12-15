#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.142

FILE *fp_in;
char *wav_data;
int c, parse;
char filename_in[20], filename_out[20];

int main()
{
	printf("name of input file 1: \n");
	gets(filename_in);
	printf("name of output file: \n");
	gets(filename_out);
	
	fp_in = fopen(filename_in, "rb");
	fseek(fp_in, 0, SEEK_END);
	int filelen = ftell(fp_in);
	printf("\nfile length: %d\n", filelen);
	realloc(wav_data,filelen + 1);
	wav_data = malloc(filelen + 1);
	rewind(fp_in);
	
	 while (1) 
  {
    c = fgetc(fp_in);
    if (feof(fp_in)) {
      break;
      }
	switch (c) {
	default:
    wav_data[parse] = c;
	break;
	  
  }
  parse++;
  }

	printf("file length at end:-> %d \n	",parse);
	
	FILE *fp;

	fp = fopen( filename_out , "w" );
	fwrite(wav_data , 1 , parse , fp );
	
	pclose(fp_in);
	
	int freq,fs,amplitude,cycle,sampleint;
	double angle,increment,sample;
 
	fclose(fp);
  
    return(0);
}