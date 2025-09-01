
void bfs(string s)
{lev.clear();
    lev[s]=1;
    queue<string>q;
    q.push(s);
    while(!q.empty())
          {
              string u=q.front();
                q.pop();
    for(auto v:adj[u])
    {
        if(lev[v]==0)
        {
            lev[v]=lev[u]+1;
            par[v]=u;
            q.push(v);
        }
    }


          }

}

int main()
{ tawfiq();
    int t;
    bool yes=0;
    while(cin>>t)
    {if(yes)cout<<endl;
    yes=1;
    adj.clear();
    par.clear();
    for(int i=0;i<t;i++)
    {
        string u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    string s,t;cin>>s>>t;
    bfs(s);
    if(lev[t]==0)
        {

        }
    vector<pair<string,string>>ans;
    while(!par[t].empty())
    {
        ans.pb({par[t],t});
        t=par[t];
    }
      reverse(ans.begin(),ans.end());

    }
}



ll seg[4*p];
ll a[p];
void build(ll index,ll left,ll right)
{
    if(left==right)
    {
        seg[index]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(2*index,left,mid);
    build(2*index+1,mid+1,right);
    seg[index]=seg[2*index]+seg[2*index+1];

}
ll query(ll index,ll left,ll right,ll l,ll r)
{
    if(right<l ||r<left)return 0;
    if(left>=l &&right<=r)return seg[index];
    ll mid=(left+right)/2;
    ll leftsum=query(2*index,left,mid,l,r);
    ll rightsum=query(2*index+1,mid+1,right,l,r);
    return leftsum+rightsum;
}
void update(ll index,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(pos==left&&pos==right)
    {
        seg[index]=val;
        return;
    }
    ll mid=(left+right)/2;
    update(2*index, left, mid, pos, val);
    update(2*index+1, mid+1, right, pos, val);
    seg[index]=seg[2*index]+seg[2*index+1];



bool vis[4*mx];
ll prop[4*mx];
vll v(mx);
void shifting(int index)
{
    prop[2*index]+=prop[index];
    prop[2*index+1]+=prop[index];
    prop[index]=0;
    vis[index*2]=vis[index*2+1]=1;
    vis[index]=0;
}
void build(int index,int left,int right)
{
    if(left==right)
    {
        prop[index]=v[left];
        return;
    }
    int mid=(left+right)/2;
    build(index*2,left,mid);
    build(2*index+1,mid+1,right);
}
void update(int index,int left,int right,int l,int r,int val)
{
    if(r<left||l>right)return;
    if(left>=l &&right<=r){
            prop[index]+=val;
            vis[index]=1;
            return;
    }
  int  mid=(left+right)/2;
    update(2*index,left,mid,l,r,val);
    update(2*index+1,mid+1,right,l,r,val);
}
ll query(int index,int left,int right,int i)
{
    if(i<left||i>right)return 0;
    if(i==left &&i==right)return prop[index];
    int mid=(left+right)/2;
    if(vis[index])
    {
        shifting(index);
    }
    ll leftS=query(2*index,left,mid,i);
    ll rightS=query(2*index+1,mid+1,right,i);
    return leftS+rightS;
}


class cmp{
public :
    int operator()(int a ,int b)
    {
       if(a<b) return false;
       else return true;
    }
    };

pair<bool,pair<int,int>>check(vector<ll>&v,ll n,ll mid,ll m)
{
    vll plate(n);
    for(int i=0;i<n;i++)
    {
        if(v[i]<mid)plate[i]=-1;
        else plate[i]=1;
    }
    vll pref(n);
    pref[0]=plate[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+plate[i];
    }
    ll mn=0,mnpos=0;
    for(int i=m-1;i<n;i++)
    {
        if(pref[i]-mn>=0)
        {
            return{true,{mnpos,i}};
        }
        if(pref[i-m+1]<mn)
        {
            mn=pref[i-m+1];
            mnpos=i-m+2 ;
        }
    }
    return {false,{-1,-1}};
}

void solve(int t)
{
ll n,m;
cin>>n>>m;
vll v(n);
for(int i=0;i<n;i++)cin>>v[i];
ll l=1,r=n,mid;
ll ans,l1,r1;
while(l<=r)
{
    mid=(l+r)/2;
    auto it=check(v,n,mid,m);
    if(it.F)
    {
        ans=mid;
        l1=it.S.F;
        r1=it.S.S;
        l=mid+1;
    }
   else r=mid-1;
}


vector<int>prime_factor(int n)
{int c=0;
vector<int>factors;
    for(auto u:primes)
    {if((u*u)>n)break;
        if(n%u==0)
        {
            while(n%u==0)
            {
                c++;
                n/=u;
                factors.pb(u);
            }
        }
    }
    if(n>1){
            factors.pb(n);
    }
    return factors;
}

ll sod(ll n)
{ll sood=1;
    for(auto u:primes)
    {if(1ll*u*u>n)break;
    if(n%u==0)
        {
            ll sum=0;
        ll a=1;
        while(n%u==0)
        {
           a*=u;
           sum+=a;
           n/=u;
        }

        sood*=(sum+1);
        }
    }
    if(n>1)sood*=(n+1);
    return sood;
}


