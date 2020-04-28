#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    int freq;
    node *left;
    node *right;
    node()
    {

    }
    node(char data,int freq)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->freq=freq;
    }
    node(int freq)
    {
        this->data='\0';
        this->left=NULL;
        this->right=NULL;
        this->freq=freq;
    }
};
class compare
{
    public:
  bool operator()(node *p,node *q)
  {
    return p->freq>q->freq;
  }
};
string ans="";
char ch1='0';
char ch2='1';
bool search1(node *head,char s,string t)
{
    if(head==NULL)
    {

        return false;

    }
    if(head->data==s)
    {
        ans=t;
        return true;
    }
    bool p=search1(head->left,s,t+ch1);
    bool r=search1(head->right,s,t+ch2);
    if(p==true || r==true)
    {

        return true;
    }
    return false;
}
int main()
{
    cout<<"enter the string in capital letters";
    string s;
    cin>>s;
    unordered_map<char,int>freq;
    priority_queue<node*,vector<node*>,compare>pq;
    for(int i=0;i<=128;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]]=freq[s[i]]+1;

    }
    unordered_map<char,int>::iterator it=freq.begin();
    while(it!=freq.end())
    {
      if(it->second!=0)
      {
        node *n=new node(it->first,it->second);
        pq.push(n);
      }
      it++;
    }
    map<char,string>encoder;
    map<string ,char>decoder;
    while(pq.size()>1)
    {
        node *n1=pq.top();
        pq.pop();
        node *n2=pq.top();
        pq.pop();
        int frequency=n1->freq+n2->freq;
        node *n=new node(frequency);
        pq.push(n);
        n->left=n1;
        n->right=n2;

    }
    node *head=pq.top();
    pq.pop();
    for(int i=0;i<s.length();i++)
    {
        ans="";
        if(encoder.find(s[i])==encoder.end())
        {
            if(search1(head,s[i],""))
            {
                decoder[ans]=s[i];
                encoder[s[i]]=ans;
            }
        }
    }
    map<char,string>::iterator it1=encoder.begin();
    cout<<"ENCODER"<<endl<<endl;
    while(it1!=encoder.end())
    {
        cout<<it1->first<<"->"<<it1->second<<endl;
        it1++;
    }
    cout<<endl<<"DECODER:"<<endl<<endl;
    map<string,char>::iterator it2=decoder.begin();
    while(it2!=decoder.end())
    {
        cout<<it2->first<<"->"<<it2->second<<endl;
        it2++;
    }
    string code="";
    for(int i=0;i<s.length();i++)
    {
       code=code+encoder[s[i]];
    }
    cout<<endl<<"Coded string:"<<code;
    string decode="";
    string use="";
    for(int i=0;i<code.length();i++)
    {
        use=use+code[i];
        if(decoder.find(use)!=decoder.end())
        {
            decode=decode+decoder[use];
            use="";
        }
    }
    cout<<endl<<"decoded string:"<<decode;

}
