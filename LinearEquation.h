int compare(double a,double b);

void logolinear(){
     system("cls");
   infinity(50);
   printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\tthe Infinite Linear equation solver\n");
    printf("\t\t-----------------------------------------------------------------------------------\n");

}

//checks the significant figures
int infl(double a){

        int k,l,m=0;
        l=(int)(a*1000000);
        k=l%1000000;
        while(k!=0){
        m=m*10+(k%10);
        k/=10;

    }
        if(m<0) m*=(-1);
        if(m==0) return 0;
        else {
                return (int)(1+(int)log10(m));}

}


void Linear(){

   int n;// number of variables
   int i,j,k=0;
   double l,m;
   double z;
   int r,t;
   int o=0;int p;
   double q=1;
   int A;
   char op;
    FILE *fptr;
   menustr mn[5];
   strcpy(mn[0].s,"1.Start");
    strcpy(mn[1].s,"2.History");
    strcpy(mn[2].s,"3.Back");

     B:
    logolinear();
     printf("\n\n");
     printf("\t\t\t\t\t\tSelect an Option\n");
     menu(40,30,3,mn);
    op=getch();
    if(op=='3'){goto EOP;}
    else if(op=='1'){}
    else if(op=='2'){goto fileworks;}
    else{goto B;}

    Start:
    logolinear();
   printf("\nThis program solves linear equations of any number of variables\n How to use?\n-Eg, if you want to solve for 2 variables, say x+y=2 and x-y=0, Enter number of variables 2 then input coefficients in the format\n1 1 2\n1 -1 0\n");

   fptr=fopen("Linear.txt","a+");
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

      fprintf(fptr,"\n");
    fprintf(fptr,"~");
   for(i=0;i<n;i++){
        k=0;
        for(j=0;j<=n;j++){

            scanf("%lf",&in[i*(n+1)+j]); //take input of coeff. matrix
           if(j==0 ) fprintf(fptr,"\t\t%7.2lf",in[i*(n+1)+j]);
           else if(j==n)  fprintf(fptr,"%7.2lf",in[i*(n+1)+j]);
           else fprintf(fptr,"%+7.2lf",in[i*(n+1)+j]);
           if(j!=n) fprintf(fptr," x%d",j+1);
           if(j==(n-1)) fprintf(fptr," = ");
            if(k<infl(in[i*(n+1)+j])){
                    k=infl(in[i*(n+1)+j]);
            }
            if(j==n) line(15,0);

        }
        if(k){
            for(j=0;j<=n;j++) in[i*(n+1)+j]*=pow(10,k);
        }
        fprintf(fptr,"\n");

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
             if(compare(var[A*n*n+i*n+i],0)==0){  //checking if the diagonal elements are zero
                if(p==(n-i)){
                printf("Error! \n");
                 fprintf(fptr,"Error! \n");
                goto B;
                }
                for(o=0;o<n;o++){

                   var[A*n*n+i*n+o]+=var[A*n*n+(i+p)*n+o];  //making diagonal elements non zero by swapping rows

                }
                p++; continue;
            }
             //steps for making upper triangular matrix
             if(compare(var[A*n*n+(i+k)*n+i],0)!=0){
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
           if(compare(z,0)==0){
            printf("Error! ");
             fprintf(fptr,"Error! ");
            getch();
            goto B;
           }
          k=  HCF(d[i],z);

     d[i]/=k; z/=k;
        if(z>0){
        printf("\n");
        fprintf(fptr,"\n");
        line(15,90); printf("\n");line(15,0);
        if(compare(round(d[i])/round(z),d[i]/z)==0){
            printf(" x%d = %.0lf /%.0lf = %lf",i+1,d[i],z,d[i]/z);
            fprintf(fptr,"\t\t x%d = %.0lf /%.0lf = %lf",i+1,d[i],z,d[i]/z);}
        else{ printf(" x%d = %lf",i+1,d[i]/z);
            fprintf(fptr,"\t\t x%d = %lf",i+1,d[i]/z);
        }
        }
        else  {
                 printf("\n");
                 fprintf(fptr,"\n");
            line(15,90); printf("\n");line(15,0);
            if(compare(round(d[i])/round(z),d[i]/z)==0){
                printf(" x%d = %.0lf /%.0lf = %lf",i+1,(-1)*d[i],(-1)*z,d[i]/z);
                fprintf(fptr,"\t\t x%d = %.0lf /%.0lf = %lf",i+1,(-1)*d[i],(-1)*z,d[i]/z);
            }
            else{
                printf(" x%d = %lf",i+1,d[i]/z);
                fprintf(fptr,"\t\t x%d = %lf",i+1,d[i]/z);
            }
        }

    }
    linef(15,90,fptr);

    printf("\n");  line(15,90);
    printf("\n\n");
    fclose(fptr);

    free(var);
    free(in);
    free(d);
    free(x);
    printf("\n");
    lineb(15,90); printf("\n");line(15,0);
  printf("Want to solve another set of Linear equations?->Press y \n");
    lineb(15,90); printf("\n");     line(15,0);
  printf("Menu-> any other key\n");
    lineb(15,90); printf("\n");
    op=getch();
    if(op=='y' || op=='Y') goto Start;
    else goto B;

    fileworks:
     history(fptr,'l');
     goto B;



    EOP:
    printf(" ");

}



