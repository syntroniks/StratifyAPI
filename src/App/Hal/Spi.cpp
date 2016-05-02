//Copyright 2011-2016 Tyler Gilbert; All Rights Reserved

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "Hal/Spi.hpp"
using namespace Hal;

Spi::Spi(port_t port) : Periph(CORE_PERIPH_SPI, port){}


int Spi::attr(spi_attr_t * attr){
	return ioctl(I_SPI_GETATTR, attr);
}

int Spi::setattr(const spi_attr_t * attr){
	return ioctl(I_SPI_SETATTR, attr);
}

int Spi::swap(int byte){
	return ioctl(I_SPI_SWAP, byte);
}

int Spi::setduplex(void * buf){
	return ioctl(I_SPI_SETDUPLEX, buf);
}

