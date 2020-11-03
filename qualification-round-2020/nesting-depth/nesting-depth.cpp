#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Global problem-specific vars
int caseMax = 0,
	currentCase = 0;
string s;

void solve();

void solve() {

	cin >> s;
	string builder = "";
	int level = 0, nextLevel = 0;
	int num, num2;

	for(int i = 0; i < int(s[0]) - int('0'); i++) 
		builder += "(";
	builder += s[0];

	for(int c = 0; c < s.length(); c++) {
		num = int(s[c]) - int('0');
		if(c != s.length() - 1) num2 = int(s[c + 1]) - int('0');
		else num2 = 0;

		level = num;
		nextLevel = num2 - level;

		if(nextLevel > 0) {
			if(c != 0) builder += s[c];
			for(int i = 0; i < nextLevel; i++) 
				builder += "(";
		} else if (nextLevel < 0) {
			if(c != 0) builder += s[c];
			for(int i = 0; i < abs(nextLevel); i++) 
				builder += ")";
		} else if(c != 0) builder += s[c];

	}

	s = builder;

	cout << "Case #" << currentCase << ": " + s << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> caseMax;
	while(currentCase < caseMax) {
		currentCase++;
		solve();
	}

	return 0;
}
