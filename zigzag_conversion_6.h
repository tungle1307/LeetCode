// 6. ZigzagConversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

// class Solution {
// public:
//     string convert(string s, int numRows) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class ZigzagConversion {
    private:
 
    public:
        // Constructor (phương thức khởi tạo)
        ZigzagConversion(){};

        // Destructor (phương thức hủy)
        ~ZigzagConversion() {};

        static string solution1(string s, int numRows){
            if(numRows == 1 || s.size() <= 1){
                return s;
            }
            string result;
            vector<int> cor;
            int row = 0;
            bool revert = false;
            for(int i = 0; i < s.size(); i++){
                // cout << "row: " << row << "; "<< s[i] <<" - " << revert <<endl;
                cor.push_back(row);
                
                if(revert == false){
                    row ++;
                }else{
                    row --;
                }
                if(row + 1 == numRows){
                    revert = true;
                }
                if(row == 0){
                    revert = false;
                }
            } 
            
            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < cor.size(); j++){
                    if(cor[j] == i){
                        result += s[j];
                    }
                }
            }      
            return result;
        }

        static string solution2(string s, int numRows){
            if(numRows == 1 || s.size() <= 1){
                return s;
            }
            string result;
            unordered_map<int, string> map;
            int row = 0;
            bool revert = false;
            for(int i = 0; i < s.size(); i++){
                map[row].push_back(s[i]);
                if(revert == false){
                    row ++;
                }else{
                    row --;
                }
                if(row + 1 == numRows){
                    revert = true;
                }
                if(row == 0){
                    revert = false;
                }
            } 
            
            for(int i = 0; i < map.size(); i++){
                result += map[i];
            }      
            return result;
        }

        static string solution3(string s, int numRows){
            if(numRows == 1 || s.size() <= 1){
                return s;
            }
            string result;
            unordered_map<int, string> map;
            int row = 0;
            bool revert = false;
            for(int i = 0; i < s.size(); i++){
                map[row].push_back(s[i]);
                row = revert ? row - 1 : row + 1;
                revert = (row + 1 == numRows) ? true : revert;
                revert = (row == 0) ? false : revert;
            } 
            
            for(int i = 0; i < map.size(); i++){
                result += map[i];
            }      
            return result;
        }
        
        static string convert(string s, int numRows) {
            
            // return solution1(s, numRows); // 74 ms; Beats 5.11%
            // return solution2(s, numRows); // 36 ms; Beats 19.48%
            return solution3(s, numRows);  // 36 ms; Beats 19.48%
        }

        static void testFunction() {
            int countPassed = 0;
            vector<string> datas = {"PAYPALISHIRING","PAYPALISHIRING", "PAYPALISHIRING", "PAYPALISHIRING", "A"};
            vector<int> rows = {1, 2, 3, 4, 1};
            vector<string> expecteds = {"PAYPALISHIRING", "PYAIHRNAPLSIIG", "PAHNAPLSIIGYIR", "PINALSIGYAHRPI", "A"};

            for(int i = 0; i < datas.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                string s = datas.at(i);
                int row = rows.at(i);
                string expected = expecteds.at(i);
                cout << "s: " << s << endl;
                cout << "row: " << row << endl;
                cout << "expected: " << expected << endl;
                
                string result = convert(s, row);
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