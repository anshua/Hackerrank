#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

vector<string> split_string(string);

// Complete the beautifulPath function below.
int beautifulPath(vector<vector<pii>> edges, int A, int B, int n) {
    bool T[n+1][1024];
    queue<int> q, k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 1024; j++){
            T[i][j] = false;
        }
    }
    T[A][0] = true;
    q.push(A);
    k.push(0);

    while(!q.empty()){
        int f = q.front();
        q.pop();
        int K = k.front();
        k.pop();
        // cout << f << " -> ";
        for(int i = 0; i < edges[f].size(); i++){
            pii p = edges[f][i];
            if(!T[p.first][p.second | K]){
                T[p.first][p.second | K] = true;
                q.push(p.first);
                k.push(p.second | K);
            }
        }
    }
    for (int i = 0; i < 1024; ++i){
        if(T[B][i])
            return i;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<pii>> edges(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edges[u].push_back(mp(v, w));
        edges[v].push_back(mp(u, w));

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B, n);

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
