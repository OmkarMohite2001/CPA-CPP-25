// Two threads, same entry point, shared global + local variable, no synchronization
// Precursor to synchronization: observe inconsistent global variable behaviour

#include <iostream>
#include <thread>
#include <chrono>

int g_counter = 0;

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
		g_counter = g_counter + 1;
		local_counter = local_counter + 1;

		std::cout << thread_name
				  << " | ID: " << std::this_thread::get_id()
				  << " | Global: " << g_counter
				  << " | Local: " << local_counter
				  << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
