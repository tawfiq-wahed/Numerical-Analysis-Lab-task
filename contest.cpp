#include<bits/stdc++.h>
#include<cmath>
using namespace std;

double f(double x)
{
    double y=log(3*x)-3;
    return y;
}
int main()
{
    double error=0.0001;
    double a=1,b=10;
  double c;
  int k=0;
    while(fabs(a-b)>=error)
    {
        if((f(b)-f(a))<1e-12)
    {
        cout<<"method fail"<<endl;;
       break;

    }

         c=((a*f(b))-b*f(a))/(f(b)-f(a));
      if(fabs(f(c))<error)   {
            cout<<fixed<<setprecision(10)<<c<<endl;
      break;
      }
         //double d=f(c);
         double e=f(a)*f(c);
         if(e>0)
         {
             cout<<"No root is found in this interval "<<endl;
         }
         if(e<0)
         {
             b=c;
         }
         else a=c;
         k++;
         cout<<"iteration no: "<<fixed<<setprecision(10)<<k<<", "<<"value of a: "<<fixed<<setprecision(10)<<a<<", "<<"value of b: "<<fixed<<setprecision(10)<<b<<", "<<"value of c: "<<fixed<<setprecision(10)<<c<<", "<<fixed<<"value of f(c): "<<setprecision(10)<<f(c)<<endl;
    }
    cout<<"Root : "<<fixed<<setprecision(10)<<c<<endl;
}
