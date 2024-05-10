#pragma once
#include <iostream>
#include <fstream>

const char TABULATOR[] = {' ',' '};
const char NEWLINE[] = {10,10};

std::string getFileNameFromParameter(int argc, char* argv[]);
std::ifstream openSourceFile(std::string& fileName);
std::string setOutputFileName(std::string& fileName);
std::ofstream openOutputFile(std::string& fileName);
void copyFile(std::ifstream& fi, std::ofstream& fo);
void closeFiles(std::ifstream& fi, std::ofstream& fo);

void processOneLine(std::ofstream& fo, std::string oneLine);