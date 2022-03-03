//Scale up the constants so they are proportional to the interparticle 
//distance

long double unstrecher(long double prestr,long double radius1,long double radius2,long double gap){
	long double newdist=1;

	//Klara pg. 12
	//const long double diameter=.000000006;
	//const long double gap=.0000000012;
	//
	//
	long double ratio=newdist/(radius1+radius2+gap);


	long double newradius1=ratio*radius1;
	long double newradius2=ratio*radius2;

	//Klara p. 50
	long double newunstr=  newdist/(prestr+1)-newradius1-newradius2;

	if(newunstr<=0){
		cout <<"Nonpositive unstreched length! "<<prestr<<" "<<radius1<<" "<<radius2<<endl;
		exit(465);
	}
	if((prestr==0)&&(newunstr+newradius1+newradius2 != 1)){
		cout << "Warning:  failure on zero prestrain, recomputing." << endl;
		return 1-newradius1-newradius2;
	}

	return newunstr;
}

long double rscale(long double radius1,long double radius2,long double gap){
	long double newdist=1;
	
	long double ratio=newdist/(radius1+radius2+gap);


	return ratio*radius1;
}
