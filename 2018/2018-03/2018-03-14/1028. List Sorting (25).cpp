#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student{
    char ID[10];
    char name[10];
    int grade;
}stu[100005];
int c;
int  cmp(student a , student b)
{
    if (c==1)
        return strcmp(a.ID,b.ID)<=0;
    else if ( c == 2 )
        return strcmp(a.name , b.name )<=0;
    else return a.grade > b.grade;
}
int main()
{
    int n ;
    cin<< n >> c ;
    for ( int i = 0 ; i < n ; i ++ )
        cin>>stu[i].ID>>stu[i].name>>stu[i].grade;
    sort( stu , stu + n );
    for ( int i = 0 ; i < n ; i ++ )
        cout <<stu[i].ID<<" "<<stu[i].name<<" "<<stu[i].grade<<endl;
    return 0;
}
