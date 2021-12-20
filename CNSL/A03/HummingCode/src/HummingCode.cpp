#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<int> encode(string msg) {
	int d = msg.size(), r = 0;

	while ((1 << r) < (d + 1 + r))
		r++;

	int n = d + r;
	vector<int> a(n+7);
	for (int i = 1, j = 0; i <= n; i++)
		if ((i & (i - 1)) != 0) { // current position is not power of 2
			a[i] = (msg[j] - '0');
			j++;
		}
		else a[i] = -1;

	for (int i = 0; i < r; i++) { // calculation p1, p2, p3, .. , pr
		int cnt = 0, x=(1<<i);
		for (int j = x; j <= n; j += 2 * x)
			for (int k = j; k < j + x; k++)
				if (a[k] == 1)
					cnt++;

		cnt %= 2;
		a[x] = cnt;
	}

	return a;
}

int is_corrupted(vector<int> a) {
	int r=0;
	while ((1<<(r+1)) < (int)a.size())
		r++;

	int p[r + 1] = { 0 }, n=a.size();
	for (int i = 0; i < r; i++) { // calculation p1, p2, p3, .. , pr

		int cnt = 0, x=(1<<i);
		for (int j = x; j <= n; j += 2 * x)
			for (int k = j; k < j + x; k++)
				if (a[k] == 1)
					cnt++;

		cnt %= 2;
		p[i+1] = cnt;
	}

	bool error_present=0;
	for (int i=1; i<=r; i++)
		error_present |= (p[i]==1);

	int pos = 0;
	for (int i=1; i<=r; i++)
		pos += (p[i]*(1<<(i-1)));

	return (error_present ? pos : -1);
}

string decode(vector<int> a) {
	string msg="";
	return msg;
}

int main() {

//	vector<int> enc = encode("1101010");
//
//	enc[5]=0;
//
//	int pos = is_corrupted(enc);
//
//	if (pos == -1) cout << "No error present.";
//	else cout << "Error is present at position: " << pos << '\n';

	return 0;
}
