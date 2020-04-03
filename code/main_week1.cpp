#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
    string name, xuehao;
    int age;
    int scores[4]; //each year average score
public:
    void init(const string &input); // initialize member variable
    void print(); //print info
};

void Student::init(const string &input) {
    const string token = ",";
    string::size_type pos1, pos2;
    pos2 = input.find(token);
    pos1 = 0;
    int i = 0;
    string strArray[7];
    while (string::npos != pos2) //process input string
    {
        if (i >= 7)
            break;
        strArray[i] = input.substr(pos1, pos2 - pos1);
        pos1 = pos2 + token.size();
        pos2 = input.find(token, pos1);
        i++;
    }
    if (i == 6) {
        strArray[i] = input.substr(pos1, pos2 - pos1);
    }
    // set value for member variables
    name = strArray[0];
    stringstream ss;
    ss << strArray[1];
    ss >> age;
    i = 0;
    xuehao = strArray[2];
    for (; i < 4; i++) {
        stringstream ss1;
        ss1 << strArray[i + 3];
        ss1 >> scores[i];
    }
}

void Student::print() {
    int avarge = (scores[0] + scores[1] + scores[2] + scores[3]) / 4;
    cout << name << "," << age << "," << xuehao << "," << avarge << endl;
}
int main() {
    string input;
    cin >> input;
    Student stu;
    stu.init(input);
    stu.print();
    return 0;
}

