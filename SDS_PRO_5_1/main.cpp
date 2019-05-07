#include <iostream>
#include <stdlib.h>

using namespace std;
int E1,E2,M1,M2,C1,C2;
int N,V[5003][2];

long long f1(int a[],int b[])
{
    long long x=abs(a[0]-b[0]);
    long long y=abs(a[1]-b[1]);
    return x*x+y*y;
}
int f2(int a[],int b[])
{
    int x=abs(a[0]-b[0]);
    int y=abs(a[1]-b[1]);
    return x+y;
}
int f3(int a[],int b[])
{
    int x=abs(a[0]-b[0]);
    int y=abs(a[1]-b[1]);
    return max(x,y);
}
int main()
{
    E1=M1=C1=1;
    E2=M2=C2=2;
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> V[i][0] >>V[i][1];
    for(int i=1; i<=N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if(f1(V[i],V[j])<f1(V[E1],V[E2]))
            {
                E1=i;
                E2=j;
            }
            if(f2(V[i],V[j])<f2(V[M1],V[M2]))
            {
                M1=i;
                M2=j;
            }
            if(f3(V[i],V[j])<f3(V[C1],V[C2]))
            {
                C1=i;
                C2=j;
            }
        }
    }
    cout << E1 << " " << E2 << endl;
    cout << M1 << " " << M2 << endl;
    cout << C1 << " " << C2 << endl;
    return 0;
}
