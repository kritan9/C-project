#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Factors.h"
#include "properfraction.h"
#include "det.h"
#include "swap.h"
#include "LinearEquation.h"
#include "regression.h"


int main(){
   double *a,*c;
   int *b;
   int d;
   int i,j;
   int x,y,l,m;  //variables for iteration
   int n;
   scanf(" %d",&n);
   a=(double *)malloc(n*n*sizeof(double));
    b=(int *)malloc(n*n*sizeof(int));
     c=(double *)malloc((n-1)*(n-1)*sizeof(double));
     i=1;
   while(i){
        scanf(" %lf",a+(i-1));
        if(i==(n*n)) i=-1;
          i++;

   }
 d=det(n,n,a);
   printf("\nDeterminant is %d\n",d);

   for(i=0;i<n;i++){

    for(j=0;j<n;j++){

       for(x=0,l=0;x<n;x++,l++){

        for(y=0,m=0;y<n;y++,m++){

            if(x!=i && y!=j){
                *(c+(l*(n-1)+m)) = *(a+(x*n+y));
            }

            if(y==j) m--;
        }

        if(x==i) l--;
       }
   if((i+j)%2==0)
       *(b+(i*n+j))=det(n-1,n-1,c);
    else *(b+(i*n+j))=(-1)*det(n-1,n-1,c);
    }
   }

   printf("The adjoint matrix is:\n");
   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",b[i*n+j]);
        }
        printf("\n");
   }




}



