std::string divide(int numerator, int denominator, int decimalPlaces) {
	std::string result;

	// Calculate the integer part
	int integerPart = numerator / denominator;
	result += std::to_string(integerPart) + ".";

	// Calculate the decimal part
	numerator %= denominator;
	for (int i = 0; i < decimalPlaces; ++i) {
		numerator *= 10;
		int digit = numerator / denominator;
		result += std::to_string(digit);
		numerator %= denominator;
	}
	return result;
}