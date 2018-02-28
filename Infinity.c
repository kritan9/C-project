#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "menu.h"
#include "Factors.h"
#include "properfraction.h"
#include "swap.h"
#include "LinearEquation.h"
#include "regression.h"
#include "polynomial.h"
#include "history.h"
#include "about.h"
#include "stat.h"
#include "matrix.h"

//This is the main program
int main(){
    system("mode con: cols=120 lines=80");
    int i,j,k,ar=0;
    char x;
    menustr a[7];
    strcpy(a[0].s," 1. Infinite Linear Equation Solver ");
    strcpy(a[1].s," 2. Infinite Polynomial Equation Solver ");
    strcpy(a[2].s," 3. Correlation And Equation Of Best fit Line ");
    strcpy(a[3].s," 4. Data Analysis (Standard Deviation And Error)  ");
    strcpy(a[4].s," 5. Matrix Problems ");
    strcpy(a[5].s," 6. About");
    strcpy(a[6].s," 7. Exit");


X:
    system("title Project Infinity ( Equation Solver, Data Analyzer And Matrix Solver)");
    system("color F0");
    system("cls");
    infinity(50);
     printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tSelect an Option\n");
    menu(28,60,7,a,ar);


    printf("\n\t\t\t");
    x=arrow(&ar,7);

    if(x=='1') Linear();
    else if(x=='3') regression();
    else if(x=='2') polynomial();
    else if(x=='7') goto Y;
    else if(x=='6') about();
    else if(x=='4') sd();
    else if(x=='5') mat();

    goto X;
    Y:
    return 0;
}

