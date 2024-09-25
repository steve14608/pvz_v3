#pragma once
#include <map>
#include<queue>

#define Pevent int

#define P_PAUSEGAME 0x0001

#define	PT_PLANTS 0
#define PT_ZOMBIES 1
#define PT_BULLETS 2

#define ROWS 5
#define COLUMNS 13

#define SQUAREDISTANCE 10

enum Entities;

class TableUnit {
private:
	std::vector<std::pair<int, int>> vec[3];
public:
	bool isEmpty(short type);
	bool add(short type, std::pair<int, int> val);
	bool del(short type, int id);
	int bsmall(short type, int val, bool* iffound);
	int sbig(short type, int val, bool* iffound);
	decltype(auto) getStart(short type);
	decltype(auto) getEnd(short type);
};



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



class Table {
private:
	TableUnit table[ROWS];
public:
	std::queue<int> search(short type, int rows, int left, int right);
	int searchFirst(short type, int rows, int left, int right, bool* iffound);
	bool remove(int type, int rows, int id);
};


template <class T> class RecyclePool {
private:
	std::queue<T> que;
public:
	bool isEmpty();
	bool input(T a);
	T& output();
};
