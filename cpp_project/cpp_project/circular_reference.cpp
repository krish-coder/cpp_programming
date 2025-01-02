#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
	int value;
	weak_ptr<Node> next{};
	//shared_ptr<Node> next{};
	Node(int value):value(value)
	{
		cout << "Constructor called" << endl;
	}
	~Node()
	{
		cout << "Destructor called" << endl;
	}

};

int main()
{
	shared_ptr<Node> nodeA = make_shared<Node>(10);
	shared_ptr<Node> nodeB = make_shared<Node>(20);
	nodeA->next = nodeA;
	//nodeA->next = nodeB;
	//nodeB->next = nodeA;
	return 0;
}