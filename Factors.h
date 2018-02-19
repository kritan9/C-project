//Finding HCF and LCM
double HCF(double a,double b){
	double c;
	if((int)round(a)==0) return 1;
	if((int)round(b)==0) return 1;
	while(a!=0 && b!=0){
		c=(int)round(b)%(int)(round(a));
		b=a;
		a=(double)c;
	}

	return (b==0)? 1 : b;
}

double LCM(double a,double b){

	double d=a,e=b;
	int c;


	while(a!=0){
		c=(int)b%((int)a);
		b=a;
		a=(double)c;
	}
	return d*e/b;
}
