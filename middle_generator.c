#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.142

FILE *fp;
FILE *fp_in;
char *wav_data;
int c, parse;
char filename[20];

int main()
{
	printf("name of input file 1: \n");
	gets(filename);
	
	fp_in = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);
	int filelen = ftell(fp_in);
	realloc(wav_data,filelen + 1);
	wav_data = malloc(filelen + 1);
	rewind(fp_in);
	
	while (1) 
  {
    c = fgetc(fp_in);
    if (feof(fp_in)) {
      break;
      }
      if (c != 7) {  
		switch (c) {
          case 0x00:
            wav_data[parse] = 'S';
          break;
		  case 62:
            wav_data[parse] = 'S';
          break;
		  case 182:
            wav_data[parse] = 'S';
          break;
		  case 90:
		  case 0x90:
		  case 0x91:
	  	  case 0x92:
		  case 0x93:
		  case 0x94:
		  case 0x95:
		  case 0x96:
		  case 0x97:
		  case 0x98:
		  case 0x99:
		  case 0x9A:
		  case 0x9B:
		  case 0x9C:
		  case 0x9D:
		  case 0x9E:
		  case 0x9F:
            wav_data[parse] = '9';
          break;
		  case 0x80:
		  case 0x81:
		  case 0x82:
		  case 0x83:
		  case 0x84:
		  case 0x85:
		  case 0x86:
		  case 0x87:
		  case 0x88:
		  case 0x89:
		  case 0x8A:
		  case 0x8B:
		  case 0x8C:
		  case 0x8D:
		  case 0x8E:
		  case 0x8F:
            wav_data[parse] = '8';
          break;
		  case 0xA0:
		  case 0xA1:
		  case 0xA2:
		  case 0xA3:
		  case 0xA4:
		  case 0xA5:
		  case 0xA6:
		  case 0xA7:
		  case 0xA8:
		  case 0xA9:
		  case 0xAA:
		  case 0xAB:
		  case 0xAC:
		  case 0xAD:
		  case 0xAE:
		  case 0xAF:
            wav_data[parse] = 'A';
          break;
		  default:
            wav_data[parse] = c;
          break;
		}
      }
	  else {
        wav_data[parse] = '_';
      }
	  parse++;
  }
	
	close(fp_in);
	
	printf("%s",wav_data);
	printf("\n flength:-> %d",parse);
	
	int freq,fs,amplitude,cycle,sampleint;
	double angle,increment,sample;

	fp = fopen( "file.txt" , "w" );
    fwrite(wav_data , 1 , sizeof(wav_data) , fp );
 
	fclose(fp);
  
    return(0);
}