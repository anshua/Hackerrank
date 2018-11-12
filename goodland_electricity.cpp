#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pylons function below.
int pylons(int k, vector<int> A) {
    int n = A.size();
    int i = k-1;
    int ans = 0;
    while(i >= 0 && A[i] == 0){     //tracks the first point for power plant
        i --;
    }

    if(i < 0){
        return -1;
    }
    ans ++;
    int lastpoint = i;
    int reach = i + k - 1;          //reach of the first power point
    while(reach < n){
        int next_point = min(lastpoint + 2*k - 1, n-1);
        while(next_point > lastpoint && A[next_point] == 0){   //tracks the next point for power plant
            next_point --;
        }
        if(next_point <= lastpoint){
            return -1;
        }
        ans ++;
        reach = next_point + k - 1;
        lastpoint = next_point;
        if(reach >= n-1)
            break;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pylons(k, arr);

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
