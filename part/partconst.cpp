//main constructor
particle::particle(long double ixpos,long double iypos,long double izpos, long double irad, bool ifixed,bool iafm){
	
	npos[0]=opos[0]=pos[0]=ixpos;//initialize particle position
	npos[1]=opos[1]=pos[1]=iypos;
	npos[2]=opos[2]=pos[2]=izpos;
	
	//initialize through monte carlo methods, with monte carl part being done 
	//before constructor is called.
	radius=irad;
	//radius=.416666667;//mean radius= 3/(6+1.2)

	fixed=ifixed;

	afm=iafm;

	if(afm && !fixed){
		cout << "On AFM but not fixed!" << endl;
	}

	reset();//finish preparations for first iteration
}

particle::~particle(){
	while(0<ligands.size()){
		delete ligands[ligands.size()-1];
		//delete starting at the end so 
		//vector::erase will be faster
	}
}//destructor 

bool particle::ligandremove(ligand * todel){
	vector<ligand*>::iterator begining=ligands.begin();
	for (unsigned int i = 0;(i<ligands.size())&&(todel!=NULL); i++){
		if(ligands[i]==todel){//assume a ligand is only listed once
			ligands.erase(begining+i);
			todel=NULL;
		} 
	}
	return true;
}//helper for ~ligand()

