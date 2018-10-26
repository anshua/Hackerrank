#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair

vector<string> split_string(string);

// Complete the chessboardGame function below.
bool board[15][15];


bool isValid(int i, int j){
    if(i < 0 || j < 0 || i >= 15 ||j >= 15)
        return false;
    return true;
}

void fillBoard(){
    int X[] = {-2, -2, 1, -1};
    int Y[] = {1, -1, -2, -2};

    queue<pii> q;
    q.push(mp(0,0));
    q.push(mp(0,1));
    q.push(mp(1,0));
    q.push(mp(1,1));
    // while(!q.empty()){
    //     pii p = q.front();
    //     q.pop();

    //     for (int i = 0; i < 4; ++i){
    //         int x = p.first + X[i];
    //         int y = p.second + Y[i];
    //         if(isValid(x, y) && !visited[x][y]){
    //             visited[x][y] = true;
    //             board[x][y] = !board[p.first][p.second] ;
    //             q.push(mp(x,y));
    //         }
    //     }
    // }
    int i, j;
    for(int sum = 0; sum <= 28; sum++){
        i = sum, j = 0;
        cout << i << " " << j << " => ";
        for (; i >= 0 && j >= 0; --i, j++){
            if(j >= 15)
                continue;
            if(i > 14){
                i = 14;
                j = sum - i;
            }
            cout << " (" << i << " " << j << ") ";
            bool b = true;
            for(int k = 0; k < 4; k++){
                int x = i + X[k];
                int y = j + Y[k];
                if(isValid(x, y)){
                    b =  b & board[x][y];
                }
            }
            board[i][j] = !b;
        }
        cout << endl;
    }

    for (int i = 0; i < 15; ++i){
        for(int j = 0; j < 15; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

string chessboardGame(int x, int y) {
    x--; y--;
    if(board[x][y])
        return "First";
    return "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    fillBoard();
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        string result = chessboardGame(x, y);

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
