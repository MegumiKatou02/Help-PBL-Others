
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
for (auto &x:A)
    Hash[x]++;
vector <int> ans;
int m = Hash.size();

if (m >=k){
    for (auto &x:Hash){
        ans.push_back(x.first);
        if (ans.size() == k)
            break;
    }
}
else{
    for (auto &x: Hash){
        ans.push_back(x.first);
        x.second--;
    }
    map <int,int>:: iterator it = Hash.begin();
    while (ans.size() < k){
        if (it->second > 0){
                ans.push_back(it->first);
                it->second--;
        }
        else
            it++;
    }
}
return ans;
	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
