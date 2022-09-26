#ifndef AFFINECIPHER
#define AFFINECIPHER

class AffineCipher
{
private:
	 int key_A;
	 int key_B;
	 std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
	AffineCipher(int key_A, int key_B);
	AffineCipher();
	std::string encryption(std::string message);
	std::string decryption(std::string message);
	int* generation_Of_Keys();
	void frequency_Analysis(std::string message);
};



#endif