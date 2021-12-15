#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.142

FILE *fp_in;
FILE *fp_in2;
char *wav_data, *wav_data2;
int c, parse, parse2;
char filename_in1[20], filename_in2[20], filename_out[20];
int datachunkscanner, in_data_chunk;

int main()
{
	
	datachunkscanner = 0;
	in_data_chunk = 0;
	
	printf("name of input file 1: \n");
	gets(filename_in1);
	printf("name of input file 2: \n");
	gets(filename_in2);
	printf("name of output file: \n");
	gets(filename_out);
	
	fp_in = fopen(filename_in1, "rb");
	fseek(fp_in, 0, SEEK_END);
	int filelen = ftell(fp_in);
	printf("\nfile length of input file 1: %d\n", filelen);
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
	
	fp_in2 = fopen(filename_in2, "rb");
	fseek(fp_in2, 0, SEEK_END);
	int filelen2 = ftell(fp_in2);
	printf("\nfile length of input file 2: %d\n", filelen2);
	realloc(wav_data2,filelen2 + 1);
	wav_data2 = malloc(filelen2 + 1);
	rewind(fp_in2);
	
	 while (1) 
  {
	 if (datachunkscanner >= 4)
	 {
		 in_data_chunk = 1;
	 }
    c = fgetc(fp_in2);
    if (feof(fp_in2)) {
      break;
      }
	switch (c) {
		
	case 'd':
	datachunkscanner++;
	break;
	case 'a':
	datachunkscanner++;
	break;
	case 't':
	datachunkscanner++;
	break;
	
	default:
	if (in_data_chunk == 1)
	{
    wav_data2[parse2] = c;
	}
	break;
	  
  }
  parse2++;
  }

	printf("file length at end:-> %d \n	",parse);
	
	FILE *fp;
	fp = fopen( filename_out , "w" );
	
	fputc ( 'R' , fp );
	fputc ( 'I' , fp );
	fputc ( 'F' , fp );
	fputc ( 'F' , fp );
    fputc ( 162 , fp );
	fputc ( 1 , fp );
	fputc ( 0 , fp );
	fputc ( 0 , fp );
	fputc ( 'W' , fp );
	fputc ( 'A' , fp );
	fputc ( 'V' , fp );
	fputc ( 'E' , fp );
	fputc ( 'f' , fp );
	fputc ( 'm' , fp );
	fputc ( 't' , fp );
	fputc ( ' ' , fp );
	fputc ( 16 , fp );
	fputc ( 0 , fp );
	fputc ( 0 , fp );
	fputc ( 0 , fp );
	fputc ( 1 , fp );
	fputc ( 0 , fp );
	fputc ( 1 , fp );
	fputc ( 0 , fp );
	fputc ( 'D' , fp );
	fputc ( 172 , fp );
	fputc ( 0 , fp );
	fputc ( 0 , fp );
	fputc ( '^' , fp );
	fputc ( 'X' , fp );
	fputc ( 1 , fp );
	fputc ( 0 , fp );
	fputc ( 2 , fp );
	fputc ( 0 , fp );
	fputc ( 16 , fp );
	fputc ( 0 , fp );
	fputc ( 'd' , fp );
	fputc ( 'a' , fp );
	fputc ( 't' , fp );
	fputc ( 'a' , fp );

	fwrite(wav_data2 , 1 , parse , fp );
	
	pclose(fp_in);
	
	int freq,fs,amplitude,cycle,sampleint;
	double angle,increment,sample;
 
	fclose(fp);
  
    return(0);
}