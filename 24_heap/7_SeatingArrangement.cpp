#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Elem {
   public:
      ll sz;
      ll left;
      ll right;
      Elem(ll s, ll l, ll r) {
         sz = s;
         left = l;
         right = r;
      }
      void print() {
          cout << sz << ' ' << left << ' ' << right << '\n';
      }
};

class Comparator {
   public:
      bool operator()(const Elem &a, const Elem &b) {
         if (a.sz == b.sz) {
            return a.left > b.left;
         } else {
            return a.sz < b.sz;
         }
      }
};

vector<int> solve (vector<long long> Q, int k, string s, long long n) {
   map<ll, int> mp;
   priority_queue<Elem, vector<Elem>, Comparator> pq;
   pq.push(Elem(n, 1, n));
   for (int i = 1; i <= k; i++) {
      Elem e = pq.top();
      pq.pop();
      e.print();
      ll md = (e.left + e.right) / 2;
      if (e.sz & 1) {
         mp[md] = i;
         if (md - e.left != 0) pq.push(Elem(md - e.left, e.left, md - 1));
         if (e.right - md != 0) pq.push(Elem(e.right - md, md + 1, e.right));
      }
      else {
         if (s[i - 1] == 'L') {
            mp[md] = i;
            if (md - e.left != 0) pq.push(Elem(md - e.left, e.left, md - 1));
            if (e.right - md != 0) pq.push(Elem(e.right - md, md + 1, e.right));
         } 
         else {
            md++;
            mp[md] = i;
            if (md - e.left != 0) pq.push(Elem(md - e.left, e.left, md - 1));
            if (e.right - md != 0) pq.push(Elem(e.right - md, md + 1, e.right));
         }
      }
   }
   vector<int> res;
   for (int i = 0; i < (int) Q.size(); i++) {
      if (mp.find(Q[i]) != mp.end()) res.push_back(mp[Q[i]]);
      else res.push_back(-1);
   }
   return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<long long> Q(q);
    for(int i_Q=0; i_Q<q; i_Q++)
    {
    	cin >> Q[i_Q];
    }

    vector<int> out_;
    out_ = solve(Q, k, s, n);
    cout << out_[0] << endl;
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_] << endl;
    }
}