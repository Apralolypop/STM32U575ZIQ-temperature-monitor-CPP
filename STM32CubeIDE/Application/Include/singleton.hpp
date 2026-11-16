#ifndef SINGLETON_IDKSMTH_HPP
#define SINGLETON_IDKSMTH_HPP

#include "stdio.h"
#include <stdint.h>

#ifdef __cplusplus

class singleton{
	private:
		uint32_t randomvar;

		uint32_t getRandomvar();
		void setRandomvar(uint32_t);

		singleton(){};
		~singleton(){};
	public:
		singleton(const singleton&) = delete;
		singleton& operator=(const singleton&) = delete;
		static singleton& getInstance();

		void run();
};

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
