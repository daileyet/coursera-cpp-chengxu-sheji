#include <iostream>
using namespace std;
class Sample {
public:
    int v;
    Sample(int n) :v(n) {}
    Sample(Sample& s) {
        v = 2 * s.v;
    }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v << endl;
    return 0;
}