/*
  hashTable.cpp
  Assignment 5: Hash
  Tested/Works

  All the functions in the hashTable class are here.  formatString from the
  record pair is present on p5_main.cpp.
*/
#include "hashFuncs.h"

hashTable::hashTable(int hashSize) : m(hashSize) {
  table = new std::list<std::unique_ptr<record>>[hashSize];
}

hashTable::~hashTable() {
  delete[] table;
}

void hashTable::insert(record *recs) {
  int k = hash(recs->first);

  table[k].emplace_front(recs);
}


//smart pointer for record
std::unique_ptr<record> hashTable::rm(unsigned int key) {
  auto value = &table[hash(key)];
  auto itr = find(key);
  std::unique_ptr<record> res = nullptr;

  if(itr != value->end()) {
    res = std::make_unique<std::pair<int, std::string>>(itr->get()->first, itr->get()->second);
    table[hash(key)].erase(itr);
  }
  return res;
}

// clear
void hashTable::clear() {
  for(unsigned int i = 0; i < m; i++) {
    table[i].clear();
  }
}

void hashTable::saveToFile(std::ofstream &outFile) {
  for(unsigned int i = 0; i < m; ++i) {
    for(auto itr = table[i].begin(); itr != table[i].end(); itr++) {
      outFile << std::to_string((*itr)->first) + " " + (*itr)->second + "\n";
    }
  }
}

// smart pointer for searching
std::unique_ptr<record> hashTable::search(int key) {
  int idx = hash(key);
  auto itr = find(key);

  if(itr != table[idx].end()) {
    return std::make_unique<record>(itr->get()->first, itr->get()->second);
  }
  return nullptr;
}

// unique pointer itr for finding
std::list<std::unique_ptr<record>>::iterator hashTable::find(int key) {
  int i = hash(key);

  for(auto itr = table[i].begin(); itr != table[i].end(); itr++) {
    if(itr->get()->first == key) {
      return itr;
    }
  }
  return table[i].end();
}

// generating hash
int hashTable::hash(int k) {
  return floor(m * ((k*c) - floor(k * c)));
}