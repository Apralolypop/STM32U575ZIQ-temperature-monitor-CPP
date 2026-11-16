/*
 * singleton.hpp
 *
 *  Created on: Aug 24, 2026
 *      Author: Celin
 */
#include "singleton.hpp"

#include "app_freertos.h"

singleton& singleton::getInstance(){
	static singleton instance;
	return instance;
}

uint32_t singleton::getRandomvar(){
	return  randomvar;
}

void singleton::setRandomvar(uint32_t input){
	randomvar = input;
}

void singleton::run(){
	for(;;){
		setRandomvar((getRandomvar() + 1));
		if(getRandomvar() > 10000){
			setRandomvar(0);
		}
	}
}

void singletonThreadEntry(void *argument){
	singleton::getInstance().run();
}
