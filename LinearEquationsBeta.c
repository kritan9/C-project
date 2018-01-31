#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Factors.h"
#include "properfraction.h"
#include "det.h"
#include "swap.h"


int main(){


   int n=10;
   int i,j,k;
   double z;
   int A;
   printf("This program solves linear equations of n variables\n How to use?\n-Eg, if you want to solve for 2 variables, say x+y=2 and x-y=0, Enter number of variables 2 then input coefficients in the format\n1 1 2\n1 -1 0\n");

  B:
      printf("\nEnter the number of variables:\n ");
      scanf(" %d",&n);
      printf("\nEnter the coefficients and constants:\n ");

      double var[n+1][n][n];
      double in[n][n+1];
      double d[n+1];
      double x[n+1];

   for(i=0;i<n;i++){
    k=0;
        for(j=0;j<=n;j++){

            scanf("%lf",&in[i][j]);
            if((((int)in[i][j])*10000)!=(int)(in[i][j]*10000)) k++;
        }
        if(k!=0){
            for(j=0;j<=n;j++){

                in[i][j]*=10000;
            }
        }
   }
   for(A=n;A>=0;A--){

        for(i=0;i<n;i++){
             k=0;
            for(j=0;j<=n;j++){
                if(j==A) continue;
                var[A][i][k]=in[i][j];

                k++;
            }
        }
   }




for(A=0;A<=n;A++){
    d[A]=det(10,n,&var[A][0][0]);
    if(d[A]==111111) goto B;
}
    for(A=0;A<=n;A++){

       if(A<n){
       if(n%2==0){
            if(A%2==0) d[A]*=(-1);
       }
       else {
        if(A%2!=0) d[A]*=(-1);
       }
       }
    }


    for(i=0;i<n;i++){
           z=d[n];
          k=  HCF(d[i],z);
     d[i]/=k; z/=k;
        if(z>0)
        printf("\n x%d = %.0lf /%.0lf = %lf",i+1,d[i],z,d[i]/z);
        else  printf("\n x%d = %.0lf /%.0lf = %lf",i+1,(-1)*d[i],(-1)*z,d[i]/z);

    }


    getch();
    return 0;
}



