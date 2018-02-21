


void Linear(){


   int n;// number of variables
   int i,j,k;
   double l,m;
   double z;
   int r,t;
   int o=0;int p;
   double q=1;
   int A;
   system("cls");
   infinity(50);
   printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\tthe Infinite Linear equation solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
   printf("\nThis program solves linear equations of any number of variables\n How to use?\n-Eg, if you want to solve for 2 variables, say x+y=2 and x-y=0, Enter number of variables 2 then input coefficients in the format\n1 1 2\n1 -1 0\n");

  B:
      lineb(15,90);
      printf("\n"); line(15,0);
     printf("Enter the number of variables \n");
    lineb(15,90); printf("\n"); lineb(15,0);
      scanf(" %d",&n);
      lineb(15,90);
      printf("\n"); line(15,0);
       printf("Enter the coefficients and constants \n");
       lineb(15,90); printf("\n"); line(15,0);


      double *var,*in,*d,*x;

      var=(double *)malloc((n+1)*n*n*sizeof(double));   //sub matrix required for Cramer's methon
      in=(double *)malloc(n*(n+1)*sizeof(double));   //coefficient matrix
      d=(double *)malloc((n+1)*sizeof(double));            //stores determinant of sub matrices
      x=(double *)malloc((n+1)*sizeof(double));           //solution to the equations

   for(i=0;i<n;i++){

        for(j=0;j<=n;j++){

            scanf("%lf",&in[i*(n+1)+j]); //take input of coeff. matrix
            if(j==n) line(15,0);
        }
   }


   //forming sub matrices for Cramers method
   for(A=n;A>=0;A--){

        for(i=0;i<n;i++){
             k=0;
            for(j=0;j<=n;j++){
                if(j==A) continue;
                var[A*n*n+i*n+k]=in[i*(n+1)+j];

                k++;
            }
        }
   }



//Finding determinant of sub matrices by making upper triangular matrix
for(A=0;A<=n;A++){
        d[A]=1;x[A]=1;
        i=0; j=0;
while(i<(n-1)){
    k=1;p=1;
    while(k<(n-i)){
             if(var[A*n*n+i*n+i]==0){  //checking if the diagonal elements are zero
                if(p==(n-i)){
                printf("Infinite or Undefined Solution \n");
                goto B;
                }
                for(o=0;o<n;o++){

                   var[A*n*n+i*n+o]+=var[A*n*n+(i+p)*n+o];  //making diagonal elements non zero by swapping rows

                }
                p++; continue;
            }
             //steps for making upper triangular matrix
             l=LCM(var[A*n*n+(i+k)*n+i],var[A*n*n+i*n+i]);
          l=l/var[A*n*n+i*n+i];
          m=l*var[A*n*n+i*n+i]/var[A*n*n+(i+k)*n+i];
            x[A]=x[A]*l*m;   //storing the excess multiplication terms
            j=i;

        while(j<n){
                var[A*n*n+i*n+j]*=l;
                var[A*n*n+(i+k)*n+j] = var[A*n*n+(i+k)*n+j]*m-(var[A*n*n+i*n+j]);
                j++;
              }
              k++;
    }
    i++;
}
    for(k=0;k<n;k++){

            d[A]=d[A]*var[A*n*n+k*n+k]; //finding determinant as product of diagonal elements

    }
}
    for(A=0;A<=n;A++){
       d[A]=d[A]/x[A]; //actual determinant
       //changing columns of determinant of sub matrix to follow cramers rule
       if(A<n){
       if(n%2==0){
            if(A%2==0) d[A]*=(-1);
       }
       else {
        if(A%2!=0) d[A]*=(-1);
       }
       }
    }

//displaying the solution obtained by cramers method
    for(i=0;i<n;i++){
           z=d[n];
          k=  HCF(d[i],z);
     d[i]/=k; z/=k;
        if(z>0){
        printf("\n");
        line(15,90); printf("\n");line(15,0);
        printf(" x%d = %.0lf /%.0lf = %lf",i+1,d[i],z,d[i]/z);
        }
        else  {
                 printf("\n");
            line(15,90); printf("\n");line(15,0);
                printf(" x%d = %.0lf /%.0lf = %lf",i+1,(-1)*d[i],(-1)*z,d[i]/z);
        }

    }
    printf("\n");  line(15,90);
    printf("\n\n");


    free(var);
    free(in);
    free(d);
    free(x);
    printf("\n");
    lineb(15,90); printf("\n");line(15,0);
  printf("Want to solve another set of Linear equations?->Press y \n");
    lineb(15,90); printf("\n");     line(15,0);
  printf("Main Menu-> any other key\n");
    lineb(15,90); printf("\n");
    if(getch()=='y') Linear();

}



