#include <iostream>

using namespace std;

int N,cnt;
long long ans;
long long d[100][100];
long long C(int m,int n)
{
    if(d[m][n]>0)
        return d[m][n];
    if(m==n||n==0||m==0)
        return d[m][n]=1;
    if(m==1)
        return d[m][n]=n;
    return d[m][n] = C(m-1,n-1)+C(m,n-1);
}
int main()
{
    cin >> N;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            d[i][j]=0;
    N--;//first is 1
    ans=0;
    cnt=0;
    do
    {
        ans+=C(cnt,N-cnt);
        cnt++;
    }
    while(N>=2*cnt);
    cout << ans<< endl;
    return 0;
}
