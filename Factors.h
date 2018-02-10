//Finding HCF and LCM
double HCF(double a,double b){
	double c;
	while(a!=0){
		c=(int)b%((int)a);
		b=a;
		a=(double)c;
	}
	return b;
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
