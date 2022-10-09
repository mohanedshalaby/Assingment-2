#include "Mechanic.cpp"

using namespace std;

class Customer : public Person
{
    int mechanicID;
    Appointment appointment;

public:
    Customer();

    Customer(string name, int id, int age, int _mechanicID, Appointment _appointment);

    void setMechanicID(int _mechanicID);

    void setAppointment(Appointment _appointment);

    int getMechanicID();

    Appointment getAppointment();

    bool operator<(const Customer &currentCustomer);

    bool operator>(const Customer &currentCustomer);

    bool operator==(const Customer &currentCustomer);
};
