using namespace std;

template <class T>
class Queue
{
    T *arr;
    int start, end, qsize;
public:

    Queue();

    void push(T x);

    T pop();

    int size();
};
