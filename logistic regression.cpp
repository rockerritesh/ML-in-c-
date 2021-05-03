// In this program i have made a simple logistic regression model of two variable i.e. y =mx+b.
// And by using gradient update same as machine learning model this program automatically update the value of m and b in each iteration.
// this program is only prototype of binary classes predicting model.


#include <iostream>
#include<math.h>
#include <cmath>

using namespace std;

long double cost(long double y[] , long double y_pred[] , int l);

long double y_pred( long double x,long double m, long double b);

long double mupdate(long double x, long double y , long double y_pred );

long double cupdate(long double y , long double y_pred );

int main()
{
    long double y[41] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // here y_train "dont forget to change the value of size of array if you want to use it on your data"
    long double x[41] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,101,111,101,111,101,115,101,118,103,115,111,101,111,105,111,102};  // here x_train      "dont forget to change the value of size of array if you want to use it on your data"
    int l=sizeof(x)/sizeof(x[0]);   // to find length of array
    long double m= 0;     // value of m initial
    long double b=0;       // value of b initial
    long double y_predict[l];   //array y_predict


    long double m1,b1;        // finial value of m & b
    int i,j;
    long double mi,ci;

    long double sum=0;
    long double hum = 0;
    long double z;

    int iteration=5000;  //number of times function will call or training loop


    for(j=0;j<iteration;j++){




    for(i=0;i<l;i++){

        z=y_pred(x[i],m,b);

        y_predict[i]=z;

    }


    for(i=0;i<l;i++)
    {
        mi=mupdate(x[i],y[i],y_predict[i]);
        m1=-2*(sum+mi);

    }
    for(i=0;i<l;i++)
    {
        ci = cupdate(y[i],y_predict[i]);
        b1=-2*(hum+ci);
    }

    m = m - 0.001*m1;
    b = b + 0.001*b1;

    cout<<j+1<<"\t"<<"loss= "<<cost(y,y_predict, l)<<"\t"<<"m="<< m<<"\t"<<"b="<<b<<"\n";


    }
    //cout<<m << "&"<< b; //final value will store in m and b
    int p;
    cin >> p;
    cin.ignore();
    cout << 1/(1+ exp(-(p*m +b)));
    return 0;
}
// y_pred
long double y_pred(long double x,long double m,long double b)
{
     return 1/(1+ exp(-(x*m +b))) ;
}


// cost function
long double cost(long double y[], long double y_pred[],int l)
 {
    int i,q;
    int p=0;
    for(i=0;i<l;i++)
    {
        long double q=(-(y[i]*log(y_pred[i]))-((1-y[i])*log(1-y_pred[i])));
        p=p+q;
    }
    return p/l;
    //return y;
 }

 // m update in each gradient update

 long double mupdate(long double x, long double y , long double y_pred)
 {
     return x*(y-y_pred)*y_pred*(1-y_pred);

 }

 // c update in each gradient update

 long double cupdate(long double y , long double y_pred )
 {
        return (y-y_pred)*y_pred*(1-y_pred);
 }
