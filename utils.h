#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> v) {
    cout << "[ " ;
    for(int i = 0; i < v.size(); i++){
        if(i+1 == v.size()){
            cout << v.at(i) ;
        }else{
            cout << v.at(i) << ", " ;
        }
    }
    cout << " ]";
}

string convertToString(vector<int> v) {
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
void printStatus(bool isPassed){
    if(isPassed)
        cout << "============> PASSED" << endl;
    else
        cout << "============> FAILED" << endl;
}

