#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;


int main()
{
    int n,i;
    __int64 ans,sum,a;

    while(cin >> n)
    {
        if(n==0)
            break;
        ans=sum=0;
        for(i=0; i<n; i++)
        {
            cin>>a;
            sum+=a;
            ans +=abs(sum);
        }
        cout << ans << endl;

    }


    return 0;
}
