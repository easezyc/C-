#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
const int alltime=43824;  //总的小时数
int randstoptime()
{
    int k=rand()%40;
    k=k+4;
    return k;
}
int randnexttime()
{
    int k=rand()%30;
    k=k+15;
    return k;
}
struct waitboat{
    int i_stoptime,i_arrivetime;
    waitboat *next;
    waitboat(){next=NULL;}
    waitboat(int a,int s,waitboat *ptr=NULL)
    {
        i_stoptime=s;
        i_arrivetime=a;
        next=ptr;
    }
};
class WaitBoat
{
private:
    waitboat *boat,*current;
    int number;
public:
    WaitBoat()
    {
        boat=new waitboat();
        current=boat;
        number=0;
    }
    ~WaitBoat(){}
    int getnumber()
    {
        return number;
    }
    void insertboat(int &x,int &y)
    {
        waitboat *t=new waitboat(x,y);
        t->next=current->next;
        current->next=t;
        number++;
    }
    int removeboat()
    {
        int stoptime=0;
        if(number!=0)
        {
            waitboat *ptr=boat->next;
            stoptime=ptr->i_stoptime;
            boat->next=ptr->next;
            number--;
        }
        return stoptime;
    }
};
int main()
{
    srand(time(NULL));
    WaitBoat WaitBoat;
    int start,finish;
    double d_money=0;;
    int i_time=0,i_randstoptime,i_randnexttime,mark=0,i_movetime=0,number,i_arrivetime,i_stoptime;
    i_randstoptime=randstoptime();
    i_movetime+=i_randstoptime;
    mark=1;
    i_arrivetime=0;
    start=clock();
    while(i_time<alltime)
    {
        if(i_movetime==i_time)
        {
            mark=0;
        }
        if(i_time==i_arrivetime)
        {
            waitboat newboat;
            i_randnexttime=randnexttime();
            i_randstoptime=randstoptime();
            i_arrivetime=i_time+i_randnexttime;
            i_stoptime=i_randstoptime;
            newboat.i_arrivetime=i_arrivetime;
            newboat.i_stoptime=i_stoptime;
            WaitBoat.insertboat(i_arrivetime,i_stoptime);
        }
        number=WaitBoat.getnumber();
        if(mark==0&&number!=0)
        {
            i_movetime=i_time+WaitBoat.removeboat();
            mark=1;
        }
        number=WaitBoat.getnumber();
        d_money+=number*1000;
        i_time++;
    }
    finish=clock();
    cout<<"5年内节约的总资金为:"<<d_money<<"元"<<endl;
    cout<<"程序运行所用时间:"<<finish-start<<endl;
    return 0;
}
