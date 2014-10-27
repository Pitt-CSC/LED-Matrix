///////////////////////////////////////////////////////////
// Protocol.h
// 
// This simply holds all of the constants for communication
// between the BeagleBone and the Arduino.
///////////////////////////////////////////////////////////

#if !defined(PROTOCOL_H)
#define PROTOCOL_H

// BeagleBone constants
const char BB_INIT_ARD = 0x01
const char BB_CHECK_ERR = 0x02
const char BB_CLOSE = 0x03
const char BB_FULLSCR_TX = 0x04
const char BB_TX_FSCR = 0x05
const char BB_FSCR_END = 0x06

// Arduino constants
const char ARD_CONFIRM = 0x01
const char ARD_INITED = 0x02
const char ARD_NO_ERR = 0x03

// Arduino errors
const char ARD_MATRIX_FAILURE = 0x81
const char ARD_BAD_TX = 0x82

#endif		// if !defined(PROTOCOL_H)