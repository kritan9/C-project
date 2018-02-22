#include<stdio.h>
#include "menu.h"
void main(){
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    menustr a22[2];
    strcpy(a22[0].s,"This is a demo version.");
    strcpy(a22[1].s,"Please support the developers by buying the software.");
    menu(28,60,2,a22);

}
