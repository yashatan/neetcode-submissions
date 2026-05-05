class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), 0);

        int oneDayPrice = costs[0];
        int sevenDayPrice = costs[1];
        int thirdtyDayPrice = costs[2];

        dp[0] = oneDayPrice;
        for(int i =1; i < days.size(); i++){
            dp[i] = dp[i-1]+oneDayPrice;
        }

        vector<int> curRow(days.size(), 0);
        int L7=0, L30 =0;
        curRow[0] = dp[0];
        for(int i =1; i < days.size(); i++){
            while(days[i]-days[L7] > 6){
                L7++;
            }
            int takeOld = dp[i];
            int takeSeven = curRow[L7-1]+sevenDayPrice;
            int takeOne = curRow[i-1] +oneDayPrice;
            curRow[i] = min(takeOld, min(takeSeven,takeOne));
        }
        dp = curRow;

        curRow = vector<int>(days.size(), 0);
        L7 =0;
        curRow[0] = dp[0];
        for(int i =0; i < days.size(); i++){
            while(days[i]-days[L7] > 6){
                L7++;
            }

            while(days[i]-days[L30] > 29){
                L30++;
            }
            int takeOld = dp[i];

            int takeSeven = curRow[L7-1]+sevenDayPrice;

            int takeNewOne = curRow[i-1] +oneDayPrice;

            int takeThirty = curRow[L30-1]+thirdtyDayPrice;

            curRow[i] = min({takeOld,takeSeven,takeNewOne, takeThirty});
        }

        dp = curRow;
        return dp[days.size()-1];
    }
};