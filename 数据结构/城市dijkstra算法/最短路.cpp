//北京0  上海1   乌鲁木齐2  西安3   广州4    拉萨5    昆明6    武汉7
#include<iostream>
#include<stdio.h>
using namespace std;
string place[8]= {"北京","上海","乌鲁木齐","西安","广州","拉萨","昆明","武汉"};
struct tour1
{
    int mark;
    int money;
    int time;
    int num;
    tour1():mark(0),money(65535),time(65535),num(0) {}
    void touradd(int newmark=0,int newmoney=0,int newtime=0,int newnum=0)
    {
        mark=newmark;
        money=newmoney;
        time=newtime;
        num=newnum;
    }
};
tour1 tour[8][8];
void ShortestPathmoney(int v0, int P[], int D[])
{
    int v,w,k,min;
    int final[8];                    /* final[w]=1表示求得顶点v0至vw的最短路径 */
    /* 初始化数据 */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* 全部顶点初始化为未知最短路径状态 */
        D[v] = tour[v0][v].money;          /* 将与v0点有连线的顶点加上权值 */
        P[v] =-1;/* 初始化路径数组P为0 */
    }
    D[v0] = 0;                        /* v0至v0路径为0 */
    /* v0至v0不需要求路径 */

    final[v0] = 1;
    /* 开始主循环，每次求得v0到某个v顶点的最短路径 */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* 当前所知离v0顶点的最近距离 */
        for(w=0; w<8; w++) /* 寻找离v0最近的顶点 */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w顶点离v0顶点更近 */
            }
        }
        final[k] = 1;                    /* 将目前找到的最近的顶点置为1 */

        /* 修正当前最短路径及距离 */
        for(w=0; w<8; w++)
        {
            /* 如果经过v顶点的路径比现在这条路径的长度短的话 */
            if(!final[w] && (min+tour[k][w].money<D[w]))
            {
                /* 说明找到了更短的路径，修改D[w]和P[w] */
                D[w] = min + tour[k][w].money; /* 修改当前路径长度 */
                P[w]=k;
            }
        }
    }
}
void ShortestPathtime(int v0, int P[], int D[])
{
    int v,w,k,min;
    int final[8];                    /* final[w]=1表示求得顶点v0至vw的最短路径 */
    /* 初始化数据 */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* 全部顶点初始化为未知最短路径状态 */
        D[v] = tour[v0][v].time;          /* 将与v0点有连线的顶点加上权值 */
        P[v] =-1;/* 初始化路径数组P为0 */
    }
    D[v0] = 0;                        /* v0至v0路径为0 */
    /* v0至v0不需要求路径 */

    final[v0] = 1;
    /* 开始主循环，每次求得v0到某个v顶点的最短路径 */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* 当前所知离v0顶点的最近距离 */
        for(w=0; w<8; w++) /* 寻找离v0最近的顶点 */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w顶点离v0顶点更近 */
            }
        }
        final[k] = 1;                    /* 将目前找到的最近的顶点置为1 */

        /* 修正当前最短路径及距离 */
        for(w=0; w<8; w++)
        {
            /* 如果经过v顶点的路径比现在这条路径的长度短的话 */
            if(!final[w] && (min+tour[k][w].time<D[w]))
            {
                /* 说明找到了更短的路径，修改D[w]和P[w] */
                D[w] = min + tour[k][w].time; /* 修改当前路径长度 */
                P[w]=k;
            }
        }
    }
}
void ShortestPathplace(int v0, int P[], int D[])
{
    int v,w,k,min;
    int final[8];                    /* final[w]=1表示求得顶点v0至vw的最短路径 */
    /* 初始化数据 */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* 全部顶点初始化为未知最短路径状态 */
        D[v] = tour[v0][v].mark;          /* 将与v0点有连线的顶点加上权值 */
        P[v] =-1;/* 初始化路径数组P为0 */
    }
    D[v0] = 0;                        /* v0至v0路径为0 */
    /* v0至v0不需要求路径 */

    final[v0] = 1;
    /* 开始主循环，每次求得v0到某个v顶点的最短路径 */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* 当前所知离v0顶点的最近距离 */
        for(w=0; w<8; w++) /* 寻找离v0最近的顶点 */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w顶点离v0顶点更近 */
            }
        }
        final[k] = 1;                    /* 将目前找到的最近的顶点置为1 */

        /* 修正当前最短路径及距离 */
        for(w=0; w<8; w++)
        {
            /* 如果经过v顶点的路径比现在这条路径的长度短的话 */
            if(!final[w] && (min+tour[k][w].mark<D[w]))
            {
                /* 说明找到了更短的路径，修改D[w]和P[w] */
                D[w] = min + tour[k][w].mark; /* 修改当前路径长度 */
                P[w]=k;
            }
        }
    }
}
int main()
{
    int i,j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            tour[i][j].mark=65535;
            tour[i][j].money=65535;
            tour[i][j].time=65535;
            tour[i][j].num=0;
        }
    tour[0][1].touradd(1,680,65,6320);
    tour[1][0].touradd(1,680,65,6320);
    tour[0][2].touradd(1,1150,115,2104);
    tour[2][0].touradd(1,1150,115,2104);
    tour[0][3].touradd(1,930,95,201);
    tour[3][0].touradd(1,930,100,201);
    tour[3][4].touradd(1,1320,140,2323);
    tour[4][3].touradd(1,1320,80,2323);
    tour[5][6].touradd(1,830,85,173);
    tour[6][5].touradd(1,830,85,173);
    tour[5][7].touradd(1,890,90,3304);
    tour[7][5].touradd(1,890,90,3304);
    tour[2][6].touradd(1,1480,165,82);
    tour[6][2].touradd(1,1480,165,82);
    tour[7][4].touradd(1,810,100,4723);
    tour[4][7].touradd(1,810,100,4723);
    while(1)
    {
        cout<<"请输入选择最少费用选A，最少时间选B,最少中转次数选C"<<endl;
        char con;
        cin>>con;
        if(con=='A')
        {
            cout<<"请输入要从哪个城市到哪个城市（北京0  上海1   乌鲁木齐2  西安3   广州4    拉萨5    昆明6    武汉7）"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathmoney(start, p, d);
            cout<<"最小费用为"<<d[end]<<endl;
            string routine="";
            cout<<place[start]<<"-"<<place[end]<<"的路线:";
            string q[8];
            int num[8];
            for(j=0; j<8; j++)
                num[j]=0;
            int n=0;
            int t1=0,t2=1;
            num[0]=end;
            j=end;
            while(p[j]!=-1)
            {
                j=p[j];
                q[n]=place[j];
                n++;
                num[n]=j;
            }
            num[n+1]=start;
            t2=n+1;
            t1=n;
            //for(j=n+1;j>=0;j--)cout<<num[j]<<endl;
            cout<<place[start]<<tour[num[t1]][num[t2]].num<<"-";
            for(j=n-1; j>=0; j--)
                cout<<q[j]<<tour[num[--t1]][num[--t2]].num<<"-";
            cout<<place[end]<<endl;
        }
        if(con=='B')
        {
            cout<<"请输入要从哪个城市到哪个城市（北京0  上海1   乌鲁木齐2  西安3   广州4    拉萨5    昆明6    武汉7）"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathtime(start, p, d);
            cout<<"最少时间为"<<d[end]<<endl;
            string routine="";
            cout<<place[start]<<"-"<<place[end]<<"的路线:";
            string q[8];
            int num[8];
            for(j=0; j<8; j++)
                num[j]=0;
            int n=0;
            int t1=0,t2=1;
            num[0]=end;
            j=end;
            while(p[j]!=-1)
            {
                j=p[j];
                q[n]=place[j];
                n++;
                num[n]=j;
            }
            num[n+1]=start;
            t2=n+1;
            t1=n;
            //for(j=n+1;j>=0;j--)cout<<num[j]<<endl;
            cout<<place[start]<<tour[num[t1]][num[t2]].num<<"-";
            for(j=n-1; j>=0; j--)
                cout<<q[j]<<tour[num[--t1]][num[--t2]].num<<"-";
            cout<<place[end]<<endl;
        }
        if(con=='C')
        {
            cout<<"请输入要从哪个城市到哪个城市（北京0  上海1   乌鲁木齐2  西安3   广州4    拉萨5    昆明6    武汉7）"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathplace(start, p, d);
            cout<<"最少中转次数为"<<d[end]<<endl;
            cout<<place[start]<<"-"<<place[end]<<"的路线:";
            string q[8];
            int num[8];
            for(j=0; j<8; j++)
                num[j]=0;
            int n=0;
            int t1=0,t2=1;
            num[0]=end;
            j=end;
            while(p[j]!=-1)
            {
                j=p[j];
                q[n]=place[j];
                n++;
                num[n]=j;
            }
            num[n+1]=start;
            t2=n+1;
            t1=n;
            //for(j=n+1;j>=0;j--)cout<<num[j]<<endl;
            cout<<place[start]<<tour[num[t1]][num[t2]].num<<"-";
            for(j=n-1; j>=0; j--)
                cout<<q[j]<<tour[num[--t1]][num[--t2]].num<<"-";
            cout<<place[end]<<endl;
        }
    }
    return 0;
}
