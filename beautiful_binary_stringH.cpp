#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string s) {
    int ans = 0;
    for (int i = 0; i < s.length()-2; ++i){
        if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0'){
            s[i+2] = '1';
            ans ++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
