#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pre[1005];
int root[1005];
int find(int x)
{
    int r=x;
    while (pre[r]!=r)
        r=pre[r];

    int i,j;
    i=x;
    while (i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

int cnt = 0 ;
void join(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if ( fx != fy )
    {
        pre[fx] = fy ;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d",&n)&&n!=0)
    {
        scanf("%d",&m);
        int a,b;
        cnt = 0;
        for (int i = 1 ; i <= n ; i++ )
        {
            pre[i] = i;
        }
        for (int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            join( a , b );//pre[a] = b;
        }
        memset( root , 0 , sizeof(root) );
        for (int i = 1 ; i <= n ; i++ )
            root[find(i)] = 1 ;
        for (int i = 1 ; i <= n ; i++ )
            if ( root[i] == 1 )
            cnt++;
        /*for (int i = 1 ; i < n ; i++ )
        {
            if ( pre[i] != pre[i+1] )
                join(i , i + 1);
        }*/

        cout<<cnt-1<<endl;
    }
    return 0;
}
