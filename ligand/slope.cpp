//compute slope of ligand
//used by curve()

const long double ligand::slope(){
	return fabsl((end->position()[2]-otherend->position()[2])/sqrtl(
		 (end->position()[0]-otherend->position()[0])
		*(end->position()[0]-otherend->position()[0])
		+(end->position()[1]-otherend->position()[1])
		*(end->position()[1]-otherend->position()[1])
	));

}
