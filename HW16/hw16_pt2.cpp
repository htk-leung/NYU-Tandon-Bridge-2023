// hl5737_hw16_pt2.cpp
// Katherine Leung


#include<vector>

template<class T>
class Queue {
private:
    int beginind;
    int endind;
    vector<T> q;

public:
    Queue();                                    // constructor
    Queue(const Queue<T>& obj);                 // copy constructor
    ~Queue();                                   // destructor
    Queue<T> operator =(const Queue<T>& rhs);   // = overload
    void push(T data);                          // push function
    T pop();                                    // pop function
    T top();                                    // top function
    int clear();                                // clear function
    bool empty();                               // isempty function
    int size();                                 // size
};

template<class T>
Queue<T>::Queue() {
    beginind = 0;
    endind = 0;
}

template<class T>
Queue<T>::Queue(const Queue<T>& obj) { 
    for(int i = beginind; i < endind; i++) 
        push(obj[i]);
    beginind = obj.beginind;
    endind = obj.endind;
}

template<class T>
Queue<T>::~Queue() {
}

template<class T>
Queue<T> Queue<T>::operator =(const Queue<T>& obj) {
    for(int i = beginind; i < endind; i++) 
        push(obj[i]);
    beginind = obj.beginind;
    endind = obj.endind;
}

template<class T>
void Queue<T>::push(T data) {
    q.push_back(data);
    endind++;
}

template<class T>
T Queue<T>::pop() {
    T temp = q[beginind];
    beginind++;
    return temp;
}

template<class T>
T Queue<T>::top() {
    return q[beginind];
}

template<class T>
int Queue<T>::clear() {
    int temp = endind - beginind;
    q.clear();
    beginind = 0;
    endind = 0;
    return temp;
}

template<class T>
bool Queue<T>::empty() {
    if(q.size() == 0)
        return true;
    else if (beginind == endind)
        return true;
    return false;
}

template<class T>
int Queue<T>::size() {
    return endind - beginind;
}