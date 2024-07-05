#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum {
    
public:
    // Constructor (phương thức khởi tạo)
    TwoSum(){}

    // TwoSum(std::string n, int a) : name(n), age(a) {};

    // Destructor (phương thức hủy)
    ~TwoSum() {}

    struct TESTCASE_STRUCTURE
    {
        vector<int> data;
        vector<int> result;
        int target;
        TESTCASE_STRUCTURE(vector<int> _data, int _target, vector<int> _result) : data(_data), result(_result), target(_target) {}
        TESTCASE_STRUCTURE(vector<int> _data, int _target) : data(_data), target(_target) {}
    };
    
    vector<TESTCASE_STRUCTURE> testCases;

    void init(){
        if(1){
            TESTCASE_STRUCTURE testCase ({2,7,11,15}, 9, {0,1});
            testCases.push_back(testCase);
        }
        if(1){
            TESTCASE_STRUCTURE testCase ({3,2,4}, 6, {1,2});
            testCases.push_back(testCase);
        }
        if(1){
            TESTCASE_STRUCTURE testCase ({3,3}, 6, {0,1});
            testCases.push_back(testCase);
        }
    }

    void add_test_case(vector<int> _data, int _target, vector<int> _result){
        TESTCASE_STRUCTURE testCase (_data, _target, _result);
        testCases.push_back(testCase);
    }
    void add_test_case(vector<int> _data, int _target){
        TESTCASE_STRUCTURE testCase (_data, _target);
        testCases.push_back(testCase);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        cout << "nums: [";
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size() -1){
                cout << nums.at(i);
            }else{
                cout << nums.at(i) << ", ";
            }
            
        }
        cout << "]" << endl;
        cout << "target: " << target << endl;

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
};