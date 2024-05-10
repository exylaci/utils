#include "main.h"
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char* argv[]) {
	auto sourceFileName = getFileNameFromParameter(argc, argv);
	auto fi = openSourceFile(sourceFileName);
	auto outputFileName = setOutputFileName(sourceFileName);
	auto fo = openOutputFile(outputFileName);
	copyFile(fi, fo);
	closeFiles(fi, fo);
	std::cout << "File rewrapped successfully." << std::endl;
}

// Returns the first parameter from the command line parameters list as the name 
// of the source file. Exits if there was't any parameter given in the command line.
std::string getFileNameFromParameter(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Input file parameter is missing!   Exiting..." << std::endl;
		exit(1);
	}
	return argv[1];
}

//Open source file for reading. Returns with its filehandler.
std::ifstream openSourceFile(std::string& fileName) {
	std::ifstream fi{ fileName };
	if (!fi.is_open()) {
		std::cout << "I cannot open for reading the " << fileName << " source file.   Exiting..." << std::endl << std::endl;
		exit(2);
	}
	std::cout << "Opened " << fileName << " file for reading." << std::endl;
	return fi;
}

//Prepares the name of the output file based on the name of the input file
std::string setOutputFileName(std::string& fileName) {
	std::string outputFileName{ fileName };
	outputFileName.replace(outputFileName.find(".xml"), 4, "_out.xml");
	return outputFileName;
}

//Open output file for writing. Returns with its filehandler.
std::ofstream openOutputFile(std::string& fileName) {
	std::ofstream fo{ fileName };
	if (!fo.is_open()) {
		std::cout << "I cannot open for writing the " << fileName << " output file.   Exiting..." << std::endl << std::endl;
		exit(3);
	}
	std::cout << "Opened " << fileName << " file for writing." << std::endl;
	return fo;
}

//Close all files.
void closeFiles(std::ifstream& fi, std::ofstream& fo) {
	fi.close();
	fo.close();
}

//Copy the contens of source file into output file.
void copyFile(std::ifstream& fi, std::ofstream& fo) {
	std::string oneLine;
	do {
		std::getline(fi, oneLine);
		std::cout << oneLine << std::endl;
	} while (!fi.eof());
}