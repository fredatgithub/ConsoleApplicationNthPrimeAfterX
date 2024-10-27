#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

static bool isPrime(int number) {
	if (number <= 1)
	{
		return false;
	}

	if (number <= 3)
	{
		return true;
	}

	if (number % 2 == 0 || number % 3 == 0)
	{
		return false;
	}

	for (int i = 5; i * i <= number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0)
		{
			return false;
		}
	}

	return true;
}

static std::vector<int> GetNPrimeAfterAnInteger(int numberOfPrime = 1, int afterNumber = 2)
{
	std::vector<int> array(numberOfPrime);
	int counter = 0;
	do
	{
		if (isPrime(afterNumber))
		{
			array[counter] = afterNumber;
			counter++;
		}

		afterNumber++;
	} while (counter < numberOfPrime);

	return array;
}

static std::string PrintPrimes(std::vector<int> array)
{
	std::string line = "";
	for (int value : array) {
		line = line + std::to_string(value) + " ";
	}

	return line;
}

static std::string Plural(int number)
{
	return number > 1 ? "s" : "";
}

int main()
{
	std::cout << "Calcul de N nombre premier après le nombre X\n";

	int x = 10, n = 10;
	std::cout << n << " nombre" << Plural(n) << " premier" << Plural(n) << " après le nombre " << x << " : " << PrintPrimes(GetNPrimeAfterAnInteger(n, x));

	return 0;
}
