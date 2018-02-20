#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "determinant.h"


float determin(float matrix[20][20],int k);
void cofac(float comatr[20][20], int f);
void trans(float matr[20][20], float m1[20][20], int r);


int main(){
    char get;
    int z,y;
    int odr,d,r,c;
    int ask[20][20],transposed[20][20];
    float matrix[20][20], deter;
    int a, b, row, col;
    int i, j;
    A:
    printf("Please select the operation you want to perform.\n");
    printf("\t1.\t DETERMINANT\n");
    printf("\t2.\t INVERSE\n");
    printf("\t3.\t TRANSPOSE\n");
    get=getch();
    switch(get){
    case '1':
        printf("\n\n\nEnter the order of matrix.\n");
        scanf("%d",&odr);
        printf("Enter the elements of the matrix.\n");
        for(z=1;z<=odr;z++)
        {
            for(y=1;y<=odr;y++)
            {
            printf("a[%d][%d] = ",z,y);
            scanf("%d",&ask[z][y]);
            }
        }
          printf("\n\nMatrix is\n");
  for(z=1;z<=odr;z++)
     {
          printf("\n");
          for(y=1;y<=odr;y++)
          {
               printf("\t%d \t",ask[z][y]);
          }
     }
     printf("\n\nDeterminant of Matrix is %d .\n",determinant(ask,odr));
        break;
    case '2':
                printf("Enter the order of matrix whose inverse you want to find.\nExample: for 3 X 3 oder press 3<space>3 and press enter!!\n");
                scanf("%d %d", &row, &col);
                if(row==col){
                printf("Enter the elements of %d X %d matrix : \n", row, col);
                for(a=0;a<row;++a){
                for(b=0;b<col;++b){
                printf("Input for matrix[%d][%d]",a+1,b+1);
                scanf("%f",&matrix[a][b]);
                }
                }
               deter = determin(matrix, row);
               printf("\n The Determinant of the Matrix is : %f", deter);
               if(deter == 0)
               printf("\n Inverse of Matrix is not possible for the matrices having 0 Determinant value !!\n");
               else
               cofac(matrix, row);
               }

    break;
    case '3':
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &r, &c);

    // Storing elements of the matrix
    printf("\nEnter elements of matrix:\n");
    for(z=0; z<r; ++z)
        for(y=0; y<c; ++y)
        {
            printf("Enter element a[%d][%d]: ",z+1, y+1);
            scanf("%d", &ask[z][y]);
        }

    // Displaying the matrix a[][] */
    printf("\nEntered Matrix is:\n\n");
    for(z=0; z<r; ++z)
        for(y=0; y<c; ++y)
        {
            printf("%d  ", ask[z][y]);
            if (y == c-1)
                printf("\n\n");
        }


    for(z=0; z<r; ++z)
        for(y=0; y<c; ++y)
        {
            transposed[y][z] = ask[z][y];
        }


    printf("\nTranspose of Matrix is:\n\n");
    for(z=0; z<c; ++z)
        for(y=0; y<r; ++y)
        {
            printf("%d  ",transposed[z][y]);
            if(y==r-1)
                printf("\n\n");
        }
        break;
    default:
        system("cls");
        printf("!!!Invalid Input. Please try again.!!!\n");
        goto A;
    }
return 0;
}


//this needs to be included in a different header file...


float determin(float matrix[20][20], int k){
               float deter=0.0, z=1.0, mt[20][20];
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
               deter=deter + z * (matrix[0][a] * determin(mt,k-1));
               z=-1 * z;
               }
               }
               return(deter);
               }
void cofac(float comatr[20][20], int f){
               float matr[20][20], cofact[20][20];
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
               cofact[c][d] = pow(-1,c + d) * determin(matr,f-1);
               }
               }
               trans(comatr, cofact, f);
               }
void trans(float matr[20][20], float m1[20][20], int r){
              float inv_matrix[20][20], tran[20][20], d;
              int a,b;
              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              tran[a][b]=m1[b][a];
              }
              }
              d=determin(matr, r);
              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              inv_matrix[a][b]=tran[a][b] / d;
              }
              }
              printf("\n\n\n The Inverse of matrix is . . . \n\n");
              for(a=0;a<r;++a){
              for(b=0;b<r;++b)
              printf("\t%f", inv_matrix[a][b]);
              printf("\n\n");
              }
              }
