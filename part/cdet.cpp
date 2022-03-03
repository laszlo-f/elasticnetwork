//colision detection and repair

int particle::cdet(){
	unsigned int i=0;

	long double cut=this->getradius()+(ligands[i]->other(this))->getradius() ;
	//cutoff is the sum of the radi
	
	long double dist,x,y,z;	
	while(
		cut * cut  //sum of radi squared
	<
		//distance squared
		  (npos[0]-(ligands[i]->other(this))->nposition()[0])
		* (npos[0]-(ligands[i]->other(this))->nposition()[0])
		+ (npos[1]-(ligands[i]->other(this))->nposition()[1])
		* (npos[1]-(ligands[i]->other(this))->nposition()[1])
		+ (npos[2]-(ligands[i]->other(this))->nposition()[2])
		* (npos[2]-(ligands[i]->other(this))->nposition()[2])
	)
	{
		i++;
		if(i>=ligands.size()){//hack, avoids attempt to access nonexistant ligand
			return 0;
		}
		cut=this->getradius()+(ligands[i]->other(this))->getradius() ;
		//update cutoff
	}


	x=(ligands[i]->other(this))->nposition()[0]-npos[0];
	y=(ligands[i]->other(this))->nposition()[1]-npos[1];
	z=(ligands[i]->other(this))->nposition()[2]-npos[2];

	//square root of distance squared
	dist=sqrtl(x*x+y*y+z*z);


	//actually change the position
	pos[0]-=(cut/dist-1)*x/2;  //half the amount of overlap in the x direction
	pos[1]-=(cut/dist-1)*y/2;  //half the amount of overlap in the y direction
	pos[2]-=(cut/dist-1)*z/2;  //half the amount of overlap in the z direction
	//other half of overlap will be handled by other particle

	//check for more colisions
	for(unsigned int j=0;j<ligands.size();j++){
		cut=this->getradius()+(ligands[j]->other(this))->getradius() ;
		//update cutoff
		if((
			cut * cut  //sum of radi squared
		>
			//distance squared
			  (npos[0]-(ligands[j]->other(this))->nposition()[0])
			* (npos[0]-(ligands[j]->other(this))->nposition()[0])
			+ (npos[1]-(ligands[j]->other(this))->nposition()[1])
			* (npos[1]-(ligands[j]->other(this))->nposition()[1])
			+ (npos[2]-(ligands[j]->other(this))->nposition()[2])
			* (npos[2]-(ligands[j]->other(this))->nposition()[2])
		)&&(j!=i)){
			cout << "Multiple overlaps, can't handle." << endl;
			exit(-93);
		} 
	}
	return 0;
}
