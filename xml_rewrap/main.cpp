#include "main.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	auto fileName = getFileNameFromParameter(argc, argv);
	auto fi = openSourceFile(fileName);

	closeFiles(fi);
	std::cout << "File rewrapped successfully.";
}

//Exit if there was't any command line parameter given in the command line.
std::string getFileNameFromParameter(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Input file parameter is missing!" << std::endl << " Exiting..." << std::endl;
		exit(-1);
	}
	return argv[1];
}

//open source file for reading
std::ifstream openSourceFile(std::string& fileName) {
	std::ifstream fi{ fileName };
	if (!fi.is_open()) {
		std::cout << "I cannot open the " << fileName << " source file.  Exiting..." << std::endl << std::endl;
		exit(-1);
	}
	std::cout << "Open " << fileName << " file for reading." << std::endl;
	return fi;
}

//close all files
void closeFiles(std::ifstream& fi) {
	fi.close();
}