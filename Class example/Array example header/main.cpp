#include <iomanip>
#include <iostream>
using namespace std;

#include "array_header.h"

int main()
{
    // variables
    int salary[MAX_SIZE];
    int numOfEmployees;
    double averageSalary;

    // get num of employees
    numOfEmployees = getSalary(salary);

    // get average salary
    averageSalary = average(salary, numOfEmployees);

    // display average salary
    cout << setprecision(2) << fixed;
    cout << "Average salary is: " << averageSalary << endl;
    return 0;
}

int getSalary(int salary[])
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        cout << "Enter 0 to exit" << endl;
        cout << "Enter the salary of employee #" << i + 1 << " : ";
        cin >> salary[i];
        if (salary[i] <= 0)
        {
            return i-1; // return the number of employees
        }
    }
    return MAX_SIZE;
}

double average(int slary[], int numOfEmployees)
{
    double sum = 0.0; // create sum variable

    // add up the values here
    for(int i = 0; i < numOfEmployees; i++)
    {
        sum += slary[i];
    }

    return sum / numOfEmployees;
}