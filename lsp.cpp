//Provides the objects needed for nanoparticle programs.

//Includes standard libraries.
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include <string>
#include <algorithm>//vector sort()
#include <unistd.h>//fork
#include <sys/types.h>//fork
#include <sys/wait.h>//wait
#include <cstdlib>//randomize
#include <time.h>//seed random number generator with time
using namespace std;

//must provide a prototype for class particle
//because it is referenced in a function prototype
//for class ligand
class particle;

#include "ligand/ligand.cpp"//class ligand prototype
#include "part/particle.cpp"//class particle prototype

#include "part/partconst.cpp"//class particle constructor/destructor
#include "part/partfunc.cpp"//class particle functions
#include "part/reposition.cpp"//particle::reposition
#include "part/cdet.cpp"//particle::cdet colision detection
#include "part/force.cpp"//particle::force
#include "part/toclean.cpp" //allow clean() to determine what needs deleting

#include "ligand/ligandconst.cpp"//ligand constructor/destructor
#include "ligand/ligandfunc.cpp"//class ligand functions
#include "ligand/slope.cpp"//class ligand functions

#include "scale.cpp"//making prestrain work, making interparticle spacing 1

#include "convergence.cpp"//test for convergence
#include "print.cpp"//particle array ostream
#include "append.cpp"//for appending things to strings
#include "iterate.cpp"//repositions particles until positions converge

#include "dist.cpp" //for boundary conditions
#include "edge.cpp" //determine if you are at the edge of a rectangular boundary
#include "clean.cpp" //delete unneeded particles

//for testing monte carlo only
/*
#warning Only using lower half of triangular distribution!
#include "stat/ltridist.cpp"
#warning Only using upper half of triangular distribution!
#include "stat/utridist.cpp"
*/

//for monte carlo simulaton
#include "stat/uni.cpp"
#include "stat/list.cpp"
#include "stat/deleter.cpp"

//for finite indenter radius
#include "multiforce.cpp"
#include "curve.cpp"
