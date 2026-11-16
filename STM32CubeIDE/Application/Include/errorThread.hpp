/*
 * errorThread.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Celin
 */

#ifndef APPLICATION_INCLUDE_ERRORTHREAD_HPP_
#define APPLICATION_INCLUDE_ERRORTHREAD_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "app_freertos.h"

void errorItrCSend(uint32_t *pData);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

class errorThread{
public:
	errorThread(const errorThread&) = delete;

	errorThread& operator=(const errorThread&) = delete;

	static errorThread& getInstance();

	void errorSend(uint32_t *pData);
	void errorItrSend(uint32_t *pData);
	void run();
private:
	errorThread(){};
	~errorThread(){};
};


#endif

#endif /* APPLICATION_INCLUDE_ERRORTHREAD_H_ */
