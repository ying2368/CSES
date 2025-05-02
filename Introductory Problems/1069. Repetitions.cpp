#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i = 1, n = 1, max = 1;
	cin >> s;

	char c = s[0];
	for ( ;i < s.size();i++)
	{
		if (c == s[i])
		{
			n++;
		}
		else
		{
			if (n > max)
				max = n;
			n = 1;
		}
		c = s[i];
	}
	if (n > max)
		max = n;
	cout << max << endl;
}