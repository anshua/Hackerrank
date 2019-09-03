#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool isPointOnCircle(int x, int y, int r, vector<int> t){
    int x1 = (x - t[0]);
    int y1 = (y - t[1]);
    double d = sqrt(x1*x1 + y1*y1);
    return (d == r);
}

bool isPointInside(int x, int y, int r, vector<int> t){
    int x1 = (x - t[0]);
    int y1 = (y - t[1]);
    double d = sqrt(x1*x1 + y1*y1);
    return (d < r);
}

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

vector<int> coefficient(vector<int> t1, vector<int> t2) {
    int a1 = t1[0];
    int a2 = t2[0];
    int b1 = t1[1];
    int b2 = t2[1];
    vector<int> v;
    int a = b1 - b2;
    int b = a2 - a1;
    int c = a1*b2 - a2*b1;
    int g = gcd(a, gcd(b, c));
    v.push_back(a/g);
    v.push_back(b/g);
    v.push_back(c/g);
    // for (int i = 0; i < v.size(); ++i){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    return v;
}

double shortestDistance(int x, int y, int r, vector<int> t1, vector<int> t2){
    vector<int> v = coefficient(t1, t2);
    double d = abs(x*v[0] + y*v[1] + v[2])/sqrt(v[0]*v[0] + v[1]*v[1]);
    return d;
}

int dist(int x1, int y1, int x2, int y2){
    return (x1 - x2)*(x1 - x2) + (y1-y2)*(y1-y2);
}

// Complete the solve function below.
bool solve(int x, int y, int r, vector<int> t1, vector<int> t2, vector<int> t3) {
    if(isPointOnCircle(x, y, r, t1) || isPointOnCircle(x, y, r, t2) || isPointOnCircle(x, y, r, t3)){
        return true;
    }
    if(isPointInside(x, y, r, t1) && isPointInside(x, y, r, t2) && isPointInside(x, y, r, t3)){
        return false;
    }
    if(isPointInside(x, y, r, t1) || isPointInside(x, y, r, t2) || isPointInside(x, y, r, t3)){
        return true;
    }
    if(shortestDistance(x, y, r, t1, t2) <= r){
        int lineDist = dist(t1[0], t1[1], t2[0], t2[1]);
        int d1 = dist(t1[0], t1[1], x, y);
        int d2 = dist(x, y, t2[0], t2[1]);
        if(lineDist > max(d1, d2)){
            return true;
        }
    }
    cout << "second\n";
    if(shortestDistance(x, y, r, t1, t3) <= r){
        int lineDist = dist(t1[0], t1[1], t3[0], t3[1]);
        int d1 = dist(t1[0], t1[1], x, y);
        int d2 = dist(x, y, t3[0], t3[1]);
        if(lineDist > max(d1, d2)){
            return true;
        }
    }
    cout << "third\n";
    if(shortestDistance(x, y, r, t3, t2) <= r){
        int lineDist = dist(t3[0], t3[1], t2[0], t2[1]);
        int d1 = dist(t3[0], t3[1], x, y);
        int d2 = dist(x, y, t2[0], t2[1]);
        if(lineDist > max(d1, d2)){
            return true;
        }
    }
    return false;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xyr_temp;
        getline(cin, xyr_temp);

        vector<string> xyr = split_string(xyr_temp);

        int x = stoi(xyr[0]);

        int y = stoi(xyr[1]);

        int r = stoi(xyr[2]);

        string t1_temp_temp;
        getline(cin, t1_temp_temp);

        vector<string> t1_temp = split_string(t1_temp_temp);

        vector<int> t1(2);

        for (int i = 0; i < 2; i++) {
            int t1_item = stoi(t1_temp[i]);

            t1[i] = t1_item;
        }

        string t2_temp_temp;
        getline(cin, t2_temp_temp);

        vector<string> t2_temp = split_string(t2_temp_temp);

        vector<int> t2(2);

        for (int i = 0; i < 2; i++) {
            int t2_item = stoi(t2_temp[i]);

            t2[i] = t2_item;
        }

        string t3_temp_temp;
        getline(cin, t3_temp_temp);

        vector<string> t3_temp = split_string(t3_temp_temp);

        vector<int> t3(2);

        for (int i = 0; i < 2; i++) {
            int t3_item = stoi(t3_temp[i]);

            t3[i] = t3_item;
        }

        bool r1 = solve(x, y, r, t1, t2, t3);
        string result = (r1)? "YES" : "NO";
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
