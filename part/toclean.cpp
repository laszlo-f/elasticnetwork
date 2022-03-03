//This function will determine if the particle is a waste of resources
//we delete particles with no ligands attached because the program won't know how to handle them
//delete particles that are fixed AND only attached to fixed particles because they can't do anything

const bool particle::toclean(){
	if(ligands.empty()){
		if(!fixed){
			cout << "Found unfixed empty ligands." << endl;
			//should not happen, but no need to panic
		}
		return true;
		//this particle is not connected to anything
	}

	if(fixed){
		for(unsigned int i=0;i<ligands.size();i++){
			if(!((ligands[i]->other(this))->getfixed())){
				return false;
				//this particle is connected to something 
				//that moves
			}
		}
		return true;//this particle is not connected to
		//anything that moves
	}

	//this particle can move
	return false;
}
