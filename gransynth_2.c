#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.142
int main()
{
 int freq,fs,amplitude,cycle,sampleint;
 double angle,increment,sample;
 printf("enter the desired frequency of the signal:\n");
 scanf("%d",&freq);
 printf("enter the desired sampling frequency:\n");
 scanf("%d",&fs);
 printf("enter the amplitude of the signal:\n");
 scanf("%d",&amplitude);
 angle=0;
 increment=((2*pi)/(fs/freq));
	for (cycle=1;cycle<=freq;cycle++)
	{
		while (angle<=(2*pi))
		{
			sample=(amplitude * sin(angle));
			angle=angle+increment;
			sampleint = sample;
			printf("%lf|",sample);
			printf("%d\t",sampleint);
		}
		
	}
}