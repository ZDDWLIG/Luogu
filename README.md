//大数排序
#include<iostream>
#include<algorithm>
#include<string>
#include<algorithm>
#include<string>
using namespace std;
typedef struct bid
{
	string s;
	int code;
	int len;
}bid;
bid num[1000000];
bool cmp(bid x, bid y)
{
	if (x.len > y.len)return 1;
	if (x.len == y.len&&x.s > y.s)return 1;
	return 0;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i].s;
		num[i].code = i + 1;
		num[i].len = num[i].s.size();
	}
	sort(num, num + n, cmp);
	cout << num[0].code << endl << num[0].s;
	return 0;
}
