#include <iostream>
#include<algorithm>

using namespace std;
int N,D[1000001];
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> D[i];
    sort(D,D+N);
    int pre=-1,cnt=0,sum=0,ans=0;
    for(int i=0; i<=N; i++)
    {
        if(D[i]!=pre)
        {
            if(cnt >sum)
            {
                ans = pre;
                sum = cnt;
            }
            cnt=0;
        }
        else
        {
            cnt++;
        }
        pre = D[i];
    }
    cout << ans << endl;
    return 0;
}
