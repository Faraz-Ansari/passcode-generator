#include <iostream>
#include <vector>
#include <set>

using namespace std;

//this function takes a single value from "main function" and then checks if the value
//contains digits other than provided by user, then in such case it returns false
//else returns true
bool isPassCodeCorrect(int element, const vector<int> &passCodeElement) {
    set<int> s;
    set<int>::iterator itr;
    vector<int> passCode;
    //splitting the element into digits and storing it in set container
    // to remove duplicate digits
    while (element > 0) {
        s.insert(element % 10);
        element /= 10;
    }
    for (itr = s.begin(); itr != s.end(); itr++)
        passCode.push_back((*itr));

    for (auto val: passCode) {
        for (int value = 0; value < passCodeElement.size(); value++) {

            //if val is not present in passCodeElement and its the last value in the vector
            // meaning the digit is not provided by user so return false
            if (val != passCodeElement[value] && value + 1 == passCodeElement.size()) {
                return false;
            }

            // if val is present in passCodeElement meaning it is user provided digit, in that case break the loop
            if (val == passCodeElement[value]) {
                break;
            }
        }
    }
    // return true if it passes all condition
    return true;
}

int main() {

    int passCode;
    int passCodeLength;
    int limit = 1;
    set<int> setOfPassCode;
    set<int>::iterator itr; // iterator for the set because set doesn't allows the index based access like vector
    vector<int> passCodeCombination;
    vector<int> passCodeElements;

    cout << "Enter The Digits You Want In Your PassCode" << endl;
    cin >> passCode;
    cout << "In How Many Digits Combination You Want (6 Digit Max)" << endl;
    cin >> passCodeLength;

    // splitting the value in to digits and inserting it into set container to remove duplicates
    while (passCodeLength > 1) {
        // this variable allows us to raise the digit combination e.g. 4 passCodeLength = 1000 (limit)
        limit *= 10;
        passCodeLength--;
    }

    int temp = passCode;
    while (temp > 0) {
        setOfPassCode.insert(temp % 10);
        temp /= 10;
    }

    // getting the duplicate free digits from set and inserting them to vector using iterator
    for (itr = setOfPassCode.begin(); itr != setOfPassCode.end(); itr++) {
        passCodeElements.push_back(*itr);
    }


    // inserting the all possible combination of passcode by using a function
    //  that checks if it doesn't contains any other digit other than we got
    // got from user
    for (auto val: passCodeElements) {
        for (int i = val * limit; i < (val + 1) * limit; i++) {
            if (isPassCodeCorrect(i, passCodeElements))
                passCodeCombination.push_back(i);
        }
    }

    // printing all possible valid combination of passcodes that
    // can be made using only value provided by user
    for (auto val: passCodeCombination)
        cout << val << endl;

    cout << "Total Combination Of PassCode = " << passCodeCombination.size();
    return 0;
}