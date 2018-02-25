//logo

void logostat(){
     system("cls");
   infinity(50);
   printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\t Data Analysis (Standard Deviation And Error)\n");
    printf("\t\t-----------------------------------------------------------------------------------\n");

}

void sd(){
    //Declaration of variables
        float *input, *dfm,*sdfm;
        int i,n=0;
        float sum=0,av,sumsdfm,sd,error;
        char op;
        FILE *fptr;
        menustr mn[5];
        strcpy(mn[0].s,"1.Start");
        strcpy(mn[1].s,"2.History");
        strcpy(mn[2].s,"3.Back");

        B:
            logostat();
            printf("\n\n");
            printf("\t\t\t\t\t\tSelect an Option\n");
            menu(40,30,3,mn);
            op=getch();
            if(op=='3'){goto EOP;}
            else if(op=='1'){}
            else if(op=='2'){goto fileworks;}
            else{goto B;}

        Start:
        logostat();
        fptr=fopen("statistics.txt","a+");

        if(n==1) printf("\t\t\tn must be greater than 1\n");
        //take number of observations
        lineb(15,90);
        printf("\n"); line(15,0);

        printf("Enter the number of Observations.\n");
        lineb(15,90);  printf("\n"); line(15,0);
        scanf("%d",&n);
        if(n==1) goto Start;
        printf("\n");

        lineb(15,90);
            printf("\n");

        input=(float*)malloc(n*sizeof(float));
        dfm=(float*)malloc(n*sizeof(float));
        sdfm=(float*)malloc(n*sizeof(float));
        fprintf(fptr,"~\n");
            line(15,0);

            printf("Enter the observations :\n",(i+1));
            lineb(15,90);  printf("\n"); line(15,0);

        //asking for the input of data
        for(i=0;i<n;i++){
            scanf("%f",input+i);
            line(15,0);
        }
        //calculated sum below
        for(i=0;i<n;i++){
            sum+=*(input+i);
        }
        //calculated average below
        av=(sum/n);

        printf("\n\n");

        //below is assigning absolute value of the difference of data from the mean value....
        lineb(15,90);  printf("\n"); line(15,0);
        printf("MEAN VALUE = %.2f\n",av);
        lineb(15,90);  printf("\n");

        printf("\n");

        for(i=0;i<n;i++){
            *(dfm+i)=fabs(*(input+i)-av);
            *(sdfm+i)=(*(dfm+i))*(*(dfm+i));
            sumsdfm+=*(sdfm+i);
        }
        sd=sqrt(sumsdfm/n);
        lineb(15,90);  printf("\n"); line(15,0);

        //this is for the formatter output for the calculation of standard deviation
        printf(" SN\t\tObservation\t\tDeviation\t\tDeviation Square\n");
        fprintf(fptr,"\t\t\t___________________________________________________________________________________\n");
        fprintf(fptr,"\t\t\t SN\t\tObservation\t\tDeviation\t\tDeviation Square\n");
        fprintf(fptr,"\t\t\t___________________________________________________________________________________\n");
        lineb(15,90); printf("\n");
        for(i=0;i<n;i++){
                line(15,0);
            printf(" %d\t\t%11.2f\t\t%9.2f\t\t%14.2f\n",(i+1),*(input+i),*(dfm+i),*(sdfm+i));
            fprintf(fptr,"\t\t\t %d\t\t%11.2f\t\t%9.2f\t\t%14.2f\n",(i+1),*(input+i),*(dfm+i),*(sdfm+i));
        }
        fprintf(fptr,"\t\t\t___________________________________________________________________________________\n");
        lineb(15,90); printf("\n\n"); fprintf(fptr,"\n\n");
        error=sd/pow(n-1,0.5);


        //prints the standard deviation
        line(15,90);  printf("\n"); line(15,0);
        printf("STANDARD DEVIATION = %.3f\n",sd);
        fprintf(fptr,"\t\t\tSTANDARD DEVIATION = %.3f\n",sd);


        //prints the standard error
        line(15,90);  printf("\n"); line(15,0);
        printf("STANDARD ERROR = %.3f\n",error);
        fprintf(fptr,"\t\t\tSTANDARD ERROR = %.3f\n",error);


        //prints the range of observation
        line(15,90);  printf("\n"); line(15,0);
        printf("Mean value of Observation = %.2f %c %.3f",av,241,error);
        fprintf(fptr,"\t\t\tMean value of Observation = %.2f %c %.3f\n",av,241,error); linef(15,90,fptr);  fprintf(fptr,"\n");
        printf("\n");
        line(15,90);  printf("\n\n");

        fclose(fptr);

            lineb(15,90); printf("\n");line(15,0);
        printf("Want to Analyze another set of observations?->Press y \n");
            lineb(15,90); printf("\n");     line(15,0);
        printf("Menu-> any other key\n");
            lineb(15,90); printf("\n");
            op=getch();
            if(op=='y' || op=='Y') goto Start;
            else goto B;

        fileworks:
            history(fptr,'s',2);
            goto B;

        EOP:
        printf("");
}
