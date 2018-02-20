#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
float *input, *dfm,*sdfm;
int i,n;
float sum=0,av,sumsdfm,sd,error;
//take number of observations
printf("Enter the number of Observations.\n");
scanf("%d",&n);
input=(float*)malloc(n*sizeof(float));
dfm=(float*)malloc(n*sizeof(float));
sdfm=(float*)malloc(n*sizeof(float));
//asking for the input of data
for(i=0;i<n;i++){
    printf("Enter the observation number\t%d.\n",(i+1));
    scanf("%f",input+i);
}
//calculated sum below
for(i=0;i<n;i++){
    sum+=*(input+i);
}
//calculated average below
av=(sum/n);
//below is assigning absolute value of the difference of data from the mean value....
printf("\n\nMEAN VALUE\t\t\t%.2f.\n\n",av);
for(i=0;i<n;i++){
    *(dfm+i)=fabs(*(input+i)-av);
    *(sdfm+i)=(*(dfm+i))*(*(dfm+i));
    sumsdfm+=*(sdfm+i);
}
sd=sqrt(sumsdfm/n);
//this is for the formatter output for the calculation of standard deviation
printf("SN\t\tObservation\t\tDeviation\t\tDeviation Square\n");
printf("_________________________________________________________________________________\n");
for(i=0;i<n;i++){
    printf("%d\t\t%11.2f\t\t%9.2f\t\t%14.2f\n",(i+1),*(input+i),*(dfm+i),*(sdfm+i));
}
//prints the standard deviation
printf("\n\nSTANDARD DEVIATION\t\t%.3f\n\n",sd);
//prints the range of observation
printf("Range of Observation\t\t%.2f %c %.3f",av,-15,sd);
error=(sd/av)*100;
//prints the error in percentage
printf("\n\nError Percentage\t\t%.2f %c\n\n\n\n\n\n\n\n\n\n",error,37);
return 0;
}
