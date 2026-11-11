#include "eventbus/AsyncEventBus.h"

namespace eventbus {

	std::size_t AsyncEventBus::processCommandsAndGetQueuedEventsCount() {
		std::lock_guard lock{event_mutex};

		while (!_commandsQueue.empty()) {
			_commandsQueue.front()();
			_commandsQueue.pop_front();
		};

		return _eventQueue.size();
	};

	int AsyncEventBus::consume(int max) {
		int consumed = 0;
		std::function<void()> event_command;

		while(processCommandsAndGetQueuedEventsCount() > 0 && consumed < max) {
			{
				std::lock_guard<std::mutex> lock{event_mutex};

				event_command = std::move(_eventQueue.front());
				_eventQueue.pop_front();
			}

			event_command();
			++consumed;
		};

		return consumed;
	};

	bool AsyncEventBus::wait() {
		std::unique_lock<std::mutex> lock{wait_mutex};
		_eventWaiting.wait(lock);

		return !_eventQueue.empty();
	};

	bool AsyncEventBus::waitFor(std::chrono::milliseconds timeout) {
		std::unique_lock<std::mutex> lock{wait_mutex};
		_eventWaiting.wait_for(lock, timeout);

		return !_eventQueue.empty();
	};

};