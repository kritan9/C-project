#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "menu.h"
#include "Factors.h"
#include "properfraction.h"
#include "det.h"
#include "swap.h"
#include "LinearEquation.h"
#include "regression.h"
#include "polynomial.h"



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

