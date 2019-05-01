#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ppii pair<int, pii>
#define mp make_pair

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    priority_queue<ppii, std::vector<ppii>, greater<ppii> > q;

    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'd'){
                q.push(mp(abs(i - posr) + abs(j - posc), mp(i, j)));
            }
        }
    }

    ppii p = q.top();
    while(!q.empty()){
        q.pop();
    }
    pii z = p.second;
    if(z == mp(posr, posc)){
        cout << "CLEAN\n";
        return;
    }
    if(z.second < posc){
        cout << "LEFT" << endl;
        return;
    }
    if(z.second > posc){
        cout << "RIGHT" << endl;
        return;
    }

    if (z.first < posr){
        cout << "UP" << endl;
        return;
    }
    cout << "DOWN" << endl;
    return;
}
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
