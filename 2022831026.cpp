
#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<numeric>
#include <algorithm>
using namespace std;
#define orderedset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define tawfiq_loves_nbs() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define mod 100000007
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define sqr(a) ((a)*(a))
typedef vector<int>vi;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pair<int,int>>vpii;
typedef vector<pair<ll,ll>>vpll;

const int mx=3e3+5;
const double mx1=-100000000.00000;
const int inf=1e9;
vll adj[mx];


ll mul(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)*(((b%mod)+mod)%mod))%mod;
}

ll add(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)+(((b%mod)+mod)%mod))%mod;
}

void solve(int t1)
{
    string s;
    cin>>s;
    int pos;
    cin>>pos;
}


 int main()
 {
     tawfiq_loves_nbs();
    int t=1;
cin>>t;
//file();
for(int i=1;i<=t;i++)
     {
       solve(i);
     }
  }
