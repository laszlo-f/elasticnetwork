//calculates z direction force on a particle recursively.  
//only run once per iteration
//
//Really this should only be used for films with a single height minimum
const long double particle::force(){
	if(!afm){//if this particle does not touch the AFM it should have no role in computing the force.
		return 0;
	}

	long double intermediate=0;//temporary variable

	for(unsigned int i=0;i<ligands.size();i++){

		//distance, with unstretched length removed.
		//multiplied by spring constant
			
		if(//avoid division by zero
			((ligands[i]->other(this))->position()[0]-this->position()[0])*((ligands[i]->other(this))->position()[0]-this->position()[0])
			+((ligands[i]->other(this))->position()[1]-this->position()[1])*((ligands[i]->other(this))->position()[1]-this->position()[1])
			+((ligands[i]->other(this))->position()[2]-this->position()[2])*((ligands[i]->other(this))->position()[2]-this->position()[2])
			==0
		){
			cout <<"distance between particles should be nonzero" << endl;
			exit(-34);
		} else if(!(ligands[i]->other(this))->getfixed()){
		//only count the ligand if its other end is unfixed.
		//should be synonymous with ignoring ligands to other particles touching the AFM
		//at least until the "sliding tip" code is written

			//force should be positive
			// by assumption that the AFM tip 
			// is below the other particle
			intermediate+=
fabsl(ligands[i]->getk()//spring constant
*(//times streched length
	(ligands[i]->other(this))->position()[2]-this->position()[2]
	//z length
	//
	//minus unstreched length
	-ligands[i]->getunstretch()
	//times cosine, which is z over total length
	*((ligands[i]->other(this))->position()[2]- (position()[2])) //z
	/sqrtl(//divide by total length
		 ((ligands[i]->other(this))->position()[0]-this->position()[0])
		*((ligands[i]->other(this))->position()[0]-this->position()[0])
		//x^2
		+((ligands[i]->other(this))->position()[1]-this->position()[1])
		*((ligands[i]->other(this))->position()[1]-this->position()[1])
		//y^2
		+((ligands[i]->other(this))->position()[2]-this->position()[2])
		*((ligands[i]->other(this))->position()[2]-this->position()[2])
		//z^2
	)
));
		}
	}
	return intermediate; 
}
