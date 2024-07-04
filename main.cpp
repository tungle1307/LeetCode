// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

//     for (const string& word : msg)
//     {
//         cout << word << " ";
//     }
//     cout << endl;
//     return 0;
// }

#include <iostream>
#include "two_sum_1.h"

using namespace std;

void twoSum() {

    TwoSum twoSum;
    twoSum.init();

    for(int i = 0; i < twoSum.testCases.size(); i++){
        cout << "=================== Begin - Test case #" << i << " ====================" << endl;
        vector<int> nums = twoSum.testCases.at(i).data;
        int target = twoSum.testCases.at(i).target;
        
        vector<int> result = twoSum.twoSum(nums, target);
        if (!result.empty()) {
            cout << "Indices: " << result[0] << ", " << result[1] << endl;
        } else {
            cout << "No two sum solution" << endl;
        }
        cout << "=================== End - Test case #" << i << " ====================" << endl;
    }
    
}

int main() {
    
    twoSum();
    return 0;
}