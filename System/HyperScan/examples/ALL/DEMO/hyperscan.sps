# Sunplus S+core IDE Project File - Name = "hyperscan"
# Sunplus S+core IDE Generated Build File Format Version V2.6.1
#**DO NOT EDIT**
CFG = Debug

# Begin Project

!IF "$(CFG)" == "hyperscan - Debug"

OutPut Type = elf
OutPut Dir = Debug
Inc Path = 
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -g -Wall -nostartfiles
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -Wa,-gdwarf-2  -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0fffff0
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = makehyper
Post-Build Command = 	cd ./Debug && move hyperscan.elf.bin Hyper.Exe	cd ./Debug && del *.o *.bin *.elf *.map *.d *.srec *.dbg *.res
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 1
Dasm File = 0
Resource File = 0
LD File = 0
Use C++ Configuration = 0
Search Header File = 0
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT1
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\ALL\DEMO
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 1
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ELSEIF "$(CFG)" == "hyperscan - Release"

OutPut Type = elf
OutPut Dir = Release
Inc Path = 
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -O2 -Wall
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0fffffc
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = 
Post-Build Command = 
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 0
Dasm File = 0
Resource File = 1
LD File = 1
Use C++ Configuration = 0
Search Header File = 0
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT2
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = 
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 1
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ENDIF

# Name "hyperscan - Debug
# Name "hyperscan - Release
# Begin SubItem "hyperscan files"

# Begin Group "Source Files"
#PROP Default_Filter = c;cpp;cc;C;cxx;asm;s;

# Begin Group "hslibs"
#PROP Default_Filter = 

# Begin Group "HS_Controller"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\hslibs\HS_Controller\HS_Controller.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End Group
# Begin Group "scorelibs"
#PROP Default_Filter = 

# Begin Group "I2C"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\I2C\I2C.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "IRQ"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\IRQ\Sys_IRQ.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\IRQ\Sys_isr.s
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\IRQ\User_IRQ.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "NorFlash"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\NorFlash\NorFlash.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "TV"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\TV\TV.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "UART"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\UART\UART.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=..\..\..\..\..\SPG290\scorelibs\libgloss.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\main.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Header Files"
#PROP Default_Filter = h;inc;

# Begin Group "hslibs"
#PROP Default_Filter = *.h

# Begin Group "HS_Controller"
#PROP Default_Filter = *.h

# Begin Source File
SOURCE=..\..\..\hslibs\include\HS_Controller\HS_Controller.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End Group
# Begin Group "scorelibs"
#PROP Default_Filter = *.h

# Begin Group "I2C"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\I2C\I2C.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "IRQ"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\IRQ\IntEnable.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "NorFlash"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\NorFlash\NorFlash.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "TV"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\TV\Font_8x16.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\TV\TV.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "UART"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\UART\UART.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\SPG290_Constants.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\..\SPG290\include\SPG290_Registers.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\Resource.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Resource.inc
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Resource Files"
#PROP Default_Filter = rc;

# Begin Source File
SOURCE=.\hyperscan.rc
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Dependencies"
#PROP Default_Filter = 

# Begin Source File
SOURCE=.\hyperscan_Prog.ld
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hyperscan_startup.s
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Makefile
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Headers"
#PROP Default_Filter = h;

# End Group
# End SubItem
# End Project
