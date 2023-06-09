�MKMSGF RAS �                W ��b��^��\�{��#�$k(P*(.$0/2947[8;e=?E?s?IEXPLANATION
Your COMDEV.INI file is either missing or is in use by another
application, such as an editor.
        
Warning: There is no need to edit your COMDEV.INI file. The 
Remote Access Setup program automatically writes the required 
information to the file, and manual editing can result in a 
corrupt file and lost data.

ACTION
Ensure that the COMDEV.INI file, located in your LAN Manager 
directory, is not in use by another application. If it is, 
close the application. If not, run the Remote Access Setup 
program to remove and reinstall Remote Access, then restart 
your computer.
IEXPLANATION
You must load the Remote Access drivers before typing RASPHONE 
or RASDIAL.

ACTION
At the DOS command line, type RASLOAD to load the Remote Access 
drivers.  If you are running the Microsoft Windows graphical 
environment, you must exit the Windows graphical environment 
prior to typing RASLOAD.
IEXPLANATION
The Remote Access server was configured to accommodate a 
specific number of NetBIOS names from your computer. 

ACTION
Contact your system administrator to determine the number of 
NetBIOS names the Remote Access server will accept from your 
computer.

If you are running the Lan Manager workstation service only, 
type NET NAME to see how many names have been registered 
by the workstation service. Try deleting some of the names 
listed. For more help on using the NET NAME command, type 
NET NAME /HELP. If you are running multiple network 
applications, try stopping some of them.
IEXPLANATION
One of the following may be true:
- Your modem is incompatible with the modem on the 
  Remote Access server.
- There is excessive static on the phone line.
- The Remote Access server is no longer running.
- A NetBIOS error has occurred on your asynchronous protocol 
  driver.

ACTION
Try to connect again.  If the problem persists, contact your 
system administrator.

IEXPLANATION
The LAN Manager workstation service was not initialized to use 
the asynchronous protocol driver.

ACTION
Contact your system administrator to verify that the WRKNETS = 
parameter in your LANMAN.INI file is set correctly. It should 
list your asynchronous net.  

Check your configuration files. For DOS computers, make sure 
that the value assigned to the LANABASE = parameter in the 
PROTOCOL.INI section of your asynchronous protocol corresponds 
to the WRKNETS = value in your LANMAN.INI file. For OS/2 
computers, ensure that you have at lease one ASYBEUI net in
your WRKNETS line.

If you modify your LANMAN.INI file only, type NET STOP 
WORKSTATION and then type NET START WORKSTATION for changes to 
take effect.  If you modify your PROTOCOL.INI file then restart 
your computer for changes to take effect.

If none of the above actions work, run the Remote Access Setup
program and restart your computer.
IEXPLANATION
One of the following may have occured:
- You edited the PHONE.INF file located in your LAN Manager 
  directory and misspelled some keywords, or your editor left 
  some unrecognized characters in the file. In this case, the 
  Remote Access program will automatically delete invalid 
  characters. Some information may be lost from your Phone Book.

  Warning: There is no need to edit your PHONE.INF file.  The 
  Remote Access Setup program automatically writes required 
  information to the file, and manual editing can result in a 
  corrupt file and lost data.

- The device information in your PHONE.INF file is not 
  consistent with the information in your COMDEV.INI file. In 
  this case the Remote Access program will correct the 
  inconsistency.  No information will be lost.

ACTION
From the File menu in the Remote Access Phone Book, choose Save. 
This will save the corrections made by Remote Access.
IEXPLANATION
Your COMDEV.INI file is missing parameters for one or more 
entries or contains unrecognizable information.

Warning: There is no need to edit your COMDEV.INI file.  The 
Remote Access Setup program automatically writes required 
information to the file, and manual editing can result in a 
corrupt file and lost data.
        
ACTION
Use the Remote Access Setup program to reconfigure your Remote
Access installation. Setup will automatically make the necessary 
corrections to your COMDEV.INI file.  The Setup program is 
located in the RAS subdirectory of your LAN Manager directory.
IEXPLANATION
One of the following may have occurred:
- The message received from the modem is not listed in your 
  MODEMS.INF file.  Check to see if your modem is supported 
  by Remote Access.
- You specified the wrong modem type when installing Remote
  Access from the Setup program. Run Setup and specify your
  correct modem type.
- You edited your COMDEV.INI or MODEMS.INF file, specifying 
  an illegal value for the MAXBAUD = parameter.  Run the 
  Remote Access Setup program to remove and reinstall Remote
  Access, then restart your computer.

  Warning: There is no need to edit your COMDEV.INI file. The 
  Remote Access Setup program automatically writes required 
  information to the file, and manual editing can result in a 
  corrupt file and lost data. Ask your system administrator 
  for assistance before modifying your MODEMS.INF file.

- Your modem is set to a baud rate that is inconsistent with
  the baud rate you specified in the Phone Book.  Ensure that 
  you are using the correct modem setting for the modem you 
  selected.
- Your modem has malfunctioned.  Refer to your modem 
  documentation or contact your modem manufacturer.
- There is excessive static on the telephone line.

ACTION

Try dialing again.  If the problem persists, contact your 
system administrator.
IEXPLANATION
Your PHONE.INF file is either missing or is in use by another
application such as an editor.
    
Warning: There is no need to edit your PHONE.INF file. The 
Remote Access Setup program automatically writes required 
information to the file, and manual editing can result in a 
corrupt file and lost data.
        
ACTION
Ensure that your PHONE.INF file, located in your LAN Manager 
directory, is not in use by another application. If it is, 
close the application. If not, run the Remote Access Setup 
program to remove and reinstall Remote Access, then restart 
your computer.
IEXPLANATION
Your MODEMS.INF file is either missing or is in use by another
application such as an editor.

ACTION
Ensure that your MODEMS.INF file, located in your LAN Manager 
directory, is not in use by another application. If it is, 
close the application. If not, run the Remote Access Setup 
program to remove and reinstall Remote Access, then restart 
your computer.
IEXPLANATION
One of the following may be true:
- The server is trying to call you back at another number.
- The server is no longer running.

ACTION
If you have Set-by-Caller callback permission, try to re-enter 
your callback number. You may be missing a dial modifier (refer 
to the Help index for more information on dial modifiers). If 
you have Preset-To callback, contact your system administrator.
IEXPLANATION
One of the following may be true:
- The modem cable is not connected to your COM port.
- The modem is turned off or malfunctioning.
- The telephone cable is not connected.
- A COM port error has occurred.
- You are not using the correct RS-232 cable or Null Modem
  cable. For example, a 25-9 pin mouse adapter will not 
  carry the required modem signals.
- The Remote Access server is paused or not running.
- The remote modem is not answering.
        
ACTION
Verify that you are using the correct cables and that they 
are connected. Ensure that your modem is configured and 
operating correctly. Try to connect again. If the problem 
persists, contact your system administrator to ensure that
the Remote Access server and server modem are functioning
properly. If so, run system diagnostics to verify that the 
COM port is functioning.
IEXPLANATION
One of the following may be true:
- The system administrator disconnected the line.
- The Remote Access server is no longer running.
- The Remote Access server's modem has been turned off.
- Your modem has been turned off.
- Your modem is incompatible with the Remote Access server's 
  modem.
- You took too long to enter your password (in the case of
  a retry) or callback number, and Remote Access disconnected
  the connection.
- Your telephone line has call waiting, and a call came in.
- Someone has picked up the telephone line.
- Hardware error in your telephone line, modem, or COM port.
- Hardware error in the Remote Access server's modem or COM 
  port.
      
ACTION
Try to reconnect. If your telephone line has call waiting, 
switch to a line without call waiting or disable call waiting
while using Remote Access. If the problem persists, contact 
your system administrator.
IEXPLANATION
One of the following may be true:
- The Remote Access server is paused or not running.
- The remote modem is not compatible with your modem.
- The remote modem is not answering.
- Someone has picked up the telephone line.
        
ACTION
Try to connect again. If the problem persists, contact your 
system administrator.
IEXPLANATION
One of the following may be true:
- You specified the wrong modem type when installing Remote
  Access from the Setup program. Run Setup and select your
  correct modem type.
- You specified an incorrect baud rate for the modem by 
  specifying an illegal value for the MAXBAUD = parameter 
  in your COMDEV.INI or MODEMS.INF file.
        
  Warning: There is no need to edit your COMDEV.INI file. 
  The Remote Access Setup program automatically writes required 
  information to the file, and manual editing can result in 
  a corrupt file and lost data.  Ask your system administrator 
  for assistance before modifying your MODEMS.INF file.

- Your modem is in an inconsistent state. Reset your modem.
- Your modem has malfunctioned.
- There is excessive static on the telephone line.

ACTION
Try dialing again. If the problem persists, contact your system
administrator.
IEXPLANATION
One of the following may be true:
- The COM port is in use by another application.
- The COM port is malfunctioning.
- The COM port you specified does not exist on your computer.

ACTION
If you selected a specific COM port, check to make sure that it 
exists on your computer and that it is not in use by another 
application. If it is, close the application and try again. If 
not, run system diagnostic tools to see if there is a COM port 
hardware problem.
IEXPLANATION
One of the following may be true:
- Your communications device driver is not supported by
  Remote Access.    
- You edited your COMDEV.INI file and specified an invalid 
  baud rate. 
        
  Warning: There is no need to edit your COMDEV.INI file. The 
  Remote Access Setup program automatically writes required 
  information to the file, and manual editing can result in a 
  corrupt file and lost data.

- The COM port is malfunctioning.

ACTION
First verify that your communications device driver is 
supported by Remote Access.  Next, check your COMDEV.INI file 
to ensure that it specifies a valid baud rate for your modem 
type (common baud rates are 1200, 2400, 4800, 9600, 19,200, 
38,400). If it doesn't, do not edit the file manually.  Use the 
Remote Access Setup program to re-configure Remote Access, and 
restart your computer. If the error persists, run system 
diagnostic tools to see if there is a COM port hardware problem.
IEXPLANATION
A telephone connection has been successfully established, but 
the Remote Access server is not responding to messages sent on 
that connection.  One of the following may be true:
- Your modem is incompatible with the Remote Access server's 
  modem.
- There is excessive static on the telephone line.
- The Remote Access server is not running.
- A network error occurred on your asynchronous protocol.

ACTION
Try again. If the problem persists, contact your system 
administrator.
IEXPLANATION
This warning message indicates that another user or application 
has already registered this same alias name from another 
workstation within your network. Messages will be sent to the 
user or application who registered first.

ACTION
If this is a user name, check to see if you are already logged 
onto the network from another computer.  If not, contact your 
system administrator to see if another user has the same alias. 
Note that no action is required unless you want to receive 
messages.
IEXPLANATION
You specified a callback number for the server to call you 
back, but you do not have Set-by-Caller callback permission.  
One of the following may have occurred:
- You have Preset-To callback permission, and the Remote 
  Access server has hung up and tried to call you back 
  at a preset number.
- You have neither type of callback permission, and the Remote
  Access server simply kept the connection intact. 

ACTION
Contact your system administrator for Set-by-Caller callback 
permission.
IEXPLANATION
Your computer is using a NetBIOS name that is already on the 
LAN.  One of the following may have occurred:
- Your computer is already connected to the LAN.  
- There is a computer on the LAN that has the same computer 
  name as your computer.  Typically, this occurs when you've 
  named your home computer the same name as your office 
  computer.  Use the LAN Manager Setup program to change one 
  of the names.
- You are running a Network application that is trying to 
  register a NetBIOS name that already exists on the LAN.

ACTION
Ensure that your computer name is not the same as that of 
another computer already connected to the LAN.  Contact 
your system administrator for assistance.
IEXPLANATION
One of the following may have occurred:
- Your COM port is not properly configured for Remote Access. 
- You are running a Remote Access server, and none of your 
  COM ports are configured for dial-out.

ACTION
Use the Remote Access Setup program to reconfigure your COM 
ports, and restart your computer.
IEXPLANATION
One of the following may have occurred: 
- COM port does not exist on your computer.        
- COM port is not properly configured for Remote Access.
- COM port is not properly configured for dial-out 
  (Remote Access servers only).
- COM port is in use by another application.
- No thread slots are available.

ACTION
Ensure that the specified COM port exists on your computer and 
is not in use by another application.  If it is being used by 
another application, close the application. Run the Remote 
Access Setup program to properly configure the COM port.  Then 
restart your computer and try again.  If this error persists, 
contact your system administrator.
IEXPLANATION
There are invalid characters in your MODEMS.INF file, or the 
modem specified in your COMDEV.INI file is not listed in your 
MODEMS.INF file.
  
Warning: Ask your system administrator for assistance before 
modifying your MODEMS.INF file, and do not edit your COMDEV.INI 
file at all. The Remote Access Setup program automatically writes 
required information to the COMDEV.INI file, and manual editing 
can result in a corrupt file and lost data. 
        
ACTION
Use the Remote Access Setup program to re-configure Remote Access, 
and then restart your computer.
IEXPLANATION
One of the following may have occurred:
- None of your COM ports are configured for Remote Access.
- There is an error in one or more of your configuration 
  files.

ACTION
Run the Remote Access Setup program. This will allow you to 
properly configure your COM ports and will automatically 
correct any errors in your configuration files.  If the 
problem persists, contact your system administrator.
IThe syntax of this command is:

RASHELP message#
I%1 is not a valid Remote Access message ID.
IEXPLANATION
One of the following may be true:
- The Remote Access drivers are already loaded.
- You are attempting to use both your network adapter card and 
  modem at the same time when your system is not configured 
  to use both at the same time.
- There is an error in your LAN Manager or Remote Access 
  configuration files.

ACTION
- Type LOAD /I to list the protocols loaded on your computer.  
  If ASYBEUI is listed, then the Remote Access drivers are 
  already loaded.  
- If any network protocols are listed, your system may not be 
  configured to use both a network adapter and modem at the 
  same time.  Unload the protocols associated with your network 
  adapter card by typing UNLOAD <PROTOCOL>, and then type RASLOAD 
  again. To reconfigure your system to use both your network 
  adapter card and modem at the same time, run the Setup program 
  to remove and reinstall Remote Access.  While reinstalling, 
  choose the appropriate option in the Remote Access Configuration 
  box.
- To correct an error in your configuration files run the Setup 
  program to remove and reinstall Remote Access.
