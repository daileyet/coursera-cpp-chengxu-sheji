//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//class Complex {
//private:
//    double r,i;
//public:
//    void Print() {
//        cout << r << "+" << i << "i" << endl;
//    }
// 在此处补充你的代码
   Complex& operator=(const string& val){
       size_t plusIndex=val.find("+");
       size_t len = val.size();
       string s_r = val.substr(0,plusIndex);
       string s_i = val.substr(plusIndex+1,len-plusIndex-2);
       this->r = atof(s_r.c_str());
       this->i = atof(s_i.c_str());
       return *this;
   }
//};
//int main() {
//    Complex a;
//    a = "3+4i"; a.Print();
//    a = "5+6i"; a.Print();
//    return 0;
//}

