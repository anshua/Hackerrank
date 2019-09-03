#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
char minimum(string s, bool selected[], int a, int b, int A[], int count[]){
    for (int i = a; i < b; ++i){
        if(!selected[i] && A[s[i]-'a'] <= count[i]){
            return s[i];
        }
    }
    return '/';
}

char maximum(string s, bool selected[], int A[], int count[]){
    for (int i = s.length()-1; i >= 0; --i){
        if(!selected[i] && A[s[i]-'a'] < count[i]){
            return s[i];
        }
    }
    return '/';
}

void selectedChar(char c, bool selected[], string s){
    for (int i = 0; i < s.length(); ++i){
        if(c == s[i] && !selected[i]){
            selected[i] = true;
            return;
        }
    }
}

void selectCriticalChar(int a, int b, bool selected[],
    int A[], string s, string newS, string &ans, int count[], int &modifiedLastIndex){
    if(a >= b)
        return;
    char c = '|';
    for (int i = a; i < b; ++i){
        if(c > s[i] && A[s[i]-'a'] > 0 && s[i] < s[b] && !selected[i]){
            c = s[i];
        }
    }
    int lastIndex = b;
    for (int i = a; i < b; ++i){
        if(c == s[i] && A[c-'a'] > 0 && !selected[i]){
            ans += c;
            A[c-'a']--;
            modifiedLastIndex = i;
            lastIndex = i;
            selectedChar(c, selected, newS);
        }
    }
    if(lastIndex < b){
        selectCriticalChar(lastIndex+1, b, selected, A, s, newS, ans, count, modifiedLastIndex);
    }
}

string reverseShuffleMerge(string s) {
    int A[26] = {0};
    int count[s.length()] = {0};
    reverse(s.begin(), s.end());
    for (int i = s.length()-1; i >= 0; --i){
        A[s[i] - 'a']++;
        count[i] = A[s[i] - 'a'];
    }
    string newS = "";
    for (int i = 0; i < 26; ++i){
        int p = 0;
        while(p < A[i]/2){
            newS += ('a' + i);
            p++;
        }
        A[i] /= 2;
    }
    bool selected[newS.length()] = {false};
    string ans = "";
    int lastIndex = -1;
    int modifiedLastIndex = -1;
    for (int i = 0; i < s.length(); ++i){
        if(count[i] == A[s[i] - 'a']){
            selectCriticalChar(modifiedLastIndex+1, i, selected, A, s, newS, ans, count, modifiedLastIndex);
            cout << i << " -> " << s[i] << endl;
            if(A[s[i] - 'a'] > 0){
            	ans += s[i];
	            lastIndex = i;
	            A[s[i] - 'a']--;
	            selectedChar(s[i], selected, newS);
            }
            continue;
        }
    }
    cout << newS << endl;
    cout << s << endl;
    cout << endl << ans << endl;
    ans  = "";
    for (int i = 0; i < s.length(); ++i){
    	if(selected[i]){
    		ans += s[i];
    	}
    }
    cout << endl << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
