//class describing gold particles
class particle {
	private:
		long double pos[3]; //position of the nanoparticle.  x,y,z
		long double npos[3]; //position of the nanoparticle.  x,y,z
		long double opos[3]; //old position of the nanoparticle.
		long double radius; //radius of the particle

		vector<ligand *>  ligands; 
		//list of ligands attached to this particle.


		bool fixed; //true if the particle should never move.
		bool afm; //true if the partiticle is on the AFM tip.

		bool repositioned;
		//true when repositioned, false when reset


	public:
		particle(long double ixpos,long double iypos,long double izpos,long double irad,bool ifixed, bool iafm);
		//constructor

		
		int reset(); //prepare for next iteration
		int addligand(ligand * nl);//attaches a ligand
		int reposition();//perform one itteration
		int cdet();//perform one itteration

		const long double force();//finds force on particle recursively.
		//run no more than oncer per iteration
		
		const vector<long double> position();//reveal position of this particle.
	
		const vector<long double> nposition();//reveal new position of this particle.
		//for colision detection

		const long double fromcenter(unsigned int sl);//distance from center of membrane
		//for use in deletelist before calling iterate() or reposition()

		const long double getradius();

		const long double movement();//reveals how much a partilce has moved
		//with rms
		
		const bool getrepositioned();

		const bool getfixed();
		
		const bool getafm();

		const bool toclean();//true if particle does nothing and should be 
		//deleted

		const vector<ligand *> getligands();//in print.cpp

		bool ligandremove(ligand *);
		//destructor helper

		~particle();
};

