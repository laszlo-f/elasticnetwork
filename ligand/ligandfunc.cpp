//this function will tell a particle where the other end of this ligand is
particle * ligand::other( particle * thisp){
	if((thisp==end)&&(thisp!=otherend)){
		return otherend;
	} else if((thisp!=end)&&(thisp==otherend)){
		return end;
	} else {

	//should never get here
		cout << "particles not attached to this ligand should not access it." << endl
		<< "Location of particle that attempted to do so:  " 
		<< thisp->position()[0] << " " 
		<< thisp->position()[1] << " " 
		<< thisp->position()[2] << " "
		<< endl;
		exit(-1);
	}
}

//get unstreched center to center distance
//used in particle::reposition()
const long double ligand::getunstretch(){
	return unstretch;
}//this preserves privateness

//get spring constant
//used in particle::reposition()
const long double ligand::getk(){
	return k;
}//this preserves privateness


