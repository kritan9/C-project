//Finding HCF and LCM
double HCF(double a,double b){
	long long int c;
	while(a!=0 && b!=0){
		c=(long long int)round(b)%(long long int)(round(a));
		b=a;
		a=(double)c;
	}

	return (compare(b,0)==0)? 1 : b;
}

double LCM(double a,double b){

	double d=a,e=b;
	long long int c;


	while(a!=0){
		c=(long long int)b%((long long int)a);
		b=a;
		a=(double)c;
	}
	return d*e/b;
}
