//overloads << for output in scene discription language.
//ligand printer
ostream &operator<<(ostream &out, particle * center){
	vector<ligand *> lig = center->getligands();
	unsigned int i;
	for(i=0;i<lig.size();i++){
		if(!center->getfixed()&&!  (lig[i]->other(center))->getfixed()){
			out << "cylinder {"<<endl
			<<"\t<"
			<< center->position()[0] << //give one end of ligand cylinder
			", "
			<< center->position()[2] << 
			", "
			<< -center->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<<"<"
			<< (lig[i]->other(center))->position()[0] << //give other end
			", "
			<< (lig[i]->other(center))->position()[2] << 
			", "
			<<-(lig[i]->other(center))->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<< ((center->getradius()< (lig[i]->other(center))->getradius() ?center->getradius(): (lig[i]->other(center))->getradius())/4)*lig[i]->getk()
			//sets radius of ligand
			<< endl
			<<"\t pigment { Red }"<< endl//ligand color
			//unfixed ligands get solid, others get translucent
			<<"}"<<endl<< endl;
		} else {
			out << "cylinder {"<<endl
			<<"\t<"
			<< center->position()[0] << //give one end of ligand cylinder
			", "
			<< center->position()[2] << 
			", "
			<< -center->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<<"<"
			<< (lig[i]->other(center))->position()[0] << //give other end
			", "
			<< (lig[i]->other(center))->position()[2] << 
			", "
			<<-(lig[i]->other(center))->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<< ((center->getradius()< (lig[i]->other(center))->getradius() ?center->getradius(): (lig[i]->other(center))->getradius())/4)*lig[i]->getk()
			//sets radius of ligand
			<< endl
			<<"\t pigment { Red transmit .7}"<< endl//ligand color
			//unfixed ligands get solid, others get translucent
			<<"}"<<endl<< endl;
		}
	}
	return out;
}

//particle printer
ostream &operator<<(ostream &out,vector<particle *> in){
	unsigned int i;
	for(i=0;i<in.size();i++){
		if(!in[i]->getfixed()){//different colors for fixed/unfixed
			out << "sphere {" << endl << "\t <"
			<< in[i]->position()[0] << 
			", "
			<<in[i]->position()[2] << 
			", "
			<< -in[i]->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<< in[i]->getradius() << endl
			<<"\t pigment{ function {abs(sin(y/3.14159))} scale <.4,.4,.4> color_map { [0.0, Yellow] [1.0, rgb <.5,0,.5>] }}"<< endl
			//unfixed is yellow
			<<"}"<<endl<< endl;

			out << in[i];//prints ligands
		} else {
			out << "sphere {" << endl << "\t <"
			<< in[i]->position()[0] << 
			", "
			<<in[i]->position()[2] << 
			", "
			<< -in[i]->position()[1] << 
			">, "//pov-ray uses left-handed coordinates
			<< in[i]->getradius() << endl
			<<"\t pigment { Green transmit .7}"<< endl
			//fixed is translucent green
			<<"}"<<endl<< endl;

			out << in[i];//prints ligands
		}
	}
	return out;
}

