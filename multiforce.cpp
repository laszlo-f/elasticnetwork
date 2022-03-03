//compute the force on a bunch of particles
long double multiforce(vector<particle *>* list){
	long double sum=0;
	for(unsigned int i=0;i<list->size();i++){
		sum+= (*list)[i]->force();
	}
	return sum;
}
