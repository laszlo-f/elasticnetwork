//adds up how much all the particles have moved 
//handy for guessing if the program has converged to the solution
//
//Run after repostion and before reset.

long double convergence(vector<particle *> film){
	long double result=0;
	for(unsigned int i=0;i<film.size();i++){//goes through all the particles

		//check to be sure this is being run at the correct time
		if(!film[i]->getrepositioned()){
			cout << "convergence(vecotor<particle>) not run between reposition() and reset() on particle "<<i<< endl;
			exit(-124);
		}

		//add on the movement
		result+=film[i]->movement();
	}
	return result;
}
