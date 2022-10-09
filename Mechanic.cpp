#include "Mechanic.h"

Mechanic::Mechanic()
{
    counter = 0;
    appointments = new Appointment[100];
}

bool Mechanic::isAvailable(Appointment appointment)
{
    for(int i = 0 ; i < counter ; ++i)
    {
        if(appointment.hours == appointments[i].hours && appointment.minutes == appointments[i].minutes)
        {
            return false;
        }
    }

    return true;
}

void Mechanic::setCounter(int _counter)
{
    counter = _counter;
}

void Mechanic::setAppointment(Appointment appointment)
{
    appointments[counter++] = appointment;
}

int Mechanic::getCounter()
{
    return counter;
}

Appointment* Mechanic::getAppointment()
{
    return appointments;
}
