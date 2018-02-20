#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void infinity(int);
float fx(float x,float *c,float *p,int n);//prototype for fx function
void main(){
    infinity(50);
    printf("\n\t\t-------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\tthe infinitly-termed,non-linear(polynomial) equation solver(if your ram is enough)\n");
    printf("\t\t-------------------------------------------------------------------------------------------------------\n\n\n");
    int l1=-1000,l2=1000;
    float in=1;
    void main2(){
        top2:
        printf("\n");
        printf("\t\t\t\t\t\tMENU");
        printf("\n\t\t1.Start\n\t\t2.Settings\n\t\t3.About\n\t\tEnter the option's number:-");
        char op=getche();
        switch(op){
        case '2':
            printf("\n\n\t1.Edit the range to check of root.:\n\t2.Edit the range to check.\n\t3.Back\nEnter the option's number: ");
            char op1=getche();
            switch(op1){
            case '1':
                printf("\n\n\n\nNote: By default the program solves the equation\nto give the root between -1000 and 1000.\n");
                printf("You can specify the limits here.");
                printf("Note that everything has pros and cons.\n");
                printf("High range equals more memory use and slower speed.\n\n");
                printf("Enter in pattern as range: -1000 1000 NOTE:-1000[space]1000\nrange: ");
                scanf("%d %d",l1,l2);
                break;
            case '2':
                printf("\n\n\n\nNote: By default the program checks the increasing and decreasing\n nature of curve in an interval of 1 unit.\n");
                printf("ie if two roots lie within the range of 1 unit then only one root is given.\n");
                printf("You can specify the range here.\n");
                printf("Lower the range high accuracy, high memory ugage and slower execution.\nEnter the range: ");
                scanf("%f",in);
                break;
            default:
                goto top2;
            }

        }

    }
    main2();
    int ic=0;//imagionary root checker
    int n;
    top:
    printf("\n \t\t\t\t**********************************************************\n");
    printf("\t\t\t\t\tHow to use?\n");
    printf("\t\t\t\t\tFor a equation(let it be in terms of x):\n\t\t\t\t\t2x\n");
    printf("\t\t\t\t**********************************************************\n");
    ic=0;
    printf("\nEnter the number of terms in the function:- ");
    scanf("%d",&n);
    float *c=calloc(n+1,sizeof(float));//array of coefficients
    float *p=calloc(n+1,sizeof(float));//array of degrees
    printf("\nEnter coefficient and power as shown below:-\neg: for\n2x^4 \ntype 2 4\n[NOTE:-2(space)4].\n\n");
    int i;
    for(i=0;i<n;i++){
        scanf("%f %f",c+i,p+i);
    }
    float *c1=calloc(n,sizeof(float));//array of coefficients
    float *p1=calloc(n,sizeof(float));//array of degrees
    //derivative of the function
    for(i=0;i<n;i++){
        if(p[i]==0){p1[i]=0;c1[i]=0;}
        else{
            c1[i]=c[i]*p[i];
            p1[i]=p[i]-1;
        }
    }
    //application of newton raphson's method
    float xn(float r){
    return (r-(fx(r,c,p,n)/fx(r,c1,p1,n)));
    }
    //printing fx
    printf("\nf(x)=");
    for(i=0;i<n;i++){
        printf("%c%.2fx(%c%.2f) ",((c[i]<0)?' ':'+'),c[i],(c[i],(p[i]<0)?' ':'+'),p[i]);
    }
    //printinf f'x
    printf("\nf'(x)=");
    for(i=0;i<n;i++){
        printf("%c%.2fx(%c%.2f) ",((c1[i]<0)?' ':'+'),c1[i],(c1[i],(p1[i]<0)?' ':'+'),p1[i]);
    }
    //finding apporiate value of root
    float root(float r){
        int j=1;
        for(i=0;j;i++){
            if((xn(r)-r)<=0.0000001 && (xn(r)-r)>=-0.0000001){
                j=0;
            }
            r=xn(r);
            if(i==150){
                r=1010;
                j=0;
            }
        }
    return r;
    }
    //checking the increasing and decreasing order of the curve
    int chk;
    if(fx(-1000,c1,p1,n)<0){
        chk=0;
    }
    else if(fx(-1000,c1,p1,n)>0){
        chk=1;
    }
    int chk1;
    int co=0;//the number of times function root is called
    float rts[20];//array of roots
    int i1=0;
    printf("%d %d %f",l1,l2,in);
    for(i1=l1;i1<=l2;i1=i1+in){
        chk1=chk;
        if(fx(i1,c1,p1,n)<0){
            chk=1;
        }
        else if(fx(i1,c1,p1,n)>0){
            chk=0;
        }
        //this condition is true when a curve changes its increasing or decreasing order
        if(chk1!=chk){
            float r=root((float) i1);
            //this condition is true when root is imagionary
            if(r==1010){
                ic=1;//imagionary coefficient is true
            }
            else{
                //taking unique inputs only to array
                int z;
                for(z=0;z<=co;z++){
                    if(((rts[z]-r)<0.001 && (rts[z]-r)>-0.001)){
                        z=co+1;
                    }
                    else{
                        if(z==co){
                            rts[z]=r;
                        }
                    }
                }
                co++;//count of call of root function
            }
        }
    }
    //displaying roots
    printf("\n\n\t[");
    for(i=0;rts[i]!='\0';i++){
        printf("\t%.3f",rts[i]);
    }
    printf("]");
    if(ic){
        printf("\nSome roots doesn't exist.");
    }
    char yn;
    printf("\n\n\n\n  Need another equation solved?(y/anything else):");
    yn=getche();
    if(yn=='y'){
        goto top;
    }
}
//value of fx when x is given
float fx(float x,float *c,float *p,int n){
        float y=0;
        int i;
        for(i=0;i<n;i++){
            y+=((*(c+i))*pow(x,(*(p+i))));
        }
        return y;
}
 void infinity(int n){
        int i,j,k;
        for(i=0;i<=6;i++){
            printf("\n");
            for(k=0;k<n;k++) printf(" ");
            for(j=0;j<=14;j++){
                if(((i+j)>=3 && (i-j)>=-4 && (i+j)<=10 && (i-j)<=3 )||((i+j)>=10 && (i-j)<=-4 && (i+j)<=17 && (i-j)>=-11 )) printf("\xdd");
                else printf(" ");
            }

        }
        printf("\n");
 }
