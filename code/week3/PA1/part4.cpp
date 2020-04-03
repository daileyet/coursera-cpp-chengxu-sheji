#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class HeadUnit;
class Warrior {
private:
    int no, power, attack;
    HeadUnit *head;
    string type;
public:
    Warrior(HeadUnit *h, string t, int n, int p, int a = 0) :
            no(n), power(p), attack(a), head(h), type(t) {
        cout << " " << type << " " << n << " born with strength " << power;
    }
};
//find minimum value in int array
int minInArray(int data[], int len);
//maximum warriros count for each head unit could create
const int MAX = 100;
class HeadUnit {
private:
    int timePoint, totalPower;
    string type, warriorSeqs[5];
    int wpowers[5];
    int wcounts[5];
    Warrior *warriors[MAX];
    bool isStop;
public:
    /***
     * PARAMS:
     * t: type, red/blue
     * seqs: warrior type array
     * wps: warrior power array
     * power: head unit total power
     */
    HeadUnit(string t, string seqs[], int wps[], int power) :
            timePoint(0), totalPower(power), type(t),isStop(false) {
        for(int i=0;i<MAX;i++){
            warriors[i]=NULL;
        }
        for (int i = 0; i < 5; i++) {
            wpowers[i] = wps[i];
            warriorSeqs[i] = seqs[i];
            wcounts[i] = 0;
        }
    }
    ~HeadUnit() {
        for (int i = 0; i < MAX; i++) {
            if (warriors[i]) {
                delete warriors[i];
            }
        }
    }
    bool isFinished() { // head unit is stop to create warrior
        return isStop;
    }
    Warrior* create() { // create Warrior object
        if (totalPower <=0 || totalPower < minInArray(wpowers, 5)){
            if(isStop==false)
                stop();
            return NULL;
        }
        int wIndex = (timePoint % 5);
        int wPower = wpowers[wIndex];
        while (wPower > totalPower) {
            wIndex = (wIndex + 1) % 5;
            wPower = wpowers[wIndex];
        }
        printf("%03d", timePoint);
        cout << " " << type;
        Warrior *obj = new Warrior(this, warriorSeqs[wIndex], (timePoint + 1),
                                   wPower);
        warriors[timePoint] = obj;
        totalPower -= wPower;
        wcounts[wIndex]++;
        cout << "," << wcounts[wIndex] << " " + warriorSeqs[wIndex] + " in "
             << type << " headquarter" << endl;
        timePoint++;
        return obj;
    }

    void stop() {
        isStop=true;
        printf("%03d", timePoint);
        cout << " " << type << " headquarter stops making warriors" << endl;
    }
};

int minInArray(int data[], int len) {
    int min = data[0];
    for (int i = 0; i < len; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

int main() {
    int caseNo, totalPower, i_dragon, i_ninja, i_iceman, i_lion, i_wolf;
    cin >> caseNo;
    cin >> totalPower;
    cin >> i_dragon >> i_ninja >> i_iceman >> i_lion >> i_wolf;
    //TODO check input
    string redSeqs[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
    int reqWPowers[5] = { i_iceman, i_lion, i_wolf, i_ninja, i_dragon };
    string blueSeqs[5] = { "lion", "dragon", "ninja", "iceman", "wolf" };
    int blueWPowers[5] = { i_lion, i_dragon, i_ninja, i_iceman, i_wolf };
    HeadUnit red("red", redSeqs, reqWPowers, totalPower);
    HeadUnit blue("blue", blueSeqs, blueWPowers, totalPower);

    cout << "Case:" << caseNo << endl;
    while (!red.isFinished() || !blue.isFinished()) {
        red.create();
        blue.create();
    }
}