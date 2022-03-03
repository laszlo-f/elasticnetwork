//repositions the particles repetedly until positions converge
//for outputing force each iteration
int iterate(vector<particle *> * film,long double h){

	unsigned int i,count=0;
	long double conv=100,oconv=10000;

	for(i=0;i<film->size();i++){//repositions the particles
		(*film)[i]->reposition();
	}
	/*
	for(i=0;i<film->size();i++){//check for and fix collisions
		(*film)[i]->cdet();
	}
	*/

	while(conv > h/10000000000.0){//check for convergence
		for(i=0;i<film->size();i++){
			(*film)[i]->reset();
		}//prepare for an iteration

		for(i=0;i<film->size();i++){
			(*film)[i]->reposition();
		}//reposition particles
		for(i=0;i<film->size();i++){//check for and fix collisions
			(*film)[i]->cdet();
		}


		oconv=conv;//reset old convergence
		conv=convergence(*film);//compute how much particles moved

		//track the number of iterations
		if(oconv<=conv){
			count++;
		}
	}

	//clean up
	for(i=0;i<film->size();i++){
		(*film)[i]->reset();
	}
	
	return 0;
}
