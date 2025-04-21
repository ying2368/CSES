#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v;
	int n,a;
	cin >> n;
	for (int i=1;i<n;i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	if (n == 2)
	{
		if(v[0]==1)
			cout << 2 << endl;
		if (v[0] == 2)
			cout << 1 << endl;
	}
	else if (v[n-2]==n-1)
	{
		cout << n << endl;
	}
	else
	{
		for (int i = 0;i < n - 1;i++)
		{
			if (v[i] + 1 != v[i + 1])
			{
				cout << v[i] + 1 << endl;
				break;
			}
		}
	}
	
}