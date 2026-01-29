#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Employee
{
protected:
    string firstName;
    char initial;
    string lastName;

public:
    Employee(string f, char i, string l)
    {
        firstName = f;
        initial = i;
        lastName = l;
    }

    virtual double getSalary() = 0;

    virtual ~Employee() {}
};

// Salary employee
class SalaryEmployee : public Employee
{
private:
    double monthlySalary;

public:
    SalaryEmployee(string f, char i, string l, double sal)
        : Employee(f, i, l)
    {
        monthlySalary = sal;
    }

    double getSalary()
    {
        return monthlySalary;
    }
};

// Hourly employee
class HourlyEmployee : public Employee
{
private:
    double hoursWorked;
    double ratePerHour;

public:
    HourlyEmployee(string f, char i, string l, double h, double r)
        : Employee(f, i, l)
    {
        hoursWorked = h;
        ratePerHour = r;
    }

    double getSalary()
    {
        return hoursWorked * ratePerHour;
    }
};

int main()
{
    Employee* e1 = new SalaryEmployee("Talia", 'E', "Auma", 80000);
    Employee* e2 = new HourlyEmployee("Louis", 'B', "Liyala", 160, 700);

    cout << "Salary Employee Pay: " << e1->getSalary() << endl;
    cout << "Hourly Employee Pay: " << e2->getSalary() << endl;

    delete e1;
    delete e2;

    return 0;
}
