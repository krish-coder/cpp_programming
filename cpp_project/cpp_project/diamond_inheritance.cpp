#include <iostream>
#include <string>
using namespace std;
class Stream
{
public:
	Stream(const string &filename)
	{
		cout << "Stream" << endl;
	}
};

class InputStream : public Stream
{
	std::istream& in;
public:
	InputStream(const string &file_name, std::istream& i) : Stream(file_name), in(i)
	{

	}
};

class OutputStream : public Stream
{
	std::ostream& out;
public:
	OutputStream(const string &file_name, std::ostream& o): Stream(file_name), out(o)
	{

	}
	operator << ()

};

class IOStream: public InputStream, public OutputStream
{
public:
	IOStream(const string &file_name, std::istream& in, std::ostream &out) :OutputStream(file_name, out), InputStream(file_name, in)
	{
		cout << "IOStream constructor" << endl;
	}
	~IOStream()
	{
		cout << "IOStream destructor" << endl;
	}
};
int main()
{
	string data;
	string filename;
	IOStream stream(filename, std::cin, std::cout);
	stream >> data;
	stream << data;
	return 0;
}