#include "main.h"

std::string getInputFile(const std::string& cppFileFullPath) {
    int fileNamePos = cppFileFullPath.find_last_of('\\');
    std::string folderPath = cppFileFullPath.substr(0, fileNamePos);
    std::string fileName = cppFileFullPath.substr(fileNamePos);
    fileName = fileName.replace(fileName.find("cpp"), sizeof("cpp") - 1, "txt");
    return folderPath + "\\inputs\\" + fileName;
}

int main() {
    runDay1();
    runDay2();
    runDay3();
    runDay4();
    return 0;
}

