#include "AD5161.h"

AD5161_base::AD5161_base(){}
AD5161_base::~AD5161_base(){}
void AD5161_base::begin( void ){}

AD5161_I2C::AD5161_I2C( uint8_t i2c_address ) : AD5161_base(), I2C_device( i2c_address ){}
AD5161_I2C::~AD5161_I2C(){}

void AD5161_I2C::value( uint8_t v )
{
	uint8_t	data[ 2 ];
	data[ 0 ]	= 0x00;
	data[ 1 ]	= v;
	
	tx( data, 2 );
}

uint8_t AD5161_I2C::value( void )
{
	uint8_t data;
	rx( &data, 1 );
	
	return data;
}

AD5161_SPI::AD5161_SPI() : AD5161_base(){}
AD5161_SPI::~AD5161_SPI(){}

uint8_t AD5161_SPI::value( uint8_t v )
{
	uint8_t	r;
	
	SPI.beginTransaction( SPISettings( 1000000, MSBFIRST, SPI_MODE0 ) );
	digitalWrite( SS, LOW );
	r	= SPI.transfer( v );
	digitalWrite( SS, HIGH );
	
	return r;
}
