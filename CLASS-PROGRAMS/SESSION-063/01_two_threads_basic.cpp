// Two threads with separate entry point functions, each printing its thread ID

#include <iostream>
#include <thread>
#include <chrono>

void thread_entry_one(void);
void thread_entry_two(void);

int main(void)
{
	std::thread t1(thread_entry_one);
	std::thread t2(thread_entry_two);

	t1.join();
	t2.join();

	return (0);
}

void thread_entry_one(void)
{
	while (true)
	{
		std::cout << "Thread ONE | ID: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void thread_entry_two(void)
{
	while (true)
	{
		std::cout << "Thread TWO | ID: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
