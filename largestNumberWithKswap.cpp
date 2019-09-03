#include <bits/stdc++.h>
#define ll long long

using namespace std;

string newString1(string s, int k, int i){
	if(k <= 0 || i >= s.length()-1)
		return s;
	int ind = i;
	char c = s[i];
	for (int j = s.length()-1; j >= i+1; --j){
		if(c == s[j] && k <= (j-i)){
			ind = j;
		}
		if(c < s[j]){
			ind = j;
			c = s[j];
		}
	}
	if(ind == i){
		return newString1(s, k, i+1);
	}
	s[ind] = s[i];
	s[i] = c;
	return newString1(s, k-1, i+1);
}

string newString2(string s, int k, int i){
	if(k <= 0 || i >= s.length()-1)
		return s;
	int ind = i;
	char c = s[i];
	for (int j = i+1; j < s.length(); ++j){
		if(c == s[j] && k <= (j-i)){
			ind = j;
		}
		if(c < s[j]){
			ind = j;
			c = s[j];
		}
	}
	if(ind == i){
		return newString2(s, k, i+1);
	}
	s[ind] = s[i];
	s[i] = c;
	return newString2(s, k-1, i+1);
}

int main(){
	int t; cin>>t;

	while(t--){
        int k;
        string s;
        cin>>k>>s;

        cout << newString1(s, k, 0) << " " << newString2(s, k, 0) << endl;
	}

	return 0;
}