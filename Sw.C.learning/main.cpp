#include <iostream>

using namespace std;


int N, paper[200][200];
int cnt0=0,cnt1=0;

void check(int s1,int s2, int len)
{
    int sum=0;
    for(int i=s1; i<s1+len; i++)
        for(int j=s2; j<s2+len; j++)
            sum += paper[i][j];

    if(sum==len*len)
        cnt1++;
    else      if(sum==0)
        cnt0++;
    else
    {
        int mid = len/2;
        check(s1,s2,mid);
        check(s1+mid,s2,mid);
        check(s1,s2+mid,mid);
        check(s2+mid,s2+mid,mid);
    }
}

int main()
{

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> paper[i][j];

    check(0,0,N);
    cout << cnt0 << endl;
    cout << cnt1 << endl;
    return 0;
}
