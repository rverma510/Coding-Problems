#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char s[100005];
		scanf("%s", s);
		vector<vector<int>> v(26);
		for(int i = 0; s[i]; i++) {
			v[s[i] - 'a'].push_back(i + 1);
		}
		int flag = 0;
		for(int i = 0; i < 26; i++) {
			if(v[i].size() % 2) {
				flag++;
			}
		}
		if(strlen(s) % 2 == 0 && flag > 0) {
			printf("-1\n");
		}
		else if(strlen(s) % 2 == 1 && flag > 1) {
			printf("-1\n");
		}
		else {
            int odd = 0;
			for(int i = 0; i < 26; i++) {
				if(v[i].size() % 2 == 1) {
					odd = v[i][v[i].size() - 1];
					v[i].pop_back();
				}
			}
			for(int i = 0; i < 26; i++) {
				for(int j = 0; j < v[i].size() / 2; j++) {
					printf("%d ", v[i][j]);
				}
			}
			if(odd) {
				printf("%d ", odd);
			}
			for(int i = 25; i >= 0; i--) {
				for(int j = v[i].size() / 2; j < v[i].size(); j++) {
					printf("%d ", v[i][j]);
				}
			}
			printf("\n");
		}
	}
}