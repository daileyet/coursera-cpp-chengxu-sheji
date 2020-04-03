//#include <iostream>
//using namespace std;
//class Sample{
//public:
//    int v;
//    Sample(int n):v(n) { }
    Sample(const Sample &other){
        this->v = 2 * other.v;
    }
//};
//int main() {
//    Sample a(5);
//    Sample b = a;
//    cout << b.v << endl;
//    return 0;
//}