// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
	hashSize=HASH_SIZE;
	data=new ListType[hashSize];
	size=0;
}


Table::Table(unsigned int hSize) {
	hashSize=hSize;
	data=new ListType[hSize];
	size=0;
}


int * Table::lookup(const string &key) {
  int index=hashCode(key);
  return getVal(data[index],key);

}

bool Table::remove(const string &key){
  int index=hashCode(key);
  bool res=listRemove(data[index],key);
  if(res){
	  size--;
  }
  return res;
}

bool Table::insert(const string &key, int value) {
	int index=hashCode(key);
	bool res=append (data[index], key, value);
	if(res){
		size++;
	}
	return res;

}

int Table::numEntries() const {
  return size;
}

void Table::printAll() const{
	for(int i=0;i<hashSize;i++){
		printList(data[i]);
	}
}

void Table::hashStats(ostream &out) const{
	out<<"numbers of buckets: "<<hashSize<<endl;
	out<<"numbers of entries: "<<size<<endl;
	int max=0;
	int numNon=0;
	for(int i=0;i<hashSize;i++){
		if(data[i]!=NULL){
			numNon++;
			int length=listSize(data[i]);
			if(length>max){
				max=length;
			}
		}
	}
	out<<"number of non-empty buckets: "<<numNon<<endl;
	out<<"longest chain: "<<max<<endl;
}

bool Table::change(const string &key,int value){
	int index=hashCode(key);
	return changeVal(data[index], key, value);

}


