#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//The differential equation considered is dy/dx=f(x,y)=-2xy^2
//Defining the function f(x,y)=-2xy^2.

float func(float X,float Y)
{
	float F;
	F=-2*X*pow(Y,2);
	return F;
}


//Defining the exact analytical form of the solution

float sol(float X)
{
	float S;
	S=1/(1+pow(X,2));
	return S ;
}

//Main program starts here
int main()

{
float h,a,b,y[50],y0,N,x[50],k1,k2,K1,u[50],t[50],v[50],p[50],g[50],A[50],
    B[50],C[50];

cout.precision(6);
cout.setf(ios::fixed);

cout<<"Enter lower limit of interval"<<endl;
cin>>a;
cout<<"Enter upper limit of interval"<<endl;
cin>>b;
cout<<"Enter initial value of function"<<endl;
cin>>y0;
cout<<"Enter step size"<<endl;
cin>>h;
N=(abs(a)+abs(b))/h;
cout<<"N="<<N<<endl;

//Assigning initial values
y[0]=y0;
x[0]=a;

//Euler's Method
u[0]=y0;
x[0]=a;

//Calculating the function value at various points
for(int i=1;i<=N;i++)
 {

     y[i]=y[i-1]+h*func(x[i-1],y[i-1]);
     x[i]=x[i-1]+h;

 }


 //Heun's Method
 //Assigning initial values
u[0]=y0;
t[0]=a;

//Calculating the function values at various points using Heun's Method
 for(int i=1;i<=N;i++)
     {

        k1=func(t[i-1],u[i-1]);
         t[i]=t[i-1]+h;
         k2=func(t[i-1]+h,(u[i-1]+h*k1));
         u[i]=u[i-1]+(h/2)*(k1+k2);
     }

//RK2 Method

//Assigning the initial values
v[0]=y0;
p[0]=a;

//Calculating the function values at various points by RK2 Method
for(int i=1;i<=N;i++)
    {

        K1=(h/2)*func(p[i-1],v[i-1]);
        p[i]=p[i-1]+h;
        v[i]=v[i-1]+h*func(p[i-1]+(h/2),v[i-1]+K1);
    }

//Calculating the exact values of function at the same points as considered above

x[0]=a;
 for(int i=0;i<=N;i++)
    {

        g[i]=sol(x[i]);
        x[i+1]=x[i]+h;
    }

//Calculating the percentage error in solutions from all the above methods
//Error=solution(exact)-solution(method)/solution(exact)

 for(int i=0;i<=N;i++)
 {
   A[i]=(g[i]-y[i])/(g[i]);
   B[i]=(g[i]-u[i])/(g[i]);
   C[i]=(g[i]-v[i])/(g[i]);

 }

//Displaying the results in a table


 cout<<setw(15)<<"x"<<setw(5)<<"|"
   <<setw(15)<<"Exact"<<setw(5)<<"|"
   <<setw(15)<<"Euler"<<setw(5)<<"|"
   <<setw(15)<<"Heun"<<setw(5)<<"|"
   <<setw(15)<<"RK2"<<setw(5)<<"|"<<endl;

for(int i=1;i<=100;i++)
{
    cout<<"-";
}

cout<<endl;

cout<<setw(20)<<"|"<<setw(20)<<"|"
<<setw(9)<<"Solution"<<setw(1)<<"|"<<setw(9)<<"Error"<<setw(1)<<"|"
<<setw(9)<<"Solution"<<setw(1)<<"|"<<setw(9)<<"Error"<<setw(1)<<"|"
<<setw(9)<<"Solution"<<setw(1)<<"|"<<setw(9)<<"Error"<<setw(1)<<"|"<<endl;

for(int i=1;i<=100;i++)
{
    cout<<"-";
}

cout<<endl;
for(int i=0;i<=N;i++)
{
    cout<<setw(15)<<x[i]<<setw(5)<<"|"
   <<setw(15)<<g[i]<<setw(5)<<"|"
   <<setw(9)<<y[i]<<setw(1)<<"|"
   <<setw(9)<<A[i]<<setw(1)<<"|"
   <<setw(9)<<u[i]<<setw(1)<<"|"
   <<setw(9)<<B[i]<<setw(1)<<"|"
   <<setw(9)<<v[i]<<setw(1)<<"|"
   <<setw(9)<<C[i]<<setw(1)<<"|"<<endl;
}

return 0;
}

