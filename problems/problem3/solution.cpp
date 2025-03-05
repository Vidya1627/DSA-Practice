#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
    int size_s = s.size();
    int size_t = t.size();

    if (size_s != size_t) return false;

    map<char, int> frequency_map;

    for (auto ele : s) {
        frequency_map[ele]++;
    }

    for (auto ele : t) {
        frequency_map[ele]--;
    }

    for (auto ele : frequency_map) {
        if (ele.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << "The strings \"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    } else {
        cout << "The strings \"" << s << "\" and \"" << t << "\" are not anagrams." << endl;
    }

    return 0;
}
