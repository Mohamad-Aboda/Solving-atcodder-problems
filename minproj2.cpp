#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

void start() {
    cout << "Please, select one of the following applications:" << endl;
    cout << "[1] Select 1 to execute Calculator" << endl;
    cout << "[2] Select 2 to execute Comparator" << endl;
    cout << "[3] Select 3 to execute Summing System" << endl;
    cout << "[4] Select 4 to find Maximum of m numbers" << endl;
    cout << "[5] Select 5 to Calculate sum of series" << endl;
    cout << "Please, Enter Your Selection: ";
}
bool check_number2(string str) {
    bool ok = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            ok = false;
            break;
        }
        
    }
    return ok;
}
bool check_number(string str) {
    bool ok = true;
    for (int i = 0; i < str.length(); i++) {
        if (i == 0) {
            if (str[i] == '-') {
                ok = true;
            }
            else if (isdigit(str[i])) {
                ok = true;
            }
            else {
                ok = false;
                break;
            }
        }
        else {
            if (isdigit(str[i])) {
                ok = true;
            }
            else {
                ok = false;
                break;
            }
        }
    }
    return ok;
}
void calculator() {
    bool ok = true;
    while (ok) {
        bool oka = false, okb = false;
        string a, b;
        char sign;
        cout << "Please Enter the First Number" << endl;
        cin >> a;
        cout << "Please Enter the operation (+, - , *, /)" << endl;
        cin >> sign;
        cout << "Please Enter the Second Number" << endl;
        cin >> b;
        float res = 0;
     
        if (sign == '+' && check_number(a) && check_number(b) ) {
            res = float(stoi(a)) + float(stoi(b));  ok = false;  cout << "The Result is = " << res << endl;
        }
        else if (sign == '-' && check_number(a) && check_number(b)) {
            res = float(stoi(a)) - float(stoi(b)); ok = false; cout << "The Result is = " << res << endl;
        }
        else if (sign == '*' && check_number(a) && check_number(b)) {
            res = float(stoi(a)) * float(stoi(b)); ok = false; cout << "The Result is = " << res << endl;
        }
        else if (sign == '/' && b != "0" && check_number(a) && check_number(b) ) {
            res = float(stoi(a)) / float(stoi(b)); ok = false; cout << "The Result is = " << res << endl;
        }
        else if (sign == '/' && b == "0" && check_number(a) && check_number(b)) {
            cout << "Division by zero not valid" << endl;
            ok = false;
        }
        else {
            cout << "Please Enter Valid Input!" << endl;
        }
    }
}

void comparator() {
    bool ok = true;
    while (ok) {
        string x, y, z;
        cout << "Enter The First Number: " << endl;
        cin >> x;
        cout << "Enter The Second Number : " << endl;
        cin >> y;
        cout << "Enter The Third Number : " << endl;
        cin >> z;
        if (check_number(x) && check_number(y) && check_number(z)) {

            int mn = min(min(stoi(x), stoi(y)), stoi(z));
            cout << "Minimum value is " << mn << endl;
            ok = false;
        }
        else {
            cout << "Please Enter Valid Input!" << endl;
        }
    }
}

void summing() {
    // the summig formula for even numbers is m * (m + 1)
    bool ok = true;
    while (ok) {
        cout << "Please Enter Positive Integers :" << endl;
        string m; cin >> m;
        if (check_number2(m) && stoi(m) != 0) {
            long long res = stoi(m) * (stoi(m) + 1);
            cout << "The sum of the first " << m << " even numbers = " << res << endl;
            cout << "And thier average is = " << res / stoi(m) << endl;
            ok = false;
        }
        else {
            cout << "Please Enter Valid Input!" << endl;
        }
    }
}

void maximum() {
    bool ok = true;
    while (ok) {
        cout << "Enter the number " << endl;
        vector<int>v;
        string n; cin >> n;
      
        if (check_number2(n) && stoi(n) > 0) {
            cout << "Now enter the numbers you want to compute the max for ?" << endl;
            for (int i = 0; i < stoi(n); ++i) {
                cout << "Enter a number: " << endl;
                string a; cin >> a;
                bool temp = true;
                while (temp) {
                    if (check_number(a)) {
                        v.push_back(stoi(a));
                        temp = false;
                    }
                    else {
                        cout << "Please Enter a number!" << endl;
                        cin >> a;
                    }
                }
            }
            int mx = *max_element(v.begin(), v.end());
            cout << "The Max between the numbers you enterd is = " << mx << endl;
            ok = false;
        }
        else {
            cout << "Please Enter Valid Input!" << endl;
        }
    }
}

void sum() {
    bool ok = true;
    while (ok) {
        cout << "Please Enter the number " << endl;
        string n; cin >> n;
        if (check_number(n)) {
            float res = 0;
            for (float i = 1; i <= stoi(n); ++i) {
                res += (1 / (i * i));
            }
            cout << "The Series sum is = " << res << endl;
            ok = false;
        }
        else {
            cout << "Please Enter Valid Input!" << endl;
        }
    }
}

string convert(string s) {
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool confirm() {
    bool ok = true;
    bool terminate = false;
    while (ok) {
        cout << "Do You want to continue? Yes/No" << endl;

        string s; cin >> s;
        s = convert(s);
        if (s == "no") {
            terminate = false;
            ok = false;
        }
        else if (s == "yes") {
            terminate = true;
            ok = false;
        }
        else {
            cout << "Please Entre Yes / No" << endl;
        }
    }

    return terminate;
}

bool valid(string n) {
    if (n == "1" || n == "2" || n == "3" || n == "4" || n == "5")
        return true;
    else
        return false;
}

void input() {
    bool ok = true;
    string n;
    while (ok) {
        cin >> n;
        if (valid(n)) {
            ok = false;
            if (n == "1")
                calculator();
            else if (n == "2")
                comparator();
            else if (n == "3")
                summing();
            else if (n == "4")
                maximum();
            else if (n == "5")
                sum();
        }
        else {
            cout << "Please enter valid input!" << endl;
            cout << "The input should be 1 or 2 or 3 or 4 or 5 : ";
        }

    }
}

int main() {
    
    bool ok = true;
    while (ok) {
        start();
        input();

        ok = confirm();

    }
    return 0;
}
