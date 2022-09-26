
#include<iostream>;

#include"AffineCipher.h";

#include<string>;

#include<random>;

#include<map>;


AffineCipher::AffineCipher() {
	int* case_Of_Keys = generation_Of_Keys();
	this->key_A = case_Of_Keys[0];
	this->key_B = case_Of_Keys[1];
	delete(case_Of_Keys);
}

AffineCipher::AffineCipher(int key_A, int key_B) {

	this->key_A = key_A;

	this->key_B = key_B;
}

 std::string AffineCipher::encryption(std::string message) {
	 std::string encryptedMessage;
	 for (int i = 0; i < message.size(); i++) {
		 for (int j = 0; j < this->alphabet.size(); j++) {

			 if (message[i] == this->alphabet[j]) {
				 int newIndex = ((j * this->key_A + this->key_B) % this->alphabet.size());
				 encryptedMessage = encryptedMessage + this->alphabet[newIndex];
				 break;
			 }
			 else if (j + 1 == this->alphabet.size()) {
				 encryptedMessage = encryptedMessage + message[i];
			 }
		 }
	 }
	 return encryptedMessage;
}

 std::string AffineCipher::decryption(std::string message) {
	 std::string decryptedMessage;
	 int for_key_A = 0;
	 for (int i = 0;;i++) {
		 if (1 == ((this->key_A * i) % this->alphabet.size())) {
			 for_key_A = i;
			 break;
		 }
	 }
	 int previousIndex = 0;
	 for (int i = 0; i < message.size(); i++) {
		 for (int j = 0; j < this->alphabet.size(); j++) {
			 if (message[i] == this->alphabet[j]) {
				 previousIndex = (for_key_A * (j + this->alphabet.size() - this->key_B) % this->alphabet.size());
				 decryptedMessage = decryptedMessage + this->alphabet[previousIndex];
				 break;
			 }
			 else if (j + 1 == this->alphabet.size()) {
				 decryptedMessage = decryptedMessage + message[i];
			 }
		 }
	 }

	 return decryptedMessage;
 }

 int* AffineCipher::generation_Of_Keys() {


	 int* case_Of_Keys = new int[2];

	 std::default_random_engine generator;
	 std::uniform_int_distribution<int> distribution(2, this->alphabet.size());
	 int Key_A = 0;

	 for (;;) {
		 int size = this->alphabet.size();
		 Key_A = distribution(generator);
		 
		 int false_Key_A = Key_A;
		 while (size != false_Key_A) {
			 if (size > false_Key_A)
				 size -= false_Key_A;
			 else
				 false_Key_A -= size;
		 }
		 if (size == 1) {
			 case_Of_Keys[0] = Key_A;
			 break;
		 }
	 }
	 
	int key_B = distribution(generator);
	case_Of_Keys[1] = key_B;
	return case_Of_Keys;
 }

 void AffineCipher::frequency_Analysis(std::string message) {
	 std::map<char, int> myMap;
	 for (int i = 0; i < this->alphabet.size(); i++) {
		 myMap.insert(std::make_pair(this->alphabet[i], 0));
	 }
	 std::map<char, int>::iterator it;
	 for (int i = 0; i < message.size(); i++) {
		 it = myMap.find(message[i]);
		 if (it != myMap.end()) {
			 it->second++;
		 }
	
	 }
	 it = myMap.begin();
	 for (it; it != myMap.end(); it++) {
		 std::cout << "Letter:  " << it->first << "    Count of entering in message:  " << it->second << std::endl;
	 }

 }
 