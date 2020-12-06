#ifndef ADVENTOFCODE_UTIL_H
#define ADVENTOFCODE_UTIL_H

#include <string>

std::string getInputFile(const std::string& cppFileFullPath) {
    int fileNamePos = cppFileFullPath.find_last_of('\\');
    std::string folderPath = cppFileFullPath.substr(0, fileNamePos);
    std::string fileName = cppFileFullPath.substr(fileNamePos);
    fileName = fileName.replace(fileName.find("cpp"), sizeof("cpp") - 1, "txt");
    return folderPath + "\\inputs\\" + fileName;
}

#endif //ADVENTOFCODE_UTIL_H
