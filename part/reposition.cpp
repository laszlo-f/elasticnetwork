
int particle::reposition(){//performs an itteration on this particle
			//by repositioning it to the minimum of 
			//its potential energy in the previous itteration.

	//prepare for convergence test
	repositioned= true;

	if(!fixed){//not all particles are movable.  This checks.

		//the way this should work:
		//1.  Find the distance to each particle 
		//minus the unstretched part, all multiplied
		//by the spring constant.
		//2.  Sum the parts.
		//3.  Sum the spring constants.
		//4.  Divide 2 by 3.
		//5.  Add the result to the old position

		long double sum[3]={0,0,0};//initialize sum of positions 
		long double sumk=0;
		
		long double temp[5];//holding variable.
		//x, y, z, unstretch, k

		for(unsigned int i=0;i<ligands.size();i++){//sum over all adjacent particles

			//get position of nearest particle
			temp[0]=(ligands[i]->other(this))->position()[0];
			temp[1]=(ligands[i]->other(this))->position()[1];
			temp[2]=(ligands[i]->other(this))->position()[2];

			//gets unstretchable part of distance (scalar)
			temp[3]=ligands[i]->getunstretch();
			//gets spring constant
			temp[4]=ligands[i]->getk();

			//prevent NAN, INF error
			if(0== 
					(temp[0]-pos[0]) * (temp[0]-pos[0])+
					(temp[1]-pos[1]) * (temp[1]-pos[1])+
					(temp[2]-pos[2]) * (temp[2]-pos[2])
			){
				cout << "Error:  no distance between particles." << endl;
				exit(145);
			}

			//find vector stretched distance
			sum[0]+=temp[4]*(
				temp[0]-pos[0]-(temp[0]-pos[0])*temp[3]/(sqrtl(
					(temp[0]-pos[0]) * (temp[0]-pos[0])+
					(temp[1]-pos[1]) * (temp[1]-pos[1])+
					(temp[2]-pos[2]) * (temp[2]-pos[2])
				))
			);
			sum[1]+=temp[4]*(
				temp[1]-pos[1]-(temp[1]-pos[1])*temp[3]/(sqrtl(
					(temp[0]-pos[0]) * (temp[0]-pos[0])+
					(temp[1]-pos[1]) * (temp[1]-pos[1])+
					(temp[2]-pos[2]) * (temp[2]-pos[2])
				))
			);
			sum[2]+=temp[4]*(
				temp[2]-pos[2]-(temp[2]-pos[2])*temp[3]/(sqrtl(
					(temp[0]-pos[0]) * (temp[0]-pos[0])+
					(temp[1]-pos[1]) * (temp[1]-pos[1])+
					(temp[2]-pos[2]) * (temp[2]-pos[2])
				))
			);
			
			
			
			//sum the spring constants
			sumk+=temp[4];

		}

		//finds the average position of surrounding particles.
		//this is the potential energy minimum (for now)
		if(sumk==0){
			cout << "All spring constants 0 or no ligands attached."<< endl;
			exit(133);
		}
		pos[0]+=sum[0]/sumk;
		pos[1]+=sum[1]/sumk;
		pos[2]+=sum[2]/sumk;
	}

	//used for colision detection
	npos[0]=pos[0];
	npos[1]=pos[1];
	npos[2]=pos[2];
	return 0;
}

