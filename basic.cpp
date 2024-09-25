#include <stdlib.h>
#include<vector>
#include<queue>
#include<map>
#define	PT_PLANTS 0
#define PT_ZOMBIES 1
#define PT_BULLETS 2

#define ROWS 5
#define COLUMNS 13

#define SQUAREDISTANCE 10
//每个格子10，最小分成10份

//
enum Entities {
	Sunflower,Peeshooter,Nutwall,Potatolandmine,
	Normal,Bucket,
	Pee
};









//to-do
//二分插入
class TableUnit {
private:
	std::vector<std::pair<int, int>> vec[3];
public:
	bool isEmpty(short type) {
		return vec[type].empty();	
	}
	bool add(short type, std::pair<int, int> val) {
		bool iffound;
		int an = sbig(type, val.second, &iffound);
		if (iffound) vec[type].emplace(vec[type].begin() + an, val);
		else vec[type].emplace(vec[type].end(), val);
		return true;
	}
	bool del(short type, int id) {
		for (auto i = vec[type].begin(); i != vec[type].end(); i++) {
			if (i->first == id) {
				vec[type].erase(i);
				return true;
			}
		}
		return false;
	}
	int bsmall(short type, int val,bool *iffound) {
		auto ve = &vec[type];
		int s = 0;
		int e = vec[type].size();
		if ((*ve).begin()->second >= val) {
			iffound = false;
			return 0;
		}
		while (s > e) {
			int mid = (s + e) / 2;
			int z = (*ve)[mid].second;
			if (z == val) {
				while ((*ve)[--mid].second != val);
				return mid;
			}
			else if (z > val) {
				e = mid-1;
			}
			else {
				s = mid;
			}
		}
		if (s == e) {
			return s;
		}
		return 0;

	}
	int sbig(short type, int val,bool *iffound) {
		auto ve = &vec[type];
		int s = 0;
		int e = vec[type].size();
		if (((*ve).begin()+(*ve).size()-1)->second <= val) {
			iffound = false;
			return 0;
		}
		while (s > e) {
			int mid = (s + e) / 2;
			int z = (*ve)[mid].second;
			if (z == val) {
				while ((*ve)[++mid].second != val);
				return mid;
			}
			else if (z > val) {
				e = mid;
			}
			else {
				s = mid+1;
			}
		}
		if (s == e) {
			return s;
		}
		return 0;
	}
	decltype(auto) getStart(short type) {
		return vec[type].begin();
	}
	decltype(auto) getEnd(short type) {
		return vec[type].end();
	}
};









template<class T> class Pool {
private:
	std::map<int, T> con[3];
public:
	void add(T a, short type) {
		con[type][T.id] = T;
	}
	void transmit(int id, short type, Pool b) {
		auto it = con[type].find(id);
		T tt = T(it->second);
		con[type].erase(it->first);
		b.add(tt, type);
	}
	
	decltype(auto) getStart(short type) {
		return con[type.begin()];
	}
	decltype(auto) getEnd(short type) {
		return con[type].end();
	}
	T& getElement(int id, short type, bool* iffound)//0plants，1zombies,2bullets
	{
		auto z = con[type].find(id);
		if (z != con[type].end()) {
			*iffound = true;
			return z->second;
		}
		*iffound = false;
		return NULL;
	}
};











//to-do
//T是一个三链表类
class Table {
private:
	TableUnit table[ROWS];
public:
	std::queue<int> search(short type, int rows, int left, int right) {
		std::queue<int> arr;
		if (table[rows].isEmpty(type)) return arr;
		bool iffound;
		auto s = table[rows].getStart(type)+ table[rows].bsmall(type, left, &iffound);
		if (iffound) s++;

		auto e = table[rows].getStart(type) + table[rows].sbig(type, right, &iffound);
		if (!iffound) e = table[rows].getEnd(type);
		while (s != e) {
			arr.push(s->first);
			s++;
		}
		return arr;
	}
	int searchFirst(short type, int rows, int left, int right,bool *iffound) {
		if (table[rows].isEmpty(type)) {
			*iffound = false;
			return 0;
		}
		bool iffoun;
		auto s = table[rows].getStart(type);
		int z = table[rows].bsmall(type, left, &iffoun);
		if (iffoun) {
			if (s+z+1 != table[rows].getEnd(rows) && s->second <= right) {
				*iffound = true;
				return s->first;
			}
			else {
				*iffound = false;
				return 0;
			}
		}
		else {
			if (s->second <= right) {
				*iffound = true;
				return s->first;
			}
			else {
				*iffound = false;
				return 0;
			}
		}
	};
	bool remove(int type,int rows,int id)
	{
		table[rows].del(type, id);
	};
};




template <class T> class RecyclePool {
private:
	std::queue<T> que;
public:
	bool isEmpty() {
		return que.empty();
	}
	bool input(T a) {
		que.push(a);
	}
	T& output() {
		return que.pop();
	}
};