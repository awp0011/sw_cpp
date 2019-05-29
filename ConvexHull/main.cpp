#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int i,j,m,n;
int ans[10001];

struct data
{
    double x,y;
}a[10001];
int r()
{
    int ans=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        ans*=10;
        ans+=ch-'0';
        ch=getchar();
    }
    return ans;
}

double mx,my=1000000;

double cj(data a1,data a2,data b1,data b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}

int cmp(data p,data q)
{
    double mul=cj(a[1],p,a[1],q);
    if(mul>0) return 1;
    return 0;
}

double dis(data p,data q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

int main()
{
    n=r();
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&a[i].x);
        scanf("%lf",&a[i].y);
        if(a[i].y<my||a[i].y==my&&a[i].x<mx)
        my=a[i].y,mx=a[i].x,m=i;
    }

    double xx,yy;
    xx=a[m].x,yy=a[m].y;
    a[m].x=a[1].x,a[m].y=a[1].y;
    a[1].x=xx;a[1].y=yy;

    sort(a+2,a+n+1,cmp);

    int tot=3;
    ans[1]=1,ans[2]=2,ans[3]=3;
    for(i=4;i<=n;i++)
    {
        while(cj(a[ans[tot-1]],a[ans[tot]],a[ans[tot]],a[i])<=0)
        tot--;
        ans[++tot]=i;
    }

    cout << tot << endl;
    double sum=0;
    for(i=1;i<tot;i++)
    sum+=dis(a[ans[i]],a[ans[i+1]]);

    sum+=dis(a[ans[tot]],a[1]);
    printf("%.2lf",sum);

    return 0;
}
