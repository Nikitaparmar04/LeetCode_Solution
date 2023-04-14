class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int n = pushed.size();
        int j =0;
        for (int i=0; i<n; i++){
            st.push_back(pushed[i]);
            while(j<n && !st.empty() && st.back()==popped[j]){
                st.pop_back();
                j++;
            }
        }
        return st.size()==0;
    }
};