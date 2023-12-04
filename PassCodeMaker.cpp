#include <iostream>
#include <vector>
#include <set>

using namespace std;

//this function takes a single value and reference of vector as input and then checks if the value
//contains digits other than provided by user, then in such a case it returns false else returns true
bool isPasscodeCorrect(int element, const vector<int> &passcodeElement) {
    set<int> s;
    set<int>::iterator itr;

    vector<int> passcode;

    //splitting the element into digits and storing it in set container to remove duplicate digits
    while (element > 0) {
        s.insert(element % 10);
        element /= 10;
    }

    for (itr = s.begin(); itr != s.end(); itr++) {
        passcode.push_back((*itr));
    }

    for (auto val: passcode) {
        for (int value = 0; value < passcodeElement.size(); value++) {

            //if val is not present in passcodeElement, and it's the last value in the vector
            // meaning user does not provide the digit so return false
            if (val != passcodeElement[value] && value + 1 == passcodeElement.size()) {
                return false;
            }

            // if val is present in passcodeElement meaning it is user provided digit, in that case break the loop
            if (val == passcodeElement[value]) break;
        }

    }
    
    // return true if it passes all conditions
    return true;
}

int main() {

    int passcode;
    int passcodeLength;
    int limit = 1;

    set<int> setOfPasscode;
    // iterator for the set because a set doesn't allow the index-based access like vector
    set<int>::iterator itr;

    vector<int> passcodeCombination;
    vector<int> passcodeElements;

    cout << "Enter The Digits You Want In Your passcode" << endl;
    cin >> passcode;

    cout << "In How Many Digits Combination You Want (6 Digit Max)" << endl;
    cin >> passcodeLength;

    // splitting the value in to digits and inserting it into set container to remove duplicates
    while (passcodeLength > 1) {

        // this variable allows us to raise the digit combination e.g. 4 passcodeLength = 1000 (limit)
        limit *= 10;
        passcodeLength--;
    }

    int temp = passcode;

    while (temp > 0) {
        setOfPasscode.insert(temp % 10);
        temp /= 10;
    }

    // getting the duplicate free digits from a set and inserting them to vector using iterator
    for (itr = setOfPasscode.begin(); itr != setOfPasscode.end(); itr++) {
        passcodeElements.push_back(*itr);
    }


    // inserting the all possible combination of passcode by using a function
    // that checks if it doesn't contain any other digit other than we got from user
    for (auto val: passcodeElements) {
        for (int i = val * limit; i < (val + 1) * limit; i++) {
            if (isPasscodeCorrect(i, passcodeElements))
                passcodeCombination.push_back(i);
        }
    }

    // printing all possible valid combinations of passcodes that can be made using only value provided by user
    for (auto val: passcodeCombination) {
        cout << val << endl;
    }

    cout << "Total Combination Of passcode = " << passcodeCombination.size();

    return 0;
}