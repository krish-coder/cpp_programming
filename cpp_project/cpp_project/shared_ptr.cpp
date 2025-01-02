#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Project
{
	string name;
public:
	void set_name(const string& name)
	{
		this->name = name;
	}

	void show_name() const
	{
		cout << "Project : " << name << endl;
	}
};
/* the project instance is created in main and is shared by multiple employees
Hence it cannot be managed by Employee class*/
class Employee
{
	shared_ptr<Project> m_prj{};
public:
	void set_project(const shared_ptr<Project>& proj)
	{
		m_prj = proj;
	}
	const shared_ptr<Project>& get_project() const
	{
		return m_prj;
	}
};

void show_info(const unique_ptr<Employee> &e)
{
	cout << "Employee ";
	e->get_project()->show_name();
}


int main()
{
	// lets create a project instance
	// this project instance is shared by all employees and hence needs to be a pointer
	shared_ptr<Project> prj = make_shared<Project>();
	prj->set_name("CV");
	//Employee e1, e2, e3;
	//e1.set_project(prj);
	//e2.set_project(prj);
	//e3.set_project(prj);
	unique_ptr<Employee> e1 = make_unique<Employee>();
	unique_ptr<Employee> e2 = make_unique<Employee>();
	unique_ptr<Employee> e3 = make_unique<Employee>();
	e1->set_project(prj);
	e2->set_project(prj);
	e3->set_project(prj);

	show_info(e1);
	show_info(e2);
	show_info(e3);
	prj->show_name();
	return 0;
}