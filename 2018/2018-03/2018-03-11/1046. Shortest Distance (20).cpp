#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3ffffff
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dis[100005];
    for (int i=1;i<=n;i++)
        cin>>dis[i];
    int m;
    cin>>m;
    int a,b;
    int sum;
    int tmp;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        sum=0;
        int min=inf;
        if (a>b)
        {
            tmp=a;
            a=b;
            b=tmp;
        }
        for (int j=a;j<b;j++)
            sum+=dis[j];
        min=sum;
        sum=0;
        for (int j=b;j<=n;j++)
            sum+=dis[j];
        for (int j=0;j<a;j++)
            sum+=dis[j];
        min = sum<min ?sum:min;
        cout<<min<<endl;
    }
    return 0;
}
