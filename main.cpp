#include <iostream>
#include <sstream>
using namespace std;

// End-case: There are no more parameters to output.
// Occurs when no parameters are given to the join function.
void join_impl(stringstream &stream, string separator) {}

// End-case: The last argument to output. End the recursion here.
template <typename Arg>
void join_impl(stringstream &stream, string separator, Arg last) 
{
	stream << last;
}

// Recursively output the arguments to the stream until an end-case is hit.
template <typename Arg, typename ...Rest>
void join_impl(stringstream &stream, string separator, Arg first, Rest ...rest)
{
	stream << first << separator;
	join_impl(stream, move(separator), rest...);
}

// Join data together with a custom separator. 
template <typename ...Args>
string join(string separator, Args ...args)
{
	stringstream stream;
	
	join_impl(stream, move(separator), args...);
	
	return stream.str();
}

int main() 
{
	cout << join(", ", "test", 1, 1.32) << endl;
	// Output: "test, 1, 1.32" 
	
	cout << join(", ", "test") << endl;
	// Output: "test"
	
	cout << join(", ") << endl;
	// Outputs an empty string.
}
