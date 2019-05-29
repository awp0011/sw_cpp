#include <iostream>

using namespace std;
long long dp[101][101];
int n,m;
int main()
{
    for(int i=0; i<101; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i=1; i<101; i++)
        for(int j=1; j<101; j++)
            dp[i][j] =  dp[i-1][j] +  dp[i-1][j-1] ;
    while(1)
    {
        cin >> n >>m;
        if(n==0)
            break;

        cout << n<<" things taken "<< m <<" at a time is "<< dp[n][m] <<" exactly." << endl;
    }

    return 0;
}
