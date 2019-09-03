#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long NoOfMoves(long n){
    if(n == 1)
        return 1;
    long m = n;
    long ans = 1;
    for (int i = 2; i <= sqrt(m+1); ++i){
        while(n%i == 0){
            n = n/i;
            ans = ans * i + 1;
        }
    }
    if(n == 1)
        return ans;
    return ans*n + 1;
}

// Complete the longestSequence function below.
long longestSequence(vector<long> a) {
    // Return the length of the longest possible sequence of moves.
    long ans = 0;
    for (int i = 0; i < a.size(); ++i){
        ans += NoOfMoves(a[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<long> a(n);

    for (int i = 0; i < n; i++) {
        long a_item = stol(a_temp[i]);

        a[i] = a_item;
    }

    long result = longestSequence(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
