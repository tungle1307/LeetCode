// 8. String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

 

// Example 1:
// Input: s = "42"
// Output: 42
// Explanation:
//     The underlined characters are what is read in and the caret is the current reader position.
//     Step 1: "42" (no characters read because there is no leading whitespace)
//     Step 2: "42" (no characters read because there is neither a '-' nor '+')
//     Step 3: "42" ("42" is read in)

// Example 2:
// Input: s = " -042"
// Output: -42
// Explanation:
//     Step 1: "   -042" (leading whitespace is read and ignored)
//     Step 2: "   -042" ('-' is read, so the result should be negative)
//     Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)

// Example 3:
// Input: s = "1337c0d3"
// Output: 1337
// Explanation:
//     Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
//     Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
//     Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)

// Example 4:
// Input: s = "0-1"
// Output: 0
// Explanation:
//     Step 1: "0-1" (no characters read because there is no leading whitespace)^
//     Step 2: "0-1" (no characters read because there is neither a '-' nor '+')  ^
//     Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)

// Example 5:
// Input: s = "words and 987"
// Output: 0
// Explanation:
//     Reading stops at the first non-digit character 'w'.

 

// Constraints:
// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

// class Solution {
// public:
//     int myAtoi(string s) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <regex.h>
using namespace std;

class StringToInteger {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        StringToInteger(){};

        // Destructor (phương thức hủy)
        ~StringToInteger() {};

        // INT_MAX là giá trị lớn nhất của int (2147483647).
        // INT_MIN là giá trị nhỏ nhất của int (-2147483648).
        // int thường có phạm vi từ -2147483648 đến 2147483647 (tức là từ INT_MIN đến INT_MAX)
        // 1463847412 => 2147483641
        // Chi chap nhan "-123" or "  -123" or "123" or "+123" or "   +123" dau tien
        // neu result  > INT_MAX => Result = INT_MAX
        // neu result  < INT_MIN => Result = INT_MIN
        
        static int solution1(string s){
            int result = 0;
            int negative = 1;
            bool is_add_int = false;
            bool has_negative = false;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == L' '){
                    if(is_add_int == true || has_negative == true){
                        break;
                    }
                    continue;
                }
                if(s[i] == '-' || s[i] == '+'){
                    if(is_add_int == false && has_negative == false){
                        has_negative = true;
                        if(s[i] == '-')
                            negative = -1;
                        else
                            negative = 1;
                        continue;
                    }else{
                        break;
                    }
                }

                if(isdigit(s[i]) == false){
                    break;
                }else{                  
                    int pop = stoi(s.substr(i, 1))*negative;
                    if(result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)){
                        result = INT_MAX;
                        break;
                    }
                    if(result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)){
                        result = INT_MIN;
                        break;
                    }
                    result = result*10 + pop;
                    is_add_int = true;
                }
            }
            return result;
        }

        static int solution2(string s){
            if(s.size() <= 0) return 0;
            int result = 0;
            string text;
            int begin = 0;
            int count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != L' '){
                    begin = i;
                    break;
                }
            }
            if(begin >= s.size()){
                return 0;
            }
            int native = 1;
            if(isdigit(s[begin]) == false){
                if(s[begin] == L'-'){
                    native = -1;
                }else if(s[begin] == L'+'){
                    native = +1;
                }else{
                    return 0;
                }
                begin ++;
            }
            for(int i = begin; i < s.size(); i++){
                if(isdigit(s[i])){
                    int pop = stoi(s.substr(i, 1))*native;
                    if(result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)){
                        result = INT_MAX;
                        break;
                    }
                    if(result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)){
                        result = INT_MIN;
                        break;
                    }
                    result = result*10 + pop;
                }else{
                    break;
                }
            }
            return result;
        }

        static int solution3(string s){
            int result = 0;
            
            return result;
        }
        
        static int myAtoi(string s) {
            // return solution1(s); // 5 ms; Beats 24.96%
            return solution2(s); //  0 ms; Beats 100.00%
            // return solution3(s); 
        }

        static void testFunction() {
            int countPassed = 0;
            vector<string> datas = {"42", "   -042", "1337c0d3", "0-1", "words and 987", "-91283472332","+1", "+-12", "   +0 123", "  +  413"};
            vector<int> expecteds = {42, -42, 1337, 0, 0, INT_MIN, 1, 0, 0, 0};

            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                string s = datas.at(i);
                int expected = expecteds.at(i);
                cout << "s: " << s << endl;
                cout << "expected: " << expected << endl;
                
                int result = myAtoi(s);
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