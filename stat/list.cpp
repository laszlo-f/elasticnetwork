//generate a list of random numbers from triangular distribution
vector<long double> list(unsigned int size,long double center,long double epsilon){
	vector<long double> result;
	
	for(unsigned int i=0;i<size;i++){
		result.push_back(tri(center*(1-epsilon),center*(1+epsilon)));//triangular distribution
	}

	return result;
}
