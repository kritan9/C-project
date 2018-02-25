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
    printf("\n\n");
    lineb(22,82);
    printf("\n");
    printf("\n\t\t\t->This  is  a  mini-project  developed  by  a  group  of  undergraduates \n\t\t\t  studying  Computer  Engineering  in   Pulchowk  Campus .  This  project\n\t\t\t  is  basically  a   calculator  that  solves  complex  problems  regarding \n\t\t\t  solving  equations ,  data  analysis  and  few  matrix  problems .\n\t\t\t\n\t\t\t-> This program has been developed in C language.\n\n");
     lineb(22,82);
    printf("\n\n\n");
    lineb(45,25);
    printf("\n"); line(50,0);
    printf("Our Core Team\n"); lineb(45,25);

    strcpy(a[0].s,"->Aman Kumar Gupta   (074BCT503) ");
    strcpy(a[1].s,"->Kritan Banstola    (074BCT516) ");
    strcpy(a[2].s,"->Prabin Lamichhane  (074BCT523) ");
    menu(28,60,3,a);

   printf("\n");
    getch();
}
