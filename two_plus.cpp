#include <bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<int, pii>
#define mp make_pair
using namespace std;

vector<string> split_string(string);

bool overlap(int x, int y, pii x_center, pii y_center){
    if(abs(x_center.first - y_center.first) < x + y || abs(x_center.second - y_center.second) < x + y)
        return false;
    return true;
}

int second_highest(vector<string> A){
    int n = A.size();
    int m = A[0].length();

    int a = 0, b = 0;

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'G'){
                int left = j, right = j, up = i, down = i;
                while(left >= 0 && A[i][left] == 'G'){
                    left --;
                }
                while(right < m && A[i][right] == 'G'){
                    right ++;
                }
                while(up >= 0 && A[up][j] == 'G'){
                    up --;
                }
                while(down < n && A[down][j] == 'G'){
                    down ++;
                }
                left ++;
                right --;
                up ++;
                down --;

                int size_of_plus = min(j - left, min(right - j, min(i - up, down - i)));
                int size_of_square = 1 + 4 * size_of_plus;
                b = max(b, size_of_square);
            }
        }
    }
    return b;
}


// Complete the twoPluses function below.
int twoPluses(vector<string> A) {
    int n = A.size();
    int m = A[0].length();

    int a = 0, b = 0;
    std::vector<ppii> v;


    int ans = 0;

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'G'){
                int left = j, right = j, up = i, down = i;
                while(left >= 0 && A[i][left] == 'G'){
                    left --;
                }
                while(right < m && A[i][right] == 'G'){
                    right ++;
                }
                while(up >= 0 && A[up][j] == 'G'){
                    up --;
                }
                while(down < n && A[down][j] == 'G'){
                    down ++;
                }
                left ++;
                right --;
                up ++;
                down --;

                int size_of_plus = min(j - left, min(right - j, min(i - up, down - i)));
                int size_of_square = 1 + 4 * size_of_plus;
                v.push_back(mp(size_of_square, mp(i, j)));
            }
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    if(v.size() < 2)
        return 0;
    if(v[0].first == 1)
        return 1;
    std::vector<string> s = A;
    for (int i = 0; i < v.size() && v[i].first != 1; ++i){
        // cout << v[i].first << " => " << v[i].second.first << " " << v[i].second.second << endl;
        ppii x = v[i];

        pii x_center = x.second;
        int x_size = x.first/4;

        int p = x_center.first;
        int q = x_center.second;

        int index = 1;
        while(index <= x_size){
            s[p][q+index] = 'B';
            index ++;
        }
        index = 1;
        while(index <= x_size){
            s[p][q-index] = 'B';
            index ++;
        }
        index = 1;
        while(index <= x_size){
            s[p+index][q] = 'B';
            index ++;
        }
        index = 1;
        while(index <= x_size){
            s[p-index][q] = 'B';
            index ++;
        }
        int z = second_highest(s);
        cout << p << " " q << " -> " << z << endl;
        ans = max(ans, x.first * z);
        s = A;
    }

    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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

