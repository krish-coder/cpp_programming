#include <iostream>
#include <memory>
using namespace std;
class Example
{
public:
   int a;
   float *b;

   Example() :a(0)
   {
	  b = new float{};
	  cout << "constructor called" << endl;
   }
   ~Example()
   {
	  delete b;
	  cout << "destructor called" << endl;
   }
};

int main()
{
	// create an object on the stack
	Example obj;
	// create objects on heap
	Example* ptr_obj = new Example{};
	unique_ptr<Example> p = make_unique<Example>();
	delete ptr_obj;
	return 0;
}