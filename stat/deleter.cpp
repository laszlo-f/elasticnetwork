bool inlist(int temp,vector<int> * list){
	for(unsigned int i=0;i<list->size();i++){
		if(temp == (*list)[i]){
			return true;
		}
	}
	return false;
}//check to see if a number is in a list



//make a random list of unfixed particles
//so we can remove "fraction" from the provided list with deleter()
//monte carlo
vector<int> deletelist(vector<particle*>* list,long double fraction){
	vector<int>  result;
	int temp;
	//don't delete too many because we want the solution to be well defined
	if(fraction>=.95){
		cout << "Fraction size too big in deletelist."<<endl;
		exit(3243);
	}

	unsigned int unfixed=0;
	for(unsigned int i=0;i < list->size();i++){
		if((*list)[i]->getfixed()==false){
			unfixed++;
		}
	}//computes number of unfixed particles


	unsigned int number=(unsigned int)(unfixed*fraction);  
	//decide how many to delete.

	for(unsigned int i=0;i<number;i++){
		temp= rand()%(list->size());
		while((inlist(temp,&result))||((*list)[temp]->getfixed())){
			temp= rand()%(list->size());
		}//do not  pick the same number twice
		//do not pick fixed particles
		//slow
			
		result.push_back(temp);
		//pick a particle at random
	}

	if(result.size()!=number){
		cout << "random number list is wrong length" << endl;
		exit(78989);
	}

	sort(result.begin(),result.end());//get in correct order for deleter()
	return result;

}

//this version of deletelist only removes particles within a certain range of distances from the center
vector<int> deletelist(vector<particle*>* list,long double fraction,unsigned int sl,long double start,long double end){
	vector<int>  result;
	int temp;
	//don't delete too many because we want the solution to be well defined
	if(fraction>=.95){
		cout << "Fraction size too big in deletelist."<<endl;
		exit(3243);
	}

	if(start<0){
		cout << "Start negative." << endl;
		exit(756);
	}
	if(end<0){
		cout << "end negative." << endl;
		exit(756);
	}
	if(start>end){
		cout << "Start bigger than end." << endl;
		exit(756);
	}
	unsigned int unfixed=0;
	for(unsigned int i=0;i < list->size();i++){
		if(
			((*list)[i]->getfixed()==false)
			&&(start<(*list)[i]->fromcenter(sl))
			&&(end>(*list)[i]->fromcenter(sl))
		){
			unfixed++;
		}
	}//computes number of unfixed particles that are within the range


	unsigned int number=(unsigned int)(unfixed*fraction);  
	//decide how many to delete.
	
	if((fraction!=0) && (number==0)){
		cout << "Warning:  fraction is nonzero but number is not!" << endl;
	}

	for(unsigned int i=0;i<number;i++){
		temp= rand()%(list->size());
		while(
			(!(
				(start<(*list)[temp]->fromcenter(sl))
				&&(end>(*list)[temp]->fromcenter(sl))
			))//not in range
			
			||(
				(inlist(temp,&result))//already taken
				||((*list)[temp]->getfixed())//fixed
			)
		){
			temp= rand()%(list->size());
		}//do not  pick the same number twice
		//do not pick fixed particles
		//do not pick particles that are out of range
		//slow
			
		result.push_back(temp);
		//pick a particle at random
	}

	if(result.size()!=number){
		cout << "random number list is wrong length" << endl;
		exit(78989);
	}

	sort(result.begin(),result.end());//get in correct order for deleter()
	return result;

}

//this function deletes random unfixed particles named in the list
int deleter(vector<particle*>* list,vector<int> *  deletelist){
	for(int i=deletelist->size()-1; i>=0; i--){
		if((*list)[(*deletelist)[i]]->getfixed()){
			cout << "tried to delete fixed particle" << endl;
			exit(666);
		}

		if((i>0) && ((*deletelist)[i-1]>=(*deletelist)[i])){
			cout << "deletelist improperly sorted " << 
			(*deletelist)[i-1]<< " " << 
			(*deletelist)[i]<< endl;
			exit(666);
		}

		if(((unsigned)(*deletelist)[i])>= list->size()){
			cout << "tried to delete a number that was too big" << endl;
			exit(666);
		}
		
		if((*deletelist)[i] < 0){
			cout << "tried to delete a number that was negative" << endl;
			exit(666);
		}
		delete (*list)[(*deletelist)[i]];//delete it
		list->erase(list->begin()+(*deletelist)[i]);
		//remove it from the vector
	}


	return 0;
}

