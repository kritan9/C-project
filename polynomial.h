void clr(){
    system("cls");
    infinity(50);
    printf("\n\t\t-------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\tthe infinitly-termed,non-linear(polynomial) equation solver(if your ram is enough)\n");
    printf("\t\t-------------------------------------------------------------------------------------------------------\n");
}

//value of fx when x is given
double fx(double x,double *c,double *p,int n){
        double y=0;
        int i;
        for(i=0;i<n;i++){
            y+=((*(c+i))*pow(x,(*(p+i))));
        }
        return y;
}

//check if root exists between two values
int chkrt(double a,double b,double *c,double *p,int n){
    if((fx(a,c,p,n)>0 && fx(b,c,p,n)<0) || (fx(a,c,p,n)<0 && fx(b,c,p,n)>0)) return 1;
    else if(fx(a,c,p,n)==0) return 2;
    else return 0;
    }

//comparing two double type values
int compare(double a,double b){
    if( (a-b)<0.0001 && (a-b)>-0.0001 ) return 0;
    else return 1;
}


void polynomial(){

    double l,l1=-5000,l2=5000,in=0.1;
    int n,i,z,j;
    system("cls");
    menustr mn[3];
    void main2(){
        top2:
        clr();
        printf("\t\t\t\t\t\tSelect an option...\n");
        //MENUMENU

        strcpy(mn[0].s,"1.Start");
        strcpy(mn[1].s,"2.Settings");
        strcpy(mn[2].s,"3.Back");
        menu(40,30,3,mn);
        printf("\n\t\t\t\t");
        char op=getche();
        switch(op){
        case '2':
            top3:
            clr();
            printf("\t\t\t\t\t\tSelect an option...\n");
            //MENUMENU
             strcpy(mn[0].s,"1.Enter the approx range of roots.");
            strcpy(mn[1].s,"2.Enter the approx minimum value of difference of two roots.");
            strcpy(mn[2].s,"                   Press any other key to go back");
            menu(32,strlen(mn[1].s)+10,3,mn);
            printf("\n\t\t\t\t");
            char op1=getche();
            switch(op1){
            case '1':
                clr();
                strcpy(mn[0].s,"1.Enter the approx range of roots.");
                menu(32,strlen(mn[0].s)+10,1,mn);
                line1(32);
                printf("\n\n\t\t\t\tNote: By default the program solves the equation\n\t\t\t\tto give the root between -5000 and 5000.\n");
                printf("\t\t\t\tSorry for the inconvenience. You can specify the limits here.\n");
                printf("\t\t\t\tNote that:\n");
                printf("\t\t\t\tHigh range equals more memory use and more execution time.\n\n");
                line1(32);
                printf("\n\t\t\t\tEnter in pattern as range: -5000 5000\n\t\t\t\tNOTE:- -5000[space]5000\n\t\t\t\trange: ");
                scanf("%d %d",&l1,&l2);
                printf("\n\t\t\t\tPress any key to go back");
                getch();
                goto top3;
                break;
            case '2':
                clr();
                strcpy(mn[0].s,"2.Enter the approx minimum value of difference of two roots.");
                menu(32,strlen(mn[0].s)+5,1,mn);
                line1(32);
                printf("\n\n\t\t\t\tNote: By default the program checks increasing and decreasing\n\t\t\t\tnature of curve in an interval of 0.1 unit.\n");
                printf("\t\t\t\tie if 3 roots lie within 0.1 unit interval the program \n\t\t\t\tdetects only one.\n");
                printf("\t\t\t\tSorry for the inconvenience. You can change the interval here.\n");
                printf("\t\t\t\tNote that:\n");
                printf("\t\t\t\tLower interval equals more memory use and more execution time.\n\n");
                line1(32);
                printf("\n\t\t\t\tEnter the interval: ");
                scanf("%f",&in);
                printf("\n\t\t\t\tPress any key to go back");
                getch();
                goto top3;
                break;
            default:
                goto top2;
            }


        }

    }
    top2:
    main2();
     top:
    clr();
    printf("\n \t\t\t\t**********************************************************\n");
    printf("\t\t\t\t\tHow to use?\n");
    printf("\t\t\t\t\tFor a equation(in terms of x):\n\t\t\t\t\t2x^4+x^3-31x^2-26x+24=0\n\t\t\t\t\ttype:\n\t\t\t\t\t2x4 +1x3 -31x2 -26x1 +24\n\t\t\t\t\tand press enter.\n");
    printf("\n\n\t\t\t\t\tDEMO::\n\t\t\t\t\tEnter the number of terms in the function: 5\n\n\t\t\t\t\tf(x)= 2x4 1x3 -31x2 -26x1 24x0\n\n\t\t\t\t\t\t[  -3.561533    -1.500000    0.561553    4.000000  ]\n\n\n");
    printf("\t\t\t\t**********************************************************\n");
    line1(32);
    printf("\n\t\tEnter the number of terms in the function: ");
    scanf("%d",&n);

    double temp;
   double *c=calloc(n+1,sizeof(double));//array of coefficients
    double *p=calloc(n+1,sizeof(double));//array of degrees
    double *rts=calloc(n+1,sizeof(double));//array for roots
    printf("\n\t\tf(x)= ");
    for(i=0;i<n;i++){
        scanf("%lfx%lf",c+i,p+i);
    }

    double *c1=calloc(n,sizeof(double));//array of coefficients
    double *p1=calloc(n,sizeof(double));//array of degrees
    //derivative of the function

    for(i=0;i<n;i++){
        if(p[i]==0){p1[i]=0;c1[i]=0;}
        else{
            c1[i]=c[i]*p[i];
            p1[i]=p[i]-1;
        }
    }
    //application of newton raphson's method

    double xn(double r){
    return (r-(fx(r,c,p,n)/fx(r,c1,p1,n)));
    }


    //finding apporiate value of root

    double root(double r){
        int j=1,i;
        for( i=0;j;i++){
            if((xn(r)-r)<=0.00000001 && (xn(r)-r)>=-0.00000001){
                j=0;
            }
            r=xn(r);
            if(i==1000){
                 if((xn(r)-r)<=0.000001 && (xn(r)-r)>=-0.000001)
                    r=xn(r);
                else
                    r=1010101010;
                    j=0;
            }
        }
    return r;
    }

    //finding increasig decreasing nature of function
    double der(double a){
        double l;
       l=fx(a,c1,p1,n);
       if(l>0) return 1;
       if(l==0) return 0;
       if(l<0) return -1;
    }

    j=0;
    rts[j]=root(-5000);

    if(compare(rts[j],1010101010)==0)  j=0;
    else j=1;

    //iteration for roots
    for(l=l1;l<=l2;l+=in){
        if(((der(l-in)!=der(l))&& der(l)!=0) || chkrt(l,l-in,c,p,n)>0) {  //checking condition for finding a different root

             temp=root(l);
             if(chkrt(l,l-0.05,c,p,n)==2)
              temp=l;


            if(compare(temp,1010101010)!=0){
              z=j;
              if(j==0) {rts[j]=temp; j++;}
              while(z!=0){
                if(!compare(temp,rts[z-1])) break;
                z--;
              }
              if(z==0 && j!=0) {
                    rts[j]=temp;
                    j++;
              }
            }

        }


    }
    //printing the roots
    printf("\n\t\t\t\tThe real roots of the equation are:\n");
     printf("\n\n\t\t\t\t[");
    for(i=0;i<j;i++){
        printf("  %lf  ",rts[i]);
    }
    printf("]");
     line1(32);

    free(rts);
    free(c);
    free(p);
    free(c1);
    free(p1);
    char yn;
    printf("\n\n\t\tNeed another equation solved?(y/anything else):");
    yn=getche();
    if(yn=='y'||yn=='Y'){
        goto top;
    }
    else{
        goto top2;
    }
}



