#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.142

	char c;
	char nul;
	char sawtooth_var[1];
	char numsamples[1], numchannels[1], bitspersample[1];
	int number1, number2, number3, number4, numberofdatachunks;
	FILE *fp;
	
void handleforinput() {
		
	printf("sawtooth freq: \n");
	scanf("%d", &number1);
	while(getchar() != '\n');
	
	printf("number of samples: \n");
	scanf("%d", &number2);
	sprintf(numsamples, "%c", number2);
	while(getchar() != '\n');
	
	printf("number of channels: \n");
	scanf("%d", &number3);
	sprintf(numchannels, "%c", number3);
	while(getchar() != '\n');
	
	printf("bits per sample: \n");
	scanf("%d", &number4);
	sprintf(bitspersample, "%c", number4);
	while(getchar() != '\n');
	
	printf("number of data chunks: \n");
	scanf("%d", &numberofdatachunks);
	while(getchar() != '\n');
	
	printf("name of output file: \n");
	char filename[20];
	gets(filename);
	fp = fopen(filename, "w"); 
	
}

int main() {
	
    handleforinput();

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
	
	
	char p;
	char q;
	
	/*
	
	for (int o=1; o!=100; o++)
	{
		for (int i=1; i!=26; i++)
		{
			char p = 100 + i;
			
				if (p != 127)
				{
					fputc ( p , fp );
				}
			
		}
	}
	
	*/
	
	char lap;
	char bin;
	char lp[1];
	
	sprintf(sawtooth_var, "%c", number1);
	
	for (int increment=0; increment != numberofdatachunks; increment++)
	{

			fputc ( 'd' , fp );
			fputc ( 'a' , fp );
			fputc ( 't' , fp );
			fputc ( 'a' , fp );
			fputc ( numsamples, fp );
			fputc ( numchannels, fp );
			fputc ( bitspersample[0] , fp );
			
			for(int i=0;i<100;i++)
    {
			p = int(3276*sin(i)+32767);
			printf("%d: %d\n", i, p);
			fputc( p , fp );
			fputc( NULL , fp );
			fputc( NULL , fp );
			fputc( NULL , fp );
    }
			
	/*
	for (int o=1; o!=50; o++)
	{
		lap = 0;
		bin = 0;
		
		for (int i=1; i!=16; i++)
		{
			
			if (bin == 0)
			{
				lap++;
			}
			
			if (bin == 1)
			{
				lap--;
			}
			
			if (lap <= 0)
			{
				bin = 0;
				fputc ( p , fp );
			}
			
			if (lap >= 16)
			{
				bin = 1;
				fputc ( p , fp );
			}
			
			lp[0] = i + sawtooth_var[0];
			
				if (p != 127)
				{
					fputc ( lp[0] , fp );
				}
			}
		}
	*/
	}
	
	printf("\n\n || %c.%c.%c.%c || \n",numsamples,numchannels,bitspersample[0], sawtooth_var[0]);

    fclose (fp);
	
	fclose(fp);
    return(0);
    
}	
 
    