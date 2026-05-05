//-------------------------------------------------------------------------------------------------
//
//  File :  modbus_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2026 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define MODBUS_MAX_BACKENDS                         1   // Only one backend on this project (RTU)

#define MODBUS_MAX_SLAVE_COMMAND_ENTRY  			20
#define MODBUS_MAX_MASTER_REQUEST_ENTRY  			20

#define MODBUS_USE_ROUTER_PASSTHRU                  DEF_DISABLED
#define MODBUS_MAX_PASSTHRU_RULES 		            10  // Maximum number of MODBUS routing entries (address/function/handler)

//-------------------------------------------------------------------------------------------------

// Digini default MODBUS_RTU configuration
#define MODBUS_RTU_IO_RE_DE_CONTROL_PIN             IO_RS485_DE				// see bsp_io_def.h
#define MODBUS_RTU_UART							    &RS485_Modbus			// see uart_var.h
#define MODBUS_RTU_SLAVE_ID                         1
#define MODBUS_RTU_MIN_ADDRESS					    100
#define MODBUS_RTU_MAX_ADDRESS					    220

//-------------------------------------------------------------------------------------------------

#define MODBUS_APP_SLAVE_TABLE(ENTRY) 								    	    \
    ENTRY(1, MODBUS_READ_HOLDING_REGISTERS, 	200,	1,  ReadHoldingRegs) 	\
    ENTRY(1, MODBUS_WRITE_SINGLE_REGISTER, 	    201, 	1,  WriteSingleReg) 	\
    ENTRY(1, MODBUS_READ_HOLDING_REGISTERS, 	202, 	1,  Poutine) 			\
    ENTRY(1, MODBUS_WRITE_MULTIPLE_REGISTERS, 	203, 	1,  WriteMultipleRegs)

//-------------------------------------------------------------------------------------------------
// Master has no ID it request to a slave
#define MODBUS_APP_MASTER_TABLE(ENTRY) 							        	          \
	ENTRY(1, MODBUS_READ_HOLDING_REGISTERS,     109, 	6,  1000, ReadMainGUI_ID)     \
	ENTRY(1, MODBUS_READ_HOLDING_REGISTERS,     126, 	2,  1000, ReadIP_Address)     \
	ENTRY(1, MODBUS_READ_HOLDING_REGISTERS,     130, 	3,  1000, ReadMAC_Address)    \

//-------------------------------------------------------------------------------------------------

// Passthrough rules used by the Modbus router. Each entry rewrites the slave address
// before forwarding the command (SourceAddress → DestinationAddress).
// MODBUS_USE_ROUTER_PASSTHRU must be enabled.
#define MODBUS_ROUTER_PASSTHRU_TABLE(ENTRY) \
    ENTRY(101, 201) \
    ENTRY(102, 202)
//-------------------------------------------------------------------------------------------------


