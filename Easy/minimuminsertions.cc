
class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int>pq(a.begin(),a.end());

        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a != b)
                pq.push(abs(a-b));
        }
        return pq.empty() ? 0 : pq.top();
    }
};