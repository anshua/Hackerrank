#include <bits/stdc++.h>

using namespace std;

bool separate(string s, int n){
    long int a, c;
    stringstream(s.substr(0, n)) >> a;
    bool b = true;

    for (int i = 0; i < n; ++i){
        if(s[i] != '9'){
            b = false;
            break;
        }
    }
    int i = n;
    if(b)
        n++;

    for (; i < s.length();){
        stringstream(s.substr(i, n)) >> c;
        if(c - a != 1 || s[i] == '0')
            return false;
        b = true;
        for(int j = i; j < i+n; j++){
            if(s[j] != '9'){
                b = false;
                break;
            }
        }
        i+=n;
        if(b){
            n++;
        }
        a = c;
    }

    return true;
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    if(s.length() == 1){
        cout << "NO\n";
        return;
    }

    // for

    for (int i = 1; i <= s.length()/2; ++i){
        if(separate(s, i)){
            cout << "YES " << s.substr(0, i) << endl;
            return;
        }
    }
    
    cout << "NO\n";
    return;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
