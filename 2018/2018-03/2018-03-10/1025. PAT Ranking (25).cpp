#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student
{
    string num;
    int s;
    int local;
    int localrank;
    int finalrank;
}stu[30005];
bool cmp(student a,student b)
{
    if (a.s!=b.s)
    return a.s>b.s;
    else
        return a.num<b.num;
}
int main()
{
    int n,k,cnt=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=cnt;j<cnt+k;j++)
        {
            cin>>stu[j].num>>stu[j].s;
            stu[j].local=i;
        }
        sort(stu+cnt,stu+k+cnt,cmp);
        int rank=1;
        for(int j=cnt;j<cnt+k;j++)
        {
            if (j==cnt)
                stu[j].localrank=1;
            else if (stu[j].s<stu[j-1].s)
                stu[j].localrank=rank;
            else
                stu[j].localrank=stu[j-1].localrank;
                rank++;
        }
        cnt+=k;
    }
    sort(stu,stu+cnt,cmp);
    int rank=1;
    cout<<cnt<<endl;
    for(int j=0;j<cnt;j++)
        {
            if (j==0)
                stu[j].finalrank=1;
            else if (stu[j].s<stu[j-1].s)
                stu[j].finalrank=rank;
            else
                stu[j].finalrank=stu[j-1].finalrank;
                rank++;
            cout<<stu[j].num<<" "<<stu[j].finalrank<<" "<<stu[j].local<<" "<<stu[j].localrank<<endl;
        }
    return 0;
}
