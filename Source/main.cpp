#include "../Header/TaskPool.h"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
	TaskPool threadPool;
	threadPool.init();

	Task* task = NULL;
	for (int i = 0; i < 10; ++i) {
		task = new Task();
		threadPool.addTask(task);
	}
	std::this_thread::sleep_for(std::chrono::seconds(5));

	threadPool.stop();

	return 0;
}
