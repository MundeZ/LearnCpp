#include <iostream>
#include <string>
#include <thread>
#include <mutex>


std::mutex mutex;

void pinger() {
	for (size_t i = 0; i < 3; i++) {
		mutex.lock();
		std::cout << "Ping" << std::endl;
		mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void ponger() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	for (size_t i = 0; i < 3; i++) {
		mutex.lock();
		std::cout << "Pong" << std::endl;
		mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main()
{

	std::thread t1(pinger);
	std::thread t2(ponger);

	t1.join();
	t2.join();

}

