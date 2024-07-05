#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class TwoSum {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        TwoSum(){};

        // Destructor (phương thức hủy)
        ~TwoSum() {};
        
        static vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> myMap;
            vector<int> output;
            for(int i = 0; i < nums.size(); i++){
                if (myMap.find(target - nums.at(i)) != myMap.end()){
                    output.push_back(i);
                    output.push_back(myMap[target - nums.at(i)]);
                    return output;
                }
                myMap.insert({nums[i], i});
            }
            return output;
        }

        static string convertToString(vector<int> v) {
            string data_str = "[ " ;
            for(int i = 0; i < v.size(); i++){
                if(i+1 == v.size()){
                    data_str += to_string(v.at(i));
                }else{
                    data_str += to_string(v.at(i));
                    data_str += ", " ;
                }
            }
            data_str += " ]";
            return data_str;
        }
        static void testFunction() {
            int countPassed = 0;
            vector<vector<int>> datas = {{2,7,11,15}, {3,2,4}, {3,3}};
            vector<int> targets = {9, 6, 6};
            vector<vector<int>> expecteds = {{0,1}, {1,2}, {0,1}};

            // {2,7,11,15}, 9, {0,1}
            // {3,2,4}, 6, {1,2}
            // {3,3}, 6, {0,1}
            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                vector<int> nums = datas.at(i);
                int target = targets.at(i);
                vector<int> expected = expecteds.at(i);
                cout << "nums: " << convertToString(nums) << endl;
                cout << "target: " << target << endl;
                cout << "expected: " << convertToString(expected) << endl;
                
                vector<int> result = twoSum(nums, target);
                cout << "result: " << convertToString(result) << endl;

                if (result.size() == expected.size()) {
                    cout << "Indices: " << result[0] << ", " << result[1] << endl;
                    if((result.at(0) == expected.at(0)) && result.at(1) == expected.at(1)){
                        countPassed ++;
                        cout << "============> PASSED" << endl;
                    }else if((result.at(0) == expected.at(1)) && result.at(1) == expected.at(0)){
                        countPassed ++;
                        cout << "============> PASSED" << endl;
                    }else{
                        cout << "============> FAILED" << endl;
                    }
                } else {
                    cout << "============> FAILED" << endl;
                }
                cout << "=================== End - Test case #" << i << " ====================" << endl;
            }
            cout << "Passed: " << countPassed <<"/" << expecteds.size() << endl;
        }
};