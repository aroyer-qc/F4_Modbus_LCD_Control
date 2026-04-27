//-------------------------------------------------------------------------------------------------
//
//  File : vt100_user_callback.cpp
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
// For all callback function here:
//
// Parameter Type
//
//
//         VT100_CALLBACK_INIT     -> Initialize part of the display in the menu, or variables in use
//                                  while in menu.
//
//                                  It is called only once when then menu is being draw item by
//                                  item.
//
//         VT100_CALLBACK_ON_INPUT -> This call is made when a key that select an item in the menu is
//                                  pressed.
//
//                                  If it is used for a display page with static or dynamic
//                                  informations, you need to return with a VT100_INPUT_ESCAPE.
//
//                                  If it is used for a modification in the actual menu, you only
//                                  perform the action and then return with the VT100_INPUT_MENU_CHOICE
//                                  to wait for a new input.
//
//         VT100_CALLBACK_REFRESH  -> Called while waiting for any key to be pressed. Use this to
//                                  refresh displayed information.
//                                  NOTE: There is no VT100_CALLBACK_REFRESH called if
//                                        VT100_INPUT_MENU_CHOICE is returned. UNLESS: you put a
//                                        callback in Option 0 of the menu list
//
//         VT100_CALLBACK_FLUSH    -> If variables need to be reset or function need to be called to
//                                  reset some app state. each existing callback will be called
//                                  leaving a menu.
//                                  Do not use any malloc function in the process of
//                                  VT100_CALLBACK_INIT/VT100_CALLBACK_FLUSH unless you manage that it
//                                  might already exist.
//
// return VT100_InputType_e     Kind of input management for this page
//
//
//       VT100_INPUT_ESCAPE      -> It is not a menu, it his a page with information updated on
//                                  screen, this kind of page is not waiting any key other than
//                                  <ESCAPE> to exit
//
//       VT100_INPUT_SAVE_DATA   -> This value inform the myVT100 of the save has being processed.
//
//       VT100_INPUT_MENU_CHOICE -> It tell the console it is a menu and waiting for an input.
//
//       VT100_INPUT_DECIMAL     -> If the callback make call for an VT100_SetDecimalInput(), then
//                                  it must return with this enum value to tell the console what
//                                  to do. It will comeback to the callback only when the input
//                                  decimal mode will be escaped by <ESCAPE> or value validated by
//                                  <ENTER>.
//
//       VT100_INPUT_STRING      -> If the callback make call for an VT100_SetStringInput(), then it
//                                  must return with this enum value to tell the console what to
//                                  do. We will comeback to the callback only when the input
//                                  decimal mode will be escaped by <ESCAPE> or value validated
//                                  by <ENTER>.
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "./Digini/lib_digini.h"

//-------------------------------------------------------------------------------------------------

#if (DIGINI_USE_VT100_MENU == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

// this is not the place for those Settings only what is generic should stay here


#define VT100_CFG_NO_REFRESH                                  0
#define VT100_CFG_REFRESH_INFO                                32768
#define VT100_CFG_REFRESH_ALL                                 65535
#define VT100_CFG_REFRESH_COMMON_MASK                         (32768 + 16384)

#define VT100_MISC_CFG_REFRESH_SET_POINT_LOW                  1
#define VT100_MISC_CFG_REFRESH_SET_POINT_HIGH                 2
#define VT100_MISC_CFG_REFRESH_SET_POINT_BACKUP_LOW_VOLTAGE   4
#define VT100_MISC_CFG_REFRESH_SET_POINT_POWER_LOW_VOLTAGE    8
#define VT100_MISC_CFG_REFRESH_SERIAL                         16
#define VT100_MISC_CFG_REFRESH_LOCATION                       32
#define VT100_MISC_CFG_REFRESH_SITE_ID                        64

//-------------------------------------------------------------------------------------------------
//
//  Name:           PrintMenuStaticInfo
//
//  Description:    Print user header/footer or static display information
//
//  Note(s);        Be aware of your cursor location
//
//-------------------------------------------------------------------------------------------------
#if (VT100_USE_USER_MENU_STATIC_INFO == DEF_ENABLED)
void VT100_Terminal::PrintMenuStaticInfo(void)
{
}
#endif

//-------------------------------------------------------------------------------------------------
//
//  Name:           VT100_CallbackInitialize
//
//  Description:    Callback Initialize
//
//  Note(s):        Put in this function what you want to be initialize only once at boot up
//
//-------------------------------------------------------------------------------------------------
#if (VT100_USER_CALLBACK_INITIALIZE == DEF_ENABLED)
void VT100_Terminal::CallbackInitialize(void)
{
}
#endif

//-------------------------------------------------------------------------------------------------
//
//  Name:           CALLBACK_TouchInformation
//
//  Description:    Display the input of the Module
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
VT100_InputType_e VT100_Terminal::CALLBACK_TouchInformation(uint8_t Input, VT100_CallBackType_e Type)
{
    static uint8_t  LastPosX;
    static uint8_t  LastPosY;
    uint16_t        ADC_Value;
    Cartesian_t     Position;

    switch(Type)
    {
        case VT100_CALLBACK_INIT:
        {
            LastPosX = 255;
            LastPosY = 255;
        }
        break;

        case VT100_CALLBACK_REFRESH_ONCE:
        {
            SetForeColor(VT100_COLOR_WHITE);
            VT100_Printf(1, 6, VT100_LBL_MENU_TOUCH);

            /// Print the box
            DrawBox(66, 8, 65, 26, VT100_COLOR_GREEN);

            /// Print the static info on the screen
            SetForeColor(VT100_COLOR_WHITE);
            VT100_Printf(4, 8, VT100_LBL_ADC_FOR);
            VT100_Printf(VT100_LBL_X1);
            VT100_Printf(4, 9, VT100_LBL_ADC_FOR);
            VT100_Printf(VT100_LBL_X2);
            VT100_Printf(4, 10, VT100_LBL_ADC_FOR);
            VT100_Printf(VT100_LBL_Y1);
            VT100_Printf(4, 11, VT100_LBL_ADC_FOR);
            VT100_Printf(VT100_LBL_Y2);
            VT100_Printf(4, 13, VT100_LBL_TOUCH_POS_X);
            VT100_Printf(4, 14, VT100_LBL_TOUCH_POS_Y);
        }
        break;

        case VT100_CALLBACK_REFRESH:
        {
            ADC_Value = PDI_ResistiveTouch.GetRawADC(0);
            VT100_Printf(36, 8, VT100_LBL_INT_4, ADC_Value);
            ADC_Value = PDI_ResistiveTouch.GetRawADC(1);
            VT100_Printf(36, 9, VT100_LBL_INT_4, ADC_Value);
            ADC_Value = PDI_ResistiveTouch.GetRawADC(2);
            VT100_Printf(36, 10, VT100_LBL_INT_4, ADC_Value);
            ADC_Value = PDI_ResistiveTouch.GetRawADC(3);
            VT100_Printf(36, 11, VT100_LBL_INT_4, ADC_Value);
            PDI_ResistiveTouch.GetXY(&Position);
            VT100_Printf(36, 13, VT100_LBL_INT_4, Position.X);
            VT100_Printf(36, 14, VT100_LBL_INT_4, Position.Y);

            if(Position.X == -1 || Position.Y == -1)
            {
                // Erase old '*'
                if (LastPosX != 255 && LastPosY != 255)
                {
                    VT100_Printf(LastPosX, LastPosY, LBL_CHAR, ' ');
                    LastPosX = 255;
                    LastPosY = 255;
                }

                // Print "No Touch" centered
                VT100_Printf(93, 20, VT100_LBL_NO_TOUCH);
            }
            else
            {
                // Convert grid -> VT100 coordinates
                uint8_t NewX = 67 + (Position.X * 2);
                uint8_t NewY = 9  + Position.Y;

                // Erase old '*'
                if((LastPosX != 255) && (LastPosY != 255))
                {
                    VT100_Printf(LastPosX, LastPosY, LBL_CHAR, ' ');
                }
                else
                {
                    VT100_Printf(93, 20, VT100_LBL_ERASE_NO_TOUCH);
                }

                // Draw new '*'
                VT100_Printf(NewX, NewY, LBL_CHAR, '*');

                // Save last position
                LastPosX = NewX;
                LastPosY = NewY;
            }
        }
        break;

        default: break;
    }


    return VT100_INPUT_ESCAPE;
}

//-------------------------------------------------------------------------------------------------

#endif // (DIGINI_USE_VT100_MENU == DEF_ENABLED)


