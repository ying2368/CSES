#include <iostream>

using namespace std;

void fun(long long int n)
{
	cout << n;
	if (n == 1)
		return;
	cout << " ";
	if (n % 2 == 0)
		return fun(n / 2);
	else
		return fun(n*3+1);
}


int main() {
	long long int n;
	cin >> n;

	fun(n);
}