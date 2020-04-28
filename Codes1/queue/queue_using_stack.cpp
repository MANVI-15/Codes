#include<iostream>
#include<queue>
using namespace std;
//Implementation of queue using stack
class stack1
{
    queue<int>primary;
    queue<int>secondary;
    public:
void push(int data)
{
  secondary.push(data);
  while(!primary.empty())
  {
      secondary.push(primary.front());
      primary.pop();
  }
  primary.swap(secondary);
  return;
}
bool isempty()
{
    return(primary.empty());
}
void pop()
{
   primary.pop();
}
int top()
{
   return primary.front();
}

};
int main()
{
    stack1 p;
    for(int i=0;i<7;i++)
    {
        p.push(i);
    }

    while(!p.isempty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}
