void logo(char x){
    if(x=='l') logolinear();
    else if(x=='p') logopoly();
   else if(x=='m') logomat();
    else if(x=='s') logostat();
    else if(x=='r') logoreg();

}

void fpos(FILE *fptr,int n,int m,int page,char x){ //display history for given page
        char ch;
        switch(x){
           case 'l':
            fptr=fopen("Linear.txt","r");
            break;

            case 'p':
            fptr=fopen("polynomial.txt","r");
            break;

            case 'r':
            fptr=fopen("regression.txt","r");
            break;

            case 'm':
            fptr=fopen("matrix.txt","r");
            break;

            case 's':
            fptr=fopen("statistics.txt","r");
            break;

        }
        fseek(fptr,-1,2); //current just before
        int i=0,j=0,k;
        k=ftell(fptr);

            while(j<(page*n+m)){
                    fseek(fptr,k,0);
                if((ch=fgetc(fptr))=='~') j++;
                k--;
            }
            if(m!=0) n=m;
       while(1){
            ch=fgetc(fptr);
            if(ch==EOF){ break;}
            if(ch=='~'){ i++;
                if(i>=n) break;
            }
            else  printf("%c",ch);


       }
       fclose(fptr);

}
int fpage(FILE *fptr,char x){ //number of pages
     char ch;
     int i=0;
         switch(x){
           case 'l':
            fptr=fopen("Linear.txt","r");
            break;

            case 'p':
            fptr=fopen("polynomial.txt","r");
            break;

            case 'r':
            fptr=fopen("regression.txt","r");
            break;

            case 'm':
            fptr=fopen("matrix.txt","r");
            break;

            case 's':
            fptr=fopen("statistics.txt","r");
            break;

        }
        fseek(fptr,0,0); //current at beginning
         while(1){
            ch=fgetc(fptr);
            if(ch=='~') i++;
            if(ch==EOF) break;

         }
         fclose(fptr);
    return i;
}

void history(FILE *fptr,char x){
    char fic;
    int fi=0,i=0,j;
       fi=fpage(fptr,x);
       j=fi%5;
       fi/=5;
        while(1){
       if(fi==0 && j==0){
       logo(x);
        printf("\t\t\t\t\t\tNo History\n\t\t\t\t\tPress any key to go back");
        getch();
        break;
       }
       else if(fi==0){
             logo(x);
             lineb(15,90); printf("\n");line(15,0);
            printf("Back to menu-> Press any key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            fpos(fptr,5,j,fi,x);
              fic=getch();
             break;
       }


      else if(i==0){
        logo(x);
        lineb(15,90); printf("\n");line(15,0);
        printf("Next page->Press + \n");
        lineb(15,90); printf("\n"); lineb(15,0);
        printf("Back to menu-> any other key\n");
        lineb(15,90); printf("\n"); line(15,0);
        printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
        fpos(fptr,5,0,i+1,x);
        fic=getch();
       if(fic=='+') i++;
       else break;
       }
       if(i<(fi-1)){
           logo(x);
            lineb(15,90); printf("\n");line(15,0);
            printf(" Next page->Press + \n\t\tPrevious page->Press -\n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            fpos(fptr,5,0,i+1,x);
              fic=getch();
            if(fic=='+') i++;
            else if(fic=='-') i--;
            else break;
       }
    if(i==(fi-1)) {
           logo(x);
             lineb(15,90); printf("\n");line(15,0);
             if(j!=0) printf(" Next page->Press + \n\t\t");
            printf("Previous page->Press - \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            fpos(fptr,5,0,i+1,x);
              fic=getch();
            if(fic=='-') i--;
            else if (j!=0 && fic=='+') i++;
            else break;
       }
       if(i==fi && j!=0){
             logo(x);
             lineb(15,90); printf("\n");line(15,0);
            printf("Previous page->Press - \n");
            lineb(15,90); printf("\n");     line(15,0);
            printf("Back to menu-> any other key\n");
             lineb(15,90); printf("\n"); line(15,0);
            printf("Page %d of %d\n",i+1,j==0? fi:fi+1);
            fpos(fptr,5,j,fi,x);
              fic=getch();
            if(fic=='-') i--;
            else break;
       }
        }



}
