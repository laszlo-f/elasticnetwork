//for mathematica
//use to determine the shape of the cross section
//junk
int lprint(vector<particle *> line){
	unsigned int i;
	cout << "NonlinearRegress[{";
	for(i=0;i<line.size();i++){
		cout << "{"
		<< line[i]->position()[1] << ", "
		<< line[i]->position()[2] << "}, ";
	}
	cout << "},a*(x-b)^2,{a,b},x]" << endl;
	return 0;
}
