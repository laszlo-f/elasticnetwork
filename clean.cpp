//clean by deleteing particles that are only attached to fixed particles
//and particles that are not attached to anything

int clean(vector<particle*>* list){
	vector<particle*>::iterator begining=list->begin();
	for(unsigned int i=0;i<list->size();i++){
		//while is necessary because after i is removed the list is renumbered.
		while(((*list)[i]->toclean())&&(i<list->size())){
			//make sure attached particles are fixed
			delete (*list)[i];//delete it
			list->erase(begining+i);
			//remove it from the vector
			//this bit is slow
		}

		//loop does not remove a particle every time
	}


	return 0;
}
