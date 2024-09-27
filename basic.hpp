#pragma once
#include <map>
#include<queue>
#include <stdlib.h>
#include<vector>
#include<graphics.h>
#include<filesystem>
#include<iostream>

#define Pevent int

#define P_PAUSEGAME 0x0001

#define	PT_PLANTS 0
#define PT_ZOMBIES 1
#define PT_BULLETS 2

#define ROWS 5
#define COLUMNS 13

#define SQUAREDISTANCE 10





//png͸����
inline static void putimage_transperant(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER ,0 ,255,AC_SRC_ALPHA });
}


//����ʵ������
enum Entities {
	Sunflower, Peeshooter, Nutwall, Potatolandmine,
	Normal, Bucket,
	Pee
};

//ѭ��������������ѭ����������
template <class T> class CycleLinkedList {
private:
	struct Node {
		T val;
		struct Node* next;
		Node(T v) :val(v), next(NULL) {}
	};
	Node* head;
	Node* tail;
public:
	CycleLinkedList() {
		head = new Node(NULL);
		tail = head;
	}
	~CycleLinkedList() {
		Node* p = head->next;
		while (p != NULL) {
			delete head;
			head = p;
			p = p->next;
		}
	}
	bool isempty() {
		return head->next == NULL;
	}
	void add(T a) {
		Node* p = new Node(a);
		tail->next = p;
		tail = tail->next;
	}
	void del(T a) {
		Node* p = head;
		while (p->next->val != a) p = p->next;
		Node* pp = p->next;
		p->next = p->next->next;
		delete pp;
		if (p->next == NULL) tail = p;
	}
	void del(T a, bool (*cmp)(T a, T b)) {
		Node* p = head;
		//while (p->next->val != a) p = p->next;
		while (!cmp(p->next->val, a)) p = p->next;
		Node* pp = p->next;
		p->next = p->next->next;
		delete pp;
		if (p->next == NULL) tail = p;
	}
	T& get(int index) {
		int z = index;
		Node* pointer = head->next;
		while (index-- >= 0 && pointer != NULL) pointer = pointer->next;
		if (index >= 0) return tail->val;
		return pointer == NULL ? NULL : ponter->next;
	}
	class iterator {
		Node* obj;
		Node* head;
	public:
		iterator(Node* ptr) :obj(ptr->next), head(ptr->next) {};
		iterator() :obj(NULL), head(NULL) {};
		iterator operator++() {
			if (obj != NULL) {
				if (obj->next == NULL) obj = head;
				else obj = obj->next;
			}
			return this;
		}
		iterator operator++(int i) {
			if (obj != NULL) {
				if (obj->next == NULL) obj = head;
				else obj = obj->next;
			}
			return this;
		}
		iterator operator+(int i) {
			if (obj == NULL) return NULL;
			Node* zz = obj;
			int z = i;
			while (zz->next != NULL && z > 0) {
				zz = zz->next;
				z--;
			}
			return iterator(zz);
		}
		T operator*()const {
			return obj==NULL?NULL:obj->val;
		}
	};
	iterator begin() {
		return iterator(this->head->next);
	}
};




//��Table�Ļ�����Ԫ
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
				auto it = &(i->second);
				vec[type].erase(i);
				delete it;
				return true;
			}
		}
		return false;
	}
	int bsmall(short type, int val, bool* iffound) {
		auto ve = &vec[type];
		int s = 0;
		int e = vec[type].size();
		if ((*ve).begin()->second >= val) {
			*iffound = false;
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
				e = mid - 1;
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
	int sbig(short type, int val, bool* iffound) {
		auto ve = &vec[type];
		int s = 0;
		int e = vec[type].size();
		if (((*ve).begin() + (*ve).size() - 1)->second <= val) {
			*iffound = false;
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
				s = mid + 1;
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








//����ʱʵ����ӣ���¼������ʵ��Ļ���ʵ����Ϣ����id����
template<class T> class Pool {
private:
	std::map<int, T> con[3];
public:
	void input(short type, T& a) {
		con[type][T.id] = T;
	}

	T& output(short type, int id) {
		auto it = con[type].find(id);
		T tt = it->second;
		con[type].erase(it);
		return tt;
	}

	decltype(auto) getStart(short type) {
		return con[type.begin()];
	}
	decltype(auto) getEnd(short type) {
		return con[type].end();
	}
	T& getElement(int id, short type, bool* iffound)//0plants��1zombies,2bullets
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












//���еģ�Ϊ�˱��ڰ�λ�ò��Ҷ����õ����ݽṹ
class Table {
private:
	TableUnit table[ROWS];
public:
	std::queue<int> search(short type, int rows, int left, int right) {
		std::queue<int> arr;
		if (table[rows].isEmpty(type)) return arr;
		bool iffound;
		auto s = table[rows].getStart(type) + table[rows].bsmall(type, left, &iffound);
		if (iffound) s++;

		auto e = table[rows].getStart(type) + table[rows].sbig(type, right, &iffound);
		if (!iffound) e = table[rows].getEnd(type);
		while (s != e) {
			arr.push(s->first);
			s++;
		}
		return arr;
	}
	int searchFirst(short type, int rows, int left, int right, bool* iffound) {
		if (table[rows].isEmpty(type)) {
			*iffound = false;
			return 0;
		}
		bool iffoun;
		auto s = table[rows].getStart(type);
		int z = table[rows].bsmall(type, left, &iffoun);
		if (iffoun) {
			if (s + z + 1 != table[rows].getEnd(rows) && s->second <= right) {
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
	bool remove(int type, int rows, int id) {
		table[rows].del(type, id);
	};
};





//���ճأ����г���ʵ��ɾ����������EntityUnit����ó��ӣ�Ҫ�õ�ʱ�����ó�����ʼ����������󷴸�����������ռ����Դ��
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






//����ʵ���ͼƬ����Ƶ��Դ��ȫ����Դ�б��
class ResourceManager {
	//IMAGE a;LoadImage(),
private:
	char* name;
	CycleLinkedList<CycleLinkedList<IMAGE>> piclist;
	//CycleLinkedList<> sndlist;
public:
	void init(const char* na) {
		//�ļ�ϵͳ
		char pathh[30];
		strcat(pathh, "pic\\");
		strcat(pathh, name);
		std::filesystem::path pa(pathh);
		if (std::filesystem::exists(pa)) {
			//std::filesystem::directory_entry dir(pa);
			std::filesystem::directory_iterator dirit(pa);
			for (auto& f : dirit) {
				CycleLinkedList<IMAGE> cy;
				std::filesystem::directory_iterator di(f.path());
				for (auto& ff : di) {
					IMAGE img;
					loadimage(&img, ff.path().c_str(), getwidth(), getheight());
					cy.add(img);
				}
				piclist.add(cy);
			}
		}
	}
	decltype(auto) getPicSequence(int type) {
		return piclist.get(type).begin();
	}

};





class GameTickControl {
private:
	static DWORD tick;
	static DWORD last;
	static const DWORD frame = 40;
public:
	static void init() {
		GameTickControl::tick = 0;
	}
	inline static void begin() {
		GameTickControl::last = GetTickCount();
	}
	inline static void end() {
		DWORD z = GetTickCount() - GameTickControl::last - GameTickControl::frame;
		if (z > 0)Sleep(z);
		GameTickControl::tick++;
		GameTickControl::last = GetTickCount();
	}
	inline static DWORD getTick() {
		return GameTickControl::tick;
	}
};



class IDAssignment {
private:
	int id = 0;
public:
	int assignID() {
		return id++;
	}
};



