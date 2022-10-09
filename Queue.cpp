#include <iostream>
#include "Queue.h"

template <class T>
Queue<T>::Queue()
{
    start = end = qsize = 0;
    arr = new T[100];
}

template <class T>
void Queue<T>::push(T x) // add to end of the queue, and increase end pointer to the next one
{
    arr[end] = x;
    end++;
    qsize++;
}

template <class T>
T Queue<T>::pop()       // get the first element in the queue, and push the start to the next one
{
    if(start == end)
    {
        cout << "Queue is empty" << endl;
        return T();
    }

    qsize--;
    return arr[start++];
}

template <class T>
int Queue<T>::size()
{
    return qsize;
}
