#include <iostream>
#include <memory>
using namespace std;

/************** Naked pointers version ************/
// in Naked pointers there is no circular reference problem
class NodeB_ptr;
class NodeA_ptr
{
public:
	NodeB_ptr* b_ptr{};
	~NodeA_ptr()
	{
		cout << "Node A Destructor" << endl;
	}
};
class NodeB_ptr
{
public:
	NodeA_ptr* a_ptr{};
	~NodeB_ptr()
	{
		cout << "Node B Destructor" << endl;
	}
};
/*************************************************/
/*********************** Shared pointer version **************************/
class NodeB_sptr;
class NodeA_sptr
{
public:
	shared_ptr<NodeB_sptr> b_ptr{};
	~NodeA_sptr()
	{
		cout << "Node A Destructor" << endl;
	}
};
class NodeB_sptr
{
public:
	shared_ptr<NodeA_sptr> a_ptr{};
	~NodeB_sptr()
	{
		cout << "Node B Destructor" << endl;
	}
};
/*************************************************/
/*********************** weak pointer version **************************/
class NodeB_wptr;
class NodeA_wptr
{
public:
	weak_ptr<NodeB_wptr> b_ptr{};
	~NodeA_wptr()
	{
		cout << "Node A Destructor" << endl;
	}
};
class NodeB_wptr
{
public:
	weak_ptr<NodeA_wptr> a_ptr{};
	~NodeB_wptr()
	{
		cout << "Node B Destructor" << endl;
	}
};

int main()
{
	//{
	//	NodeA_ptr* a = new NodeA_ptr{}; // one memory for object NodeA allocated
	//	NodeB_ptr* b = new NodeB_ptr{}; // one memory for object NodeB allocated
	//	a->b_ptr = b;
	//	b->a_ptr = a;
	//	delete a; // one memory for object NodeA deallocated
	//	delete b; // one memory for object NodeB deallocated
	//}
	//{
	//	shared_ptr<NodeA_sptr> a = make_shared<NodeA_sptr>(); // one heap memory for object NodeA allocated
	//	shared_ptr<NodeB_sptr> b = make_shared<NodeB_sptr>(); // one heap memory for object NodeB allocated
	//	a->b_ptr = b;
	//	b->a_ptr = a;
	//	cout << a.use_count() << endl;
	//	cout << b.use_count() << endl;
	//}
	{
		shared_ptr<NodeA_wptr> a = make_shared<NodeA_wptr>(); // one heap memory for object NodeA allocated
		shared_ptr<NodeB_wptr> b = make_shared<NodeB_wptr>(); // one heap memory for object NodeB allocated
		a->b_ptr = b;
		b->a_ptr = a;
		cout << a.use_count() << endl;
		cout << b.use_count() << endl;
	}

	return 0;
}