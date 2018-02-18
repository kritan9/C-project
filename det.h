

int det(int n,int y,double *var){

   int i,j,k;
   double l,m;
   double z;
   int r,t;
   int o=0;int p;
   double q=1;
	    double d=1,x=1;
        i=0; j=0;

while(i<(y-1)){
    k=1;p=1;
    while(k<(y-i)){
             if(*(var+i*n+i)==0){
                if(p==(y-i)){
                printf("Infinite or Undefined Solution \n");
                return 111111;
                }
                for(o=0;o<y;o++){

                    swap(var+i*n+o,var+(i+p)*n+o);

                }
                p++; continue;
            }


             l=LCM(*(var+i*n+k*n+i),*(var+i*n+i));
          l=l/ *(var+i*n+i);
          m=l* *(var+i*n+i)/ *(var+i*n+k*n+i);
            x=x*l*m;
            j=i;

        while(j<y){
               *(var+i*n+j)*=l;
                *(var+i*n+j+k*n) = *(var+i*n+j+k*n)*m-(*(var+i*n+j));
                j++;
              }
              k++;
    }
    i++;
}
    for(k=0;k<y;k++){

            d=d* *(var+k*n+k);

    }


	return (int)(d/x);


}

