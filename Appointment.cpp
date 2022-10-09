#include "Appointment.h"

Appointment::Appointment()
{

}

Appointment::Appointment(int _hours, int _minutes)
{
    hours = _hours;
    minutes = _minutes;
}

int Appointment::getHours()
{
    return hours;
}

int Appointment::getMinutes()
{
    return minutes;
}
