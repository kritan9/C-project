void logoreg(){
     system("cls");
        infinity(50);
         printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\tCorrelation And Equation Of Best fit Line\n");
    printf("\t\t-----------------------------------------------------------------------------------\n");
}

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
     char op;
    FILE *fptr;
    menustr mn[5];
    strcpy(mn[0].s,"1.Start");
    strcpy(mn[1].s,"2.History");
    strcpy(mn[2].s,"3.Back");

    B:
    logoreg();
     printf("\n\n");
     printf("\t\t\t\t\t\tSelect an Option\n");
     menu(40,30,3,mn);
    op=getch();
    if(op=='3'){goto eop;}
    else if(op=='1'){}
    else if(op=='2'){goto fileworks;}
    else{goto B;}

    Start:
    logoreg();
    printf("\n");
    lineb(15,90); printf("\n");line(15,0);
    printf("Enter the number of data \n");
    lineb(15,90);  printf("\n"); line(15,0);
    scanf(" %d",&n);

   if(n<=1){
             printf("\n");
            lineb(15,90); printf("\n");line(15,0);
            printf("n must be greater than 1\n");
            lineb(15,90);printf("\n");
            line(15,0);
            printf("Press any key to continue.");
            getch();
            goto Start;
   }
   //allocating size of array
    x=(double *)malloc(n*sizeof(double));
    y=(double *)malloc(n*sizeof(double));

    if(x==0 || y==0){
        printf("error! Out of memory");
        exit(1);
    }
    fptr=fopen("regression.txt","a+");
    fprintf(fptr,"\n~\t\t\tx:\t");

    //Taking input of x
    printf("\n");
    lineb(15,90); printf("\n");line(15,0);
    printf("Enter the values of x: \n");
    lineb(15,90);  printf("\n"); line(15,0);
    for(i=0;i<n;i++){

        scanf(" %lf",x+i);
        line(15,0);
        fprintf(fptr,"%7.2lf|",x[i]);
    }
    fprintf(fptr,"\n \t\t\ty:\t");

    //Taking input of y
    printf("\n");
    lineb(15,90); printf("\n");line(15,0);
     printf("Enter the values of y: \n");
     lineb(15,90);  printf("\n"); line(15,0);
    for(i=0;i<n;i++){

        scanf(" %lf",y+i);
        line(15,0);
         fprintf(fptr,"%7.2lf|",y[i]);
    }
    printf("\n\n");
    fprintf(fptr,"\n\n");
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
     line(15,90); printf("\n");line(15,0);
    printf("Equation of best fit line is: y = %.6lf x%c%.6lf \n",m,c<0? ' ':'+',c);   line(15,90); printf("\n");line(15,0);
    printf("Coefficient of correlation = %lf\n",r);                                 line(15,90); printf("\n\n");

    fprintf(fptr,"\t\t\tEquation of best fit line is: y = %.6lf x%c%.6lf ",m,c<0? ' ':'+',c);
    fprintf(fptr,"\n\t\t\tCoefficient of correlation = %lf\n\n",r);
    fclose(fptr);

     printf("\n");
    lineb(15,90); printf("\n");line(15,0);
  printf("Want to find best fit line for next set of data?->Press y \n");
    lineb(15,90); printf("\n");     line(15,0);
  printf("Menu-> any other key\n");
    lineb(15,90); printf("\n");
    op=getch();
    if(op=='y' || op=='Y') goto Start;
    else goto B;

    fileworks:
        history(fptr,'r');
        goto B;

    eop: //end of program
    printf("");
}
