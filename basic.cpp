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
		auto ve = &vec[type];
		int s = 0;
		int e = vec[type].size();
		while (s > e) {
			int mid = (s + e) / 2;
			int z = (*ve)[mid].second;
			if (z == val.second) {
				(*ve).emplace((*ve).begin() + mid, val);
				return true;
			}
			else if(z>val.second){
				e = mid;
			}
			else {
				s = mid;
			}
		}
		if (s == e) {
			(*ve).emplace((*ve).begin() + s, val);
			return true;
		}
		return false;
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
		return con[type.begin(); ]
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
		int le = left / SQUAREDISTANCE;
		int ri = (right + SQUAREDISTANCE - 1) / SQUAREDISTANCE;
		/*for (int i = le; i < +ri; i++) {
			auto s = table[rows][i].getStart(type);
			auto end = table[rows][i].getEnd(type);
			while (s != end) {
				if (s->second >= left && s->second <= right) {
					arr.push(s->first);
				}
				s++;
			}
		}*/
		return arr;
	}
	//std::queue<int> search(int rows, int center, bool(*cm)(int,int,int,int)) {
	//	/*std::vector<int> arr;
	//	for (int i = 0; i < ROWS; i++) {
	//		for (int j = 0; j < COLUMNS; j++) {
	//			if (cm(rows,center,i,table[i][j].position)) {
	//				arr.push_back(table[i][j].id);
	//			}
	//		}
	//	}
	//	int array[arr.size()];
	//	std::copy(arr.begin(), arr.end(), array);
	//	return array;*/
	//	std::queue<int> arr;
	//	for (int i = 0; i < ROWS; i++) {
	//		for (int j = 0; j < COLUMNS; j++) {

	//		}
	//	}
	//}
	int searchFirst(short type, int rows, int left, int right) {
		int minid = 0;
		int minpoi = right + 1;
		int le = left / SQUAREDISTANCE;
		int ri = (right + SQUAREDISTANCE - 1) / SQUAREDISTANCE;
		for (int i = le; i < +ri; i++) {
			/*	auto s = table[rows][i].getStart(type);
				auto end = table[rows][i].getEnd(type);
				while (s != end) {
					if (s->second<minpoi&&s->second >= left && s->second <= right) {
						minid = s->first;
						minpoi = s->second;
					}
					s++;
				}
			}*/
			return minid;
		}
		bool remove(int type);
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