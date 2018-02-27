
//options in main menu
typedef struct {
    char s[150];
} menustr;

char arrow(int *ar,int n){
    char x,y;
    x=getch();
    if(x==-32){
      y=getch();
      if(y==72){
            if(*ar==0) {*ar=n;}
            *ar=(*ar-1)%n;}
      else if(y==80) *ar=(*ar+1)%n;
      return 255;
    }
    else {
     if(x==13) x='1'+*ar;
       return x;
    }

}


//main menu table
void menu(int n,int o,int m,menustr *a,int ar){  //x coordinate, width, no of Options, structure
    char f[o-2];
    int i,j,k,l=0;
    for(i=0;i<(o-3);i++){
        f[i]='\xec';
    }
    f[o-3]=0;
    for(i=0;i<=(3*m+1);i++){
            k=0;
        printf("\n");
        for(j=0;j<n;j++) printf(" ");
        for(j=0;j<=o;j++){

            if(j==0 || i==0 || j==o || i==(3*m+1)) printf("\xdc");
            else if( i<(3*m) && j==2 &&k==0 ) {
                 k=1;j-=1;
                if(i%3==0){ printf("%s",f);
                            j+=strlen(f);
                }
                if(i%3==2){
                        if(ar!=l) printf("   %s",a[l].s);
                        else printf(">>>%s",a[l].s);
                            j+=(3+strlen(a[l].s));
                            l++;
                            }



            }
            else printf(" ");
        }

    }
    printf("\n");
}

void line(int a,int b){
    int i;
    for(i=0;i<(a+b);i++){
        if(i<a) printf(" ");
        else printf("\xdc");
    }
}
void lineb(int a,int b){
    int i;
    for(i=0;i<(a+b);i++){
        if(i<a) printf(" ");
        else printf("\xec");
    }
}

void linef(int a,int b,FILE *fptr){
    fprintf(fptr,"\n");
    int i;
    for(i=0;i<(a+b);i++){
        if(i<a) fprintf(fptr," ");
        else fprintf(fptr,"-");
    }
    fprintf(fptr,"\n");
}

//Infinity Logo
 void infinity(int n){
        int i,j,k;
        for(i=0;i<=6;i++){
            printf("\n");
            for(k=0;k<n;k++) printf(" ");
            for(j=0;j<=14;j++){
                if(((i+j)>=3 && (i-j)>=-4 && (i+j)<=10 && (i-j)<=3 )||((i+j)>=10 && (i-j)<=-4 && (i+j)<=17 && (i-j)>=-11 )) printf("\xdd");
                else printf(" ");
            }

        }
        printf("\n");

 }

 void line2(int n){
    int c=1;
    printf("\n");
    while(c<94){
        if(c<=n){printf(" ");}
        else{printf("\xec");}
        c++;
    }
    printf("\n");
 }
void line1(int n){
    int c=1;
    printf("\n");
    while(c<94){
        if(c<=n){printf(" ");}
        else{printf("\xdc");}
        c++;
    }
    printf("\n");
 }



