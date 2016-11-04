//����0  �Ϻ�1   ��³ľ��2  ����3   ����4    ����5    ����6    �人7
#include<iostream>
#include<stdio.h>
using namespace std;
string place[8]= {"����","�Ϻ�","��³ľ��","����","����","����","����","�人"};
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
    int final[8];                    /* final[w]=1��ʾ��ö���v0��vw�����·�� */
    /* ��ʼ������ */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* ȫ�������ʼ��Ϊδ֪���·��״̬ */
        D[v] = tour[v0][v].money;          /* ����v0�������ߵĶ������Ȩֵ */
        P[v] =-1;/* ��ʼ��·������PΪ0 */
    }
    D[v0] = 0;                        /* v0��v0·��Ϊ0 */
    /* v0��v0����Ҫ��·�� */

    final[v0] = 1;
    /* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* ��ǰ��֪��v0������������ */
        for(w=0; w<8; w++) /* Ѱ����v0����Ķ��� */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w������v0������� */
            }
        }
        final[k] = 1;                    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */

        /* ������ǰ���·�������� */
        for(w=0; w<8; w++)
        {
            /* �������v�����·������������·���ĳ��ȶ̵Ļ� */
            if(!final[w] && (min+tour[k][w].money<D[w]))
            {
                /* ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
                D[w] = min + tour[k][w].money; /* �޸ĵ�ǰ·������ */
                P[w]=k;
            }
        }
    }
}
void ShortestPathtime(int v0, int P[], int D[])
{
    int v,w,k,min;
    int final[8];                    /* final[w]=1��ʾ��ö���v0��vw�����·�� */
    /* ��ʼ������ */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* ȫ�������ʼ��Ϊδ֪���·��״̬ */
        D[v] = tour[v0][v].time;          /* ����v0�������ߵĶ������Ȩֵ */
        P[v] =-1;/* ��ʼ��·������PΪ0 */
    }
    D[v0] = 0;                        /* v0��v0·��Ϊ0 */
    /* v0��v0����Ҫ��·�� */

    final[v0] = 1;
    /* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* ��ǰ��֪��v0������������ */
        for(w=0; w<8; w++) /* Ѱ����v0����Ķ��� */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w������v0������� */
            }
        }
        final[k] = 1;                    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */

        /* ������ǰ���·�������� */
        for(w=0; w<8; w++)
        {
            /* �������v�����·������������·���ĳ��ȶ̵Ļ� */
            if(!final[w] && (min+tour[k][w].time<D[w]))
            {
                /* ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
                D[w] = min + tour[k][w].time; /* �޸ĵ�ǰ·������ */
                P[w]=k;
            }
        }
    }
}
void ShortestPathplace(int v0, int P[], int D[])
{
    int v,w,k,min;
    int final[8];                    /* final[w]=1��ʾ��ö���v0��vw�����·�� */
    /* ��ʼ������ */
    for(v=0; v<8; v++)
    {
        final[v] = 0;                    /* ȫ�������ʼ��Ϊδ֪���·��״̬ */
        D[v] = tour[v0][v].mark;          /* ����v0�������ߵĶ������Ȩֵ */
        P[v] =-1;/* ��ʼ��·������PΪ0 */
    }
    D[v0] = 0;                        /* v0��v0·��Ϊ0 */
    /* v0��v0����Ҫ��·�� */

    final[v0] = 1;
    /* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
    for(v=1; v<8; v++)
    {
        min=65535;                    /* ��ǰ��֪��v0������������ */
        for(w=0; w<8; w++) /* Ѱ����v0����Ķ��� */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w������v0������� */
            }
        }
        final[k] = 1;                    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */

        /* ������ǰ���·�������� */
        for(w=0; w<8; w++)
        {
            /* �������v�����·������������·���ĳ��ȶ̵Ļ� */
            if(!final[w] && (min+tour[k][w].mark<D[w]))
            {
                /* ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
                D[w] = min + tour[k][w].mark; /* �޸ĵ�ǰ·������ */
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
        cout<<"������ѡ�����ٷ���ѡA������ʱ��ѡB,������ת����ѡC"<<endl;
        char con;
        cin>>con;
        if(con=='A')
        {
            cout<<"������Ҫ���ĸ����е��ĸ����У�����0  �Ϻ�1   ��³ľ��2  ����3   ����4    ����5    ����6    �人7��"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathmoney(start, p, d);
            cout<<"��С����Ϊ"<<d[end]<<endl;
            string routine="";
            cout<<place[start]<<"-"<<place[end]<<"��·��:";
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
            cout<<"������Ҫ���ĸ����е��ĸ����У�����0  �Ϻ�1   ��³ľ��2  ����3   ����4    ����5    ����6    �人7��"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathtime(start, p, d);
            cout<<"����ʱ��Ϊ"<<d[end]<<endl;
            string routine="";
            cout<<place[start]<<"-"<<place[end]<<"��·��:";
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
            cout<<"������Ҫ���ĸ����е��ĸ����У�����0  �Ϻ�1   ��³ľ��2  ����3   ����4    ����5    ����6    �人7��"<<endl;
            int start,end;
            cin>>start>>end;
            int p[8],d[8];
            for(int i=0; i<8; i++)
            {
                p[i]=0;
                d[i]=0;
            }
            ShortestPathplace(start, p, d);
            cout<<"������ת����Ϊ"<<d[end]<<endl;
            cout<<place[start]<<"-"<<place[end]<<"��·��:";
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
