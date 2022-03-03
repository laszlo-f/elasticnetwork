//Prototype for ligand class


class ligand{
	private:
		
		//say what the ligand is attached to
		particle * end;
		particle * otherend;

		//unstretched length between particles
		long double unstretch;

		//spring constant
		long double k;

	public:
		//constructor
		ligand(particle * first,particle * second,long double unstretch,long double kspring,long double limit);

		//allows a particle attached at one end to identify the other end.
		particle * other( particle * thisp);

		//provide information
		const long double getunstretch();
		const long double getk();
		const long double slope();

		//TODO: Destructor
		~ligand();
};
