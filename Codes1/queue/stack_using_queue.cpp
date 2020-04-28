#include<iostream>
#include<queue>
using namespace std;
//Implementation of stack using queue
class stack1
{
    queue<int>primary;
    queue<int>secondary;
    public:
void push(int data)
{
  primary.push(data);
  return;
}
bool isempty()
{
    return(primary.empty());
}
void pop()
{
    if(!primary.empty())
    {
        while(primary.size()>1)
        {
            secondary.push(primary.front());
            primary.pop();
        }
    }
    primary.pop();
    primary.swap(secondary);
    return;
}
int top()
{
   if(!primary.empty())
    {
        while(primary.size()>1)
        {
            secondary.push(primary.front());
            primary.pop();
        }
    }
    int l=primary.front();
    secondary.push(l);
    primary.pop();
    primary.swap(secondary);
    return l;
}

};
int main()
{
    stack1 p;
    for(int i=0;i<7;i++)
    {
        p.push(i);
    }
    p.pop();
    while(!p.isempty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}
