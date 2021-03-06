// hdu 1002A + B Problem II.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
#include "iostream"
using namespace std;

string add(string a, string b)
{
	string sum;
	int len1 = a.size(), len2 = b.size();
	int len = len1 > len2 ? len1 : len2;
	int ans = len;
	int p = 0;
	while (len1 >= 0 || len2 >= 0)
	{
		len1--;
		len2--;
		len--;
		if (len1 >= 0 && len2 >= 0)
		{
			sum[len] = (((a[len1] - '0') + (b[len2] - '0') + p) % 10) + '0';
			p = ((a[len1] - '0') + (b[len2] - '0') + p) / 10;
		}
		else if (len1 < 0 && len2 >= 0)
		{
			sum[len] = (((b[len2] - '0') + p) % 10) + '0';
			p = ((b[len2] - '0') + p) / 10;
		}
		else if (len2 < 0 && len1 >= 0)
		{
			sum[len] = (((a[len1] - '0') + p) % 10) + '0';
			p = ((a[len1] - '0') + p) / 10;
		}
	}
	return sum;
}
int main()
{
	int cnt = 0, k;
	string a, b, sum;
	cin >> a >> k;
	while (cnt <= k)
	{
		b = a;
		reverse(a.begin(), a.end());
		a = add(a , b);
	}
	
	return 0;
}

