// std::unique_lock — flexible RAII lock with deferred locking and manual control
// Demonstrates: deferred lock, manual lock/unlock, ownership transfer

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex g_mtx;
int g_counter = 0;

void deferred_locking_demo(const char* thread_name);
void ownership_transfer_demo(void);

int main(void)
{
	std::cout << "=== Deferred Locking ===" << std::endl;

	std::thread t1(deferred_locking_demo, "Thread ONE");
	std::thread t2(deferred_locking_demo, "Thread TWO");

	t1.join();
	t2.join();

	std::cout << "\n=== Ownership Transfer ===" << std::endl;

	std::thread t3(ownership_transfer_demo);
	t3.join();

	return (0);
}

void deferred_locking_demo(const char* thread_name)
{
	for (int i = 0; i < 5; ++i)
	{
		// Construct without locking — mutex is associated but NOT acquired
		std::unique_lock<std::mutex> lock(g_mtx, std::defer_lock);

		// Do non-critical work here (no lock held)
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		// Now explicitly acquire when needed
		lock.lock();

		g_counter = g_counter + 1;
		std::cout << thread_name << " | Global: " << g_counter << std::endl;

		// Can manually unlock before scope exit
		lock.unlock();

		// More non-critical work (lock already released)
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void ownership_transfer_demo(void)
{
	std::unique_lock<std::mutex> lock1(g_mtx);
	std::cout << "lock1 owns mutex: " << lock1.owns_lock() << std::endl;

	// Transfer ownership via move — lock1 no longer owns the mutex
	std::unique_lock<std::mutex> lock2 = std::move(lock1);
	std::cout << "lock1 owns mutex: " << lock1.owns_lock() << std::endl;
	std::cout << "lock2 owns mutex: " << lock2.owns_lock() << std::endl;

	// lock2 destructor releases the mutex
}
