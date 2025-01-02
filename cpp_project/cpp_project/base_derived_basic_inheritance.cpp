#include <iostream>
using namespace std;

class Animal
{
public:
	void eat()
	{
		cout << "animal eats" << endl;
	}
	void speak()
	{
		cout << "animal speaks" << endl;

	}
	void walk()
	{
		cout << "animal walks" << endl;

	}
};

class Dog : public Animal
{
public:
	void eat()
	{
		cout << "dog eats" << endl;
	}
};

int main()
{
	Dog d;
	d.speak();
	d.walk();
	d.eat();
	return 0;
}