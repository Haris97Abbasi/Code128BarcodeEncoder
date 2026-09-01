#include "Encoder.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
	if (argc != 3 || std::string(argv[1]) != "--encode") {
		std::cerr << "Invalid input command";
		return 1;
	}

	try {
		barcode::Encoder encoder;
		std::vector<int> encodedMessage;
		encodedMessage = encoder.encode(argv[2]);
		for (int i = 0; i < encodedMessage.size(); i++) {
			std::cout << encodedMessage[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& ex){
		std::cerr <<"An Error has occured: " << ex.what() << std::endl;
	}

	return 0;
}