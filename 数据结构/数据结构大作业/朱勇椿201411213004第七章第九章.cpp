#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct airquality
{
    string num,city,category,level1,level2;
    int zhishu,year,month,day;
    int number=0;
    void getnumber()
    {
        int j=1;
        for(; j<month; j++)
        {
            if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)number+=31;
            else if(j==2)number+=28;
            else number+=30;
        }
        number+=day;
    }
};
struct citytongji
{
    string city="";
    double num=0;
    int level[6]= {0,0,0,0,0,0};
};
airquality save[100001];
void putongday(string q,int month,int day)
{
    if(month>12||day>31)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    else if((month==4||month==6||month==9||month==11)&&day>30)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    else if(month==2&&day>28)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=1;
    for(; j<365; j++,i++)
        if(save[i].month==month&&save[i].day==day)break;
    if(j!=365)
        cout<<q<<"   "<<month<<"月"<<day<<"号空气质量为:"<<save[i].category<<"  "<<save[i].zhishu<<"  "<<save[i].level1<<"  "<<save[i].level2<<endl;
    else cout<<"无此条记录"<<endl;
}
void putongmonth(string q,int month)
{
    if(month>12)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=1;
    for(; j<365; j++,i++)
        if(save[i].month==month)break;
    if(j!=365)
    {
        for(int j=0; j<31; j++,i++)
            if(save[i].month==month)cout<<q<<"   "<<month<<"月"<<save[i].day<<"号空气质量为:"<<save[i].category<<"  "<<save[i].zhishu<<"  "<<save[i].level1<<"  "<<save[i].level2<<endl;
    }
    else cout<<"无此条记录"<<endl;
}
void tongjimonth(string q,int month)
{
    if(month>12)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int level[6]= {0,0,0,0,0,0};
    int j=1;
    for(; j<365; j++,i++)
        if(save[i].month==month)break;
    if(j!=365)
    {
        for(int j=0; j<31; j++,i++)
            if(save[i].month==month)
            {
                if(save[i].zhishu>0&&save[i].zhishu<=50)level[0]++;
                else if(save[i].zhishu>50&&save[i].zhishu<=100)level[1]++;
                else if(save[i].zhishu>100&&save[i].zhishu<=150)level[2]++;
                else if(save[i].zhishu>150&&save[i].zhishu<=200)level[3]++;
                else if(save[i].zhishu>200&&save[i].zhishu<=250)level[4]++;
                else level[5]++;
            }
        cout<<q<<"第"<<month<<"月空气质量统计:"<<endl;
        cout<<"优"<<level[0]<<"天"<<endl;
        cout<<"良"<<level[1]<<"天"<<endl;
        cout<<"轻微污染"<<level[2]<<"天"<<endl;
        cout<<"轻度污染"<<level[3]<<"天"<<endl;
        cout<<"中度污染"<<level[4]<<"天"<<endl;
        cout<<"重度污染"<<level[5]<<"天"<<endl;
    }
    else cout<<"无此条记录"<<endl;
}
void tongjimonth2(int q,int month)
{
    if(month>12)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    citytongji x[300];
    int j=0;
    x[0].city=save[0].city;
    for(i=0; i<100001; i++)
    {
        if(x[j].city!=save[i].city)
        {
            j++;
            x[j].city=save[i].city;
        }
        if(save[i].month==month)
        {
            if(save[i].zhishu>0&&save[i].zhishu<=50)x[j].level[0]++;
            else if(save[i].zhishu>50&&save[i].zhishu<=100)x[j].level[1]++;
            else if(save[i].zhishu>100&&save[i].zhishu<=150)x[j].level[2]++;
            else if(save[i].zhishu>150&&save[i].zhishu<=200)x[j].level[3]++;
            else if(save[i].zhishu>200&&save[i].zhishu<=250)x[j].level[4]++;
            else x[j].level[5]++;
        }
    }
    cout<<"2006年"<<month<<"月："<<endl;
    cout<<"空气优"<<q<<"天以上的有:"<<endl;
    int n;
    n=0;
    for(i=0; i<j; i++)
    {
        if(x[i].level[0]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气良"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[1]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if((n%5)==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻微污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[2]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[3]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气中度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[4]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气重度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[5]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
}
void paixumonth(int month)
{
    if(month>12)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    citytongji x[300];
    int i=0,j=0;
    double n=0,m=0;
    x[0].city=save[i].city;
    for(; i<100001; i++)
    {

        if(x[j].city!=save[i].city)
        {
            x[j].num=n/m;
            n=0;
            m=0;
            j++;
            x[j].city=save[i].city;
        }
        if(x[j].city==save[i].city&&save[i].month==month)
        {
            n+=save[i].zhishu;
            m++;
        }
    }
    int o=0;
    for(o=1; o<j; o++)
        for(i=j-1; i>=o; i--)
            if(x[i-1].num>x[i].num)
            {
                citytongji t=x[i-1];
                x[i-1]=x[i];
                x[i]=t;
            }
    for(i=0; i<20; i++)
        cout<<x[i].city<<"空气平均指数为:"<<x[i].num<<endl;
}
void putongweek(string q,int k)
{
    if(k>57)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int n=0;
    int j=0;
    cout<<q<<"第"<<k<<"周:"<<endl;
    for(int j=0; j<365; j++,i++)
        if(save[i].number<=k*7&&save[i].number>(k-1)*7)
        {
            cout<<q<<"   "<<save[i].month<<"月"<<save[i].day<<"号空气质量为:"<<save[i].category<<"  "<<save[i].zhishu<<"  "<<save[i].level1<<"  "<<save[i].level2<<endl;
            n++;
        }
    if(n==0)cout<<"无此周记录"<<endl;
}
void tongjiweek(string q,int k)
{
    if(k>57)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=0;
    cout<<q<<"第"<<k<<"周空气质量统计:"<<endl;
    int level[6]= {0,0,0,0,0,0};
    int n=0;
    for(int j=0; j<365; j++,i++)
    {
        if(save[i].number<=k*7&&save[i].number>(k-1)*7)
        {
            if(save[i].zhishu>0&&save[i].zhishu<=50)level[0]++;
            else if(save[i].zhishu>50&&save[i].zhishu<=100)level[1]++;
            else if(save[i].zhishu>100&&save[i].zhishu<=150)level[2]++;
            else if(save[i].zhishu>150&&save[i].zhishu<=200)level[3]++;
            else if(save[i].zhishu>200&&save[i].zhishu<=250)level[4]++;
            else level[5]++;
            n++;
        }
    }
    if(n==0)
    {
        cout<<"无此周记录"<<endl;
        return;
    }
    cout<<q<<"第"<<k<<"周空气质量统计:"<<endl;
    cout<<"优"<<level[0]<<"天"<<endl;
    cout<<"良"<<level[1]<<"天"<<endl;
    cout<<"轻微污染"<<level[2]<<"天"<<endl;
    cout<<"轻度污染"<<level[3]<<"天"<<endl;
    cout<<"中度污染"<<level[4]<<"天"<<endl;
    cout<<"重度污染"<<level[5]<<"天"<<endl;

}
void tongjiweek2(int q,int k)
{
    if(k>57)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    citytongji x[300];
    int j=0;
    x[0].city=save[0].city;
    for(i=0; i<100001; i++)
    {
        if(x[j].city!=save[i].city)
        {
            j++;
            x[j].city=save[i].city;
        }
        if(save[i].number<=k*7&&save[i].number>(k-1)*7)
        {
            if(save[i].zhishu>0&&save[i].zhishu<=50)x[j].level[0]++;
            else if(save[i].zhishu>50&&save[i].zhishu<=100)x[j].level[1]++;
            else if(save[i].zhishu>100&&save[i].zhishu<=150)x[j].level[2]++;
            else if(save[i].zhishu>150&&save[i].zhishu<=200)x[j].level[3]++;
            else if(save[i].zhishu>200&&save[i].zhishu<=250)x[j].level[4]++;
            else x[j].level[5]++;
        }
    }
    cout<<"2006年"<<k<<"周："<<endl;
    cout<<"空气优"<<q<<"天以上的有:"<<endl;
    int n;
    n=0;
    for(i=0; i<j; i++)
    {
        if(x[i].level[0]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气良"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[1]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if((n%5)==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻微污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[2]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[3]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气中度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[4]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气重度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[5]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
}
void paixuweek(int k)
{
    if(k>57)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    citytongji x[300];
    int i=0,j=0;
    double n=0,m=0;
    x[0].city=save[i].city;
    for(; i<100001; i++)
    {

        if(x[j].city!=save[i].city)
        {
            x[j].num=n/m;
            n=0;
            m=0;
            j++;
            x[j].city=save[i].city;
        }
        if(x[j].city==save[i].city&&save[i].number<=k*7&&save[i].number>(k-1)*7)
        {
            n+=save[i].zhishu;
            m++;
        }
    }
    int o=0;
    for(o=1; o<j; o++)
        for(i=j-1; i>=o; i--)
            if(x[i-1].num>x[i].num)
            {
                citytongji t=x[i-1];
                x[i-1]=x[i];
                x[i]=t;
            }
    for(i=0; i<20; i++)
        cout<<x[i].city<<"空气平均指数为:"<<x[i].num<<endl;
}
void putongyear(string q)
{
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=0;
    cout<<q<<"2006年空气质量:"<<endl;
    for(int j=0; j<365; j++,i++)
        cout<<save[i].month<<"月"<<save[i].day<<"号空气质量为:"<<save[i].category<<"  "<<save[i].zhishu<<"  "<<save[i].level1<<"  "<<save[i].level2<<endl;

}
void tongjiyear(string q)
{
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=0;
    int level[6]= {0,0,0,0,0,0};
    cout<<q<<"2006年空气质量统计:"<<endl;
    for(int j=0; j<365; j++,i++)
    {
        if(save[i].zhishu>0&&save[i].zhishu<=50)level[0]++;
        else if(save[i].zhishu>50&&save[i].zhishu<=100)level[1]++;
        else if(save[i].zhishu>100&&save[i].zhishu<=150)level[2]++;
        else if(save[i].zhishu>150&&save[i].zhishu<=200)level[3]++;
        else if(save[i].zhishu>200&&save[i].zhishu<=250)level[4]++;
        else level[5]++;
    }
    cout<<q<<"第2006年空气质量统计:"<<endl;
    cout<<"优"<<level[0]<<"天"<<endl;
    cout<<"良"<<level[1]<<"天"<<endl;
    cout<<"轻微污染"<<level[2]<<"天"<<endl;
    cout<<"轻度污染"<<level[3]<<"天"<<endl;
    cout<<"中度污染"<<level[4]<<"天"<<endl;
    cout<<"重度污染"<<level[5]<<"天"<<endl;

}
void tongjiyear2(int q)
{
    int i=0;
    citytongji x[300];
    int j=0;
    x[0].city=save[0].city;
    for(i=0; i<100001; i++)
    {
        if(x[j].city!=save[i].city)
        {
            j++;
            x[j].city=save[i].city;
        }
        if(save[i].zhishu>0&&save[i].zhishu<=50)x[j].level[0]++;
        else if(save[i].zhishu>50&&save[i].zhishu<=100)x[j].level[1]++;
        else if(save[i].zhishu>100&&save[i].zhishu<=150)x[j].level[2]++;
        else if(save[i].zhishu>150&&save[i].zhishu<=200)x[j].level[3]++;
        else if(save[i].zhishu>200&&save[i].zhishu<=250)x[j].level[4]++;
        else x[j].level[5]++;
    }
    cout<<"2006年："<<endl;
    cout<<"空气优"<<q<<"天以上的有:"<<endl;
    int n;
    n=0;
    for(i=0; i<j; i++)
    {
        if(x[i].level[0]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气良"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[1]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if((n%5)==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻微污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[2]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[3]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气中度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[4]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气重度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[5]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
}
void paixuyear()
{
    citytongji x[300];
    int i=0,j=0;
    double n=0,m=0;
    x[0].city=save[i].city;
    for(; i<100001; i++)
    {

        if(x[j].city!=save[i].city)
        {
            x[j].num=n/m;
            n=0;
            m=0;
            j++;
            x[j].city=save[i].city;
        }
        if(x[j].city==save[i].city)
        {
            n+=save[i].zhishu;
            m++;
        }
    }
    int o=0;
    for(o=1; o<j; o++)
        for(i=j-1; i>=o; i--)
            if(x[i-1].num>x[i].num)
            {
                citytongji t=x[i-1];
                x[i-1]=x[i];
                x[i]=t;
            }
    for(i=0; i<20; i++)
        cout<<x[i].city<<"空气平均指数为:"<<x[i].num<<endl;
}
void putongseason(string q,int k)
{
    if(k>4)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=0;
    for(; j<365; j++,i++)
        if(save[i].month>(k-1)*3&&save[i].month<=k*3)break;
    cout<<q<<"第"<<k<<"季度空气质量:"<<endl;
    for(int j=0; j<93; j++,i++)
        if(save[i].month>(k-1)*3&&save[i].month<=k*3)cout<<q<<"   "<<save[i].month<<"月"<<save[i].day<<"号空气质量为:"<<save[i].category<<"  "<<save[i].zhishu<<"  "<<save[i].level1<<"  "<<save[i].level2<<endl;
}
void tongjiseason(string q,int k)
{
    if(k>4)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    for(; i<100001; i=i+1)
    {
        if(save[i].city==q)break;
    }
    if(i==100001)
    {
        cout<<"无此城市"<<endl;
        return;
    }
    int j=0;
    int level[6]= {0,0,0,0,0,0};
    for(; j<365; j++,i++)
        if(save[i].month>(k-1)*3&&save[i].month<=k*3)break;
    cout<<q<<"第"<<k<<"季度空气质量统计:"<<endl;
    for(int j=0; j<93; j++,i++)
        if(save[i].month>(k-1)*3&&save[i].month<=k*3)
        {
            if(save[i].zhishu>0&&save[i].zhishu<=50)level[0]++;
            else if(save[i].zhishu>50&&save[i].zhishu<=100)level[1]++;
            else if(save[i].zhishu>100&&save[i].zhishu<=150)level[2]++;
            else if(save[i].zhishu>150&&save[i].zhishu<=200)level[3]++;
            else if(save[i].zhishu>200&&save[i].zhishu<=250)level[4]++;
            else level[5]++;
        }
    cout<<q<<"2006年"<<k<<"季度空气质量统计:"<<endl;
    cout<<"优"<<level[0]<<"天"<<endl;
    cout<<"良"<<level[1]<<"天"<<endl;
    cout<<"轻微污染"<<level[2]<<"天"<<endl;
    cout<<"轻度污染"<<level[3]<<"天"<<endl;
    cout<<"中度污染"<<level[4]<<"天"<<endl;
    cout<<"重度污染"<<level[5]<<"天"<<endl;
}
void tongjiseason2(int q,int k)
{
    if(k>4)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    int i=0;
    citytongji x[300];
    int j=0;
    x[0].city=save[0].city;
    for(i=0; i<100001; i++)
    {
        if(x[j].city!=save[i].city)
        {
            j++;
            x[j].city=save[i].city;
        }
        if(save[i].month>(k-1)*3&&save[i].month<=k*3)
        {
            if(save[i].zhishu>0&&save[i].zhishu<=50)x[j].level[0]++;
            else if(save[i].zhishu>50&&save[i].zhishu<=100)x[j].level[1]++;
            else if(save[i].zhishu>100&&save[i].zhishu<=150)x[j].level[2]++;
            else if(save[i].zhishu>150&&save[i].zhishu<=200)x[j].level[3]++;
            else if(save[i].zhishu>200&&save[i].zhishu<=250)x[j].level[4]++;
            else x[j].level[5]++;
        }
    }
    cout<<"2006年"<<k<<"季度："<<endl;
    cout<<"空气优"<<q<<"天以上的有:"<<endl;
    int n;
    n=0;
    for(i=0; i<j; i++)
    {
        if(x[i].level[0]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气良"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[1]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if((n%5)==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻微污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[2]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气轻度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[3]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气中度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[4]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
    n=0;
    cout<<endl<<"空气重度污染"<<q<<"天以上的有:"<<endl;
    for(i=0; i<j; i++)
    {
        if(x[i].level[5]>=q)
        {
            cout<<x[i].city<<"   ";
            n++;
            if(n%5==0)cout<<endl;
        }
    }
}
void paixuseason(int k)
{
    if(k>4)
    {
        cout<<"Day value error!"<<endl;
        return;
    }
    citytongji x[300];
    int i=0,j=0;
    double n=0,m=0;
    x[0].city=save[i].city;
    for(; i<100001; i++)
    {

        if(x[j].city!=save[i].city)
        {
            x[j].num=n/m;
            n=0;
            m=0;
            j++;
            x[j].city=save[i].city;
        }
        if(x[j].city==save[i].city&&save[i].month>(k-1)*3&&save[i].month<=k*3)
        {
            n+=save[i].zhishu;
            m++;
        }
    }
    int o=0;
    for(o=1; o<j; o++)
        for(i=j-1; i>=o; i--)
            if(x[i-1].num>x[i].num)
            {
                citytongji t=x[i-1];
                x[i-1]=x[i];
                x[i]=t;
            }
    for(i=0; i<20; i++)
        cout<<x[i].city<<"空气平均指数为:"<<x[i].num<<endl;
}
int main()
{
    airquality x;
    ifstream infile;
    infile.open("data.txt",ios_base::in);
    if(!infile)
    {
        cout<<"读取错误"<<endl;
        exit(1);
    }
    int i=0;
    while(infile>>x.num>>x.city>>x.category>>x.zhishu>>x.level1>>x.level2>>x.year>>x.month>>x.day)
    {
        save[i]=x;
        save[i].getnumber();
        i++;
    }
    int k=i;
    char con;
    cout<<"普通查询请输入A，统计查询1请输入B,统计查询2请输入C，排序查询请输入D"<<endl;
    cin>>con;
    while(1)
    {
        if(con=='A')
        {
            char con1;
            cout<<"按照年查询请输入A，按照季度查询请输入B，按照月份查询请输入C，按照周查询请输入D，按照日查询请输入E:"<<endl;
            cin>>con1;
            if(con1=='A')
            {
                cout<<"请输入要查询的城市:";
                string city;
                cin>>city;
                putongyear(city);
            }
            if(con1=='B')
            {
                cout<<"请输入要查询的城市和季度:";
                string city;
                int n;
                cin>>city>>n;
                putongseason(city,n);
            }
            if(con1=='C')
            {
                cout<<"请输入要查询的城市和月份:";
                string city;
                int n;
                cin>>city>>n;
                putongmonth(city,n);
            }
            if(con1=='D')
            {
                cout<<"请输入要查询的城市和周:";
                string city;
                int n;
                cin>>city>>n;
                putongweek(city,n);
            }
            if(con1=='E')
            {
                cout<<"请输入要查询的城市和月份以及号数:";
                string city;
                int n,m;
                cin>>city>>n>>m;
                putongday(city,n,m);
            }
        }
        if(con=='B')
        {
            char con1;
            cout<<"按照年查询请输入A，按照季度查询请输入B，按照月份查询请输入C，按照周查询请输入D:"<<endl;
            cin>>con1;
            if(con1=='A')
            {
                cout<<"请输入要查询的城市:";
                string city;
                cin>>city;
                tongjiyear(city);
            }
            if(con1=='B')
            {
                cout<<"请输入要查询的城市和季度:";
                string city;
                int n;
                cin>>city>>n;
                tongjiseason(city,n);
            }
            if(con1=='C')
            {
                cout<<"请输入要查询的城市和月份:";
                string city;
                int n;
                cin>>city>>n;
                tongjimonth(city,n);
            }
            if(con1=='D')
            {
                cout<<"请输入要查询的城市和周:";
                string city;
                int n;
                cin>>city>>n;
                tongjiweek(city,n);
            }
        }
        if(con=='C')
        {
            char con1;
            cout<<"按照年查询请输入A，按照季度查询请输入B，按照月份查询请输入C，按照周查询请输入D:"<<endl;
            cin>>con1;
            if(con1=='A')
            {
                cout<<"请输入需要统计大于等于多少天"<<endl;
                int q;
                cin>>q;
                tongjiyear2(q);
            }
            if(con1=='B')
            {
                cout<<"请输入需要统计大于等于多少天,请输入要查询的季度:";
                int n,q;
                cin>>q>>n;
                tongjiseason2(q,n);
            }
            if(con1=='C')
            {
                cout<<"请输入需要统计大于等于多少天,请输入要查询月份:";
                int n,q;
                cin>>q>>n;
                tongjimonth2(q,n);
            }
            if(con1=='D')
            {
                cout<<"请输入要查询的周:";
                int n,q;
                cin>>q>>n;
                tongjiweek2(q,n);
            }
        }
        if(con=='D')
        {
            char con1;
            cout<<"按照年查询请输入A，按照季度查询请输入B，按照月份查询请输入C，按照周查询请输入D:"<<endl;
            cin>>con1;
            if(con1=='A')
            {
                cout<<"2006年空气质量前20的城市"<<endl;
                paixuyear();
            }
            if(con1=='B')
            {
                cout<<"请输入要查询的季度:";
                int n;
                cin>>n;
                cout<<"2006年"<<n<<"季度空气质量前20的城市"<<endl;
                paixuseason(n);
            }
            if(con1=='C')
            {
                cout<<"请输入要查询月份:";
                int n;
                cin>>n;
                cout<<"2006年"<<n<<"月空气质量前20的城市"<<endl;
                paixumonth(n);
            }
            if(con1=='D')
            {
                cout<<"请输入要查询的周:";
                int n;
                cin>>n;
                cout<<"2006年第"<<n<<"周空气质量前20的城市"<<endl;
                paixuweek(n);
            }
        }
        cout<<"普通查询请输入A，统计查询1请输入B,统计查询2请输入C，排序查询请输入D"<<endl;
        cin>>con;
    }
    return 0;
}
