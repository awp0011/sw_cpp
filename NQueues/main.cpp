#include <iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

/*
ֻ��Ҫ��һ��һλ��������ŵ�ǰ�ʺ��״̬����������Ϊint state[n], state[i]��ʾ�� i �лʺ����ڵ��С���ô���µ�һ�� k ����һ���ʺ��:

    �ж����Ƿ��ͻ��ֻ��Ҫ��state������state[0��k-1] �Ƿ��к�state[k]��ȣ�
    �ж϶Խ����Ƿ��ͻ����������ʺ���ͬһ�Խ��ߣ���ô|row1-row2| = |column1 - column2|����row1��column1������row2��column2���ֱ�Ϊ��ͻ�������ʺ��λ��

*/
int N,ans;


bool isVaild(vector<int> &state, int row,int col)
{
    for(int i=0; i<row; i++)
        if(state[i]==col || abs(i-row)==abs(state[i]-col))
            return false;
    return true;
}

void helper(vector<int> &state, int row)
{

    for(int col=0; col<N; col++)
    {
        if(isVaild(state,row,col))
        {

            if(row==(N-1))
            {
                ans++;
            }
            else
            {
                state[row]=col;
                helper(state,row+1);
                state[row]=-1;
            }

        }
    }
}



int main()
{
    cin >> N;
    vector<int> state(N, -1);
    ans=0;
    helper(state,0);
    cout << ans << endl;
    return 0;
}
