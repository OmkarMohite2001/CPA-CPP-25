// Deadlock fix: std::scoped_lock acquires multiple mutexes atomically
// Uses deadlock avoidance algorithm internally — order doesn't matter

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

	return (0);
}

void thread_one_entry(void)
{
	while (true)
	{
		{
			// scoped_lock acquires BOTH mutexes without deadlock
			std::scoped_lock lock(mtx_A, mtx_B);

			std::cout << "Thread ONE: acquired both mutexes" << std::endl;

			// scoped_lock releases both at scope exit
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void thread_two_entry(void)
{
	while (true)
	{
		{
			// Same two mutexes, different order — still safe
			std::scoped_lock lock(mtx_B, mtx_A);

			std::cout << "Thread TWO: acquired both mutexes" << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
