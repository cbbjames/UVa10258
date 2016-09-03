#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
struct P {
	int sol=0;
	int pun = 0;
	int pb[10][2];//[0]=incorrect try [1]=solved?
	bool areUthere = false;
	int id;
	bool operator<(const P& a)const {
		if (sol != a.sol) return sol > a.sol;
		else if(pun!=a.pun) return pun < a.pun;
		else return id < a.id;
	}
};
int main() {
	int n; cin >> n; getchar(); getchar();
	while (n--) {
		P p[105];
		for (int i = 0; i < 100; i++)
			memset(p[i].pb, 0, sizeof(p[i].pb));
		string s;
		while (getline(cin,s)&&isdigit(s[0])) {
			stringstream ss(s);
			int pid, pbid, t;
			char tr,c;
			ss >> pid >> pbid >> t;
			ss >>c;
			//cout << c << "zz";
			pid--;
			p[pid].id = pid+1;
			if (!p[pid].areUthere) p[pid].areUthere = true;
			if (p[pid].pb[pbid][1] == 1) continue;
			if (c == 'C') {
				p[pid].pb[pbid][1] = 1;
				p[pid].sol++;
				p[pid].pun += p[pid].pb[pbid][0] * 20 + t;
			}
			else if (c == 'I') { p[pid].pb[pbid][0]++; }
		}
		//
		sort(p, &p[104]);
		for (int i = 0; i < 105; i++)
			if (p[i].areUthere)
				printf("%d %d %d\n", p[i].id, p[i].sol, p[i].pun);
		if (n > 0) cout << endl;
	}
	//system("PAUSE");
	return 0;
}