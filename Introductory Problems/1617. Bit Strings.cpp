#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(vector<int> v)
{
	if (v[0] >= 7)
		return true;
	for (int i = 1;i < v.size()-1;i++){
		if (v[i] != 0)
			return true;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	v.push_back(1);

	if (n == 0)
		cout << 0 << endl;
	else {
		for (int i = 0;i < n;i++) {
			int buff = 0;
			for (int j = 0;j < v.size();j++) {
				v[j] *= 2;
				v[j] += buff;

				buff = 0;
				if (v[j] > 9)
				{
					buff = 1;
					v[j] -= 10;
				}
			}

			if (buff==1) v.push_back(1);
			if (v.size() >= 10 && check(v)){
				v[0] -= 7;
				v[9]--;

				for (int j = 0; j < v.size() - 1;j++){
					if (v[j] < 0){
						v[j] += 10;
						v[j + 1]--;
					}

				}

				for (int j = v.size() - 1;j >= 0;j--) {
					if (v[j] == 0) v.pop_back();
					else break;
				}
			}
		}

		for (int j = v.size()-1;j >= 0 ;j--)
			cout << v[j];
		cout << endl;
	}
}