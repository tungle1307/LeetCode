// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21
 
// Constraints:
// -231 <= x <= 231 - 1

// class Solution {
// public:
//     int reverse(int x) {
        
//     }
// };


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class ReverseInteger {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        ReverseInteger(){};

        // Destructor (phương thức hủy)
        ~ReverseInteger() {};

        // INT_MAX là giá trị lớn nhất của int (2147483647).
        // INT_MIN là giá trị nhỏ nhất của int (-2147483648).
        // int thường có phạm vi từ -2147483648 đến 2147483647 (tức là từ INT_MIN đến INT_MAX)
        // 1463847412 => 2147483641
        static int solution1(int x){
            int result = 0;
            int abs_x = x;
            while(abs_x != 0){
                int pop = (abs_x%10);
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                    return 0;
                }
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                    return 0;
                }
                result = result*10 + pop;
                abs_x = abs_x/10;
            }
            return result;
        }

        static int solution2(int x){
            int result = 0;
            
            return result;
        }

        static int solution3(int x){
            int result = 0;
            
            return result;
        }
        
        static int reverse(int x) {
            
            return solution1(x); // 3 ms; Beats 24.66%
            // return solution2(x);
            // return solution3(x); 
        }

        static void testFunction() {
            int countPassed = 0;
            vector<int> datas = {123, -123, 120, 0, 1534236469, 1463847412};
            vector<int> expecteds = {321, -321, 21, 0, 0, 2147483641};

            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                int x = datas.at(i);
                int expected = expecteds.at(i);
                cout << "x: " << x << endl;
                cout << "expected: " << expected << endl;
                
                int result = reverse(x);
                cout << "result: " << result << endl;

                if (result == expected) {
                    countPassed ++;
                    cout << "============> PASSED" << endl;
                } else {
                    cout << "============> FAILED" << endl;
                }
                cout << "=================== End - Test case #" << i << " ====================" << endl;
            }
            cout << "Passed: " << countPassed <<"/" << expecteds.size() << endl;
        }
};