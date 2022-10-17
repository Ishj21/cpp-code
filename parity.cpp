#include <bits/stdc++.h>
using namespace std;

class stackArr
{
private:
    char *data;
    int nextIndex;
    int capacity;

public:
    stackArr(int ts)
    {
        data = new char[ts];
        nextIndex = 0;
        capacity = ts;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(char ele)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is Full";
            return;
        }
        data[nextIndex] = ele;
        nextIndex++;
    }

   //insert pop here
    int top()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

char oneCount(char a[], stackArr s)
{
    for (int i = 0; i < 15; i++)
    {
        if (a[i] == '1')
        {
            if (s.isEmpty())
            {
                s.push('1');
            }
            else
            {
                s.pop();
            }
        }
    }
    if (!s.isEmpty())
    {
        return '1';
    }
    else
    {
        return '0';
    }
}

int main()
{
    stackArr s(1);
    char a[16] = {};
    cout<<endl<<"Enter BIT String for checking"<<endl;
    for (int i = 0; i < 15; i++)
    {
        cin >> a[i];
    }
    char b = oneCount(a, s);
    cout<<endl<<"Output with Parity Bit is: "<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout << a[i];
    }
    cout << b;
    cout<<endl;
    return 0;
}
