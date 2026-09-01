#include "Encoder.h"
#include "Constants.h"

#include <stdexcept>

namespace barcode {
	
	int Encoder::encodeCharacter(char ch) {
		int asciiCode = static_cast<unsigned>(ch);
		if (asciiCode < ASCII_MIN || asciiCode > ASCII_MAX) {
			throw std::invalid_argument("The input message contains character/s outside the range of Code-128 Subset B.");
		}
		
		return asciiCode - ASCII_DIFFERENCE;
	}

	void Encoder::validate(const std::string& message) {
		if (message.empty()) {
			throw std::invalid_argument("The input message can't be empty.");
		}
	}

	int Encoder::calculateChecksum(const std::vector<int>& encodedValues) {
		long long checksum = STARTCODE;
		for (int i = 0; i < encodedValues.size(); i++) {
			checksum += static_cast<long long>(encodedValues[i] * (i + 1));
		}
		return static_cast<int>(checksum % MODULUS);
	}

	std::vector<int> Encoder::encode(const std::string& message) const {
		validate(message);

		std::vector<int> encodedMessage;
		for (char ch : message) {
			encodedMessage.push_back(encodeCharacter(ch));
		}
		int checksum = calculateChecksum(encodedMessage);
		std::vector<int> finalSequence;
		finalSequence.push_back(STARTCODE);
		finalSequence.insert(finalSequence.end(), encodedMessage.begin(), encodedMessage.end());
		finalSequence.push_back(STOPCODE);
		finalSequence.push_back(checksum);

		return finalSequence;
	}

}
