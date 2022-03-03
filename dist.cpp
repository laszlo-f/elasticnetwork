//Used to fix the position of the particle if it is outside a circle.
bool dist(long double x, long double y,long double rad, unsigned int sl){
	if(sqrt((sl/2-x)*(sl/2-x)+((sl/2)*sqrtl(3.)-y)*((sl/2)*sqrtl(3.)-y))<rad){
		return false; //inside the circle
	} else {
		return true; //outside
	}
}
