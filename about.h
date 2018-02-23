void about(){
    system("cls");
    infinity(50);
    printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\tProject:- Equation Solver, Data Analyzer And Matrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------\n\n");
    menustr a;
    strcpy(a.s,"About the Project and Developers");
    menu(28,60,1,&a);

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
    strcpy(a.s,"Contact us");
    menu(28,60,1,&a);
    printf("\n");
    line1(24);
    printf("\n\t\t\tAman Kumar Gupta");
    line2(24);
    printf("\n\t\t\tKritan Bastola \t\twww.facebook.com/kree.tan.9");
    line2(24);
    printf("\n\t\t\tPrabin Lamichhane \twww.facebook.com/prabin.lc4");
    line1(24);
    printf("\n\t\t\t");
    getch();
}
