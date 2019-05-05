class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        float dx1 = points[0][0]-points[1][0];
        float dy1 = points[0][1]-points[1][1];
        float dx2 = points[1][0]-points[2][0];
        float dy2 = points[1][1]-points[2][1];
        
        if(dx1 == 0 && dy1 == 0) return false;
        else if(dx2 == 0 && dy2 == 0) return false;
        else{
            if(dx1 == 0){
                if(dx2 == 0) return false;
                else return true;
            }
            else{
                if(dx2 == 0) return true;
                else if(dy1/dx1 == dy2/dx2) return false;
                else return true;
            }    
        }
    }
};
