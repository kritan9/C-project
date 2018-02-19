#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float fx(float x,float *c,float *p,int n);
void main(){
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
        if((fx(r,c,p,n)<0.000000000001 && fx(r,c,p,n)>-0.000000000001)||(r==xn(r))){
            j=0;
        }else{
        r=xn(r);
        }
        if(i==100){
            printf("\nReal root doesn't exist.");
            j=0;
        }
    }
    printf("\nroot :- %.2f",r);
}
    for(int i=-1000;i<=1000;i++){

    }
}
float fx(float x,float *c,float *p,int n){
        float y=0;
        for(int i=0;i<n;i++){
            y+=((*(c+i))*pow(x,(*(p+i))));
        }
        return y;
}

