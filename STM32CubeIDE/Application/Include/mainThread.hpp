/*
 * mainThread.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#ifndef APPLICATION_INCLUDE_MAINTHREAD_HPP_
#define APPLICATION_INCLUDE_MAINTHREAD_HPP_



#include "app_freertos.h"

#ifdef __cplusplus

class mainThread
{
	private:
		mainThread(){};
		~mainThread(){};
	public:
		// 1. Delete copy constructor to prevent cloning
		mainThread(const mainThread&) = delete;

		// 2. Delete assignment operator to prevent overwriting
		mainThread& operator=(const mainThread&) = delete;

		// 3. The only public access point to get the instance
		static mainThread& getInstance();

		void run();
};

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_INCLUDE_MAINTHREAD_H_ */
