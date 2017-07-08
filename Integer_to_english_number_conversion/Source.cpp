#include <iostream>
#include <string>

	std::string basic[10] = { "zero", "one","two","three","four","five","six","seven","eight","nine" };
	std::string medium[10] = { "ten","eleven","twelwe","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	std::string tens[10] = { "nope", "ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety" };
	std::string rest[4] = { "houndred", "thousand","million","billion" };

	char* buffer;

	bool all_three(int start);

int main() {
	
	//Write a program that takes an integer and displays the English name of that value.
	//You should support both positive and negative numbers, in the range supported by a 32 - bit integer(approximately - 2 billion to 2 billion).
	
	int integer = 1546325;

	buffer = new char;

	itoa(integer,buffer,10);	/*konwersja z int do string*/
	_strrev(buffer);
	int length = strlen(buffer);

	bool minus = 0;					/*Czy jest z minusem*/
	if (buffer[length-1] == '-') {
		minus = 1;
		buffer[length - 1] = '\0';
		length--;
	}

	/*	Dodawaie 0	*/
	if (length != 3 && length != 6 && length != 9 && length != 12) {
		if (length != 2 && length != 5 && length != 8 && length != 11)
			strcat(buffer, "0");
		strcat(buffer, "0");
	}

	if (minus == 1) 
		std::cout << "minus ";

	switch (length) {
		case 10: case 11: case 12: {
			if(all_three(9))
				std::cout << rest[3] << " ";
		}
		case 7: case 8: case 9: {
			if(all_three(6))
				std::cout << rest[2] << " ";
		}
		case 4: case 5: case 6: {
			if(all_three(3))
				std::cout << rest[1] << " ";
		}
		case 1: case 2: case 3: {
			all_three(0);
			break;
		}
	}

	return 0;
}

bool all_three(int start) {

	if (buffer[start+2] != '0') {			/*0xx*/
			std::cout << basic[buffer[start + 2]-48] << " " << rest[0] << " ";
			if (buffer[start + 1] == '0' && buffer[start] == '0')	/*y0x*/
				return 1;
	}
	
	if (buffer[start + 1] == '0') {		/*y0x*/
		if (buffer[start] == '0')
			return 0;
		else
			std::cout << basic[buffer[start] - 48] << " ";
	}
	else {						/*yzx*/
		if ((buffer[start + 1] - 48) > 1) {	/*z>1*/
			std::cout << tens[buffer[start + 1] - 48] << " ";
			if ((buffer[start] - 48) != 0)
				std::cout << basic[buffer[start] - 48] << " ";
		}
		else {
			std::cout << medium[buffer[start] - 48] << " ";
		}
	}
	return 1;
}