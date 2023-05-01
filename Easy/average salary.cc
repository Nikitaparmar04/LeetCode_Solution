class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
        }
        return (sum - salary[0] - salary[salary.size() - 1]) / (salary.size() - 2);
    }
};