#include<bits/stdc++.h>
using namespace std;
class graph
{
  map<int,list<pair<int,int>>>adjlist;
  public:
  void create(int u,int v,int weight,bool diric=true)
  {
    adjlist[u].push_back(make_pair(v,weight));
    if(diric)
    {
     adjlist[v].push_back(make_pair(u,weight));
    }
  }
  int dijikstra(int src)
  {
      map<int,int>dist;
      map<int,bool>visited;
      for(auto node:adjlist)
      {
          dist[node.first]=INT_MAX;
          visited[node.first]=false;
      }
      visited[src]=true;
      dist[src]=0;
      set<pair<int,int>>s;
      s.insert(make_pair(0,src));
      while(!s.empty())
      {
          auto p=*(s.begin());
          s.erase(s.begin());
          visited[p.second]=true;
          for(auto vertex:adjlist[p.second])
          {
              if(!visited[vertex.first] && (vertex.second+p.first)<dist[vertex.first])
              {
                  auto removal=s.find(make_pair(dist[vertex.first],vertex.first));
                  if(removal!=s.end())
                  {
                      s.erase(removal);
                  }
                  dist[vertex.first]=p.first+vertex.second;
                  s.insert(make_pair(dist[vertex.first],vertex.first));

              }
          }
      }
  for(auto i:adjlist)
  {
      if(i.first!=src)
      cout<<dist[i.first]<<" ";
  }
  }
};
int main()
{
 int t,x,y,r;
 cin>>t;
 for(int i=0;i<t;i++)
 {
     graph g;
     int n,m;
     cin>>n>>m;
     for(int i=0;i<m;i++)
     {
         cin>>x>>y>>r;
         g.create(x,y,r);
     }
     int src;
     cin>>src;
     g.dijikstra(src);
 }
return 0;
}
