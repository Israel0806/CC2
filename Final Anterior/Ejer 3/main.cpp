#include <iostream>

using namespace std;

template <class T>
class Stack
{
public:
    Stack() :top(0){ }
    ~Stack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }

    void push(const T& object);
    T pop();
    bool isEmpty();
    void print();

private:
    struct StackNode
    {
        T data;
        StackNode *next;

        StackNode(const T& newData, StackNode *nextNode)
        : data(newData), next(nextNode) {}
    };
    StackNode *top;
};

template <class T>
bool Stack<T>::isEmpty()
{
    if(top==0)
        return true;
    return false;
}

template <class T>
void Stack<T>::push(const T& obj)
{
    if(top==0)
    {
        top = new StackNode(obj,0);
        return;
    }
    top = new StackNode(obj, top);
}

template <class T>
T Stack<T>::pop()
{
    if(!isEmpty())
    {
        StackNode* temp=top->next;
        delete top;
        top=temp;
    }
}

template <class T>
void Stack<T>::print()
{
    if(!isEmpty())
    {
        StackNode* temp=top;
        while(temp)
        {
            cout<<temp->data;
            if(temp->next)
                cout<<" -> ";
            temp=temp->next;
        }
    }
}

int main()
{
    Stack<int>* s = new Stack<int>();
    s->push(5);
    s->push(4);
    s->push(10);
    s->pop();
    s->pop();
    s->pop();
    s->pop();
    s->print();



    return 0;
}
