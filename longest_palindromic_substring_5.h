
// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

// A string is palindromic if it reads the same forward and backward.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.
// Seen this question in a real interview before?


// class Solution {
// public:
//     string longestPalindrome(string s) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class LongestPalindromicSubstring {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        LongestPalindromicSubstring(){};

        // Destructor (phương thức hủy)
        ~LongestPalindromicSubstring() {};

        static bool isReveseString(string s, int left, int right){
            while (left < right)
            {
                if(s[left] != s[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
        // 
        static string solution1(string s){
            string result;
            string subString;
            for(int left = 0; left < s.size() - result.size(); left++){
                for(int right = left + result.size(); right < s.size(); right++){
                    if(s[left] != s[right]) continue;
                    if(isReveseString(s, left, right)){
                        subString = s.substr(left, right - left + 1);
                        result = result.size() >= subString.size() ? result : subString;
                    }
                }
            }
            return result;
        }
        static string expandCenter(string s, int cor_left, int cor_right){
            while(cor_left >= 0 && cor_right < s.size() && s[cor_left] == s[cor_right]){
                cor_left --;
                cor_right ++;
            }
            return s.substr(cor_left+1, cor_right - cor_left-1);
        }

        static string solution2(string s){
            string result;
            string subString;
            for(int i = 0; i < s.size(); i++){
                subString = expandCenter(s, i, i);
                if(subString.size() > result.size()){
                    result = subString;
                }
                subString = expandCenter(s, i, i+1);
                if(subString.size() > result.size()){
                    result = subString;
                }
            }
            return result;
        }

        static string solution3(string s){
            string result;

            return result;
        }
        
        static string longestPalindrome(string s){
            // return solution1(s);
            return solution2(s);
            // return solution3(s);
        }

        static void testFunction() {
            int countPassed = 0;
            vector<string> datas = {"babad", "cbbd","a","ccc"};
            vector<string> expecteds = {"bab", "bb","a","ccc"};

            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                string s = datas.at(i);
                string expected = expecteds.at(i);
                cout << "s: " << s << endl;
                cout << "expected: " << expected << endl;
                
                string result = longestPalindrome(s);
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