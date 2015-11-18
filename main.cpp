#include <iostream>
#include <sstream>
using namespace std;

void join_impl(stringstream &stream, string separator) {}

template <typename Arg>
void join_impl(stringstream &stream, string separator, Arg last) 
{
	stream << last;
}

template <typename Arg, typename ...Rest>
void join_impl(stringstream &stream, string separator, Arg first, Rest ...rest)
{
	stream << first << separator;
	join_impl(stream, separator, rest...);
}

template <typename ...Args>
string join(string separator, Args ...args)
{
	stringstream stream;
	
	join_impl(stream, separator, args...);
	
	return stream.str();
}

int main() 
{
	cout << join(", ") << endl;
}
