

double sum(double *x, int n){
    double k=0;
    int i;
    for(i=0;i<n;i++){

       k+=*(x+i);
    }
    return k;
}
double sum2(double *x,double *y,int n){
    double k=0;
    int i;
    for(i=0;i<n;i++){
       k+=(*(x+i) * *(y+i));
    }
    return k;
}


void regression(){

    int n,i,j;
     double *x, *y , r , m , c ,r1,r2,r3,r4;
    A:
        system("cls");
         printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\tCorrelation And Equation Of Best fit Line\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    printf("\nEnter the number of data ");
    scanf(" %d",&n);

   if(n<=1){ printf("n must be greater than 1\n");
    goto A;
   }
   //allocating size of array
    x=(double *)malloc(n*sizeof(double));
    y=(double *)malloc(n*sizeof(double));

    if(x==0 || y==0){
        printf("error! Out of memory");
        exit(1);
    }
    //Taking input of x
    printf("Enter the values of x: ");
    for(i=0;i<n;i++){

        scanf(" %lf",x+i);
    }
    //Taking input of y
     printf("Enter the values of y: ");
    for(i=0;i<n;i++){

        scanf(" %lf",y+i);
    }
//Finding coefficient of correlation
    r1 = (n*sum2(x,y,n)-sum(x,n)*sum(y,n));
   r2=pow(n*sum2(x,x,n)-pow(sum(x,n),2),0.5);
   r3=pow(n*sum2(y,y,n)-pow(sum(y,n),2),0.5);
   r=r1 / (r2 * r3);

   //Finding Slope
   m=r1 /(r2 * r2);
    m=r*pow(n*sum2(y,y,n)-pow(sum(y,n),2),0.5);
    m/=pow(n*sum2(x,x,n)-pow(sum(x,n),2),0.5);

    //Finding y-intercept
    c=(sum(y,n)/n)-m*sum(x,n)/n;
    free(x);
    free(y);

    //Display the equation of best fit
    printf("Equation of best fit line is: y = %.6lf x%c%.6lf ",m,c<0? ' ':'+',c);

    printf("\nCoefficient of correlation = %lf\n",r);

    getch();
}
