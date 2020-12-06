#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "util.h"
// I had C++ Streams API deployed in the folder next to this one.
#include "../../StreamsCpp/source/Stream.h"

using namespace std;

int convertSeatIdToNumber(const string &ticket) {
    int value = 0;
    // Traverse the string backwards.
    for (int i = ticket.size() - 1, j = 1; i >= 0; i--, j *= 2) {
        value += (ticket[i] == 'B' || ticket[i] == 'R') ? j : 0;
    }
    return value;
}

int findHighestSeatIdApproach1(const vector<string> &ticketsData) {
    return stream::Stream<string>(ticketsData) | stream::op::map_(convertSeatIdToNumber) | stream::op::max();
}

int findHighestSeatIdApproach2(const vector<string> &ticketsData) {
    int highestSeatId = -1;
    for (string seatIdStr: ticketsData) {
        replace(seatIdStr.begin(), seatIdStr.end(), 'F', '0');
        replace(seatIdStr.begin(), seatIdStr.end(), 'B', '1');
        replace(seatIdStr.begin(), seatIdStr.end(), 'L', '0');
        replace(seatIdStr.begin(), seatIdStr.end(), 'R', '1');
        int seatId = stoi(seatIdStr, nullptr, 2);
        if (seatId > highestSeatId) {
            highestSeatId = seatId;
        }
    }
    return highestSeatId;
}

int findMissingSeatId(const vector<string> &ticketsData) {
    auto existingSeatIds = stream::Stream<string>(ticketsData) | stream::op::map_(convertSeatIdToNumber) | stream::op::to_set();
    for (int value = 1; value < 1023; value++) {
        if (binary_search(existingSeatIds.begin(), existingSeatIds.end(), value - 1)
         && binary_search(existingSeatIds.begin(), existingSeatIds.end(), value + 1)
         && !binary_search(existingSeatIds.begin(), existingSeatIds.end(), value)) {
            return value;
        }
    }
    return -1;
}

void runDay5() {
    // https://adventofcode.com/2020/day/5
    vector<string> ticketsData;
    string curLine;
    ifstream puzzleInputFile(getInputFile(__FILE__));
    if (puzzleInputFile.is_open()) {
        while (getline(puzzleInputFile, curLine)) {
            ticketsData.push_back(curLine);
        }
        puzzleInputFile.close();
    }

    cout << "Day 5: findHighestSeatIdApproach1 = " << findHighestSeatIdApproach1(ticketsData);
    cout << ", findHighestSeatIdApproach2 = " << findHighestSeatIdApproach2(ticketsData);
    cout << ", findMissingSeatId = " << findMissingSeatId(ticketsData);
}