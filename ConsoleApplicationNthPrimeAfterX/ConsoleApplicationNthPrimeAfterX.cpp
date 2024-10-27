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

static std::vector<int> GetPrimeBetweenTwoNumbers(int startNumber = 2, int endNumber = 3) {
	std::vector<int> array;
	for (int i = startNumber; i < endNumber; i++) {
		if (isPrime(i)) {
			array.push_back(i);
		}
	}
	return array;
}

static std::vector<int> GetNPrimeAfterAnInteger(int numberOfPrime = 1, int afterNumber = 2) {
	std::vector<int> array;
	int counter = 0;
	while (counter < numberOfPrime) {
		if (isPrime(afterNumber)) {
			array.push_back(afterNumber);
			counter++;
		}
		afterNumber++;
	}
	return array;
}

static std::vector<int> GetPrimeBetweenTwoNumbers0(int startNumber = 2, int endNumber = 3)
{
	std::vector<int> array(20);
	int counter = 0;
	for (int i = startNumber; i < endNumber; i++)
	{
		if (isPrime(i))
		{
			array[counter] = i;
			counter++;
		}
	}

	return array;
}

static std::vector<int> GetNPrimeAfterAnInteger2(int numberOfPrime = 1, int afterNumber = 2)
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

static void ComputePrime(int x, int n)
{
	std::cout << n << " nombre" << Plural(n) << " premier" << Plural(n) << " après le nombre " << x << " : " << PrintPrimes(GetNPrimeAfterAnInteger(n, x)) << std::endl;
}

static int GetNumberOfPrime(int number)
{
	int counter = 0;
	for (int i = number; i < number + 100; i++)
	{
		if (isPrime(i))
		{
			counter++;
		}
	}

	return counter;
}

static void DisplayPrimes(int n)
{
	int numberOfPrime = GetNumberOfPrime(n);
	std::cout << numberOfPrime << " nombre" << Plural(n) << "  premier" << Plural(n) << " entre le nombre " << n << " et " << n + 100 << " : " << PrintPrimes(GetPrimeBetweenTwoNumbers(n, n + 100)) << std::endl;
}

int main()
{
	std::cout << "Calcul de N nombre premier après le nombre X\n";

	/*ComputePrime(2, 25);
	ComputePrime(100, 21);
	ComputePrime(200, 16);
	ComputePrime(300, 16);
	ComputePrime(400, 17);
	ComputePrime(500, 14);
	ComputePrime(600, 16);
	ComputePrime(700, 14);
	ComputePrime(800, 15);
	ComputePrime(900, 14);
	ComputePrime(1000, 16);

	ComputePrime(1100, 12);
	ComputePrime(1200, 15);
	ComputePrime(1300, 11);
	ComputePrime(1400, 17);
	ComputePrime(1500, 12);
	ComputePrime(1600, 15);
	ComputePrime(1700, 12);
	ComputePrime(1800, 12);
	ComputePrime(1900, 13);
	ComputePrime(2000, 14);*/

	for (int i = 100; i < 10'000'000; i = i + 100)
	{
		DisplayPrimes(i);
	}

	return 0;
}
