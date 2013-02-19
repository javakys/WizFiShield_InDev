#include "HTMLPages.h"
#include <avr/pgmspace.h>

#ifdef CODEMEM
prog_char Protocol_Msg[] PROGMEM = "HTTP/1.1 200 OK\r\n";   // "String 0" etc are strings to store - change to suit.
prog_char Page1_Line0[] PROGMEM = "<!DOCTYPE html PUBLIC \"-//WAPFORUM//DTD XHTML Mobile 1.2//EN\" ";   // "String 0" etc are strings to store - change to suit.
prog_char Page1_Line1[] PROGMEM = "\"http://www.wapforum.org/DTD/xhtml-mobile 12.dtd\">\r\n";   // "String 0" etc are strings to store - change to suit.
prog_char Html_start[] PROGMEM = "<html>\r\n";   // "String 0" etc are strings to store - change to suit.
prog_char head_start[] PROGMEM = "<head>\r\n";   // "String 0" etc are strings to store - change to suit.
prog_char Page1_Line2[] PROGMEM = "<meta http-equiv=\"Content-Type\" content=\"text/html/>\r\n";
prog_char Content_Msg[] PROGMEM = "Content-Type: text/html\r\n";
prog_char Page1_Line3[] PROGMEM = "<meta name=\"viewport\" content=\"user-scalable=no, initial-scale=5.0,";
prog_char Page1_Line4[] PROGMEM = " maximum-scale=5.0, minimum-scale=5.0, width=device-width\"/>\r\n";
prog_char head_end[] PROGMEM = "</head>\r\n";   // "String 0" etc are strings to store - change to suit.
prog_char Page1_Line5[] PROGMEM = "<body>\r\n";
prog_char new_Line[] PROGMEM = "\r\n";
prog_char Page1_Line6[] PROGMEM = "Hello World\r\n";
prog_char Page1_Line7[] PROGMEM = "<form>\r\n";
prog_char Page1_Line8[] PROGMEM = "<table width=\"100%\"><tr><td width=\"40%\"></td><td width=\"20%\" bgcolor=\"silver\" align=\"center\"><h1><button ";
prog_char Page1_Line8_cont[] PROGMEM = "name=\"command\" value=\"FW_CMD\">forward</button></h1></td><td width=\"40%\"></td></tr>\r\n";
prog_char Middle_Line[] PROGMEM = "<tr><td width= \"40%\" align=\"right\"><h1><button name=\"command\" value=\"LEFT_CMD\">LEFT</button></h1></td>";
prog_char Middle_Line_cont[] PROGMEM = "<td width=\"20%\"></td><td width= \"40%\" align=\"left\"><h1><button name=\"command\" value=\"RIGHT_CMD\">";
prog_char Middle_Line_cont2[] PROGMEM = "RIGHT</button></h1></td></tr>\r\n";
prog_char Page1_Line9[] PROGMEM = "<tr><td width=\"40%\"></td><td width= \"20%\" bgcolor=\"#c3c3c3\" align=\"center\"><h1><button name=\"command\"  ";
prog_char Page1_Line9_cont[] PROGMEM = "value=\"BW_CMD\">backward</button></h1></td><td width=\"40%\"></td></tr></table>\r\n";
prog_char Page1_Line10[] PROGMEM = "</form>\r\n";
prog_char Page1_Line11[] PROGMEM = "</body>\r\n";
prog_char Html_end[] PROGMEM = "</html>\r\n";   // "String 0" etc are strings to store - change to suit.

/*
prog_char WM_Msg[] PROGMEM = "AT+WM=%d\r\n";
prog_char DHCPSRVR_Msg[] PROGMEM = "AT+DHCPSRVR=1\r\n";
prog_char WP_Msg[] PROGMEM = "AT+WP=%d\r\n";
prog_char DNSSET_Msg[] PROGMEM = "AT+DNSSET=%s\r\n";
prog_char DNSSET2_Msg[] PROGMEM = "AT+DNSSET=%s,%s\r\n";
prog_char DNSLOOKUP_Msg[] PROGMEM = "AT+DNSLOOKUP=%s,3,5\r\n";
prog_char WAUTO_Msg[] PROGMEM = "AT+WAUTO=0,%s\r\n";
prog_char NAUTO_Msg[] PROGMEM = "AT+NAUTO=%d,%d,%s,%u\r\n";
prog_char NDHCP_Msg[] PROGMEM = "AT+NDHCP=%d\r\n";
prog_char WWEP_Msg[] PROGMEM = "AT+WWEP1=%s\r\n";
prog_char WWPA_Msg[] PROGMEM = "AT+WWPA=%s\r\n";
prog_char WPAPSK_Msg[] PROGMEM = "AT+WPAPSK=%s,%s\r\n";
prog_char BDATA_Msg[] PROGMEM = "AT+BDATA=1\r\n";
prog_char WATA_Msg[] PROGMEM = "ATA\r";
prog_char NSET_Msg[] PROGMEM = "AT+NSET=%s,%s,%s\r\n";
prog_char ATCID_Msg[] PROGMEM = "AT+CID=?\r\n";
prog_char ATO_Msg[] PROGMEM = "AT\r";
prog_char NCTCP_Msg[] PROGMEM = "AT+NCTCP=%s,%u\r\n";
prog_char NSTCP_Msg[] PROGMEM = "AT+NSTCP=%u\r\n";
prog_char NCLOSE_Msg[] PROGMEM = "AT+NCLOSE=%c\r\n";
prog_char NCLOSEALL_Msg[] PROGMEM = "AT+NCLOSEALL\r\n";
prog_char CMDMODE_Msg[] PROGMEM = "+++";
prog_char WS2_Msg[] PROGMEM = "AT+WS=,,%d\r\n";

prog_char DNS_Success[] PROGMEM = "DNS Query Success";   // "String 0" etc are strings to store - change to suit.
prog_char DNS_Fail[] PROGMEM = "DNS Query Failed";
prog_char Conn_F_Msg[] PROGMEM = "Connection Failed";
prog_char Disconn_F_Msg[] PROGMEM = "Disconnection Failed";
prog_char Conn_S_Msg[] PROGMEM = "CID[%c] Connected";
prog_char Disconn_S_Msg[] PROGMEM = "CID[%c] Disconnected";
prog_char PeerIP_Msg[] PROGMEM = "Peer IP: %d.%d.%d.%d";
prog_char PeerPort_Msg[] PROGMEM = "Peer Portnum: %u";
prog_char Sock_F_Msg[] PROGMEM = "Socket Failure";
prog_char Inval_Noti_Msg[] PROGMEM = "Invalid Notification";

prog_char NCUDP_Msg[] PROGMEM = "AT+NCUDP=%s,%u,%u\r\n";
prog_char NSUDP_Msg[] PROGMEM = "AT+NSUDP=%u\r\n";

prog_char PING_Msg[] PROGMEM = "AT+PING=%s,%d\r\n";

prog_char Disassociate_Msg[] PROGMEM = "Disassociated!";

prog_char ConnectNoti_Msg[] PROGMEM = "CONNECT";
prog_char DisconnNoti_Msg[] PROGMEM = "DISCONNECT";
prog_char DisassociateNoti_Msg[] PROGMEM = "Disassociation";
*/

PROGMEM const char *HTML_table[] = 
{
	Protocol_Msg,
	Content_Msg,
	new_Line,				// 0
//	Html_start,
//	head_start,
	Page1_Line6,			// 5
	Page1_Line7,			// 6
	Page1_Line8,				// 7
	Page1_Line8_cont,
	Middle_Line,
	Middle_Line_cont,
	Middle_Line_cont2,
	Page1_Line9,				// 8
	Page1_Line9_cont,				// 8
	Page1_Line10	// 9
//	Page1_Line11,
//	Html_end
/*	
	WP_Msg,				// 10
	DNSSET_Msg,			// 11
	DNSSET2_Msg,		// 12
	DNSLOOKUP_Msg,		// 13
	WAUTO_Msg,			// 14
	NAUTO_Msg,			// 15
	NDHCP_Msg,			// 16
	WWEP_Msg,			// 17
	WWPA_Msg,			// 18
	WPAPSK_Msg,			// 19
	BDATA_Msg,			// 20
	WATA_Msg,			// 21
	NSET_Msg,			// 22
	ATCID_Msg,			// 23
	ATO_Msg,			// 24
	NCTCP_Msg,			// 25
	NSTCP_Msg,			// 26
	NCLOSE_Msg,			// 27
	NCLOSEALL_Msg,		// 28
	CMDMODE_Msg,		// 29
	WS2_Msg,			// 30
	DNS_Success,			// 31
	DNS_Fail,				// 32
	Conn_F_Msg,			// 33
	Disconn_F_Msg,		// 34
	Conn_S_Msg,			// 35
	Disconn_S_Msg,		// 36
	PeerIP_Msg,			// 37
	PeerPort_Msg,			// 38
	Sock_F_Msg,			// 39
	Inval_Noti_Msg,		// 40
	NCUDP_Msg,			// 41
	NSUDP_Msg,			// 42
	PING_Msg,			// 43
	Disassociate_Msg		// 44
*/
};

HTMLPages::HTMLPages() //constructor
{
	CurrentIndex = 0;
}

uint8_t HTMLPages::GetNextLine(char *buf) //if no data, return 0. Otherwise, return 1
{

	if(CurrentIndex == 13)
	{
		CurrentIndex = 0;
		return 0;
	}
	else
	{
		memset(buf, 0, 128);
	       strcpy_P((char *)buf, (char*)pgm_read_word(&(HTML_table[CurrentIndex++]))); // Necessary casts and dereferencing, just copy. 
	       return 1;
	}
}

#endif

