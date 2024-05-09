#pragma once
#include <iostream>
#include <fstream>

std::string getFileNameFromParameter(int argc, char* argv[]);
std::ifstream openSourceFile(std::string& fileName);
void closeFiles(std::ifstream& fi);
