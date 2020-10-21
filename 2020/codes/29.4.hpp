#include <vector>
#include <stack>

using namespace std;

vector<int> unfold(const generalized_list<int> &glist) noexcept {
    vector<int> vec {};
    stack<generalized_list<int>> s {};
    for(auto i {glist.size() - 1}; i >= 0; --i) {
        s.push(glist[i]);
    }
    while(!s.empty()) {
        if(s.top().empty()) {
            s.pop();
            continue;
        }
        if(s.top().is_glist(0)) {
            for(auto i {s.top().size() - 1}; i >= 0; --i) {
                s.push(s.top()[i]);
            }
            continue;
        }
        vec.push_back(s.top());
        s.pop();
    }
    return vec;
}
