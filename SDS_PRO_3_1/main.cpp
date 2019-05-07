#include <iostream>
#include<cstdio>
#include <stdlib.h>
using namespace std;

struct Node
{
    int index;
    Node *next;
};
int N,K;

Node *GetNode(int i)
{
    Node * p = (Node *)malloc(sizeof(Node));
    p->index = i;
    p->next = NULL;
    return p;

}

int main()
{
    scanf("%d",&N);
    scanf("%d",&K);
    Node* first = GetNode(0);
    Node* cur = first;
    for(int i=1; i<=N; i++)
    {
        Node* next = GetNode(i);
        cur->next = next;
        cur = next;
    }
    cur->next = first->next;
    Node* pre= cur;
    cur =first->next;
    int cnt=0;
    while(N!=1)
    {
        if(0==(cnt%K))
        {
            cnt=1;
            printf("%d ",cur->index);
            pre->next = cur->next;
            N--;
        }
        else
        {
            cnt++;
            pre = cur;
        }
        cur = cur->next;
    }
    printf("%d\n",cur->index);
}




