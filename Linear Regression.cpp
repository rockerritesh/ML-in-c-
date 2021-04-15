// In this program i have made a simple linear regression model of two variable i.e. y =mx+b.
// And by using gradient update same as machine learning model this program automatically update the value of m and b in each iteration.
// this program is only prototype of house price predicting model.
// let us suppose the value of house is y , and the value of house depends upon area of land ie x and  b is any constant prameters in our program.
// And if we feed the value of price and area, this model will predict the corelation between how land area is linearly depends upon price.
// This program suppose price and area are linearly dependent.
//


#include <iostream>
#include<math.h>

using namespace std;

long double cost(long double y[] , long double y_pred[] , int l);

long double y_pred( long double x,long double m, long double b);

long double mupdate(long double x, long double y , long double y_pred );

long double cupdate(long double y , long double y_pred );

int main()
{
    long double y[14] ={20,30,40,50,60,70,80,90,100,110,120,130,140,150}; // here y_train "dont forget to change the value of size of array if you want to use it on your data"
    long double x[14] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14};  // here x_train      "dont forget to change the value of size of array if you want to use it on your data"
    int l=sizeof(x)/sizeof(x[0]);   // to find length of array
    long double m= 20;     // value of m initial
    long double b=0;       // value of b initial
    long double y_predict[l];   //array y_predict


    long double m1,b1;        // finial value of m & b
    int i,j;
    long double mi,ci;

    long double sum=0;
    long double hum = 0;
    long double z;

    int iteration=20;  //number of times function will call or training loop

    for(j=0;j<iteration;j++){




    for(i=0;i<l;i++){

        z=y_pred(x[i],m,b);
        y_predict[i]=z;

    }


    for(i=0;i<l;i++)
    {
        mi=mupdate(x[i],y[i],y_predict[i]);
        m1=-(sum+mi)/l;

    }
    for(i=0;i<l;i++)
    {
        ci = cupdate(y[i],y_predict[i]);
        b1=-(hum+ci)/l;
    }

    m = m- 0.1*m1;
    b = b - 0.1*b1;

    cout<<j+1<<"\t"<<"loss= "<<cost(y,y_predict, l)<<"\t"<<"m="<< m<<"\t"<<"b="<<b<<"\n";


    }
    //cout<<m << "&"<< b; //final value will store in m and b


}
// y_pred
long double y_pred(long double x,long double m,long double b)
{
     return x*m +b ;
}


// cost function
long double cost(long double y[], long double y_pred[],int l)
 {
    int i,q;
    int p=0;
    for(i=0;i<l;i++)
    {
        long double q=(y[i]-y_pred[i])*(y[i]-y_pred[i]);
        p=p+q;
    }
    return p/l;
    //return y;
 }

 // m update in each gradient update

 long double mupdate(long double x, long double y , long double y_pred)
 {
     return x*(y-y_pred);

 }

 // c update in each gradient update

 long double cupdate(long double y , long double y_pred )
 {
        return y-y_pred;
 }
