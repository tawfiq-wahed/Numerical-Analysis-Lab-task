stack<char>st;
int n;
cin>>n;
string s;
cin>>s;
int ans=1,d=0;
for(int i=0;i<n;i++)
{if(st.top()!=s[i] &&d>0 &&!st.empty())
{
    ans++;
    d=0;
    st.pop();
}
  else if(st.empty()||st.top()!=s[i])
   {
       st.push(s[i]);
   }
   else if(st.top()==s[i])
   {d++;
       continue;
   }

}
map<char,int>cnt;
if(st.size())
{while(!st.empty())
{
    char u=st.top();
    st.pop();
    cnt[u]++;
}
int x=cnt.size()-1;
int c=0;

for(auto u:cnt)
{
    if(c<x)
    {
        ans+=u.S;
    }
    c++;
}
}
cout<<ans<<endl;
