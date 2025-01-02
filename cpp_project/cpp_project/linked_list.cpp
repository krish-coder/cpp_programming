#include <iostream>
using namespace std;
static int glob = 2;
class Node
{
public:
	int value;
	Node* next{};
	Node(int value) : value(value)
	{
	}
};

class LinkedList
{
	Node* head{};
public:
	LinkedList()
	{

	}
	~LinkedList()
	{
		Node* current_node = head;
		while (current_node != nullptr)
		{
			Node* next_node = current_node->next;
			delete current_node;
			current_node = next_node;
		}
	}
	void insert_at_end(int value)
	{
		if (head == nullptr)
		{
			head = new Node(value);
		}
		else
		{
			Node* current_node = head;
			while (current_node->next != nullptr)
			{
				current_node = current_node->next;
			}
			current_node->next = new Node(value);
		}
	}

	void insert_at_start(int value)
	{
		Node* new_node = new Node(value);
		new_node->next = head;
		head = new_node;
	}

	void delete_node(int value)
	{
		Node* current_node = head;
		Node* previous_node{};
		while (current_node!= nullptr && current_node->value != value)
		{
			previous_node = current_node;
			current_node = current_node->next;
		}
		if (current_node)
		{
			previous_node->next = current_node->next;
			delete current_node;
		}
	}

	void display()
	{
		Node* current_node = head;
		while (current_node != nullptr)
		{
			cout << current_node->value << " -> ";
			current_node = current_node->next;
		}
		cout << endl;
	}

};

int main()
{
	LinkedList list;
	


	/// insert at end
	list.insert_at_end(20);
	list.display();
	list.insert_at_end(10);
	list.display();
	/// insert at start
	list.insert_at_start(30);
	list.display();

	/// delete value
	list.delete_node(20);
	list.display();

	return 0;
}