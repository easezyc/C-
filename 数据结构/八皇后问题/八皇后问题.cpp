#include<iostream>
using namespace std;
struct queen1{
int x,y;
};
queen1 queen[8];
bool judge(queen1 newx)
{
    int i;
    for(i=0;i<newx.x;i++)
    {
        if(queen[i].y==newx.y||(queen[i].x+queen[i].y==newx.y+newx.x)||(queen[i].x-queen[i].y==newx.x-newx.y))return false;
    }
    return true;
}
void print()
{
    int qipan[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            qipan[i][j]=0;
    for(int i=0;i<8;i++)
        qipan[queen[i].x][queen[i].y]=1;
    for(int i=0;i<8;i++)
        {for(int j=0;j<8;j++)
            cout<<qipan[i][j]<<"  ";
            cout<<endl;
        }
        cout<<endl;

}
void placequeen(int n)
{
    queen[n].x=n;
    for(int y=0;y<8;y++)
    {
        queen[n].y=y;
        if(judge(queen[n]))
        {

            if(n==7){print();}
            else placequeen(n+1);
        }
    }
}
int main()
{
    placequeen(0);
    return 0;
}
