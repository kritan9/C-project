#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "menu.h"
void line2(int);
void line1(int);
void clr();
void main2();
float fx(float x,float *c,float *p,int n);//prototype for fx function
void main(){
    infinity(50);
    printf("\n\t\t-------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\tthe infinitly-termed,non-linear(polynomial) equation solver(if your ram is enough)\n");
    printf("\t\t-------------------------------------------------------------------------------------------------------\n");
    int l1=-1000,l2=1000;
    float in=1;
    void main2(){
        top2:
        clr();
        printf("\t\t\t\t\t\tSelect an option...\n");
        //MENUMENU
        menu(32,2,"1.Start","2.Settings","Settings","Settings","Settings","Settings","Settings");
        printf("\n\t\t\t\t");
        char op=getche();
        switch(op){
        case '2':
            top3:
            clr();
            printf("\t\t\t\t\t\tSelect an option...\n");
            //MENUMENU
            menu(32,3,"1.Enter the approx range of roots.","2.Enter the approx minimum value of difference of two roots.","\t  Press any other key to go back","Settings","Settings","Settings","Settings");
            printf("\n\t\t\t\t");
            char op1=getche();
            switch(op1){
            case '1':
                clr();
                menu(32,1,"1.Enter the approx range of roots.","a","a","a","a","a","a");
                line1(32);
                printf("\n\n\t\t\t\tNote: By default the program solves the equation\n\t\t\t\tto give the root between -1000 and 1000.\n");
                printf("\t\t\t\tYou can specify the limits here.\n");
                printf("\t\t\t\tNote that everything has pros and cons.\n");
                printf("\t\t\t\tHigh range equals more memory use and more execution time.\n\n");
                line1(32);
                printf("\n\t\t\t\tEnter in pattern as range: -1000 1000\n\t\t\t\tNOTE:-1000[space]1000\n\t\t\t\trange: ");
                scanf("%d %d",&l1,&l2);
                goto top3;
                break;
            case '2':
                clr();
                printf("\n\n\n\nNote: By default the program checks the increasing and decreasing\n nature of curve in an interval of 1 unit.\n");
                printf("ie if two roots lie within the range of 1 unit then only one root is given.\n");
                printf("You can specify the range here.\n");
                printf("Lower the range high accuracy, high memory ugage and slower execution.\nEnter the range: ");
                scanf("%f",&in);
                printf("\nPress any key to go back");
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
    int ic=0;//imagionary root checker
    int n;
    top:
    clr();
    printf("\n \t\t\t\t**********************************************************\n");
    printf("\t\t\t\t\tHow to use?\n");
    printf("\t\t\t\t\tFor a equation(in terms of x):\n\t\t\t\t\t2x^4+x^3-31x^2-26x+24=0\n\t\t\t\t\ttype:\n\t\t\t\t\t2x4 +1x3 -31x2 -26x1 +24\n\t\t\t\t\tand press enter.\n");
    printf("\n\n\t\t\t\t\tDEMO::\n\t\t\t\t\tEnter the number of terms in the function: 5\n\n\t\t\t\t\tf(x)= 2x4 1x3 -31x2 -26x1 24x0\n\n\t\t\t\t\t\t[  -3.562    -1.500    0.562    4.000  ]\n\n\n");
    printf("\t\t\t\t**********************************************************\n");
    ic=0;
    line1(16);
    printf("\n\t\tEnter the number of terms in the function: ");
    scanf("%d",&n);
    line1(50);
    float *c=calloc(n+1,sizeof(float));//array of coefficients
    float *p=calloc(n+1,sizeof(float));//array of degrees
    printf("\n\tf(x)= ");
    int i;
    for(i=0;i<n;i++){
        scanf(" %fx%f",c+i,p+i);
    }
    line1(50);
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
    /*printf("\nf(x)=");
    for(i=0;i<n;i++){
        printf("%c%.2fx(%c%.2f) ",((c[i]<0)?' ':'+'),c[i],(c[i],(p[i]<0)?' ':'+'),p[i]);
    }
    //printinf f'x
    printf("\nf'(x)=");
    for(i=0;i<n;i++){
        printf("%c%.2fx(%c%.2f) ",((c1[i]<0)?' ':'+'),c1[i],(c1[i],(p1[i]<0)?' ':'+'),p1[i]);
    }*/
    //finding apporiate value of root
    float root(float r){
        int j=1;
        for(i=0;j;i++){
            if((xn(r)-r)<=0.0000001 && (xn(r)-r)>=-0.0000001){
                j=0;
            }
            r=xn(r);
            if(i==150){
                r=1010101010;
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
            if(r==1010101010){
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
    printf("\n\n\t\t[");
    for(i=0;rts[i]!='\0';i++){
        printf("  %.3f  ",rts[i]);
    }
    printf("]");
    line1(50);
    if(ic){
        printf("\n\tSome roots doesn't exist.");
        line1(50);
    }
    char yn;
    line1(50);
    printf("\n\n\n\tNeed another equation solved?(y/anything else):");
    yn=getche();
    line1(50);
    if(yn=='y'||yn=='Y'){
        goto top;
    }
    else{
        goto top2;
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
 void line2(int n){
    int c=1;
    printf("\n");
    while(c<94){
        if(c<=n){printf(" ");}
        else{printf("\xec");}
        c++;
    }
    printf("\n");
 }
void line1(int n){
    int c=1;
    printf("\n");
    while(c<94){
        if(c<=n){printf(" ");}
        else{printf("\xdc");}
        c++;
    }
    printf("\n");
 }
void clr(){
    system("cls");
    infinity(50);
    printf("\n\t\t-------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\tthe infinitly-termed,non-linear(polynomial) equation solver(if your ram is enough)\n");
    printf("\t\t-------------------------------------------------------------------------------------------------------\n");
}
