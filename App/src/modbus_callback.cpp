//-------------------------------------------------------------------------------------------------
//
//  File : modbus_callback.cpp
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------`

#include "./Digini/lib_digini.h"

//-------------------------------------------------------------------------------------------------
// Function(s)
//-------------------------------------------------------------------------------------------------`

void ReadHoldingRegs(const MODBUS_Command_t& Command, MODBUS_Response_t& Response)
{
    // 1 registre → ByteCount = 2
    Response.pPayload[0] = 2;          // ByteCount
    Response.pPayload[1] = 0x12;       // High byte
    Response.pPayload[2] = 0x34;       // Low byte

    Response.Length = 3;               // ByteCount + 2 bytes de data
    Response.IsException = false;
}

void WriteSingleReg(const MODBUS_Command_t& Command, MODBUS_Response_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

void Poutine(const MODBUS_Command_t& Command, MODBUS_Response_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

void WriteMultipleRegs(const MODBUS_Command_t& Command, MODBUS_Response_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

//-------------------------------------------------------------------------------------------------
