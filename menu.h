
//options in main menu
typedef struct {
    char s[150];
} menustr;

//main menu table
void menu(int n,int o,int m,menustr *a){  //x coordinate, width, no of Options, structure
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
                if(i%3==2){printf("%s",a[l].s);
                            j+=strlen(a[l].s);
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
void line1(int a,int b){
    int i;
    for(i=0;i<(a+b);i++){
        if(i<a) printf(" ");
        else printf("\xec");
    }
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

