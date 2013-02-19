#include "HTMLParser.h"

//////////////////////////
// Constructor
HTMLParser::HTMLParser()
{
	bInParsing = NO_PARSING; 
	
	IsFirstCRLF = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Parse HTML message transferred by parameter, buf. It returns 1 when it encounters to the EOF of HTML file, ohterwise 0
uint8_t HTMLParser::Parsing(char * buf)
{
	uint8_t index = 0;

	if(bInParsing == NO_PARSING)
	{
		memset(myParam, 0, sizeof(PARAM_STRUCT)*MAX_PARAM_COUNT);
		myParamCount = 0;

		memset(parserBuf, 0, PARSEBUF_SIZE); 
		parserBufIndex = 0;
	}
		
	while(buf[index] != '\0')
	{
		parserBuf[parserBufIndex] = buf[index];
		
		if(buf[index] == 0x0a)
		{
			if(parserBuf[parserBufIndex - 1] == 0x0d)
			{
				if(IsFirstCRLF)
				{
					IsFirstCRLF = false;
					parserBufIndex = 0;
					bInParsing = NO_PARSING;
					return 1; // Parsing was finished.
				}else
				{
					IsFirstCRLF = true;
					/////////////////////////
					// Do Parsing a sentence terminated by CR and LF
					// ...
				}
			}
		}else if(buf[index] != 0x0d)
		{			
			if(IsFirstCRLF)
			{
				IsFirstCRLF = false;
			}
		}
		parserBufIndex++;
		index++;
	}

	if(parserBufIndex > 0)
		bInParsing = IN_PARSING;
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//If we received a pair of name, which specified in param_name, and value, this function stores value to param_value and returns 1. Otherwise, return 0.
uint8_t HTMLParser::GetParam(char * param_name, char * param_value)
{
}

