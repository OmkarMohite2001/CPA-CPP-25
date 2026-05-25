// Two threads, same entry point, shared global + local variable
// Mutex protects g_counter and std::cout (both shared resources)

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int g_counter = 0;
std::mutex g_mtx;

void thread_entry(const char* thread_name);

int main(void)
{
	std::thread t1(thread_entry, "Thread ONE");
	std::thread t2(thread_entry, "Thread TWO");

	t1.join();
	t2.join();

	return (0);
}

void thread_entry(const char* thread_name)
{
	int local_counter = 0;

	while (true)
	{
		g_mtx.lock();

		g_counter = g_counter + 1;
		local_counter = local_counter + 1;

		std::cout << thread_name
				  << " | ID: " << std::this_thread::get_id()
				  << " | Global: " << g_counter
				  << " | Local: " << local_counter
				  << std::endl;

		g_mtx.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
