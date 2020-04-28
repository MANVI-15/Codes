#include<iostream>
#include<list>
using namespace std;
//Basic code of implementation of queue
class queue1
{
  int cs;
  list<int>arr;
  public:
  queue1(int def_size=10)
  {
      this->cs=0;
  }
  bool isempty()
  {
     return (this->cs==0);
  }
  void enqueue(int data)
  {
      this->arr.push_back(data);
      this->cs+=1;
  }
  void dequeue()
  {
      this->arr.pop_front();
      this->cs-=1;
  }
   int get_front()
   {
       return this->arr.front();
    }
};
int main()
{
    queue1 q;
    for(int i=0;i<7;i++)
    {
        q.enqueue(i);
    }
    q.dequeue();
    q.dequeue();
    while(!q.isempty())
    {
        cout<<q.get_front();
        q.dequeue();
    }
}
