// Deadlock: two threads acquire two mutexes in opposite order
// Thread ONE: locks mtx_A then mtx_B
// Thread TWO: locks mtx_B then mtx_A
// Run this — the program WILL hang

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx_A;
std::mutex mtx_B;

void thread_one_entry(void);
void thread_two_entry(void);

int main(void)
{
	std::thread t1(thread_one_entry);
	std::thread t2(thread_two_entry);

	t1.join();
	t2.join();

	std::cout << "This line will never be reached" << std::endl;

	return (0);
}

void thread_one_entry(void)
{
	while (true)
	{
		mtx_A.lock();
		std::cout << "Thread ONE: acquired mtx_A, waiting for mtx_B..." << std::endl;

		// Sleep to widen the deadlock window — makes it nearly guaranteed
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		mtx_B.lock();
		std::cout << "Thread ONE: acquired both" << std::endl;

		mtx_B.unlock();
		mtx_A.unlock();
	}
}

void thread_two_entry(void)
{
	while (true)
	{
		mtx_B.lock();
		std::cout << "Thread TWO: acquired mtx_B, waiting for mtx_A..." << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		mtx_A.lock();
		std::cout << "Thread TWO: acquired both" << std::endl;

		mtx_A.unlock();
		mtx_B.unlock();
	}
}
