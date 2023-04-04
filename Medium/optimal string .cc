class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> checkUniqueAlphabet;
        int i = 0;
        int minCount = 0;
        while (i < s.length()) {
            minCount++;
            while (i < s.length() && checkUniqueAlphabet.find(s[i]) == checkUniqueAlphabet.end()) {
                checkUniqueAlphabet.insert(s[i]);
                i++;
            }
            checkUniqueAlphabet.clear();
        }
        return minCount;
    }
};
