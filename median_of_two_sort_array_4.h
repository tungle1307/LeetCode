// 4. median of two sort array
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

 
// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106
// Seen this question in a real interview before?

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class MediumOfTwoSortArray {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        MediumOfTwoSortArray(){};

        // Destructor (phương thức hủy)
        ~MediumOfTwoSortArray() {};
        static double solutiom1(vector<int>& nums1, vector<int>& nums2) {
            int size_num1 = nums1.size();
            int size_num2 = nums2.size();
            int mid = (size_num1 + size_num2)/2;
            int v_mid = 0;
            int v_mid_1 = 0;
            int i = 0;
            int j = 0; 
            while (i < size_num1 && j  < size_num2 && i+j <= mid){
                v_mid_1 = v_mid;
                v_mid = nums1[i] <= nums2[j] ? nums1[i] : nums2[j];
                nums1[i] <= nums2[j] ? i++ : j++;
            }
            while (i < size_num1 && i+j <= mid){
                v_mid_1 = v_mid;
                v_mid = nums1[i];
                i++;
            }
            while (j < size_num2 && i+j <= mid){
                v_mid_1 = v_mid;
                v_mid = nums2[j];
                j++;
            }
            double output = (size_num1 + size_num2)%2 == 0 ? (v_mid_1 + v_mid)/2.0 : v_mid;
            return output;
        }
        
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            return solutiom1(nums1, nums2);
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
            vector<vector<int>> datas1 = {{1,3}, {1,2}};
            vector<vector<int>> datas2 = {{2}, {3,4}};
            vector<double> expecteds = {2.0, 2.5};

            for(int i = 0; i < datas1.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                vector<int> data1 = datas1.at(i);
                vector<int> data2 = datas2.at(i);
                double expected = expecteds.at(i);
                cout << "data1: " << convertToString(data1) << endl;
                cout << "data2: " << convertToString(data2) << endl;
                cout << "expected: " << expected<< endl;
                
                double result = findMedianSortedArrays(data1, data2);
                cout << "result: " << result << endl;

                if (result == expected) {
                    cout << "============> PASSED" << endl;
                    countPassed ++;
                } else {
                    cout << "============> FAILED" << endl;
                }
                cout << "=================== End - Test case #" << i << " ====================" << endl;
            }
            cout << "Passed: " << countPassed <<"/" << expecteds.size() << endl;
        }
};