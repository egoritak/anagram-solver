#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>

std::unordered_map<std::string, std::vector<std::string>> createAnagramDict(
	const std::string& filename) {
	std::unordered_map<std::string, std::vector<std::string>> anagramDict;
	std::ifstream file(filename);
	std::string word;

	while (file >> word) {
		std::string sortedWord = word;
		std::sort(sortedWord.begin(), sortedWord.end());
		anagramDict[sortedWord].push_back(word);
	}

	return anagramDict;
}

std::vector<std::string> findAnagrams(
	const std::unordered_map<std::string, std::vector<std::string>>&
		anagramDict,
	const std::string& word) {
	std::string sortedWord = word;
	std::sort(sortedWord.begin(), sortedWord.end());
	auto it = anagramDict.find(sortedWord);

	if (it != anagramDict.end()) {
		return it->second;
	}

	return {};
}

int main() {
	std::string filename = "../etc/words.txt";
	auto anagramDict = createAnagramDict(filename);

	std::string word;
	std::cout << "Enter a string: ";
	std::cin >> word;

	auto anagrams = findAnagrams(anagramDict, word);

	if (!anagrams.empty()) {
		std::cout << "Anagrams found: ";
		for (const auto& anagram : anagrams) {
			std::cout << anagram << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "No anagrams found." << std::endl;
	}

	return 0;
}
