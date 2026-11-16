/*
 * operationThread.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#ifndef APPLICATION_INCLUDE_OPERATIONTHREAD_HPP_
#define APPLICATION_INCLUDE_OPERATIONTHREAD_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "app_freertos.h"
#include "logThread.hpp"

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

class operationThread{
	private:
		float temperatureCal(uint32_t raw);
		operationThread() {};
		~operationThread(){};
	public:

	operationThread(const operationThread&) = delete;

	operationThread& operator=(const operationThread&) = delete;

	static operationThread& getInstance();

	void run();
};

#endif

#endif /* APPLICATION_INCLUDE_OPERATIONTHREAD_H_ */
