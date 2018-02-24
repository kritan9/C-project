void logomat(){

    system("cls");
   infinity(50);
   printf("\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tWELCOME TO INFINITY\n");
    printf("\t\t\t\t\t\tMatrix Solver\n");
    printf("\t\t-----------------------------------------------------------------------------------\n");


}

double determinant(double matrix[20][20], int k){
               double deter=0.0, z=1.0, mt[20][20];
               int a, b, c, x, y;
               if(k==1)
               {
               return(matrix[0][0]);
               }
               else
               {
               deter=0;
               for(a=0;a<k;++a){
               x=0;
               y=0;
               for(b=0;b<k;++b){
               for(c=0;c<k;++c){
               mt[b][c]=0;
               if((b != 0) && (c != a))
               {
               mt[x][y]=matrix[b][c];
               if(y<(k-2))
               y++;
               else
               {
               y=0;
               x++;
               }
               }
               }
               }
               deter=deter + z * (matrix[0][a] * determinant(mt,k-1));
               z=-1 * z;
               }
               }
               return(deter);
               }
void cofac(double comatr[20][20], int f, FILE *fptr){
               double matr[20][20], cofact[20][20];
               int a, b, c, d, x, y;
               for(c=0; c<f; ++c){
               for(d=0; d<f; ++d){
               x=0;
               y=0;
               for(a=0;a<f; ++a){
               for(b=0; b<f; ++b){
               if(a != c && b != d)
               {
               matr[x][y]=comatr[a][b];
               if(y<(f-2))
               y++;
               else
               {
               y=0;
               x++;
               }
               }
               }
               }
               cofact[c][d] = pow(-1,c + d) * determinant(matr,f-1);
               }
               }
               trans(comatr, cofact, f);
               }
void trans(double matr[20][20], double m1[20][20], int r,FILE *fptr){
              double inv_matrix[20][20], tran[20][20], d;
              int a,b;

              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              tran[a][b]=m1[b][a];
              }
              }
              d=determinant(matr, r);
              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              inv_matrix[a][b]=tran[a][b] / d;
              }
              }
              fptr=fopen("matrix.txt","a+");
              printf("\n"); line(15,90); printf("\n"); line(15,0);
              printf("The Inverse of matrix is . . . ");
               printf("\n"); line(15,90); printf("\n");
               fprintf(fptr,"\n\n\t\t\t The Inverse of matrix is . . . \n");
              for(a=0;a<r;++a){
                    fprintf(fptr,"\n\n\t\t\t");
                     line(15,0);
              for(b=0;b<r;++b){
              printf("% 10.4lf", inv_matrix[a][b]);
              fprintf(fptr," %10.3lf", inv_matrix[a][b]);
              }
              printf("\n\n");

              }
              line(15,90);
              fprintf(fptr,"\n");linef(15,90,fptr);  fprintf(fptr,"\n\n");
              fclose(fptr);
              }


void mat(){
    char op;
    FILE *fptr;
    int z,y;
    int d,r,c;
    menustr mn[5];
    double ask[20][20],transposed[20][20];
    double matrix[20][20], deter;
    int a, b, odr;
    int i, j;
    strcpy(mn[0].s,"1.Determinant And Inverse");
    strcpy(mn[1].s,"2.Transpose");
    strcpy(mn[2].s,"3.History");
    strcpy(mn[3].s,"4.Back");

    B:
    logomat();
     printf("\n\n");
     printf("\t\t\t\t\t\tSelect an Option\n");
     menu(35,40,4,mn);
    op=getch();
    if(op=='4'){goto EOP;}
    else if(op=='1'){goto DET;}
     else if(op=='2'){goto TRAN;}
    else if(op=='3'){goto fileworks;}
    else{goto B;}

   DET:
                logomat();
                fptr=fopen("matrix.txt","a+");
                lineb(15,90);
                printf("\n"); line(15,0);
                printf("Enter the order of matrix whose inverse you want to find.\n");
                lineb(15,90);
                printf("\n");
                line(15,0);
                scanf("%d", &odr);
                lineb(15,90);
                printf("\n"); line(15,0);
                printf("Enter the elements of %d X %d matrix : \n", odr ,odr);
                lineb(15,90);
                printf("\n"); line(15,0);
                //taking input of matrix
                for(a=0;a<odr;++a){
                for(b=0;b<odr;++b){
                printf("Input for matrix[%d][%d]",a+1,b+1);
                scanf("%lf",&matrix[a][b]);
                line(15,0);
                }
                }
                printf("\n\n");
                fprintf(fptr,"~");
               deter = determinant(matrix, odr);
                lineb(15,90);
                printf("\n");
                line(15,0);
                 printf("Entered Matrix is\n");
                 lineb(15,90);
                 fprintf(fptr,"\t\tEntered Matrix is\n");
                for(z=0;z<odr;z++)
                    {
                        fprintf(fptr,"\n\t\t\t");
                        printf("\n"); line(15,0);
                        for(y=0;y<odr;y++)
                            {
                                printf(" %10.2lf ",matrix[z][y]);
                                fprintf(fptr," %10.2lf ",matrix[z][y]);
                                }
                        }
                        fprintf(fptr,"\n\n");
                printf("\n\n");line(15,90); printf("\n"); line(15,0);
               printf("The Determinant of the Matrix is : %.2lf\n", deter);
               line(15,90); printf("\n");
               fprintf(fptr,"\t\t\tThe Determinant of the Matrix is : %.2lf\n", deter);

               fclose(fptr);
               if(compare(deter,0.0)==0){
                   printf("\n");
                    lineb(15,90);
               printf(" Inverse of Matrix is not possible for the matrices having 0 Determinant value !!\n");
               lineb(15,90);
                printf("\n"); line(15,0); printf("Press any key!\n");
                lineb(15,90);
                getch(); goto B;
               }
               else{
               cofac(matrix, odr,fptr);
                printf("\n");
            lineb(15,90); printf("\n");line(15,0);
            printf("Want to find Det. and Inv. of another matrix?->Press y \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Menu-> any other key\n");
            lineb(15,90); printf("\n");
            op=getch();
            if(op=='y' || op=='Y') goto DET;
            else goto B;
               }





    TRAN:
        logomat();
                fptr=fopen("matrix.txt","a+");
                lineb(15,90);
                printf("\n"); line(15,0);
    printf("Enter rows and columns of matrix: \n");
    lineb(15,90);printf("\n"); line(15,0);
    scanf("%d %d", &r, &c);
    printf("\n\n"); lineb(15,90); printf("\n"); line(15,0);

    // Storing elements of the matrix
    printf("Enter elements of matrix:\n");
    lineb(15,90);printf("\n");
    for(z=0; z<r; ++z)
        for(y=0; y<c; ++y)
        {
            line(15,0);
            printf("Enter element a[%d][%d]: ",z+1, y+1);
            scanf("%lf", &ask[z][y]);
        }
    printf("\n\n");
    lineb(15,90);printf("\n"); lineb(15,0);
    fprintf(fptr,"~\t\t");
    // Displaying the matrix a[][] */
    printf("Entered Matrix is:\n");
    lineb(15,90);printf("\n");

    fprintf(fptr,"Entered Matrix is:");

    for(z=0; z<r; ++z){
            fprintf(fptr,"\n\n\t\t\t"); lineb(15,0);
        for(y=0; y<c; ++y)
        {
            printf("% 10.2lf  ", ask[z][y]);
            fprintf(fptr,"% 10.2lf  ", ask[z][y]);
            if (y == c-1)
                printf("\n\n");
        }
    }

    for(z=0; z<r; ++z)
        for(y=0; y<c; ++y)
        {
            transposed[y][z] = ask[z][y];
        }
    fprintf(fptr,"\n\n\t\t\t");
    line(15,90); printf("\n"); line(15,0);
    fprintf(fptr,"Transpose of Matrix is:\n");
    printf("Transpose of Matrix is:\n");
    line(15,90); printf("\n\n");
    for(z=0; z<c; ++z){
            fprintf(fptr,"\n\n\t\t\t"); line(15,0);
        for(y=0; y<r; ++y)
        {
            printf("% 10.2lf  ",transposed[z][y]);
            fprintf(fptr,"% 10.2lf  ",transposed[z][y]);
            if(y==r-1)
                printf("\n\n");
        }}
        fprintf(fptr,"\n");  linef(15,90,fptr);  fprintf(fptr,"\n\n");
        line(15,90);
        printf("\n\n");
            fclose(fptr);
            lineb(15,90); printf("\n");line(15,0);
            printf("Want to find Transpose of another matrix?->Press y \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Menu-> any other key\n");
            lineb(15,90); printf("\n");
            op=getch();
            if(op=='y' || op=='Y') goto TRAN;
            else goto B;



        fileworks:
        history(fptr,'m');
        goto B;


        EOP:             //end of program
       printf("");
}




