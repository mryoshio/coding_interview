
#include <vector>
#include <iostream>

using namespace std;

bool dup(string arg) {
    vector<int> nums;
    //    cout << "--- start: " << arg << endl;
    for (int i = 0; i < arg.size(); i++) {
        if (find(nums.begin(), nums.end(), arg[i]) == nums.end()) {
            nums.push_back(arg[i]);
        } else {
            //            std::vector<int>::iterator x = find(nums.begin(), nums.end(), arg[i]);
            //            cout << "dup: " << arg[i] << " and " << (char)*x << endl;
            return true;
        }
    }
    return false;
}

int main(){
    vector<string> strs;
    strs.push_back("shibata");
    strs.push_back("shibaku");
    vector<string>::iterator it = strs.begin();
    while (it != strs.end()) {
        cout << *it << " is ";
        if (dup(*it)) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
        it++;
    }
}
