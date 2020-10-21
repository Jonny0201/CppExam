#include <iostream>

using namespace std;

template <typename T, size_t N>
void in(int (&arr)[N], int index, T &&value) {
    arr[index] = forward<T>(value);
}
template <typename T, typename ...Args, size_t N>
void in(int (&arr)[N], int index, T &&value, Args &&...args) {
    arr[index] = forward<T>(value);
    in(arr, index + 1, forward<Args>(args)...);
}
template <typename ...Args>
void f(Args &&...args) {
    int arr[sizeof...(Args)] {};
    in(arr, 0, forward<Args>(args)...);
    for(auto i {0}; i < sizeof...(Args); ++i) {
        for(auto j {0}; j < sizeof...(Args) - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                auto temp {arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for(auto c : arr) {
        cout << c << "\t";
    }
    cout << endl;
}
