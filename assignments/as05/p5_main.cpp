/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  hashFuncs.h
  Assignment 5: Hash
  Tested/Works
  - If given incorrect input i.e. 8 instead of 7, it will not work/end

  This hash program requires one numeric input choice and is asked for a second
  input (can be either numeric, string, or both) depending on the prompt.  If
  given duplicate data the functions should match the first found match.  The
  value the key is holding is stored as a string incase if any letters are 
  inputted.
*/

#include "hashFuncs.h"

// helper like function for the insert portion of hashtable class (case 2)
// purpose is to get the index and 
record formatString(std::string lineInput) {
  auto idx = lineInput.find(" ");
  if (idx != std::string::npos) {
    return {std::stoi(lineInput.substr(0, idx)), lineInput.substr(idx + 1)};
  }
  throw std::runtime_error("Invalid Input at " + lineInput);
}

int main() {
  hashTable Hash(178000);

  bool done = false;
  std::string userInput;  // for user's choice prompt
  std::string strInput;   // for the choices that req additional input

  while(!done) {
    std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save";
    std::cout << " (7)quit -- Your choice? ";
    
    std::getline(std::cin, userInput);

    switch (std::stoi(userInput)) {
      case (1): {    // load
        std::cout << "read hash table - filename? ";

        std::getline(std::cin, strInput);
        // create input file stream with strInput value
        std::ifstream ifil(strInput);
        std::string input;

        while (std::getline(ifil, input)) {
          record* rec = new record(formatString(input));
          Hash.insert(rec);
        }

        break;
      }
      case (2): {    // insert
        std::cout << "input new record:" << '\n';

        std::getline(std::cin, strInput);
        record* rec =  new record(formatString(strInput));
        Hash.insert(rec);
        break;
      }
      case (3): {
        std::cout << "delete record - key? ";
        std::getline(std::cin, strInput);

        int key = std::stoi(strInput);
        // stores whatever value the key was storing
        auto value = Hash.rm(key);

        // if value is true/value is storing some data then run
        if (value) {
          std::cout << "Delete: " << key << " " << value->second << '\n';
        }else{  // no data stored in value, prompt this
          std::cout << "Delete not found: " << key << '\n';
        }

        break;
      }
      case (4): {    // search
        std::cout << "search for record - key? ";
        std::getline(std::cin, strInput);

        int key = stoi(strInput);
        // stores whatever value the key was storing
        auto value = Hash.search(key);

        if(value){
          std::cout << "Found: " << key << " " << value->second << '\n';
        }else{
          std::cout << "Search not found: " << key << '\n';
        }

        break;
      }
      case (5): {    // clear
        std::cout << "clearing hash table. " << '\n';
        Hash.clear();

        break;
      }
      case (6): {    // save
        std::cout << "write hash table - filename? ";
        std::getline(std::cin, strInput);

        std::ofstream outFile(strInput);
        Hash.saveToFile(outFile);

        break;
      }
      case (7): {   // quit
        done = true;
        break;
      }
    }
  }
}