// Lab 05: Hash Table
// Matthew Bianchi
// Creates custom hash table with XOR and Last7 hashing functions
// and Linear and Double collision strategies with probe count
#include "hash_202.hpp"
#include <sstream>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//Hash function that breaks key into smaller 7 char words and XOR them together
int XOR(string key, int tableSize){

  int hashKey = 0;
  int size;
  int index = 0;
  //Runs if key is greater than 7 chars
  if(key.size() > 7){
      //Finds size of string and int arrays
      if(key.size() % 7 == 0){
        size = (key.size() / 7);
      } else {
        size = (key.size() / 7) + 1;
      }
      
      string str[size];
      int XOR[size];
      vector<char> lastNum;
      int hashIndex = 0;
      string temp = "0000000";
      
      //Loops through key
      for(long unsigned int i = 0; i < key.size(); i++){
        temp[i % 7] = key[i];
        //Assigns temp string to str array
        if((i+1) % 7 == 0){
          str[hashIndex] = temp;
          hashIndex++;
          temp = "0000000";
          //if key is not divisible by 7 puts last chars into vector using push_back()
        } else if ((i == (key.size() - 1)) && ((i+1) % 7 != 0)){
          for(long unsigned int j = 0; j < ((i+1) % 7); j++){
              lastNum.push_back(temp[j]);
          }
          //assigns last part of key to the str array
          string temp2(lastNum.begin(), lastNum.end());
          str[hashIndex] = temp2;
        }
      }
      //Loops through string array converting key to int hex values
      for(int i = 0; i < size; i++){
        stringstream(str[i]) >> std::hex >> XOR[i];
        //XOR's hashKey
        hashKey = hashKey ^ XOR[i];
      }
      //gets index of hashTable
      index = hashKey % tableSize;
    } else if(key.size() <= 7){//Runs if key is less than 7 chars
      stringstream(key) >> std::hex >> hashKey;
      index = hashKey % tableSize;
    }
    return index;
}

//Helper function to hash using Last7 numbers in hex key
int Last7(string key, int tableSize){
  int index;
  int hashKey;
  string temp = "0000000";
  //If key greater than 7 chars loops through assigning last 7 chars to temp string
  if(key.size() > 7){
    for(long unsigned int i = key.size() - 1; i >= key.size()-7; i--){
      temp[i + 7 - key.size()] = key[i];
    }
  //If key not greater than 7 assigns chars to the temp string.
  } else {
    for(int i = key.size() - 1; i >= 0; i--){
      temp[i + 7 - key.size()] = key[i];
    }
  }
  //converts temp string to hex int and converts hashKey to hashTable index
  stringstream(temp) >> std::hex >> hashKey;
  index = hashKey % tableSize;
  return index;
}

//Helper function to check if key is hex
bool isHex(string key){
  for(long unsigned int i = 0; i < key.size(); i++){ 
    if ((key[i] < '0' || key[i] > '9') && (key[i] < 'A' || key[i] > 'F') && (key[i] < 'a' || key[i] > 'f') && (key[1] != '-')){
      return false; 
    }
  }
  return true;
}

//Helper Function to check if key is repeated
bool isRepeat(string key, int tableSize, vector<string> Keys){
  for(int i = 0; i < tableSize; i++){
    if(Keys[i] == key){
      return true;
    }
  }
  return false;
}

string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{
  //Sets collision to class member
  if(collision == "Linear"){
    Coll = 0;
  } else if(collision == "Double"){
    Coll = 1;
  }
  //Sets hash function to class member
  if(fxn == "Last7"){
    Fxn = 0;
  } else if(fxn == "XOR"){
    Fxn = 1;
  }
  if(Keys.size() > 0){//if table is set up
    return "Hash table already set up";
  } else if(table_size <= 0){//if tableSize is incorrect
    return "Bad table size";
  } else if(Fxn > 1 || Fxn < 0){//if hash function is incorrect
    return "Bad hash function";
  } else if(Coll > 1 || Coll < 0){//if collision strat is incorrect
    return "Bad collision resolution strategy";
  } else {
    //Resizes Vector to size of the hash table
    Keys.resize(table_size);
    Vals.resize(table_size);
    Nkeys = 0;

    (void) table_size;
    (void) fxn;
    (void) collision;
    return "";
  }
}

string Hash_202::Add(const string &key, const string &val)
{
  int index = 0;
  int hashKey = 0;
  long unsigned int count = 0;
  int h2;

  //Checks if table is not set up
  if(Keys.size() == 0){ //Checks if table is not set up
    return "Hash table not set up";
  } else if (key == ""){ //Checks if key is empty
    return "Empty key";
  } else if (!isHex(key)){//Checks if key is all hex
    return "Bad key (not all hex digits)";
  } else if (val == ""){//Checks if val is empty
    return "Empty val";
  } else if (Nkeys == Keys.size()){//Checks if table is full
    return "Hash table full";
  } else if(isRepeat(key, Keys.size(), Keys)){//Checks if key is repeated
      return "Key already in the table";
  } else {
    //Gets Index
    //Last7
    if(Fxn == 0){
      hashKey = Last7(key, Keys.size());
      index = Last7(key, Keys.size());//Sets index if collision does not occur
    //XOR
    } else if (Fxn == 1){
      hashKey = XOR(key, Keys.size());
      index = XOR(key, Keys.size());
    }
    // Linear Hashing
    if(Coll == 0){ 
      if(!Keys[index].empty()){
        count = 0;
        while(!Keys[index].empty()){
          count++;
          //Linear hash function
          index = (hashKey + count) % Keys.size();
        }
      }
      Nkeys++;
      Keys [index] = key;
      Vals [index] = val;
    // Double Hashing
    } else if(Coll == 1){ // Double Hashing
      if(!Keys[index].empty()){
        while(!Keys[index].empty()){
          count++;
          if(Fxn == 0){
            h2 = (XOR(key, Keys.size()));
          } else if(Fxn == 1){
            h2 = (Last7(key, Keys.size()));
          }
          if(h2 % Keys.size() == 0){
            h2 = 1;
          }
          //Double Hash Function
          index = (hashKey + (h2*count)) % Keys.size();
          if(count > Keys.size()){
            return "Cannot insert key";
          }
        }
      }
      Nkeys++;
      Keys[index] = key;
      Vals[index] = val;
    }

    (void) key;
    (void) val;
    return "";
  }

}

//Finds val associated with key and sets the TP count
string Hash_202::Find(const string &key)
{
  if(Keys.size() == 0){//If table is not setup
    return "";
  } else if(!isHex(key)) {//If key is not hex
    return "";
  } else {
    Nprobes = 0;
    int Index;
    string val = "";
    int count = 0;
    int probe = 0;

    //Gets index
    if(Fxn == 0){
      Index = Last7(key, Keys.size()) % Keys.size();
    }   else if (Fxn == 1) {
      Index = XOR(key, Keys.size()) % Keys.size();
    }

    //Sets Probe for Linear and Double Hashing
    if(Coll == 0){
      probe = 1;
    } else if(Coll == 1){
      if(Fxn == 0){
        probe = XOR(key, Keys.size());
      } else if(Fxn == 1){
        probe = Last7(key, Keys.size());
      }
      if(probe % Keys.size() == 0){
        probe = 1;
      }
    }

    //Loops through table to find key
    for(long unsigned int i = 0; i < Keys.size(); i++){
      if(Keys.at((Index + (count * probe)) % Keys.size()) == key){
        val = Vals.at((Index + (count * probe)) % Vals.size());
        break;
      } else {
        count++;
      }
    }
    //Sets probe count for individual key to be used by the TP function
    Nprobes = count;
	  (void) key;
	  return val; // "" if key not in hash table
  }
}

//Prints Hash Table
void Hash_202::Print() const
{
  //Loops through key vector
  if(Keys.size() != 0) {
		for(unsigned long int i = 0; i < Keys.size(); i++) {
			//print if not empty
			if(Keys.at(i) != "") 
				printf("%5lu %s %s\n", i, Keys.at(i).c_str(), Vals.at(i).c_str());
		}
	}
}

//Holds count of total probes in hash table
size_t Hash_202::Total_Probes()
{
  size_t sum = 0;
	
  //Loops through key vector and adds probes to sum.
	if(Keys.size() != 0) {
		for(unsigned long int i = 0; i < Keys.size(); i++) {
			if(Keys.at(i) != "") { //don't include empty strings
				Find(Keys.at(i));
				sum += Nprobes;
			}
		}
	}
  return sum;
}
