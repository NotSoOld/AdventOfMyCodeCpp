//
// Created by dsomov on 28.11.2020.
//
#include <iostream>
#include <unordered_map>
#include "../../StreamsCpp/source/Stream.h"

using namespace std;

int countPasswords(int lower, int upper) {
    return stream::MakeStream::closed_range(lower, upper)
        | stream::op::filter([](int password) {
            string passwordStr = to_string(password);
            bool hasDouble = false;
            char lastDigit = '\0';
            for (auto digit: passwordStr) {
                if (digit == lastDigit) {
                    hasDouble = true;
                }
                if (digit < lastDigit) {
                    return false;
                }
                lastDigit = digit;
            }
            return hasDouble;
        })
        | stream::op::count();
}

int countPasswordsPart2(int lower, int upper) {
    return stream::MakeStream::closed_range(lower, upper)
        | stream::op::filter([](int password) {
            string passwordStr = to_string(password);
            auto adjacentDigits = unordered_map<int, int>();
            char lastDigit = '\0';
            for (auto digit: passwordStr) {
                adjacentDigits[digit]++;
                if (digit < lastDigit) {
                    return false;
                }
                lastDigit = digit;
            }
            for (auto keyValue: adjacentDigits) {
                if (keyValue.second == 2) {
                    return true;
                }
            }
            return false;
        })
        | stream::op::count();
}

void runDay4() {
    int lower = 146810;
    int upper = 612564;

    int count = countPasswords(lower, upper);
    cout << "Day 4: countPasswords = " << count;
    count = countPasswordsPart2(lower, upper);
    cout << ", countPasswordsPart2 = " << count;
}