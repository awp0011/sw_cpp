#include <iostream>
#include<stdlib.h>
using namespace std;
int N;
long long point[100001][2];
long long ans;
int main()
{
    cin  >> N;
    for(int i=0; i<N; i++)
    {
        cin >>point[i][0] >>point[i][1];
    }
    point[N][0] = point[0][0];
    point[N][1] = point[0][1];
    ans = 0;
    for(int i=0; i<N; i++)
    {
        ans += point[i][0]*point[i+1][1] - point[i][1]*point[i+1][0];
    }
    ans = abs(ans);
    if( ans %2 ==0)
        cout << (ans >> 1)  << ".0" << endl;
    else
        cout << (ans >> 1)  << ".5" << endl;
    return 0;
}
