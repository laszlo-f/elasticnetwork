//uniform distribution
long double uni(long double a, long double b){
	return a+(b-a)*drand48();
}

//triangular distribution
//see p. 5 of lab notebook.
long double tri(long double a, long double b){
	if(a==b){
		return a;
	}
	if(b<a){
		cout <<"Warning:  b<a in tri"<<endl;
	}
	long double un=drand48();
	if(un<.5){
		return a+(b-a)*sqrtl(2*un)/2;
	} 
	//else 
	return  b-(b-a)*sqrtl(2*(1-un))/2;
}
