# _BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED

--- ns: HUD aliases: ["0x0A24DA3A41B718F5"] --- ## BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED  // 0x0A24DA3A41B718F5 0x00E20F2D void BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(char* labelName);  ## Parameters * **labelName**: Text entry name. This can be created using [`AddTextEntry`](#_0x32CA01C3).  ## Examples -- Create new text entry AddTextEntry('TEST_LABEL', 'Hello world.')  -- Draw help message BeginTextCommandDisplayHelp('TEST_LABEL') EndTextCommandDisplayHelp(0, false, true, -1)  -- Test if the message has been displayed BeginTextCommandIsThisHelpMessageBeingDisplayed("TEST_LABEL") local isDisplayed = EndTextCommandIsThisHelpMessageBeingDisplayed(0)

### Parameters
* const char* labelName

### Return Value
* void

### Notes
* AP Hash: 0x0x00E20F2D
* Build: 323
* BOOL IsContextActive(char *ctx)
    {
     BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(ctx);
     return END_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(0);
  }

