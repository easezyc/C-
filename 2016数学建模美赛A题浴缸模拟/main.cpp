//程序注释，改程序采用文件输出，输出到f.txt时间（/s），每秒的平均温度，温度方差，最低温度，最高温度，温度极差，
//还输出了模型在430s和2000s时的三维温度分布数据，430s的从下层到最上层分别在shiqi0.txt到shiqi4.txt。
//2000s的输出在jieshu0.txt到jieshu4.txt
#include<iostream>
#include<iomanip>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;
const double changeenergy=14207.2;
double inwater;
double temperature;
class water
{
private:
    double temperature;
    double energy;
    double temporaryenergy;
    double frequency;
    double V;
    double moreV;
    double moreenergy;
    double lossenergy1;
    double lossenergy2;
public:
    void loss1()
    {
        energy-=lossenergy1;
        caculatetemperature();
    }
    void loss2()
    {
        energy-=lossenergy2;
        caculatetemperature();
    }
    water(double newtemperature=38)
    {
        temperature=newtemperature;
        V=1;
        caculateenergy();
        temporaryenergy=0;
        frequency=0;
        moreV=0;
        moreenergy=0;
        lossenergy1=8.5;
        lossenergy2=7.5;
    }
    void allenergy()
    {
        energy=energy*(8-frequency)/8+temporaryenergy;
        resettemporaryenergy();
        resetfrequency();
        caculatetemperature();
    }
    void settemperature(double num)
    {
        temperature=num;
    }
    void caculateenergy()
    {
        energy=temperature*4200*V;
    }
    void caculatetemperature()
    {
        temperature=energy/4200/V;
    }
    double gettemperature()
    {
        return temperature;
    }
    double getenergy()
    {
        return energy;
    }
    void setfrequency1()
    {
        frequency+=1;
    }
    void resetfrequency()
    {
        frequency=0;
    }
    int getfrequency()
    {
        return frequency;
    }
    void settemporaryenergy(double number)
    {
        temporaryenergy+=number;
    }
    void resettemporaryenergy()
    {
        temporaryenergy=0;
    }
    void blend()
    {
        double oldV=V;
        energy+=moreenergy;
        V+=moreV;
        caculatetemperature();
        moreenergy=moreV/V*energy;
        energy=energy/V;
        V=oldV;
    }
    void addwater(double newenergy,double newV)
    {
        moreenergy=newenergy;
        moreV=newV;
    }
    double getmoreV()
    {
        return moreV;
    }
    double getmoreenergy()
    {
        return moreenergy;
    }
};
double getenergy(double V,double t)
{
    double energy=V*4200*t;
    return energy;
}
water water[17][7][6];
int mark[17][7][6];
double sum[3005];
double variance[3005];
double maxtemperature[3005];
double mintemperature[3005];
double chatemperature[3005];
int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(7);
    int i,j,k,p;
    double radio1=1.0/8.0;
    int tenergy=0;
    ofstream o("shiqi.txt",ios_base::out);
    ofstream z0("shiqiz0.txt",ios_base::out);
    ofstream z1("shiqiz1.txt",ios_base::out);
    ofstream z2("shiqiz2.txt",ios_base::out);
    ofstream z3("shiqiz3.txt",ios_base::out);
    ofstream z4("shiqiz4.txt",ios_base::out);
    for(i=0; i<17; i++)
    {
        for(j=0; j<7; j++)
        {
            for(k=0; k<6; k++)
            {
                mark[i][j][k]=0;
            }
        }
    }
    for(j=0; j<7; j++)
    {
        for(k=0; k<6; k++)
        {
            //mark[14][j][k]=1;
            //mark[13][j][k]=1;
            mark[15][j][k]=1;
            mark[16][j][k]=1;

        }
    }
    for(i=0; i<17; i++)
    {
        for(j=0; j<7; j++)
        {
            mark[i][j][0]=1;
            //mark[i][j][1]=1;
            //mark[i][j][2]=1;
        }
    }
    for(i=0; i<17; i++)
    {
        for(k=0; k<6; k++)
        {
            //mark[i][4][k]=1;
            mark[i][5][k]=1;
            mark[i][6][k]=1;
        }
    }
    for(i=1; i<14; i++)
    {
        mark[i][1][1]=2;
        mark[i][3][1]=2;
    }

    mark[13][2][1]=2;
    mark[12][2][1]=2;
    mark[11][2][1]=2;
    mark[13][2][2]=2;
    mark[12][2][2]=2;
    mark[11][2][2]=2;
    mark[13][1][2]=2;
    mark[12][1][2]=2;
    mark[11][1][2]=2;
    mark[13][3][2]=2;
    mark[12][3][2]=2;
    mark[11][3][2]=2;//gai
    mark[13][3][3]=2;
    mark[12][3][3]=2;
    mark[13][2][3]=2;
    mark[12][2][3]=2;
    mark[13][1][3]=2;
    mark[12][1][3]=2;
    mark[13][3][4]=2;
    mark[12][3][4]=2;
    mark[13][2][4]=2;
    mark[12][2][4]=2;
    mark[13][1][4]=2;
    mark[12][1][4]=2;
    mark[13][1][5]=2;
    mark[13][2][5]=2;
    mark[13][3][5]=2;
    int rand1=3,rand2=3,rand3=4,rand4=4;
    /*for(i=6;i<=9;i++)
    {
        mark[i][rand1][rand2]=2;
        mark[i][rand3][rand4]=2;
    }*/
    for(i=0; i<17; i++)
    {
        for(j=0; j<7; j++)
        {
            for(k=0; k<6; k++)
            {
                if(mark[i][j][k]==2)water[i][j][k].settemperature(37);
            }
        }
    }
    int time=0;//两秒交换1次
    cout<<"请输入进水体积，请输入进水温度,输入时间（单位秒）"<<endl;
    cin>>inwater>>temperature>>time;
    double energy=getenergy(inwater,temperature);
    ofstream oe("f.txt",ios_base::out);
    int t1,t2,t3,t4;
    double T1,T2;
    int n=0;
    for(i=0; i<17; i++)
    {
        for(j=0; j<7; j++)
        {
            for(k=0; k<6; k++)
            {
                if(mark[i][j][k]==0)n++;
            }
        }
    }
    cout<<n<<endl;

    for(p=0; p<time; p++)
    {
        /*if(p%10==0)
        {
            t1=rand1;t2=rand2;t3=rand3;t4=rand4;
            for(i=6;i<=9;i++)
            {
                mark[i][rand1][rand2]=0;
                mark[i][rand3][rand4]=0;
            }
            rand1=rand()%5;
            rand2=rand()%4+2;
            while(rand3==rand1&&rand4==rand2)
            {
                rand3=rand()%5;
                rand4=rand()%4+2;
            }
            for(i=6;i<=9;i++)
            {
                mark[i][rand1][rand2]=2;
                mark[i][rand3][rand4]=2;
            }
            for(i=6;i<=9;i++)
            {
                T1=water[i][t1][t2].gettemperature();
                water[i][t1][t2].settemperature(water[i][rand1][rand2].gettemperature());
                water[i][t1][t2].caculateenergy();
                water[i][rand1][rand2].settemperature(T1);
                water[i][rand1][rand2].caculateenergy();
                T2=water[i][t3][t4].gettemperature();
                water[i][t3][t4].settemperature(water[i][rand3][rand4].gettemperature());
                water[i][t3][t4].caculateenergy();
                water[i][rand3][rand4].settemperature(T2);
                water[i][rand3][rand4].caculateenergy();
            }
        }
        */
        if(p==410)
        {
            for(k=1; k<6; k++)
            {
                for(i=0; i<15; i++)
                {
                    for(j=0; j<5; j++)
                    {
                        o<<i+1<<"  "<<j+1<<"   "<<k<<"  "<<water[i][j][k].gettemperature()<<endl;
                        if(k==1)
                        {
                            z0<<water[i][j][1].gettemperature()<<"  ";
                        }
                        if(k==2)
                        {
                            z1<<water[i][j][2].gettemperature()<<"  ";
                        }
                        if(k==3)
                        {
                            z2<<water[i][j][3].gettemperature()<<"  ";
                        }
                        if(k==4)
                        {
                            z3<<water[i][j][4].gettemperature()<<"  ";
                        }
                        if(k==5)
                        {
                            z4<<water[i][j][5].gettemperature()<<"  ";
                        }

                    }
                    if(k==1)
                    {
                        z0<<endl;
                    }
                    if(k==2)
                    {
                        z1<<endl;
                    }
                    if(k==3)
                    {
                        z2<<endl;
                    }
                    if(k==4)
                    {
                        z3<<endl;
                    }
                    if(k==5)
                    {
                        z4<<endl;
                    }
                }
            }
        }
        sum[p]=0;
        variance[p]=0;
        maxtemperature[p]=0;
        mintemperature[p]=100;
        chatemperature[p]=0;

        for(i=0; i<17; i++)
        {
            for(j=0; j<7; j++)
            {
                for(k=0; k<6; k++)
                {
                    if(mark[i][j][k]==0)
                    {
                        sum[p]+=water[i][j][k].gettemperature();

                        if(water[i][j][k].gettemperature()<mintemperature[p])
                        {
                            mintemperature[p]=water[i][j][k].gettemperature();
                        }
                        if(water[i][j][k].gettemperature()>maxtemperature[p])
                        {
                            maxtemperature[p]=water[i][j][k].gettemperature();
                        }
                    }
                }
            }
        }
        sum[p]=sum[p]/n;
        for(i=0; i<17; i++)
        {
            for(j=0; j<7; j++)
            {
                for(k=0; k<6; k++)
                {
                    if(mark[i][j][k]==0)
                    {
                        variance[p]=pow(water[i][j][k].gettemperature()-sum[p],2);
                    }
                }
            }
        }
        variance[p]=variance[p]/n;
        chatemperature[p]=maxtemperature[p]-mintemperature[p];
        oe<<p+1<<"   "<<sum[p]<<"  "<<variance[p]<<"   "<<mintemperature[p]<<"  "<<maxtemperature[p]<<"  "<<chatemperature[p]<<endl;
        if(p>410)
        {
            water[0][2][5].addwater(energy,inwater);
            water[0][2][5].blend();
            double moreV,moreenergy;
            for(i=0; i<17; i++)
            {
                for(j=2; j<7; j++)
                {
                    if(mark[i][j][5]==0)
                    {
                        if(j!=2&&i==0&&mark[i][j-1][5]==0)
                        {

                            moreV=water[i][j-1][5].getmoreV()/3;
                            moreenergy=water[i][j-1][5].getmoreenergy()/3;
                            water[i][j][5].addwater(moreenergy,moreV);
                            water[i][j][5].blend();
                        }
                        if(i!=0&&j==2&&mark[i-1][j][5]==0)
                        {
                            moreV=water[i-1][j][5].getmoreV()/3;
                            moreenergy=water[i-1][j][5].getmoreenergy()/3;
                            water[i][j][5].addwater(moreenergy,moreV);
                            water[i][j][5].blend();
                        }
                        if(i!=0&&j!=2&&mark[i][j-1][5]==0&&mark[i-1][j][5]==0)
                        {
                            moreV=water[i-1][j][5].getmoreV()/6+water[i][j-1][5].getmoreV()/6;
                            moreenergy=water[i][j-1][5].getmoreenergy()/6+water[i-1][j][5].getmoreenergy()/6;
                            water[i][j][5].addwater(moreenergy,moreV);
                            water[i][j][5].blend();
                        }
                    }
                }
                for(j=1; j>=0; j--)
                {
                    if(mark[i][j][5]==0)
                    {
                        if(i==0&&mark[i][j+1][5]==0)
                        {
                            moreV=water[i][j+1][5].getmoreV()/3;
                            moreenergy=water[i][j+1][5].getmoreenergy()/3;
                            water[i][j][5].addwater(moreenergy,moreV);
                            water[i][j][5].blend();
                        }

                        if(i!=0&&mark[i-1][j][5]==0&&mark[i][j+1][5]==0)
                        {
                            moreV=water[i-1][j][5].getmoreV()/6+water[i][j+1][5].getmoreV()/6;
                            moreenergy=water[i][j+1][5].getmoreenergy()/6+water[i-1][j][5].getmoreenergy()/6;
                            water[i][j][5].addwater(moreenergy,moreV);
                            water[i][j][5].blend();
                        }
                    }
                }
            }
        }
        if(p>410)
        {
            for(i=0; i<4; i++)
            {
                for(j=0; j<7; j++)
                {
                    if(mark[i][j][5]==0)
                    {
                        water[i][j][5].loss1();
                    }
                }
            }
        }
        else
        {
            for(i=0; i<4; i++)
            {
                for(j=0; j<7; j++)
                {
                    if(mark[i][j][5]==0)
                    {
                        water[i][j][5].loss1();
                    }
                }
            }
        }
        for(i=11; i<17; i++)
        {
            for(j=0; j<7; j++)
            {
                if(mark[i][j][5]==0)
                {
                    water[i][j][5].loss2();
                }
            }
        }
        for(i=4; i<11; i++)
        {
            for(j=0; j<7; j++)
            {
                if(mark[i][j][5]==0)
                {
                    water[i][j][5].loss2();
                }
            }
        }
        int tenergy=0;
        for(i=0; i<17; i++)
        {
            for(j=0; j<7; j++)
            {
                for(k=0; k<6; k++)
                {
                    if(mark[i][j][k]==0)
                    {
                        if(i!=16&&mark[i+1][j][k]==0)
                        {
                            tenergy=water[i+1][j][k].getenergy()*radio1;
                            water[i][j][k].settemporaryenergy(tenergy);
                            tenergy=water[i][j][k].getenergy()*radio1;
                            water[i+1][j][k].settemporaryenergy(tenergy);
                            water[i][j][k].setfrequency1();
                            water[i+1][j][k].setfrequency1();
                        }
                        if(j!=6&&mark[i][j+1][k]==0)
                        {
                            tenergy=water[i][j+1][k].getenergy()*radio1;
                            water[i][j][k].settemporaryenergy(tenergy);
                            tenergy=water[i][j][k].getenergy()*radio1;
                            water[i][j+1][k].settemporaryenergy(tenergy);
                            water[i][j][k].setfrequency1();
                            water[i][j+1][k].setfrequency1();
                        }
                        if(k!=5&&mark[i][j][k+1]==0)
                        {
                            tenergy=water[i][j][k+1].getenergy()*radio1;
                            water[i][j][k].settemporaryenergy(tenergy);
                            tenergy=water[i][j][k].getenergy()*radio1;
                            water[i][j][k+1].settemporaryenergy(tenergy);
                            water[i][j][k].setfrequency1();
                            water[i][j][k+1].setfrequency1();
                        }
                    }
                }
            }
        }

        for(i=0; i<17; i++)
        {
            for(j=0; j<7; j++)
            {
                for(k=0; k<6; k++)
                {
                    if(mark[i][j][k]==0)
                    {
                        water[i][j][k].allenergy();
                    }
                }
            }
        }
    }

    /*for(i=0; i<15; i++)
    {
        for(j=0; j<5; j++)
        {
            for(k=0; k<5; k++)
            {
                cout<<i<<j<<k<<":"<<water[i][j][k].gettemperature()<<"   ";
            }
            cout<<endl;
        }
        cout<<endl;
    }*/
    ofstream ofile("jieshu.txt",ios_base::out);
    ofstream oz0("jieshuz0.txt",ios_base::out);
    ofstream oz1("jieshuz1.txt",ios_base::out);
    ofstream oz2("jieshuz2.txt",ios_base::out);
    ofstream oz3("jieshuz3.txt",ios_base::out);
    ofstream oz4("jieshuz4.txt",ios_base::out);
    for(k=1; k<6; k++)
    {
        for(i=0; i<15; i++)
        {
            for(j=0; j<5; j++)
            {
                ofile<<i+1<<"  "<<j+1<<"   "<<k+1<<"  "<<water[i][j][5].gettemperature()<<endl;
                if(k==1)
                {
                    oz0<<water[i][j][1].gettemperature()<<"  ";
                }
                if(k==2)
                {
                    oz1<<water[i][j][2].gettemperature()<<"  ";
                }
                if(k==3)
                {
                    oz2<<water[i][j][3].gettemperature()<<"  ";
                }
                if(k==4)
                {
                    oz3<<water[i][j][4].gettemperature()<<"  ";
                }
                if(k==5)
                {
                    oz4<<water[i][j][5].gettemperature()<<"  ";
                }
            }
            if(k==1)
            {
                oz0<<endl;
            }
            if(k==2)
            {
                oz1<<endl;
            }
            if(k==3)
            {
                oz2<<endl;
            }
            if(k==4)
            {
                oz3<<endl;
            }
            if(k==5)
            {
                oz4<<endl;
            }
        }
    }

}


