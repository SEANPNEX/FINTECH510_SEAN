#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>

using namespace std;



template <typename T>
T openFile(string name){
    T res(name);
    if(!res.is_open()){
        cerr << "Unable to open" << name << endl;
        exit(EXIT_FAILURE);
    }
    return res;
}

int generate_random_number(int max, int seed) {
    // Usually, we would use "rd" to seed the random number generator
    // in non-test / non-reproducibility situations.
    //
    // Also, we wouldn't recreate the generator every call, but re-use
    // to generate a sequence of results.
    // using class static members would be a good place to hold these objects
    //
    // random_device rd;

    mt19937 gen(seed);
    uniform_int_distribution<> distr(0, max); // closed interval
    return distr(gen);
}

map<string, vector<string>> createWordMap(const string& fileName) {
    ifstream inputFile = openFile<ifstream>(fileName);

    map<string, vector<string>> wordMap;
    string line;

    while (getline(inputFile, line)) {
        // Split line by ':'
        size_t delimiterPos = line.find(':');
        if (delimiterPos == string::npos) {
            throw runtime_error("Invalid line format: " + line);
        }

        string key = line.substr(0, delimiterPos); 
        string valuePart = line.substr(delimiterPos + 1); 

        // Split the valuePart by ','
        vector<string> values;
        stringstream ss(valuePart);
        string token;

        while (getline(ss, token, ',')) {
            values.push_back(token); 
        }

        // Insert the key-value pair into the map
        wordMap[key] = values;
    }

    inputFile.close();
    return wordMap;
}

void randomStory(string inputFile, string outputFile, map<string,vector<string> > wordMap,int seed){
    
    ifstream in = openFile<ifstream>(inputFile);
    ofstream out = openFile<ofstream>(outputFile);

    string line;

    while (getline(in, line)) {
        stringstream processedLine;
        size_t startPos = 0;

        while ((startPos = line.find('<', startPos)) != string::npos) {
            // Find the closing '>'
            size_t endPos = line.find('>', startPos);
            if (endPos == string::npos) {
                throw runtime_error("Invalid placeholder format in line: " + line);
            }

            string placeholder = line.substr(startPos + 1, endPos - startPos - 1);

            // Replace the placeholder with a random value from the map
            if (wordMap.find(placeholder) != wordMap.end()) {
                const auto& values = wordMap.at(placeholder);
                int randomIndex = generate_random_number(values.size() - 1, seed);
                string randomValue = values[randomIndex];

                // Replace placeholder with random value
                line.replace(startPos, endPos - startPos + 1, randomValue);
                startPos += randomValue.length();
            } else {
                startPos = endPos + 1; // Move past the placeholder if type not found
            }
        }

        processedLine << line << endl;
        out << processedLine.str();
    }

    in.close();
    out.close();
}




int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <template>" << "<word_catagories>" << "<int>seed" << endl;
        return EXIT_FAILURE;
    }
    
    string story_template = argv[1];
    string catagories = argv[2];
    int seed = stoi(argv[3]);
    map<string, vector<string> > wordMap = createWordMap(catagories);
    string ofTest = "story_tmp";
    randomStory(story_template, ofTest, wordMap, seed);
    ifstream tmp(ofTest);
    string line;
    while(getline(tmp, line)){
        cout << line << endl;
    }
    return 0;
}

