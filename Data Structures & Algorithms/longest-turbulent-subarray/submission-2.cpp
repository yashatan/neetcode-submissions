class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool smallerFlag = false;
        int lengthRes = 1;
        int curLength = 1;
        if (arr.size() <2){
            return arr.size();
        }

        for (int i=1; i<arr.size(); i++){
            if((smallerFlag&& (arr[i]<arr[i-1]))|| (!smallerFlag&& (arr[i]>arr[i-1])) || (curLength==1 && (arr[i]!=arr[i-1]))){
                curLength++;
                if(arr[i]>arr[i-1]) smallerFlag = true;
                if(arr[i]<arr[i-1]) smallerFlag = false;
                lengthRes = max(lengthRes, curLength);
                cout << "Dang chuoi: " <<  arr[i] << endl;
            }else{
                if (arr[i]>arr[i-1]){
                    curLength=2;
                    smallerFlag = true;
                }else if(arr[i]<arr[i-1]){
                    curLength=2;
                    smallerFlag = false;
                }else{
                    curLength=1;
                }
                cout << "Dut chuoi: " << arr[i] << endl;
            }
        }
        return lengthRes;
    }
};