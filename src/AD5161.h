/** I2C multiplexer and switch operation library for Arduino
 *
 *  @author Tedd OKANO
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_AD5161_H
#define ARDUINO_AD5161_H

#include <Arduino.h>
#include <stdint.h>

#include <I2C_device.h>
#include <SPI.h>


/** AD5161 class
 *	
 *  @class AD5161_I2C
 *
 */

class AD5161_base
{
public:
	AD5161_base();
	virtual ~AD5161_base();
	
	/** Begin the device operation
	 *
	 *	Dummy
	 */
	virtual	void begin( void );
};

class AD5161_I2C : public AD5161_base, public I2C_device
{
public:
	/** Create a AD5161_I2C instance with specified address
	 *
	 * @param i2c_address I2C-bus address (default: (0xE2>>1))
	 */
	AD5161_I2C( uint8_t i2c_address = (0x5A >> 1) );

	/** Create a AD5161_I2C instance with specified address
	 *
	 * @param wire TwoWire instance
	 * @param i2c_address I2C-bus address (default: (0xE2>>1))
	 */
	AD5161_I2C( TwoWire& wire, uint8_t i2c_address = (0xE2 >> 1) );
	virtual ~AD5161_I2C();
	
	/** Set value
	 *
	 * @param v for potentiometer position
	 */
	void value( uint8_t v );	

	/** Get value
	 *
	 * @return potentiometer position
	 */
	uint8_t value( void );	
};

class AD5161_SPI : public AD5161_base
{
public:
	/** Create a AD5161_SPI instance with specified address
	 *
	 * @param i2c_address I2C-bus address (default: (0xE2>>1))
	 */
	AD5161_SPI();
	virtual ~AD5161_SPI();

	/** Set/Get value
	 *
	 * @param v for potentiometer position
	 * @return potentiometer position
	 */
	uint8_t value( uint8_t v );	
	
	/** Send/receive data
	 * 
	 * @param data pointer to data buffer
	 * @param size data size
	 */
	void txrx( uint8_t *data, int size );

};

#endif //	ARDUINO_AD5161_H
