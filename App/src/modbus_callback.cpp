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

char GuiID[12];
char IP_Address[16];   // max "255.255.255.255" + '\0'
char MAC_Address[18];   // 17 chars + '\0'


uint16_t Register[16] =
{
    0x0000,
    0x1111,
    0x2222,
    0x3333,
    0x4444,
    0x5555,
    0x6666,
    0x7777,
    0x8888,
    0x9999,
    0xAAAA,
    0xBBBB,
    0xCCCC,
    0xDDDD,
    0xEEEE,
    0xFFFF
};



/* Example
void ReadHoldingRegs(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
    // Table locale des sources
    const uint16_t* Table[] =
    {
        &Reg_A, // 200
        &Reg_B, // 201
        &Reg_C, // 202
        &Reg_D  // 203
    };

    const uint16_t Offset = Command.Address - 200;

    // ByteCount = Quantity * 2
    Response.pPayload[0] = Command.Quantity * 2;

    uint8_t* pOut = &Response.pPayload[1];

    for(uint16_t i = 0; i < Command.Quantity; i++)
    {
        uint16_t value = *Table[Offset + i];
        pOut[i*2 + 0] = value >> 8;
        pOut[i*2 + 1] = value & 0xFF;
    }

    Response.PayloadLength = 1 + (Command.Quantity * 2);
    Response.IsException   = false;
}

void ReadHoldingRegs(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
    const uint16_t* pBase = (const uint16_t*)&Register;

    const uint16_t Offset = Command.Address - 200;

    // ByteCount = Quantity * 2
    Response.pPayload[0] = Command.Quantity * 2;

    uint8_t* pOut = &Response.pPayload[1];

    for(uint16_t i = 0; i < Command.Quantity; i++)
    {
        uint16_t value = pBase[Offset + i];
        pOut[i*2 + 0] = value >> 8;
        pOut[i*2 + 1] = value & 0xFF;
    }

    Response.PayloadLength = 1 + (Command.Quantity * 2);
    Response.IsException   = false;
}

*/

void ReadHoldingRegs(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
    const uint16_t* pBase = (const uint16_t*)&Register;

    const uint16_t Offset = Command.Address - 200;

    // ByteCount = Quantity * 2
    Response.pPayload[0] = Command.Quantity * 2;

    uint8_t* pOut = &Response.pPayload[1];

    for(uint16_t i = 0; i < Command.Quantity; i++)
    {
        uint16_t value = pBase[Offset + i];
        pOut[i*2 + 0] = value >> 8;
        pOut[i*2 + 1] = value & 0xFF;
    }

    Response.PayloadLength = 1 + (Command.Quantity * 2);
    Response.IsException   = false;
}

void WriteSingleReg(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

void Poutine(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

void WriteMultipleRegs(const MODBUS_Command_t& Command, MODBUS_SlaveResponse_t& Response)
{
	//Response.Payload[0] = ByteCount;
	//Response.Payload[1] = HighByte;
	//Response.Payload[2] = LowByte;
	//Response.Length = 3;
}

void ReadMainGUI_ID(const MODBUS_MasterResponse_t& Response)
{
    // We expect 6 bytes of data → ByteCount = 6
    if(Response.PayloadLength < 8)   // 1 func + 1 bytecount + 6 data
    {
        return;
	}

    const uint8_t* pData = &Response.pPayload[2]; // début des 6 bytes

    // Convert 6 bytes into 12 hex character
    for(int i = 0; i < 6; i++)
    {
        sprintf(&GuiID[i * 2], "%02X", pData[i]);
    }

    GuiID[12] = '\0'; // null-terminate
}

void ReadIP_Address(const MODBUS_MasterResponse_t& Response)
{
    // Response.pPayload[0] = Function
    // Response.pPayload[1] = ByteCount (should be 4)
    // Response.pPayload[2..5] = 4 bytes of IP

    if(Response.PayloadLength < 6)   // 1 func + 1 bytecount + 4 data
	{
        return;
	}

    const uint8_t* p = &Response.pPayload[2];

    // Format: A.B.C.D
    snprintf(IP_Address, sizeof(IP_Address), "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
}

void ReadMAC_Address(const MODBUS_MasterResponse_t& Response)
{
    // Expect 6 bytes of MAC
    if(Response.PayloadLength < 8)   // 1 func + 1 bytecount + 6 data
    {
		return;
	}

    const uint8_t* p = &Response.pPayload[2];
    snprintf(MAC_Address, sizeof(MAC_Address), "%02X:%02X:%02X:%02X:%02X:%02X", p[0], p[1], p[2], p[3], p[4], p[5]);
}

void TestQT(const MODBUS_MasterResponse_t& Response)
{
    __asm("nop");
}


//-------------------------------------------------------------------------------------------------
