#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> A) {
    int n = A.size();
    int ans = INT_MAX;
    sort(A.begin(), A.end());

    for (int i = 0; i < n && i+k-1 < n; ++i){
        ans = min(A[i+k-1] - A[i], ans);
    }
    
    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
