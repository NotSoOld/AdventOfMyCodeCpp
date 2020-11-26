#include <iostream>
#include <vector>

using namespace std;

int computer(vector<int> memory) {
    for (int i = 0; i < memory.size(); i += 4) {
        int opcode = memory[i];
        if (opcode == 99) {
            return memory[0];
        }
        int leftOperand = memory[memory[i + 1]];
        int rightOperand = memory[memory[i + 2]];
        int resultIndex = memory[i + 3];
        switch (opcode) {
            case 1:
                memory[resultIndex] = leftOperand + rightOperand;
                break;
            case 2:
                memory[resultIndex] = leftOperand * rightOperand;
                break;
            default:
                return -2;
        }
    }
    return -1;
}

int computeFirstPart(vector<int> input) {
    // Restore the "1202 program alarm" state.
    input[1] = 12;
    input[2] = 2;
    return computer(input);
}

int findStateBruteForce(vector<int> program) {
    int trueState = 19690720;
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            program[1] = i;
            program[2] = j;
            if (computer(program) == trueState) {
                return 100 * i + j;
            }
        }
    }
    return -1;
}

void day2start() {
    const vector<int> input = {
       /* 000 */ 1, 0, 0, 3,
       /* 004 */ 1, 1, 2, 3,
       /* 008 */ 1, 3, 4, 3,
       /* 012 */ 1, 5, 0, 3,
       /* 016 */ 2, 13, 1, 19,
       /* 020 */ 1, 19, 10, 23,
       /* 024 */ 1, 23, 6, 27,
       /* 028 */ 1, 6, 27, 31,
       /* 032 */ 1, 13, 31, 35,
       /* 036 */ 1, 13, 35, 39,
       /* 040 */ 1, 39, 13, 43,
       /* 044 */ 2, 43, 9, 47,
       /* 048 */ 2, 6, 47, 51,
       /* 052 */ 1, 51, 9, 55,
       /* 056 */ 1, 55, 9, 59,
       /* 060 */ 1, 59, 6, 63,
       /* 064 */ 1, 9, 63, 67,
       /* 068 */ 2, 67, 10, 71,
       /* 072 */ 2, 71, 13, 75,
       /* 076 */ 1, 10, 75, 79,
       /* 080 */ 2, 10, 79, 83,
       /* 084 */ 1, 83, 6, 87,
       /* 088 */ 2, 87, 10, 91,
       /* 092 */ 1, 91, 6, 95,
       /* 096 */ 1, 95, 13, 99,
       /* 100 */ 1, 99, 13, 103,
       /* 104 */ 2, 103, 9, 107,
       /* 108 */ 2, 107, 10, 111,
       /* 112 */ 1, 5, 111, 115,
       /* 116 */ 2, 115, 9, 119,
       /* 120 */ 1, 5, 119, 123,
       /* 124 */ 1, 123, 9, 127,
       /* 128 */ 1, 127, 2, 131,
       /* 132 */ 1, 5, 131, 0,
       /* 136 */ 99,
       /* 140 */ 2, 0, 14, 0
    };
    cout << computeFirstPart(input) << endl;    // 5866714
    cout << findStateBruteForce(input) << endl; // 5208
    // The internet says part 2 could be solved with the help of SAT/SMT.
    // I don't have ay knowledge in these topics, unfortunately (though I had a thought
    // that this program can be reverse-engineered and simplified to an equation).
}