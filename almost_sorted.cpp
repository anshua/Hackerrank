#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> A) {
    int n = A.size();
    vector<int> v = A;
    sort(v.begin(), v.end());
    int l, r;
    int p = 0;

    for(int i = 0; i < n; i++){
        if(v[i] != A[i]){
            if(p == 0){
                l = i;
            }
            else{
                r = i;
            }
            p++;
        }
    }
    if(p == 0){
        cout << "yes\n";
        return;
    }
    if(p == 2){
        cout << "yes\n";
        cout << "swap " << l+1 << " " << r+1 << endl;
        return;
    }
    p = 0;
    for(int i = 0; i < n; i++){
        if(p == 0 && i < n-1 && A[i] > A[i+1]){
            p++;
            l = i;
            while(i < n-1 && A[i] > A[i+1]){
                i++;
            }
            r = i;
            if(r < n-1 && A[l] > A[r+1]){
                cout << i <<  "no\n";
                return ;
            }
            if(l > 0 && A[l-1] > A[r]){
                cout << i << "no\n";
                return;
            }
        }
        if(p == 1 && i < n-1 && A[i] > A[i+1]){
            cout << i << "no\n";
                return ;
        }
    }
    cout << "yes\n";
    if(r-l == 1){
        cout << "swap " << l+1 << " " << r+1 << endl;
    }
    else
        cout << "reverse " << l+1 << " " << r+1 << endl;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
