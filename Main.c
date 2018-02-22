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
#include "buy.h"
#include "about.h"


int main(){
    int i,j,k;
    char x;
    menustr a[7];
    strcpy(a[0].s," 1. Infinite Linear Equation Solver ");
    strcpy(a[1].s," 2. Infinite Polynomial Equation Solver ");
    strcpy(a[2].s," 3. Correlation And Equation Of Best fit Line ");
    strcpy(a[3].s," 4. Data Analysis (Standard Deviation And Error)  ");
    strcpy(a[4].s," 5. Welcome to Matrix");
    strcpy(a[5].s," 6.About");
    strcpy(a[6].s," 7.Exit");


X:
    system("cls");
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\tSelect an Option\n");
    menu(28,60,7,a);


    printf("\n\t\t\t");
    x=getch();
   if(x=='1') Linear();
    if(x=='3') regression();
    if(x=='2') polynomial();
    if(x=='4') buy();
    if(x=='5') buy();
    if(x=='6') about();
    if(x=='7') goto Y;
    goto X;
    Y:
    return 0;
}

