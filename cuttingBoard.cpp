#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define M 1000000007
using namespace std;

vector<string> split_string(string);

int boardCuttingHelper(vector<int> cost_x, vector<int> cost_y) {
    int pieces[2] = {1, 1};
    sort(cost_x.begin(), cost_x.end());
    sort(cost_y.begin(), cost_y.end());
    int i = cost_x.size()-1;
    int j = cost_y.size()-1;

    long ans = 0;
    long p = 0;
    while(i >= 0 && j >= 0){
        if(cost_x[i] > cost_y[j]){
            p = cost_x[i];
            ans += pieces[1] * p;
            pieces[0]++;
            i--;
        }
        else if(cost_x[i] < cost_y[j]) {
            p = cost_y[j];
            ans += pieces[0] * p;
            pieces[1]++;
            j--;
        }
        else if(i > j) {
            p = cost_x[i];
            ans += pieces[1] * p;
            pieces[0]++;
            i--;
        }
        else {
            p = cost_y[j];
            ans += pieces[0] * p;
            pieces[1]++;
            j--;
        }
        ans %= M;
    }

    while(i >= 0) {
        p = cost_x[i];
        ans += pieces[1] * p;
        pieces[0]++;
        i--;
        ans %= M;
    }

    while(j >= 0){
        p = cost_y[j];
        ans += pieces[0] * p;
        pieces[1]++;
        j--;
        ans %= M;
    }
    // cout << ans << endl;
    return ans;
}

// Complete the boardCutting function below.
int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    if(cost_y.size() > cost_x.size()){
        return boardCuttingHelper(cost_y, cost_x);
    }
    else {
        return boardCuttingHelper(cost_x, cost_y);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string mn_temp;
        getline(cin, mn_temp); 

        vector<string> mn = split_string(mn_temp);

        int m = stoi(mn[0]);

        int n = stoi(mn[1]);

        string cost_y_temp_temp;
        getline(cin, cost_y_temp_temp);

        vector<string> cost_y_temp = split_string(cost_y_temp_temp);

        vector<int> cost_y(m-1);

        for (int i = 0; i < m-1; i++) {
            int cost_y_item = stoi(cost_y_temp[i]);

            cost_y[i] = cost_y_item;
        }

        string cost_x_temp_temp;
        getline(cin, cost_x_temp_temp);

        vector<string> cost_x_temp = split_string(cost_x_temp_temp);

        vector<int> cost_x(n-1);

        for (int i = 0; i < n-1; i++) {
            int cost_x_item = stoi(cost_x_temp[i]);

            cost_x[i] = cost_x_item;
        }

        int result = boardCutting(cost_y, cost_x);

        fout << result << "\n";
    }

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
