#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
double strangeCounter(long n) {
    if(n%3 == 0){
        n--;
    }
    else if(n%3 == 1)
        n -= 2;

    double a = (3 + sqrt(5))/(5 + sqrt(5));
    double x = (1 + sqrt(5))/2;
    double y = (1 - sqrt(5))/2;
    
    double p = a * x * (pow(x, n) - 1)/(x - 1) + (1 - a) * y * (pow(y, n) - 1) / (y - 1);
    p++;
    return p/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double result = strangeCounter(t);

    cout << result << "\n";

    fout.close();

    return 0;
}
