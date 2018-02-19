#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float fx(float x,float *c,float *p,int n);
void main(){
    int ic=0;
    int n;
    printf("Enter the number of terms in the function:- ");
    scanf("%d",&n);
    float *c=calloc(n+1,sizeof(float));
    float *p=calloc(n+1,sizeof(float));
    printf("\nEnter coefficient and power as shown below:-\neg: for\n2x^4 \ntype 2 4\n[NOTE:-2(space)4].\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",c+i,p+i);
    }
    float *c1=calloc(n,sizeof(float));
    float *p1=calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        if(p[i]==0){p1[i]=0;c1[i]=0;}
        else{
            c1[i]=c[i]*p[i];
            p1[i]=p[i]-1;
        }

    }
    float xn(float r){
    return (r-(fx(r,c,p,n)/fx(r,c1,p1,n)));
    }
    printf("\nf(x)=");
    for(int i=0;i<n;i++){

        printf("(%c%.2f)x(%c%.2f) ",((c[i]<0)?' ':'+'),c[i],(c[i],(p[i]<0)?' ':'+'),p[i]);

    }
    printf("\nf'(x)=");
    for(int i=0;i<n;i++){
        printf("%.2fx%.2f",c1[i],p1[i]);
    }
    float root(float r){
        int j=1;
        for(int i=0;j;i++){
            if((xn(r)-r)<0.0000001 && (xn(r)-r)>-0.0000001){
                j=0;
            }
            r=xn(r);
            printf("\n%f",r);
            if(i==150){
                r=1010;
                j=0;
            }
        }
    return r;
    }
    int chk;
    if(fx(-1000,c1,p1,n)<0){
        chk=0;
    }
    else if(fx(-1000,c1,p1,n)>0){
        chk=1;
    }
    int chk1;
    int co=0;
    float rts[20];
    for(int i=-1000;i<=1000;i++){
        chk1=chk;
        if(fx(i,c1,p1,n)<0){
            chk=1;
        }
        else if(fx(i,c1,p1,n)>0){
            chk=0;
        }
        if(chk1!=chk){
            float r=root((float) i);
            if(r==1010){
                ic=1;
            }
            else{
                for(int z=0;z<=co;z++){
                    if(((rts[z]-r)<0.001 && (rts[z]-r)>-0.001)){
                        z=co+1;
                    }
                    else{
                        if(z==co){
                            rts[z]=r;
                        }
                    }
                }
                printf("%d",co);
                co++;
            }
        }
    }
    for(int i=0;rts[i]!='\0';i++){
        printf("\n%f",rts[i]);
        if(ic){
            printf("Some roots doesn't exist.");
        }
    }
}
float fx(float x,float *c,float *p,int n){
        float y=0;
        for(int i=0;i<n;i++){
            y+=((*(c+i))*pow(x,(*(p+i))));
        }
        return y;
}

