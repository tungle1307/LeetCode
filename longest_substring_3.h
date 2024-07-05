
// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class LongestSubstring {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        LongestSubstring(){};

        // Destructor (phương thức hủy)
        ~LongestSubstring() {};
        static int solution1(string s){
            int result = 1;
            string stringTemp;
            for(int i = 0; i < s.size() - result; i++){
                stringTemp += s[i];
                for(int j = i+1; j < s.size(); j++){
                    if(stringTemp.find(s[j]) == std::string::npos){
                        stringTemp += s[j];
                    }else{
                        if(stringTemp.size() > result){
                            result = stringTemp.size();
                            cout << "stringTemp: " <<stringTemp << endl;
                        }
                        stringTemp.clear();
                        break;
                    }
                }
            }
            return result;
        }

        static int solution2(string s){
            int result = 0;
            unordered_map<char, int> myMap;
            int erase = 0;
            for(int i = 0; i < s.size(); i++){
                if(myMap.count(s[i]) == 0){
                    result = max(result, i - erase + 1);
                }else{
                    erase = i;
                    myMap.clear();
                }
                myMap[s[i]] = i;
            }
            return result;
        }

        static int solution3(string s){
            int result = 0;
            unordered_map<char, int> myMap;
            int erase = 0;
            for(int i = 0; i < s.size(); i++){
                if(myMap.count(s[i]) != 0){
                    erase = max(myMap[s[i]]+1, erase);
                }
                result = max(result, (i - erase) + 1);
                myMap[s[i]] = i;
            }
            return result;
        }
        
        static int lengthOfLongestSubstring(string s) {
            
            // return solution1(s);
            // return solution2(s);
            return solution3(s);
        }
        static void testFunction() {
            int countPassed = 0;
            vector<string> datas = {"abcabcbb", "bbbbb", "pwwkew", "dvdf", "tmmzuxt"};
            vector<int> expecteds = {3,1,3, 3, 5};

            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                string s = datas.at(i);
                int expected = expecteds.at(i);
                cout << "s: " << s << endl;
                cout << "expected: " << expected << endl;
                
                int result = lengthOfLongestSubstring(s);
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