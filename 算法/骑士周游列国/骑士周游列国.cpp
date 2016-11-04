#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int number[8];
int mark[8][8];
int n=1;
int startx,starty;
const int fx[8]= {1,1,-2,-2,2,2,-1,-1};
const int fy[8]= {-2,2,1,-1,1,-1,2,-2};
int start,finish;
int num;
struct marknum{
int number,xuhao;
marknum(){number=0;xuhao=0;}
};
int getnumber(int x,int y)
{
    int i;int count=0;
    for(i=0;i<num;i++)
    {
        if(x>=0&&x<num&&y>=0&&y<num&&mark[x+fx[i]][y+fy[i]]==0&&(x+fx[i])>=0&&(x+fx[i])<num&&(y+fy[i]>=0)&&(y+fy[i]<num)&&mark[x][y]==0)
        {
            count++;
        }
    }
    return count;
}
void travel(int x,int y)
{
    if(n==(num*num))
    {
        int i,j;
        cout<<"case:"<<endl;
        for(i=0; i<num; i++)
        {
            for(j=0; j<num; j++)
            {
                cout<<mark[i][j]<<" ";
            }
            cout<<endl;
        }
        finish=clock();
        cout<<"the time cost:"<<finish-start<<endl;
        exit(0);
    }
    marknum a[8];
    for(int i=0;i<num;i++)
    {
        a[i].number=getnumber(x+fx[i],y+fy[i]);
        a[i].xuhao=i;
    }
    marknum t;
    for(int i=num;i>0;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(a[j].number>a[j+1].number)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=0;i<num;i++)
    {
        if((x+fx[a[i].xuhao])>=0&&(x+fx[a[i].xuhao])<num&&(y+fy[a[i].xuhao]>=0)&&(y+fy[a[i].xuhao]<num)&&mark[x+fx[a[i].xuhao]][y+fy[a[i].xuhao]]==0)
        {
            n++;
            mark[x+fx[a[i].xuhao]][y+fy[a[i].xuhao]]=n;
            travel(x+fx[a[i].xuhao],y+fy[a[i].xuhao]);
            mark[x+fx[a[i].xuhao]][y+fy[a[i].xuhao]]=0;
            n--;
        }
    }
}
int main()
{
    cout<<"plaease input how large"<<endl;
    cin>>num;
    cout<<"please input startx and starty:"<<endl;
    start=clock();
    cin>>startx>>starty;
    int i,j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            mark[i][j]=0;
        }
    for(i=0;i<8;i++)
        number[i]=0;
    mark[startx][starty]=1;
    travel(startx,starty);
    cout<<"no result"<<endl;
    finish=clock();
    cout<<"the time cost:"<<finish-start<<endl;
    return 0;
}
