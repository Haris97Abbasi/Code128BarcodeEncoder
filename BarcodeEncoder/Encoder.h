#pragma once
#include <vector>
#include <string>

namespace barcode {
	class Encoder {

	public:
		// Used to encode the input string to Barcode-128 Subset B; Uses other functions
		std::vector<int> encode(const std::string& message) const;

		// Used to calculate teh checksum
		static int calculateChecksum(const std::vector<int>& encodedValues);

		// Used to encode a char into ASCII number
		static int encodeCharacter(char ch);

	private:
		// Used for validation
		static void validate(const std::string& message);

	};
}