#include "Customer.h"

Customer::Customer()
{

}

Customer::Customer(string name, int id, int age, int _mechanicID, Appointment _appointment) : Person(name, id, age)
{
    mechanicID = _mechanicID;
    appointment = _appointment;
}

void Customer::setMechanicID(int _mechanicID)
{
    mechanicID = _mechanicID;
}

void Customer::setAppointment(Appointment _appointment)
{
    appointment = _appointment;
}

int Customer::getMechanicID()
{
    return mechanicID;
}

Appointment Customer::getAppointment()
{
    return appointment;
}

bool Customer::operator<(const Customer &currentCustomer)
{
    if(appointment.hours < currentCustomer.appointment.hours)
    {
        return true;
    }

    else if(appointment.hours == currentCustomer.appointment.hours)
    {
        if(appointment.minutes < currentCustomer.appointment.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Customer::operator>(const Customer &currentCustomer)
{
    if(appointment.hours > currentCustomer.appointment.hours)
    {
        return true;
    }

    else if(appointment.hours == currentCustomer.appointment.hours)
    {
        if(appointment.minutes > currentCustomer.appointment.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Customer::operator==(const Customer &currentCustomer)
{
    if(appointment.hours == currentCustomer.appointment.hours && appointment.minutes == currentCustomer.appointment.minutes)
    {
        return true;
    }

    return false;
}

