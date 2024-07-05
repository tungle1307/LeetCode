#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class AddTwoNumber {

    private:

    public:
        // Constructor
        AddTwoNumber(){}
        // Destructor
        ~AddTwoNumber() {}


        //   Definition for singly-linked list.
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };
         
        static ListNode* solution1(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode(0);
            ListNode* current = result;
            int add = 0;
            
            while (l1 != nullptr || l2 != nullptr || add != 0) {                
                if(l1 != nullptr){
                    current->val += l1->val;
                    l1 = l1->next;
                }
                    
                if(l2 != nullptr){
                    current->val += l2->val;
                    l2 = l2->next;
                }
                
                if(current->val > 9){
                    current->val = current->val -10;
                    add = 1;
                }
                if (l1 != nullptr || l2 != nullptr || add != 0){
                    current->next = new ListNode(add);
                    add = 0;
                    current = current->next;
                }
            }
            return result;
        }
        static ListNode* solution2(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode(0);
            ListNode* current = result;
            int add = 0;
            
            while (l1 != nullptr || l2 != nullptr || add != 0) {
                int sum = add;
                add = 0;
                if(l1 != nullptr){
                    sum += l1->val;
                    l1 = l1->next;
                }
                    
                if(l2 != nullptr){
                    sum += l2->val;
                    l2 = l2->next;
                }
                
                if(sum > 9){
                    sum = sum -10;
                    add = 1;
                }
                current->next = new ListNode(sum);
                current = current->next;
            }
            return result->next;
        }

        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            // return solution1(l1, l2);
            return solution2(l1, l2);
        }

        // ------------------------------------ Test funtion --------------------------
        // Constraints:
        //     The number of nodes in each linked list is in the range [1, 100].
        //     0 <= Node.val <= 9
        //     It is guaranteed that the list represents a number that does not have leading zeros.
        // Test case #1
        //      Input: l1 = [2,4,3], l2 = [5,6,4]
        //      Output: [7,0,8]
        //      Explanation: 342 + 465 = 807.
        // Test case #2
        //      Input: l1 = [0], l2 = [0]
        //      Output: [0]
        // Test case #3
        //      Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
        //      Output: [8,9,9,9,0,0,0,1]
        static ListNode* convertVectorToListNode(vector<int> vt){
            if (vt.empty()) {
                return nullptr;
            }
            // Tạo nút đầu tiên của danh sách liên kết
            ListNode* ln = new ListNode(vt[0]);
            ListNode* current = ln;

            // Lặp qua các phần tử còn lại của vector và tạo các nút liên kết
            for (size_t i = 1; i < vt.size(); ++i) {
                current->next = new ListNode(vt[i]);
                current = current->next;
            }
            return ln;
        }
        static vector<int> convertListNodeToVector(ListNode* ln){
            vector<int> vt;
            ListNode* current = ln;
            while (current != nullptr) {
                vt.push_back(current->val);
                current = current->next;
            }
            return vt;
        }
        

        static void testFunction() {
            int countPassed = 0;
            vector<vector<int>> L1 = {{2,4,3}, {0}, {9,9,9,9,9,9,9}};
            vector<vector<int>> L2 = {{5,6,4}, {0}, {9,9,9,9}};
            vector<vector<int>> expecteds = {{7,0,8}, {0}, {8,9,9,9,0,0,0,1}};

            for(int i = 0; i < L1.size(); i++){
                cout << "=================== Begin - Test case #" << i << " ====================" << endl;
                vector<int> l1 = L1.at(i);
                vector<int> l2 = L2.at(i);
                vector<int> expected = expecteds.at(i);

                cout << "l1: " << convertToString(l1) << endl;
                cout << "l2: " << convertToString(l2) << endl;
                cout << "expected: " << convertToString(expected) << endl;

                ListNode* ln1 = convertVectorToListNode(l1);
                ListNode* ln2 = convertVectorToListNode(l2);
                
                ListNode* ln_r = addTwoNumbers(ln1, ln2);
                vector<int> lnv = convertListNodeToVector(ln_r);

                // print output result
                cout << "retuls: " << convertToString(lnv) << endl;

                // Compare output result
                if (lnv.size() == expected.size() && lnv.size() > 0) {
                    bool isPassed = true;
                    for(int ri = 0; ri < expected.size(); ri++){
                        if(lnv.at(ri) != expected.at(ri)){
                            isPassed = false;
                        }
                    }
                    if(isPassed){
                        countPassed ++;
                        printStatus(true);
                    }else{
                        printStatus(false);
                    }
                    
                } else {
                    printStatus(false);
                }
                cout << "=================== End - Test case #" << i << " ====================" << endl;
            }
            cout << "Passed: " << countPassed <<"/" << expecteds.size() << endl;
        }
};