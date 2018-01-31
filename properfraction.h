

void pfraction(int *a,int *b){
	int c,n=*a,d=*b;
	while(a!=0){
		c=(*b)%(*a);
		*b=*a;
		*a=c;
	}
	*a=n/(*b);
	*b=d/(*b);
}
