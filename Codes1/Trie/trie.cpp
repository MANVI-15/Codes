#include<bits/stdc++.h>
using namespace std;
/* Basic implementation of trie code of insertion in trie and code to search that string*/

class node
{
  public:
  char data;
  bool is_terminal=false;
  unordered_map<char,node*> map;
  node(int data)
  {
    this->data=data;
  }
};
class trie
{
  node *root;
  public:
  trie()
  {
    root=new node('\0');
  }
void insert(string s)
{
  int length=s.length();
  node *temp=root;
  for(int i=0;i<length;i++)
  {
     char ch=s[i];
     if(temp->map.find(ch)!=temp->map.end())
     {
       temp=temp->map[ch];
     }
     else
     {
       node *temp1=new node(s[i]);
       temp->map[ch]=temp1;
       temp=temp1;
     }
  }
 temp->is_terminal=true;
}
bool search(string s)
{
  int length=s.length();
  node *temp=root;
  for(int i=0;i<length;i++)
  {
     char ch=s[i];
    if(temp->map.find(ch)!=temp->map.end())
    {
       temp=temp->map[ch];
    }
    else
    {
      return false;
    }
  }
  return temp->is_terminal;
}
};
int main()
{
	trie t;
	string arr[] = {"apple","ape","application","note","news"};
	for(int i=0;i<5;i++){
		t.insert(arr[i]);
	}
	cout<<t.search("application")<<endl;
	cout<<t.search("app")<<endl;

	return 0;
}




