#include<iostream>
using namespace std;
class edge
{
public:
  int u;
  int v;
  public:
  edge(){}
  edge(int u,int v)
  {
    this->u=u;
    this->v=v;
  }
};
class set
{
  public:
  int parent;
  int rank;
};
int findset(int u,set *s)
{
  if(s[u].parent!=u)
  {
    s[u].parent=findset(s[u].parent,s);
  }
  return(s[u].parent);
}
void union1(int u,int v,set *s)
{
    int parent1=findset(u,s);
    int parent2=findset(v,s);
    if(s[parent1].rank>s[parent2].rank)
    {
       s[parent2].parent=parent1;
       s[parent1].rank=s[parent1].rank+1;
    }
    else if(s[parent2].rank>s[parent1].rank)
    {
       s[parent1].parent=parent2;
       s[parent2].rank=s[parent2].rank+1;
+
    }
    else
    {
       s[parent2].parent=parent1;
       s[parent1].rank=s[parent1].rank+1;
    }
};
bool find_cycle(edge *e,int n,int v)
{
    set *s=new set[v];
    for(int i=0;i<v;i++)
    {
        s[i].parent=i;
        s[i].rank=0;
    }
    for(int i=0;i<n;i++)
    {
        int parent1=findset(e[i].u,s);
        int parent2=findset(e[i].v,s);
        if(parent1==parent2)
        {
            return true;
        }
        union1(parent1,parent2,s);
    }
    return false;
}
int main()
{
int n,v;
cin>>n>>v;
edge *e=new edge[n];
for(int i=0;i<n;i++)
{
  int u,v;
  cin>>u>>v;
  edge p(u,v);
  e[i]=p;
}
cout<<find_cycle(e,n,v);
}
