#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
#include "basic.h"
class EventProcessor{
public:
	static void pushEvent(Pevent ev) {
		mut0.lock();
		list.push(ev);
		mut0.unlock();
		mut1.notify_all();
	}
	//to-do
	static void process() {
		while (true) {
			while (!list.empty()) {
				mut0.lock();
				//handle
				mut0.unlock();
			}
			//mut1.wait()
		}
	}
	//to-do
	static void init() {
		//thread.detach();
	}
private:
	//to-do
	static std::queue<Pevent> list;
	static std::mutex mut0;//¿ØÖÆlistµÄ
	static std::condition_variable mut1;
	static std::thread(process);
};
//to-do
class ChangeTable {
private:
	static std::queue<Change> que;
public:
	/*static void add(Change a) {
		que.push(a);
	}*/
	//static handle
};