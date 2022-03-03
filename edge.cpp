//fixes edge for rectangular boundary
bool edge(unsigned int i,unsigned int sl){
	bool answer=false;//default

	//maybe this should be a switch?
	if(i%sl==0){//left edge
		answer=true;
	} else if (i%sl==(sl-1)){//right edge
		answer=true;
	} else if (i<=(sl-1)){//botom
		answer=true;
	} else if (i>=(sl*sl-sl)){//top
		answer=true;
	}
	return answer;
}
