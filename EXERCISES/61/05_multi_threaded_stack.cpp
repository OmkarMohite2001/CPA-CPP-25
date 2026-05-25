// Multi-threaded stack: C++ threads conversion
// Each stack instance owns its mutex — same kernel-object design as the C version

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define SUCCESS			1
#define TRUE			1
#define FALSE			0
#define STACK_FULL		2
#define STACK_EMPTY		3
#define NR_OPERATIONS	15000

#define PUSH		0
#define TOP			1
#define IS_EMPTY	2
#define POP			3

#define NR_MAX_THREADS		10
#define NR_DEFAULT_THREADS	5

typedef int data_t;
typedef int status_t;

typedef struct thread_safe_stack
{
	data_t* pa;
	int size;
	int top_index;
	std::mutex mtx;
} thread_safe_stack_t;

thread_safe_stack_t* create_thread_safe_stack(int size);
status_t push(thread_safe_stack_t* p_stack, data_t new_data);
status_t top(thread_safe_stack_t* p_stack, data_t* p_top_data);
status_t pop(thread_safe_stack_t* p_stack, data_t* p_pop_data);
status_t is_empty(thread_safe_stack_t* p_stack);
status_t destroy_thread_safe_stack(thread_safe_stack_t* p_stack);
void thread_function(thread_safe_stack_t* p_stack);

int main(int argc, char* argv[])
{
	int nr_threads = 0;
	int i;
	thread_safe_stack_t* p_stack = nullptr;

	if (argc != 2)
	{
		std::cerr << "Usage Error:" << argv[0] << " number of threads" << std::endl;
		exit(EXIT_FAILURE);
	}

	nr_threads = atoi(argv[1]);
	if (nr_threads <= 0)
		nr_threads = NR_DEFAULT_THREADS;
	if (nr_threads > NR_MAX_THREADS)
		nr_threads = NR_MAX_THREADS;

	p_stack = create_thread_safe_stack(10);

	std::thread* thread_arr = new std::thread[nr_threads];

	for (i = 0; i < nr_threads; ++i)
		thread_arr[i] = std::thread(thread_function, p_stack);

	for (i = 0; i < nr_threads; ++i)
		thread_arr[i].join();

	destroy_thread_safe_stack(p_stack);
	p_stack = nullptr;

	delete[] thread_arr;
	thread_arr = nullptr;

	return (0);
}

void thread_function(thread_safe_stack_t* p_stack)
{
	static std::mutex stdout_mtx;
	int i;
	int new_element, top_data, pop_data;
	status_t status;

	// XOR with thread ID hash to diversify across threads
	std::hash<std::thread::id> hasher;
	srand((unsigned int)(time(nullptr) ^ hasher(std::this_thread::get_id())));

	for (i = 0; i < NR_OPERATIONS; ++i)
	{
		switch (rand() % 4)
		{
		case PUSH:
			new_element = rand() % 10000;
			status = push(p_stack, new_element);
			if (status == STACK_FULL)
			{
				stdout_mtx.lock();
				std::cout << std::this_thread::get_id() << ":PUSH:stack is full" << std::endl;
				stdout_mtx.unlock();
				break;
			}
			stdout_mtx.lock();
			std::cout << std::this_thread::get_id() << ":PUSH:" << new_element << std::endl;
			stdout_mtx.unlock();
			break;

		case TOP:
			status = top(p_stack, &top_data);
			if (status == STACK_EMPTY)
			{
				stdout_mtx.lock();
				std::cout << std::this_thread::get_id() << ":TOP:stack is empty" << std::endl;
				stdout_mtx.unlock();
				break;
			}
			stdout_mtx.lock();
			std::cout << std::this_thread::get_id() << ":TOP:" << top_data << std::endl;
			stdout_mtx.unlock();
			break;

		case POP:
			status = pop(p_stack, &pop_data);
			if (status == STACK_EMPTY)
			{
				stdout_mtx.lock();
				std::cout << std::this_thread::get_id() << ":POP:stack is empty" << std::endl;
				stdout_mtx.unlock();
				break;
			}
			stdout_mtx.lock();
			std::cout << std::this_thread::get_id() << ":POP:" << pop_data << std::endl;
			stdout_mtx.unlock();
			break;

		case IS_EMPTY:
			status = is_empty(p_stack);
			stdout_mtx.lock();
			if (status)
				std::cout << std::this_thread::get_id() << ":IS_EMPTY:TRUE" << std::endl;
			else
				std::cout << std::this_thread::get_id() << ":IS_EMPTY:FALSE" << std::endl;
			stdout_mtx.unlock();
			break;
		}
	}
}

thread_safe_stack_t* create_thread_safe_stack(int size)
{
	thread_safe_stack_t* p_stack = nullptr;

	if (size <= 0)
	{
		std::cerr << "Bad size of stack" << std::endl;
		exit(EXIT_FAILURE);
	}

	p_stack = new thread_safe_stack_t;

	p_stack->pa = new data_t[size];
	memset(p_stack->pa, 0, size * sizeof(data_t));
	p_stack->size = size;
	p_stack->top_index = -1;
	// std::mutex is default-constructed — no explicit init needed

	return (p_stack);
}

status_t push(thread_safe_stack_t* p_stack, data_t new_data)
{
	p_stack->mtx.lock();
	if (p_stack->top_index + 1 == p_stack->size)
	{
		p_stack->mtx.unlock();
		return (STACK_FULL);
	}

	p_stack->top_index += 1;
	p_stack->pa[p_stack->top_index] = new_data;

	p_stack->mtx.unlock();
	return (SUCCESS);
}

status_t top(thread_safe_stack_t* p_stack, data_t* p_top_data)
{
	p_stack->mtx.lock();
	if (p_stack->top_index == -1)
	{
		p_stack->mtx.unlock();
		return (STACK_EMPTY);
	}

	*p_top_data = p_stack->pa[p_stack->top_index];
	p_stack->mtx.unlock();

	return (SUCCESS);
}

status_t pop(thread_safe_stack_t* p_stack, data_t* p_pop_data)
{
	p_stack->mtx.lock();
	if (p_stack->top_index == -1)
	{
		p_stack->mtx.unlock();
		return (STACK_EMPTY);
	}

	*p_pop_data = p_stack->pa[p_stack->top_index];
	p_stack->top_index -= 1;

	p_stack->mtx.unlock();

	return (SUCCESS);
}

status_t is_empty(thread_safe_stack_t* p_stack)
{
	status_t status;
	p_stack->mtx.lock();
	status = (p_stack->top_index == -1);
	p_stack->mtx.unlock();
	return (status);
}

status_t destroy_thread_safe_stack(thread_safe_stack_t* p_stack)
{
	delete[] p_stack->pa;
	// std::mutex destructor handles cleanup — no explicit destroy needed
	delete p_stack;
	return (SUCCESS);
}
