//can be used to convert just about anything to a string
//needed to make output file names more useful.
//
template <typename T>
std::string Ttos(T arg) {
	std::ostringstream buffer;
	buffer << arg;
	return buffer.str();
}
