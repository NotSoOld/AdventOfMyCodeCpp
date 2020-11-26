#include <iostream>
#include <vector>
// I had C++ Streams API deployed in the folder next to this one.
#include "../../StreamsCpp/source/Stream.h"
#include "day2.cpp"

using namespace std;

int sumOfFuel1(const vector<string>& masses) {
    int resultSum = 0;
    for (const auto& massString: masses) {
        resultSum += stoi(massString) / 3 - 2;
    }
    return resultSum;
}

// Uses open-source C++ Streams API: https://github.com/jscheiny/Streams
int sumOfFuel1withStreams(const vector<string>& masses) {
    return stream::Stream<string>(masses)
           | stream::op::map_([](const string& mass) { return stoi(mass) / 3 - 2; })
           | stream::op::sum();
}

int sumOfFuel2(const vector<string>& masses) {
    int resultFuelSum = 0;
    for (const auto& massString: masses) {
        int intermediateFuelSum = stoi(massString) / 3 - 2;
        int additionalFuel = intermediateFuelSum / 3 - 2;
        while (additionalFuel > 0) {
            intermediateFuelSum += additionalFuel;
            additionalFuel = additionalFuel / 3 - 2;
        }
        resultFuelSum += intermediateFuelSum;
    }
    return resultFuelSum;
}

int main() {
    const vector<string> masses = {
        "126360", "61158", "149929", "88405", "87526", "51688", "75356", "116265", "134986", "111581",
        "135675", "69679", "74035", "144951", "86157", "68946", "76761", "114768", "70694", "84768", "147379", "78755",
        "109688", "118595", "54608", "77033", "54654", "61473", "69644", "81744", "97148", "106473", "61541", "98898",
        "70394", "117635", "128388", "140622", "108691", "126962", "137756", "125904", "75675", "127051", "126388",
        "85591", "51583", "101392", "62959", "135077", "90916", "127119", "112427", "79703", "54739", "50092", "92505",
        "53719", "60887", "62642", "76382", "85763", "125799", "67285", "147992", "80713", "133619", "131433", "141765",
        "109553", "122534", "88734", "115622", "82195", "130771", "121649", "89355", "121364", "71664", "130412", "88936",
        "63234", "80274", "108251", "136663", "139149", "85052", "67973", "116461", "75070", "144261", "106539", "79712",
        "116112", "55755", "121428", "79362", "103489", "103157", "64403"
    };
    cout << sumOfFuel1(masses) << endl; // 3254441
    cout << sumOfFuel2(masses) << endl; // 4878818
    cout << sumOfFuel1withStreams(masses) << endl; // 3254441

    day2start();

    return 0;
}