#include <iostream>
#include <string>

using namespace std;

bool is_good_prize(int position) {
    string good_prizes = "loyalixa";
    return good_prizes.find(position + 'a') != string::npos;
}

int main() {
    int n;
    cin >> n;

    int final_position = n % 26;
    cout << (is_good_prize(final_position) ? "HAPPY" : "SAD") << endl;

    return 0;
}
