#include <iostream>
#include<cstdio>
using namespace std;
int height[100005];
int main()
{

    for(int i=0; i<100005; i++)
    {
        height[i]=0;
    }
    int balls = 0;
    int cnt=0;
    scanf("%d",&balls);
    for(int i=0; i<balls; i++)
    {
        int h=0;
        scanf("%d",&h);
        if(height[h]==0)
        {
            cnt++;
            height[h-1]++;
        }
        else
        {
            height[h-1]++;
            height[h]--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
