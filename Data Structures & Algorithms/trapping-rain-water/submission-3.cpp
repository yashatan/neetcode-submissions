class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxValueIndex;
        int sumRain =0;

        int leftboundary =0;
        while(height[leftboundary] == height[leftboundary+1]){
            leftboundary++;
        }
        if(height[leftboundary] > height[leftboundary+1]){
            maxValueIndex.push_back(leftboundary);
        }
        

        for(int i =1; i< height.size()-1; i++){
            if(height[i-1] < height[i] && height[i] > height[i+1]){
                maxValueIndex.push_back(i);
            }
        }
        
        int rightboundary =height.size()-1;
        while(height[rightboundary] == height[rightboundary-1]){
            leftboundary--;
        }
        if(height[rightboundary] > height[rightboundary-1]){
            maxValueIndex.push_back(rightboundary);
        }
        cout<<"cuc tri: " ;
        for(int i =0; i < maxValueIndex.size(); i++){
            cout << maxValueIndex[i] << " ";
        }

        int L =0;
        for(int R=1; R < maxValueIndex.size(); R++){
            
            if(height[maxValueIndex[R]] > height[maxValueIndex[L]]){
                for(int j = maxValueIndex[L]+1; j < maxValueIndex[R]; j++){
                    sumRain += min(height[maxValueIndex[L]], height[maxValueIndex[R]]) - height[j];
                    cout<<"test for: " << j << endl;
                }
                L =R;
            }

            if((R>L)&&(R==maxValueIndex.size()-1)){
                for(int j = maxValueIndex[L]+1; j < maxValueIndex[R]; j++){
                    if ( min(height[maxValueIndex[L]], height[maxValueIndex[R]]) > height[j]){
                    sumRain += min(height[maxValueIndex[L]], height[maxValueIndex[R]]) - height[j];
                    }

                }
            }
        }
        return sumRain;
    }
};
