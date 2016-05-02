//Copyright 2011-2016 Tyler Gilbert; All Rights Reserved

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "Hal/Dac.hpp"
using namespace Hal;

Dac::Dac(port_t port) : Periph(CORE_PERIPH_DAC, port){}

int Dac::attr(dac_attr_t * attr){
	return ioctl(I_DAC_GETATTR, attr);
}

int Dac::setattr(const dac_attr_t * attr){
	return ioctl(I_DAC_SETATTR, attr);
}

dac_sample_t Dac::value(uint32_t channel){
	dac_reqattr_t attr;
	attr.channel = channel;
	ioctl(I_DAC_VALUE, &attr);
	return attr.value;
}

int Dac::set(dac_sample_t value, uint32_t channel){
	dac_reqattr_t attr;
	attr.channel = channel;
	attr.value = value;
	return ioctl(I_DAC_SET, &attr);
}


