#include "queue"
#include "list"
#include <mutex>
#include <thread>
#include <random>
#include <memory>
#include <string>
#include <iostream>
#include <condition_variable>

using namespace std;


// структура детали
typedef struct Part {
	int part_id;
	float volume;
	typedef shared_ptr<struct Part> PartPtr; // умный указатель
} Part;


static bool done = false;
static bool done2 = false;
queue<Part::PartPtr> shared_queue;
mutex lock_queue;
mutex lock_cout;
queue<Part::PartPtr> shared_queue2;
mutex lock_queue2;

condition_variable event_holder;

void locked_output(const std::string& str) {
	lock_guard<mutex> raii(lock_cout);
	cout << str << endl;
}

void threadAwork(Part::PartPtr& part) {
	part->volume -= 3;
	std::this_thread::sleep_for(std::chrono::milliseconds(500 + rand() % 6000));

	locked_output("threadAwork finished with part " + to_string(part->part_id));
}

void threadBwork(Part::PartPtr& part) {
	part->volume -= 2;
	std::this_thread::sleep_for(std::chrono::milliseconds(500 + rand() % 6000));

	locked_output("threadBwork finished with part " + to_string(part->part_id));
}

void threadCwork(Part::PartPtr& part) {
	part->volume -= 0.5;
	this_thread::sleep_for(chrono::milliseconds(500 + rand() % 6000));
	locked_output("threadCwork finished with part " + to_string(part->part_id));
}


void threadA(list<Part::PartPtr>& input) {
	srand(77777);
	size_t size = input.size();
	for (size_t i = 0; i < size; i++) {
		// обрабатываем деталь
		threadAwork(*input.begin());
		// кладём в очередь
		{
			lock_guard<mutex> raii_obj(lock_queue);
			shared_queue.push(Part::PartPtr(*input.begin()));
			input.remove(*input.begin());
			locked_output("Part was added to queue");
			event_holder.notify_one();
		}
	}
	done = true;
	event_holder.notify_one();
}

void threadB() {
	srand(1000000);
	while (true) {
		list<Part::PartPtr> parts_for_work;
		{
			unique_lock<mutex> m_holder(lock_queue);

			if (done && shared_queue.empty()) break;

			if (shared_queue.empty()) {
				event_holder.wait(m_holder, []() { return !shared_queue.empty() || done; });
			}
			for (size_t i = 0; i < shared_queue.size(); i++)
			{
				parts_for_work.push_back(shared_queue.front());
				shared_queue.pop();
			}
			locked_output("Parts were removed from queue");
		}
		for (auto& p : parts_for_work)
			threadBwork(p);
	}
}

void threadC() {
	srand(5555555);
	while (true) {
		Part::PartPtr part_for_work;
		{
			lock_queue2.lock();
			if (shared_queue2.empty()) {
				lock_queue2.unlock();
				if (done2) break;
				locked_output("threadC useless check, queue is empty. Going to bed");
				this_thread::sleep_for(chrono::milliseconds(1000));
				continue;
			}
			else {
				part_for_work = shared_queue2.front();
				shared_queue2.pop();
				lock_queue2.unlock();
			}
		}
		threadCwork(part_for_work);
	}
}

int main()
{

	list<Part::PartPtr> spare_parts;
	for (int i = 0; i < 5; i++) {
		spare_parts.push_back(Part::PartPtr(new Part{ i + 1, 10.0 }));
	}
	// запуск потоков
	thread ta(threadA, std::ref(spare_parts));
	thread tb(threadB);
	thread tc(threadC);
	// ждем завершения
	ta.join();
	tb.join();
	tc.join();

	locked_output("done");
	return 0;
}
