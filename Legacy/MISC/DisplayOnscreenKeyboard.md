# _DISPLAY_ONSCREEN_KEYBOARD

--- ns: MISC --- ## DISPLAY_ONSCREEN_KEYBOARD  // 0x00DC833F2568DBF6 0xAD99F2CE void DISPLAY_ONSCREEN_KEYBOARD(int keyboardType, char* windowTitle, char* description, char* defaultText, char* defaultConcat1, char* defaultConcat2, char* defaultConcat3, int maxInputLength);  Displays a text input box.  enum eKeyboardType { ONSCREEN_KEYBOARD_ENGLISH = 0, ONSCREEN_KEYBOARD_LOCALISED = 1, ONSCREEN_KEYBOARD_PASSWORD = 2, ONSCREEN_KEYBOARD_GAMERTAG = 3, ONSCREEN_KEYBOARD_EMAIL = 4, ONSCREEN_KEYBOARD_BASIC_ENGLISH = 5, ONSCREEN_KEYBOARD_FILENAME = 6 };  ## Parameters * **keyboardType**: See the list above. Default is `0`. * **windowTitle**: Text label for the title of the box. * **description**: Has no use on PC. * **defaultText**: Default text that is written in the input field. * **defaultConcat1**: * **defaultConcat2**: * **defaultConcat3**: * **maxInputLength**: Max number of characters that can be typed (2 - 256).   ## Examples AddTextEntry("my_input_title", "Enter something cool:")  DisplayOnscreenKeyboard(0, "my_input_title", "", "", "", "", "", 30) -- Show the text input box  while UpdateOnscreenKeyboard() == 0 do Wait(0) end -- Wait for the user to stop editing  -- This block of code is reached after the user is done editing  local inputUpdate = UpdateOnscreenKeyboard()  if inputUpdate == 1 then -- User hit OK in the text input box local result = GetOnscreenKeyboardResult() print("You wrote this in the input box:", result) elseif inputUpdate == 2 then print("You canceled the input!") else -- -1 or 3 print("An error has occurred") end

### Parameters
* int p0
* const char* windowTitle
* const char* p2
* const char* defaultText
* const char* defaultConcat1
* const char* defaultConcat2
* const char* defaultConcat3
* int maxInputLength

### Return Value
* void

### Notes
* AP Hash: 0x0xAD99F2CE
* Build: 323
* sfink: note, p0 is set to 6 for PC platform in at least 1 script, or to `unk::_get_ui_language_id() == 0` otherwise.

NOTE: windowTitle uses text labels, and an invalid value will display nothing.

www.gtaforums.com/topic/788343-vrel-script-hook-v/?p=1067380474

windowTitle's
-----------------
CELL_EMAIL_BOD  =   "Enter your Eyefind message"
CELL_EMAIL_BODE =   "Message too long. Try again"
CELL_EMAIL_BODF    =   "Forbidden message. Try again"
CELL_EMAIL_SOD    =   "Enter your Eyefind subject"
CELL_EMAIL_SODE =   "Subject too long. Try again"
CELL_EMAIL_SODF    =   "Forbidden text. Try again"
CELL_EMASH_BOD   =   "Enter your Eyefind message"
CELL_EMASH_BODE =   "Message too long. Try again"
CELL_EMASH_BODF    =   "Forbidden message. Try again"
CELL_EMASH_SOD    =   "Enter your Eyefind subject"
CELL_EMASH_SODE =   "Subject too long. Try again"
CELL_EMASH_SODF    =   "Forbidden Text. Try again"
FMMC_KEY_TIP10   =   "Enter Synopsis"
FMMC_KEY_TIP12  =   "Enter Custom Team Name"
FMMC_KEY_TIP12F =   "Forbidden Text. Try again"
FMMC_KEY_TIP12N  =   "Custom Team Name"
FMMC_KEY_TIP8 =   "Enter Message"
FMMC_KEY_TIP8F   =   "Forbidden Text. Try again"
FMMC_KEY_TIP8FS  =   "Invalid Message. Try again"
FMMC_KEY_TIP8S  =   "Enter Message"
FMMC_KEY_TIP9    =   "Enter Outfit Name"
FMMC_KEY_TIP9F   =   "Invalid Outfit Name. Try again"
FMMC_KEY_TIP9N  =   "Outfit Name"
PM_NAME_CHALL  =   "Enter Challenge Name"

