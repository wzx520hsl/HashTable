// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2016


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue,ListType n) {
  key = theKey;
  value = theValue;
  next = n;
}

bool append (ListType &list, const string &theKey,int val)
{
	ListType p = list;

  if (p == NULL) {
	  insertFront(theKey,val,list);
    return true;
  }
  if(containsKey(list,theKey)){
	  return false;
  }
  while (p->next != NULL) {
    p = p->next;
  }

  p->next = new Node(theKey,val);
  return true;
}

void insertFront(const string &theKey, int val,ListType &list) {
  list = new Node(theKey,val, list);
}

void printList(ListType list) {



  ListType p = list;
  while (p != NULL) {
    cout << p->key << " ";
    cout << p->value<<" ";
    cout << endl;
    p = p->next;
  }

}

bool containsVal(ListType list,int val){
	if(list==NULL){
		return false;
	}
	ListType p=list;
	while(p!=NULL){
		if(p->value==val){
			return true;
		}
		p=p->next;
	}
	return false;
}

bool containsKey(ListType list,const string &theKey){
	if(list==NULL){
		return false;
	}
	ListType p=list;
	while(p!=NULL){
		if(p->key==theKey){
			return true;
		}
		p=p->next;
	}
	return false;
}

bool changeVal(ListType list,const string &theKey,int value){
	if(list==NULL){
		return false;
	}
	ListType p=list;
	while(p!=NULL){
		if(p->key==theKey){
			p->value=value;
			return true;
		}
		p=p->next;
	}
	return false;
}

int *getVal(ListType list,const string &theKey){
	if(list==NULL){
		return NULL;
	}
	ListType p=list;
	while(p!=NULL){
		if(p->key==theKey){
			return &(p->value);
		}
		p=p->next;
	}
	return NULL;
}

int listSize(ListType list){
	int count=0;
	ListType p=list;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}

bool listRemove(ListType &list,string target){
	if(list==NULL){
		return false;
	}
	ListType p=list;
	ListType pre=NULL;
	while(p!=NULL){
		if(p->key==target){
			if(pre==NULL){
				list=p->next;
				p=NULL;
			}else{
				pre->next=p->next;
			}
			return true;
		}
		pre=p;
		p=p->next;

	}
	return false;

}



//*************************************************************************
// put the function definitions for your list functions below
