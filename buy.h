void buy(){
    system("cls");
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------");
    menustr a22[3];
    strcpy(a22[0].s,"This is a demo version.");
    strcpy(a22[1].s,"Features are limited. Honestly best parts are not included.");
    strcpy(a22[2].s,"Please support the developers by buying the software.");
    menu(28,65,3,a22);
    getch();
}
