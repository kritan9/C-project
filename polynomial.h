
//value of fx when x is given
double fx(double x,double *c,double *p,int n){
        double y=0;
        int i;
        for(i=0;i<n;i++){
            y+=((*(c+i))*pow(x,(*(p+i))));
        }
        return y;
}
//comparing two double type values
int compare(double a,double b){
    if( (a-b)<0.0001 && (a-b)>-0.0001 ) return 0;
    else return 1;
}


void polynomial(){

    double l;
    int n,i,z,j;
    system("cls");
     printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tthe infinitely termed non-linear equation solver(if your ram is enough)\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    printf("\nEnter the number of terms in the function:- ");
    scanf("%d",&n);

    double temp;
   double *c=calloc(n+1,sizeof(double));//array of coefficients
    double *p=calloc(n+1,sizeof(double));//array of degrees
    double *rts=calloc(n+1,sizeof(double));//array for roots

    printf("\nEnter coefficient and power as shown below:-\neg: for\n2x^4+3x^2-2 \ntype 2x4  3x2  -2x0\n\nf(x) = ");

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
                    r=10010;
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

    if(compare(rts[j],10010)==0)  j=0;
    else j=1;

    //iteration for roots
    for(l=-5000;l<=5000;l+=0.05){
        if((der(l-0.05)!=der(l))&& der(l)!=0) {  //checking condition for finding a different root

             temp=root(l);

            if(compare(temp,10010)!=0){
              z=j;
              if(j==0) {rts[j]=temp; j++;}
              while(z!=0){
                if(!compare(temp,rts[z])) break;
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
    printf("\nThe real roots of the equation are:\n");
    for(i=0;i<j;i++){
        printf("%lf\n",rts[i]);
    }

    printf("\nWant to solve another equation? then press y\nelse press any other key to return to main menu");

    if(getch()=='y') polynomial();
}



