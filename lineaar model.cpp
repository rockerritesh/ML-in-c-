#include <iostream>
#include<math.h>

using namespace std;

float cost(float y[] , float y_pred[]);

float y_pred( float x[],float m,float b);

int main()
{
    float y[3] ={30000,50000,70000};
    float x[3] ={10,20,30};
    float b=3;
    float m= 100
    float y_pred[3]= y_pred(x[],100,2);
    cout<<"loss= "<<cost(y,y_pred);


}
// y_pred
float y_pred(float x[],float m,float b)
{
    float y_p[3];
    int i;
    for(i=0;i<3,i++)
    {

        y_p[i]=m*x[i]+b;

    }
     return y_p;
}


// cost function
float cost(float y[], float y_pred[])
 {
    int i,q;
    int p=0;
    for(i=0;i<3;i++)
    {
        float q=(y[i]-y_pred[i])*(y[i]-y_pred[i]);
        p=p+q;
    }
    return p/3;
    //return y;
 }
