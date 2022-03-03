ligand::ligand(particle * first,particle * second,long double relaxlength,long double kspring, long double limit){

	if((first!=NULL)&&(second!=NULL)){
	//ensure the ligand can be attached to the provided particles
	
	
		end=first;
		otherend=second;




		//TODO: add in unstretched length of ligand 
		//using monte carlo(?) method
		unstretch=relaxlength+end->getradius()+otherend->getradius();


		//TODO: add in monte carlo method of computing spring constant
		k=kspring;

		//makes sure the particles know that this ligand is attached to them.
		end->addligand(this);
		otherend->addligand(this);
	} else {
		cout << "Cannot connect ligand to nonexistant particle." << endl;
	}
}//usual constructor.

ligand::~ligand(){
	otherend->ligandremove(this);	
	end->ligandremove(this);	
}//destructor

