// C++ program to find frequecy of every word using unordered_map

#include <bits/stdc++.h> 

// Prints frequencies of individual words in str 
void printFrequencies(const std::string &str) 
{ 
	// declaring map of <string, int> type
    // each word is mapped to its frequency 
	std::unordered_map<std::string, int> wordFreq; 

	// breaking input into word using string stream 
	std::stringstream ss(str); // Used for breaking words 
	std::string word;          // To store individual words 
	while (ss >> word)
	{ 
		wordFreq[word]++; 
	}
	// now iterating over word, freq pair and printing them in <, > format 
	std::unordered_map<std::string, int>:: iterator iter; 
	for (iter = wordFreq.begin(); iter != wordFreq.end(); iter++) 
		std::cout << "(" << iter->first << ", " << iter->second << ")\n"; 
} 

// Driver code 
int main() 
{ 
	std::string str = "geeks for geeks geeks quiz "
				"practice qa for"; 
	printFrequencies(str); 
	return 0; 
} 
