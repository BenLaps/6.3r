#include <iostream>
using namespace std;

struct Elem
{
    Elem* next, * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int info)
{
    Elem* tmp = new Elem;
    tmp->info = info;
    tmp->next = nullptr;
    if (last != nullptr)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == nullptr)
        first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    int info = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return info;
}

void print(const Elem* first)
{
    if (first == nullptr)
        cout << endl;
    else
    {
        cout << first->info << " ";
        print(first->next);
    }
}

int check(const Elem* L, bool c)
{
    if (L != nullptr)
    {
        if (L->prev != NULL)
        {
            if (L->prev->info == L->info)
            {
                c = true;
            }
        }
        L = L->next;
        return check(L, c);
    }
    return c;
}
int main() {
    int number = 5;
    Elem* first = nullptr, * last = nullptr;
    enqueue(first, last, 1);
    enqueue(first, last, 2);
    enqueue(first, last, 0);
    enqueue(first, last, 7);
    enqueue(first, last, 7);
    for (int i = 1; i <= 4; i++)
        enqueue(first, last, i);


    print(first);
    if (check(first, false))
    {
        cout << "adjacent equal numbers are available " << endl << endl;
    }
    else
    {
        cout << "adjacent equal numbers aren't available " << endl << endl;
    }

    for (size_t i = 0; i < number; i++)
        dequeue(first, last);
    return 0;
}
