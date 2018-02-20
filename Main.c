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
void menu(int n,int m,char*a,char*b,char*c,char*d,char*e,char*g,char*h);

int main(){
    int i,j,k;
    char x;
     char a[]=" 1. Infinite Linear Equation Solver ";
     char b[]=" 2. Infinite Polynomial Equation Solver ";
     char c[]=" 3. Correlation And Equation Of Best fit Line ";
     char d[]=" 4. Data Analysis (Standard Deviation And Error) ";
    char  e[]=" 5. Matrix Problems ";
    char g[]=" 7.Exit";
    char l[]=" 6.About";


X:
    system("cls");
    infinity(50);
     printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\tSelect an Option\n");
    menu(28,7,a,b,c,d,e,l,g);

    printf("\n\t\t\t");
    x=getch();
   if(x=='1') Linear();
    if(x=='3') regression();
    if(x=='2') polynomial();
    if(x=='7') goto Y;
    goto X;
    Y:
    return 0;
}

void menu(int n,int m,char*a,char*b,char*c,char*d,char*e,char*g,char*h){
    char f[58];
    int i,j,k;
    for(i=0;i<57;i++){
        f[i]='\xec';
    }
    f[57]=0;
    for(i=0;i<=(3*m+1);i++){
            k=0;
        printf("\n");
        for(j=0;j<n;j++) printf(" ");
        for(j=0;j<=60;j++){

            if(j==0 || i==0 || j==60 || i==(3*m+1)) printf("\xdc");
            else if( i<(3*m) && j==2 &&k==0 ) {
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
                case 18:  printf("%s",f);
                        j+=strlen(f);
                        break;
                  case 20 : printf("%s",h);
                        j+=strlen(h);
                         break;
                 }


            }
            else printf(" ");
        }

    }
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

