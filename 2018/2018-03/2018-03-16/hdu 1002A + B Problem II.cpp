// hdu 1002A + B Problem II.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;

int main()
{
	int cas, p;
	char a[100005], b[100005], sum[100005];
	cin >> cas;
	for (int i = 1; i <= cas; i++)
	{
		cin >> a >> b;
		int len1 = strlen(a), len2 = strlen(b);
		int len = len1 > len2 ? len1 : len2;
		int ans = len;
		p = 0;
		while (len1 >= 0 || len2 >= 0 )
		{
			len1--;
			len2--;
			len--;
			if (len1 >= 0 && len2 >= 0)
			{
				sum[len] = (((a[len1] - '0') + (b[len2] - '0') + p) % 10 ) + '0';
				p = ((a[len1] - '0') + (b[len2] - '0') + p ) / 10;
			}
			else if (len1 < 0 && len2 >= 0)
			{
				sum[len] = (((b[len2] - '0') + p) % 10 ) + '0';
				p = ((b[len2] - '0' ) + p) / 10;
			}
			else if (len2 < 0 && len1 >= 0)
			{
				sum[len] = (((a[len1] - '0') + p) % 10 ) + '0';
				p = ((a[len1] - '0' ) + p) / 10;
			}
		}
		cout << "Case " << i << ":" << endl;
		cout << a << " + " << b << " = " ;
		for (int i = 0; i < ans; i++)
		{
			cout << sum[i];
		}
		cout << endl;
		if (i != cas)
			cout << endl;
	}
    return 0;
}

