/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  hashFuncs.h
  Assignment 5: Hash
  Tested/Works
*/

#include <memory>
#include <list>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>

typedef std::pair<int, std::string> record; // alt to using record class

class hashTable{
  public:
    hashTable(int=100); // build a table
    ~hashTable(); // destroys table (after code is finished)
    void insert(record *); // insert copy of record
    // clears record instead of delete
    std::unique_ptr<record> rm(unsigned int key); // delete a record
    // return pointer to a copy of found record, or 0
    void clear();
    // same thing as writing to file
    void saveToFile(std::ofstream&);
    std::unique_ptr<record> search(int key); 
  private:
    // find return value: some type of index
    // record *find(int); // helper search fn
    // int hash(record *); // hash value for record
    std::list<std::unique_ptr<record>>::iterator find(int key);
    int hash(int); // hash value for key  
    unsigned int m; // size of table
    // array of m lists that hold records
    const double c = 0.618034;  // result/value of 1 / phi. const for hash
    // other members as desired
    std::list<std::unique_ptr<record>>* table;
  };