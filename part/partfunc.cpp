int particle::reset(){
	//unfortunately, arrays can't be assigned because they
	//do not know their size, so here is an inelegant solution
	//it is probably still more efficient than using a 
	//vector, which is assignable
	opos[0]=pos[0];
	opos[1]=pos[1];
	opos[2]=pos[2];

	//denies convergence check until new reposition
	repositioned=false;

	return 0;
}//prepare for next iteration.

int particle::addligand(ligand * nl){//attaches another ligand
	ligands.push_back(nl);
	return 0;
}

const vector<long double> particle::position(){
	vector<long double> temp;
	temp.push_back(opos[0]);
	temp.push_back(opos[1]);
	temp.push_back(opos[2]);
	return temp;
}//reveals the old position of this particle
//after convergence, opos=pos, hopefully

const vector<long double> particle::nposition(){
	vector<long double> temp;
	temp.push_back(npos[0]);
	temp.push_back(npos[1]);
	temp.push_back(npos[2]);
	return temp;
}//reveals the new position of this particle
//for use in cdet for colision detection only

const long double particle::getradius(){
	return radius;
}

const long double particle::movement(){
	return fabsl(sqrtl(
		(pos[0]-opos[0])*(pos[0]-opos[0])+
		(pos[1]-opos[1])*(pos[1]-opos[1])+
		(pos[2]-opos[2])*(pos[2]-opos[2])
	));
} //determines how far a particle has been displaced in an iteration.

const bool particle::getrepositioned(){
	return repositioned;
}

const bool particle::getfixed(){
	return fixed;
}

const vector<ligand *> particle::getligands(){
	return ligands;
}

const long double particle::fromcenter(unsigned int sl){
	return sqrtl(
		(sl/2-pos[0]) * (sl/2-pos[0])
		+(sqrtl(3)*sl/2-pos[1]) * (sqrtl(3)*sl/2-pos[1])
	);
}
