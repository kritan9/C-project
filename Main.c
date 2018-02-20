#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "Factors.h"
#include "properfraction.h"
#include "det.h"
#include "swap.h"
#include "LinearEquation.h"
#include "regression.h"
#include "polynomial.h"

void infinity(int);
int main(){
    int i,j,k;
    char x;
     char a[]=" 1. Linear Equation Solver ";
     char b[]=" 2. Polynomial Equation Solver ";
     char c[]=" 3. Correlation And Equation Of Best fit Line ";
     char d[]=" 4. Data Analysis (Standard Deviation And Error) ";
    char  e[]=" 5. Matrix Problems ";
    char g[]=" 6.Exit";
    char f[58];
    for(i=0;i<57;i++){
        f[i]='\xec';
    }
    f[57]=0;

X:
    system("cls");
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\tSelect an Option\n");

    for(i=0;i<=19;i++){
            k=0;
        printf("\n \t\t\t");
        for(j=0;j<=60;j++){

            if(j==0 || i==0 || j==60 || i==19) printf("\xdc");
            else if( i<19 && j==2 &&k==0 ) {
                 k=1;j-=1;

                 switch(i){

                case 2 : printf("%s",a);
                        j+=strlen(a);
                        break;
                case 3:  printf("%s",f);
                        j+=strlen(f);
                        break;
                case 5 : printf("%s",b);
                        j+=strlen(b);
                         break;
                 case 6:  printf("%s",f);
                        j+=strlen(f);
                        break;
                case 8 : printf("%s",c);
                        j+=strlen(c);
                         break;
                 case 9:  printf("%s",f);
                        j+=strlen(f);
                        break;
                case 11 : printf("%s",d);
                        j+=strlen(d);
                         break;
                 case 12:  printf("%s",f);
                        j+=strlen(f);
                        break;
                case 14 : printf("%s",e);
                        j+=strlen(e);
                         break;
                 case 15:  printf("%s",f);
                        j+=strlen(f);
                        break;
                  case 17 : printf("%s",g);
                        j+=strlen(g);
                         break;
                 }


            }
            else printf(" ");
        }

    }
    printf("\n\t\t\t");
    x=getch();
   if(x=='1') Linear();
    if(x=='3') regression();
    if(x=='2') polynomial();
    if(x=='6') goto Y;
    goto X;
    Y:
    return 0;
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

