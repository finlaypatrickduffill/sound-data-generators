#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.142

FILE *fp;

int main()
{
 int freq,fs,amplitude,cycle,sampleint;
 double angle,increment,sample;
 printf("enter the desired frequency of the signal:\n");
 scanf("%d",&freq);
 while(getchar() != '\n');
 printf("enter the desired sampling frequency:\n");
 scanf("%d",&fs);
 while(getchar() != '\n');
 printf("enter the amplitude of the signal:\n");
 scanf("%d",&amplitude);
 while(getchar() != '\n');
 printf("name of output file: \n");
	char filename[20];
	gets(filename);
	fp = fopen(filename, "w"); 
 angle=0;
 increment=((2*pi)/(fs/freq));
 
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
 
	for (cycle=1;cycle<=freq;cycle++)
	{
		while (angle<=(2*pi))
		{
			sample=(amplitude * sin(angle));
			angle=angle+increment;
			sampleint = sample;
			printf("%lf|",sample);
			printf("%d\t",sampleint);
			fputc ( sampleint , fp );
		}
		
	}
}