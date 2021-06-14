// Optimal boxes in truck

class Solution {
public:
    struct Comparator {
        bool operator() (vector<int> const& v1, vector<int> const& v2) {
            return v1[1] > v2[1];
        }
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), Comparator());
        int unitCount = 0;
        for (auto boxType : boxTypes) {
            int boxCount = min(truckSize, boxType[0]);
            unitCount += boxCount * boxType[1];
            truckSize -= boxCount;
            if (truckSize == 0)
                break;
        }
        return unitCount;
    }
};