#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <time.h>
using namespace std;

int main (int argc, char*argv[]) {
    /*used the map to store the words as a key value. That key 
    value would then point to a vector of strings that are all words
    that came after that key value in the text*/
    map<string, vector<string> > markov;
    vector<string> textfile;//initially stores words in text file as vector
    vector<string> wordChain;//used as the vector of chained words
    
    string word;
    string startingWord;
    
    int totalChar = 280;
    int i = 0;
    int charCount = 0;
    int randomNum;

    ifstream infile;
    infile.open("trump.txt");
    while (infile >> word){
  
        if(markov.count(word) == 0){//wont add dupplicate keys
            markov[word];
        }
        textfile.push_back(word);
    }

    while(i < textfile.size()){
        if(i != (textfile.size() - 1)){
            markov[textfile[i]].push_back(textfile[i+1]);
        }
        i++;
    }
    
    cout << "choose a word to start with: ";
    cin >> startingWord;
    
    while(markov.count(startingWord) == 0){
        cout<< "Invalid word.  Please try again: ";
        cin >> startingWord;
    } 
    
    charCount = startingWord.length() + 1;
    int start = 0;
    srand(time(NULL));
    wordChain = markov[startingWord];
    
    while(charCount < totalChar){
        randomNum = rand() % wordChain.size();
        charCount = charCount + wordChain[randomNum].length() + 1;
        if(charCount < totalChar){
            cout << wordChain[randomNum] << " ";
        }
        wordChain = markov[wordChain[randomNum]];
    }
    
    infile.close();
    return 0;
}