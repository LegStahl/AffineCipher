#include<iostream>;
#include<string>;
#include "AffineCipher.h";


int main(int argc, char **argv) {
	std::string sentence;
	std::string choose;
	std::cout << "Please enter your message: ";
	std::getline(std::cin, sentence);
	std::cout << ("Do you want to generate the keys or enter them?\n Write generation or enter: ");
	std::cin >> choose;
	if (choose == "generation") {
		AffineCipher coder;
		coder.frequency_Analysis(sentence);
		std::cout << coder.encryption(sentence) << std::endl;
		std::cout << coder.decryption(coder.encryption(sentence));
	}
	else if (choose == "enter") {
		std::cout << "Please enter two keys but you need to remember that size of alphabet is 52 and first key must have GCD with 52 that eguals 1: ";
		int key_A = 0;
		std::cin >> key_A;
		int key_B = 0;
		std::cin >> key_B;
		AffineCipher coder;
		coder.frequency_Analysis(sentence);
		std::cout << coder.encryption(sentence) << std::endl;
		std::cout << coder.decryption(coder.encryption(sentence));
	}
	else {
		std::cout << "The programm isn't able to get what you mean.";
	}
	return 0;
}