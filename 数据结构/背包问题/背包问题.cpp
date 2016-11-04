#include<iostream>
using namespace std;
int mark[15];
int w[10]= {1,2,10,4,5,6,10,8,9,3};
int count=0;
void knap(int s,int n)
{
    if(s==0)
    {
        int j;
        for(j=0; j<count; j++)
            cout<<mark[j]<<"  ";
        cout<<endl;
    }

    else if(s<0||n<1) {}
    else
    {
        int i;
        for(i=0; i<2; i++)
        {
            if(i==0)knap(s,n-1);
            else
            {
                int t=count;
                mark[count]=w[n-1];
                count++;
                knap(s-w[n-1],n-1);
                count=t;
            }
        }

    }
}
int main()
{
    knap(8,10);
    return 0;
}
