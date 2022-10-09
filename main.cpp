#include <iostream>
#include "Customer.cpp"
#include "Queue.cpp"

using namespace std;

string getMecanicName(int mechanicsNumber, Mechanic *mechanics, int id)
{
    for(int i = 0 ; i < mechanicsNumber ; i++)
    {
        if(mechanics[i].getId() == id)
        {
            return mechanics[i].getName();
        }
    }

    return "";
}

int main()
{
    cout << "Enter the number of mechanics : ";
    int mechanicsNumber;
    cin >> mechanicsNumber;

    Mechanic *mechanics = new Mechanic[mechanicsNumber];

    for(int i = 0; i < mechanicsNumber ; i++)
    {
        mechanics[i].setCounter(0);

        cout << "Enter the name of the current mechanic " << i + 1 << " : ";
        string name;
        cin >> name;

        mechanics[i].setName(name);
        mechanics[i].setId(i);
    }

    int currentMechanicIndex = 0;

    cout << "Enter the number of customers : ";
    int customersNumber;
    cin >> customersNumber;

    Customer *customers = new Customer[customersNumber];

    for(int i = 0 ; i < customersNumber ; i++)
    {
        cout << "Enter name of customer number " << i + 1 << " : ";
        string name;
        cin >> name;

        customers[i].setName(name);

        cout << "Enter appointment hour of customer number " << i + 1 << " : ";
        int hour;
        cin >> hour;

        cout << "Enter appointment minutes of customer number " << i + 1 << " : ";
        int minutes;
        cin >> minutes;

        Appointment appointment = Appointment(hour, minutes);

        customers[i].setAppointment(appointment);

        while(mechanics[currentMechanicIndex].isAvailable(appointment) == false)
        {
            currentMechanicIndex++;
            if(currentMechanicIndex == mechanicsNumber)
            {
                currentMechanicIndex = 0;
            }
        }

        customers[i].setMechanicID(mechanics[currentMechanicIndex].getId());
        mechanics[currentMechanicIndex++].setAppointment(appointment);

        if(currentMechanicIndex == mechanicsNumber)
        {
            currentMechanicIndex = 0;
        }
    }

    // Printing Customers before sorting in the queue
    for(int i = 0 ; i < customersNumber ; i++)
    {
        Customer currentCustomer = customers[i];
        int id = currentCustomer.getMechanicID();

        cout << currentCustomer.getName() << " should be assigned to " << getMecanicName(mechanicsNumber, mechanics, id);

        Appointment appointment = currentCustomer.getAppointment();

        cout << " At " << appointment.hours << ":" << appointment.minutes << endl;
    }

    cout << endl;
    cout << "----------------------" << endl;
    cout << endl;

    // init token array to mark token customers
    Queue<Customer> q;

    bool *token = new bool[customersNumber];

    for(int i = 0 ; i < customersNumber ; i++)
    {
        token[i] = false;
    }

    // inserting customer into the queue by minimum appointment
    for(int i = 0 ; i < customersNumber ; i++)
    {
        int customerIndex;
        Customer smalletCustomer;
        Appointment appointment = Appointment(24, 0);
        smalletCustomer.setAppointment(appointment);

        for(int j = 0 ; j < customersNumber ; j++)
        {
            if(customers[j] < smalletCustomer && token[j] == false)
            {
                customerIndex = j;
                smalletCustomer = customers[j];
            }
        }

        token[customerIndex] = true;
        q.push(smalletCustomer);
    }

    // Printing Customers sorted in the queue
    while(q.size() > 0)
    {
        Customer currentCustomer = q.pop();
        int id = currentCustomer.getMechanicID();

        cout << currentCustomer.getName() << " should be assigned to " << getMecanicName(mechanicsNumber, mechanics, id);

        Appointment appointment = currentCustomer.getAppointment();

        cout << " At " << appointment.hours << ":" << appointment.minutes << endl;
    }

    return 0;
}
