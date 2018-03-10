#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int post[35];
int in[35];
int ceng[30];
int prenum[35];
int ans=0;
void pre(int root ,int start,int end,int cnt)
{
    if (start>end)
        return;
    int i=start;
    while (i<end&&post[root]!=in[i])
    i++;
    prenum[ans++]=post[root];
    ceng[post[root]]=cnt;
    pre(root-(end-i)-1,start,i-1,cnt+1);
    pre(root-1,i+1,end,cnt+1);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>post[i];
    for (int i=0;i<n;i++)
        cin>>in[i];
    pre(n-1,0,n-1,1);
    cout<<prenum[0];
    for(int i=1;i<29;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (ceng[prenum[j]]==i+1)
                cout<<" "<<prenum[j];
        }
    }
    cout<<endl;
    return 0;
}
