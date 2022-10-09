using namespace std;

struct Appointment
{
    int hours;
    int minutes;

    Appointment();

    Appointment(int _hours, int _minutes);

    int getHours();

    int getMinutes();
};
