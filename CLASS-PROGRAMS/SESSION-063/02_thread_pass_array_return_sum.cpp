// Parent sends array to child thread, child computes sum and returns it

#include <iostream>
#include <thread>

void compute_sum(int arr[], int size, int& result);

int main(void)
{
	int arr[] = {10, 20, 30, 40, 50};
	int sum = 0;

	std::thread t1(compute_sum, arr, 5, std::ref(sum));
	t1.join();

	std::cout << "Sum returned by child thread: " << sum << std::endl;

	return (0);
}

void compute_sum(int arr[], int size, int& result)
{
	result = 0;
	for (int i = 0; i < size; i++)
		result = result + arr[i];

	std::cout << "Child thread [" << std::this_thread::get_id() << "] computed sum: " << result << std::endl;
}
