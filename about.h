void about(){
    system("cls");
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------\n\n");
    menustr a[3];
    strcpy(a[0].s,"About the Project and Developers");
    menu(28,60,1,a);
    printf("\n");
    lineb(45,25);
    printf("\n"); line(50,0);
    printf("Our Core Team\n"); lineb(45,25);

    strcpy(a[0].s,"->Aman Kumar Gupta   (074BCT503) ");
    strcpy(a[1].s,"->Kritan Banstola    (074BCT516) ");
    strcpy(a[2].s,"->Prabin Lamichhane  (074BCT523) ");
    menu(28,60,3,a);

    //printf("\n");
    /*
    line1(24);
    printf("\n\t\t\t\tThis project is a ");
    printf("\n\t\t\t");
    printf("\n\t\t\t");
    printf("\n\t\t\t");
    printf("\n\t\t\t");
    printf("\n\t\t\t");
    printf("\n\t\t\t");*/

   printf("\n");
    getch();
}
