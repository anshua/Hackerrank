#include <bits/stdc++.h>

using namespace std;

bool miniChar(string a, string b, int i, int j){
    while(i < a.length() && j < b.length()){
        if(s[i] < s[j])
            return true;
        if(s[i] > s[j])
            return false;
        i++, j++;
    }
    return true;
}

// Complete the morganAndString function below.
string morganAndString(string a, string b) {
    int i = 0, j = 0;
    string ans = "";
    while(i < a.length() && j < b.length()) {
        if(s[i] < s[j]){
            ans += s[i];
            i++;
        }
        else if(s[i] > s[j]){
            ans += s[j];
            j++;
        }
        else {
            ans += s[i];
            i++;
            // if(miniChar(a, b, i, j)){
                
            // }
            // else {
            //     ans += s[j];
            //     j++;
            // }
        }
    }
    while(i < a.length()) {
        ans += s[i];
        i++;
    }
    while(j < b.length()){
        ans += s[j];
        j++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
