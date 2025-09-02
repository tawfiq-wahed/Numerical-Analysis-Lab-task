#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int main()
{//double x[10],y[10];
int n=4,x1=5;
double x[]={0,1,3,8};
double y[]={1,3,13,123};
double ans=0;

for(int i=0;i<n;i++)
{
    double c=y[i];

    for(int j=0;j<n;j++)
    {
       if(i!=j) c*=(x1-x[j])/(x[i]-x[j]);
    }
  //  cout<<c<<endl;
    ans+=c;
}
cout<<ans<<endl;
}
