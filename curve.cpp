//compute radius of curvature of AFM tip
//see lab notebook p. 34

long double curve(const vector<particle*>* givenlist){
	vector<particle *> tiplist;
	long double center[3]={0,0,0};
	long double rbar=0;
	long double mbar=0;
	unsigned int ligandnumber=0;

	vector <ligand *> ligandholder;

	for(unsigned int i=0;i<givenlist->size();i++){
		if(((*givenlist)[i]->getafm())&&(!(*givenlist)[i]->toclean())){
			tiplist.push_back((*givenlist)[i]);
		}
	}
	//makes a list of particles that should be considered to be on the edge of the afm tip
	
	if(tiplist.size()==0){
		cout << "No tip found" << endl;
		exit(3444);
	}
	for(unsigned int i=0;i<tiplist.size();i++){
		center[0]+=tiplist[i]->position()[0];
		center[1]+=tiplist[i]->position()[1];
		center[2]+=tiplist[i]->position()[2];
	}

	//center point of afm contact boundary
	center[0]=center[0]/tiplist.size();
	center[1]=center[1]/tiplist.size();
	center[2]=center[2]/tiplist.size();

	for(unsigned int i=0;i<tiplist.size();i++){
		rbar+=sqrtl(
			 (center[0]-tiplist[i]->position()[0])
			*(center[0]-tiplist[i]->position()[0])
			+(center[1]-tiplist[i]->position()[1])
			*(center[1]-tiplist[i]->position()[1])
			+(center[2]-tiplist[i]->position()[2])
			*(center[2]-tiplist[i]->position()[2])
		);
	}
	rbar=rbar/tiplist.size();
	//average radius of afm fixed section
	
	for(unsigned int i=0;i<tiplist.size();i++){
		ligandholder=tiplist[i]->getligands();
		for(unsigned int j=0;j<ligandholder.size();j++){
			mbar+=ligandholder[j]->slope();
		}
		ligandnumber+=ligandholder.size();
	}

	mbar=mbar/ligandnumber;

	return sqrtl(rbar*rbar*mbar*mbar/(mbar*mbar-1));
}
