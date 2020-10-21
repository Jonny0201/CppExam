#include <iostream>
#include <vector>

using namespace std;

auto move_count {0ull};
inline void move(vector<int> &from, vector<int> &to, char char_from, char char_to) {
    auto value {from.back()};
    from.pop_back();
    to.push_back(value);
    ++move_count;
    cout << "Move " << char_from << " To " << char_to << endl;
}
void hanoi_aux(typename vector<int>::size_type size, vector<int> &X, vector<int> &Y, vector<int> &Z, char char_X = 'X', char char_Y = 'Y', char char_Z = 'Z') {
    if(size == 0) {
        return;
    }
    hanoi_aux(size - 1, X, Z, Y, char_X, char_Z, char_Y);
    move(X, Z, char_X, char_Z);
    hanoi_aux(size - 1, Y, Z, X, char_Y, char_Z, char_X);
}
inline void hanoi(vector<int> &X, vector<int> &Y, vector<int> &Z) {
    hanoi_aux(X.size(), X, Y, Z);
}
vector<int> init_X(int n) {
    vector<int> vec;
    while(n > 0) {
        vec.push_back(n--);
    }
    return vec;
}
int main() {
    auto X {init_X(10)};
    vector<int> Y {}, Z {};
    hanoi(X, Y, Z);
    cout << "Move Times : " << move_count << endl;
    for(auto c : Z) {
        cout << c << "\t";
    }
    cout << endl;
}
