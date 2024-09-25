#pragma once
#include <map>
#include<queue>

#define Pevent int

#define P_PAUSEGAME 0x0001

#define	PT_PLANTS 0
#define PT_ZOMBIES 1
#define PT_BULLETS 2

enum Entities;

class Change;



template<class T> class Pool {
private:
	std::map<int, T> con[3];
public:
	void add(T a, short type);
	void transmit(int id, short type, Pool b);
	decltype(auto) getStart(short type);
	decltype(auto) getEnd(short type);
	T& getElement(int id, short type, bool* iffound);//0plants£¬1zombies,2bullets
};



class Table;


template <class T> class RecyclePool {
private:
	std::queue<T> que;
public:
	bool isEmpty();
	bool input(T a);
	T& output();
};
