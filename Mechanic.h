#include <iostream>
#include "Person.cpp"
#include "Appointment.cpp"

using namespace std;

class Mechanic : public Person
{
    int counter;
    Appointment *appointments;
public:
    Mechanic();

    bool isAvailable(Appointment appointment);

    void setCounter(int _counter);

    void setAppointment(Appointment appointment);

    int getCounter();

    Appointment* getAppointment();
};
