#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}

int convertFive(int n) {
    int temp = n;
    int last_digit, digit, sum = 0, r = 0;
    
    while (temp > 0) {
        last_digit =  temp % 10;
        digit = last_digit;
        if (last_digit == 0) {
            digit = 5;
        }
        sum = (sum * 10) + digit;
        temp = temp/10;
    }
    
    int no = sum;
    temp = no;
    sum = 0;
    
    while(temp > 0) {
        r = temp % 10;
        sum = sum*10 + r;
        temp = temp / 10;
    }
    
    return sum;
    
}