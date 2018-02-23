void poly(FILE *fptr,int n,int m,int page){
        char ch;
        fptr=fopen("polynomial.txt","r");
        fseek(fptr,-1,2); //current just before
        int i=0,j=0,k;
        k=ftell(fptr);

            while(j<(page*n+m)){
                    fseek(fptr,k,0);
                if((ch=fgetc(fptr))=='~') j++;
                k--;
            }
            if(m!=0) n=m;
       while(1){
            ch=fgetc(fptr);
            if(ch==EOF){ break;}
            if(ch=='~'){ i++;
                if(i>=n) break;
            }
            else  printf("%c",ch);


       }
       fclose(fptr);

}
int popage(FILE *fptr){
     char ch;
     int i=0;
        fptr=fopen("polynomial.txt","r");
        fseek(fptr,0,0); //current at beginning
         while(1){
            ch=fgetc(fptr);
            if(ch=='~') i++;
            if(ch==EOF) break;

         }
         fclose(fptr);
    return i;
}

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

    int fi; char fic;
    double l,l1=-1000,l2=1000,in=1;
    FILE *fptr;
    int n,i,z,j;
    int opt;
    system("cls");
    menustr mn[4];
    void main2(){
        opt=0;
        top2:
        clr();
        printf("\t\t\t\t\t\tSelect an option...\n");
        //MENUMENU

        strcpy(mn[0].s,"1.Start");
        strcpy(mn[1].s,"2.Settings");
        strcpy(mn[2].s,"3.History");
        strcpy(mn[3].s,"4.Back");
        menu(40,30,4,mn);
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
                printf("\n\n\t\t\t\tNote: By default the program solves the equation\n\t\t\t\tto give the root between -1000 and 1000.\n");
                printf("\t\t\t\tSorry for the inconvenience. You can specify the limits here.\n");
                printf("\t\t\t\tNote that:\n");
                printf("\t\t\t\tHigh range equals more memory use and more execution time.\n\n");
                line1(32);
                printf("\n\t\t\t\tEnter in pattern as range: -1000 1000\n\t\t\t\tNOTE:- -1000[space]1000\n\t\t\t\trange: ");
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
                printf("\n\n\t\t\t\tNote: By default the program checks increasing and decreasing\n\t\t\t\tnature of curve in an interval of 1 unit.\n");
                printf("\t\t\t\tie if 3 roots lie within 1 unit interval the program \n\t\t\t\tdetects only one.\n");
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
            case '1': break;

            case '4': opt=1;
                      break;
            case '3': opt=3;
                        break;

            default : main2();
        }

    }

    top2:
    main2();
    if(opt==1) goto _back;
    if(opt==3) goto filework;
     top:
    clr();
    printf("\n \t\t\t\t**********************************************************\n");
    printf("\t\t\t\t\tHow to use?\n");
    printf("\t\t\t\t\tFor a equation(in terms of x):\n\t\t\t\t\t2x^4+x^3-31x^2-26x+24=0\n\t\t\t\t\ttype:\n\t\t\t\t\t2x4 +1x3 -31x2 -26x1 +24x0\n\t\t\t\t\tand press enter.\n");
    printf("\n\n\t\t\t\t\tDEMO::\n\t\t\t\t\tEnter the number of terms in the function: 5\n\n\t\t\t\t\tf(x)= 2x4 1x3 -31x2 -26x1 24x0\n\n\t\t\t\t\t\t[  -3.561533    -1.500000    0.561553    4.000000  ]\n\n\n");
    printf("\t\t\t\t**********************************************************\n");
    line1(32);
    printf("\n\t\tEnter the number of terms in the function: ");
    scanf("%d",&n);

    fptr=fopen("polynomial.txt","a+");

    double temp;
   double *c=calloc(n+1,sizeof(double));//array of coefficients
    double *p=calloc(n+1,sizeof(double));//array of degrees
    double rts[20];//array for roots
    printf("\n\t\tf(x)= ");
    fprintf(fptr,"\n~\t\tf(x)= ");
    for(i=0;i<n;i++){
        scanf("%lfx%lf",c+i,p+i);
        if(i!=0 && c[i]>=0) fprintf(fptr," + ");
        fprintf(fptr,"%.3lfx^(%.3lf)",c[i],p[i]);
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


    //finding appropriate value of root

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

    //finding increasing decreasing nature of function
    int der(double a){
        double l;
       l=fx(a,c1,p1,n);
       if(l>0) return 1;
       if(l==0) return 0;
       if(l<0) return -1;
    }

    j=0;
    rts[j]=root(-1000);
    if(compare(rts[j],1010101010)==0)  j=0;
    else j=1;

    //iteration for roots
    for(l=l1;l<=l2;l+=in){
        if(((der(l-in)!=der(l))&& der(l)!=0) || chkrt(l,l-in,c,p,n)>0) {  //checking condition for finding a different root

             temp=root(l);
            if(chkrt(l,l-in,c,p,n)==2)
              temp=l;


            if(compare(temp,1010101010)!=0){
              if(j==0) {rts[j]=temp; j++;}
              z=j;
              while(z!=0){
                if(compare(temp,rts[z-1])==0) break;
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
     fprintf(fptr,"\n\t\t\t\tThe real roots of the equation are:\n");
     printf("\n\n\t\t\t\t[");
     fprintf(fptr,"\n\n\t\t\t\t[");
    for(i=0;i<j;i++){
        printf("  %lf  ",rts[i]);
        fprintf(fptr,"  %lf  ",rts[i]);
    }
    printf("]");
    fprintf(fptr,"]");
     line1(32);
    fclose(fptr);
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
    //displaying history
    filework:
       fi=0;i=0;
       fi=popage(fptr);
       j=fi%5;
       fi/=5;
        while(1){
       if(fi==0 && j==0){
        clr();
        printf("\t\t\t\t\t\tNo History\n\t\t\t\t\tPress any key to go back");
        getch();
        goto top2;
       }
        else if(fi==0){
           clr();
             lineb(15,90); printf("\n");line(15,0);
            printf("Back to menu-> Press any key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            poly(fptr,5,j,fi);
              fic=getch();
             goto top2;
       }

        if(i==0 && j==0){
        clr();
        lineb(15,90); printf("\n"); lineb(15,0);
        printf("Back to menu->Press any key\n");
        lineb(15,90); printf("\n"); line(15,0);
        printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
        poly(fptr,5,0,i+1);
        fic=getch();
        goto top2;
       }
      else if(i==0){
        clr();
        lineb(15,90); printf("\n");line(15,0);
        printf("Next page->Press + \n");
        lineb(15,90); printf("\n"); lineb(15,0);
        printf("Back to menu-> any other key\n");
        lineb(15,90); printf("\n"); line(15,0);
        printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
        poly(fptr,5,0,i+1);
        fic=getch();
       if(fic=='+') i++;
       else goto top2;
       }
       if(i<(fi-1)){
           clr();
            lineb(15,90); printf("\n");line(15,0);
            printf(" Next page->Press + \n\t\tPrevious page->Press -\n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            poly(fptr,5,0,i+1);
              fic=getch();
            if(fic=='+') i++;
            else if(fic=='-') i--;
            else goto top2;
       }
    if(i==(fi-1)) {
           clr();
             lineb(15,90); printf("\n");line(15,0);
             if(j!=0) printf(" Next page->Press + \n\t\t");
            printf("Previous page->Press - \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            poly(fptr,5,0,i+1);
              fic=getch();
            if(fic=='-') i--;
            else if (j!=0 && fic=='+') i++;
            else goto top2;
       }
       if(i==fi){
             clr();
             lineb(15,90); printf("\n");line(15,0);
            printf("Previous page->Press - \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            poly(fptr,5,j,fi);
              fic=getch();
            if(fic=='-') i--;
            else goto top2;
       }
        }


    _back:
    printf(" ");
}




