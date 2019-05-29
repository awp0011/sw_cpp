#include <iostream>

using namespace std;

int main()
{
    int ans=0,t[105][105];
    int N ;
    cin >> N;

    for(int i=0; i<N; i++)
        for(int j=0; j<=i; j++)
        {
            cin >> t[i][j];
        }
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0)
                t[i][j]=t[i-1][j]+t[i][j];
            else if(j==N-1)
                t[i][j]=t[i-1][j-1]+t[i][j];
            else
                t[i][j]=max(t[i-1][j]+t[i][j],t[i-1][j-1]+t[i][j]);
        }
    }
    for(int i=0; i<N; i++)
    {
        ans = max(t[N-1][i],ans);
    }
    cout << ans << endl;
    return 0;
}
