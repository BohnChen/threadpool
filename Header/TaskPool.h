/**
 * TaskPool.h
 * 跟学《C++ 服务器开发精髓》
 */
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <vector>
#include <memory>
#include <iostream>

#include <functional>

class Task
{
	public:
		virtual void doIt()
		{
			std::cout << "handle a task..." << std::endl;
		}

		virtual ~Task()
		{
			// Display the destroy course.
			std::cout << "a task destructed..." << std::endl;
		}
};


class TaskPool final
{
	public:
		TaskPool();
		~TaskPool();
		TaskPool(const TaskPool& rhs) = delete;
		TaskPool& operator = (const TaskPool& rhs) = delete;

	public:
		void init(int threadNum = 5);
		void stop();

		void addTask(Task* task);
		void removeAllTasks();


	private:
		void threadFunc();

	private:
		std::list<std::shared_ptr<Task>>						m_taskList;
		std::mutex																	m_mutexList;
		std::condition_variable											m_cv;
		bool																				m_bRunning;
		std::vector<std::shared_ptr<std::thread>>		m_threads;
};
