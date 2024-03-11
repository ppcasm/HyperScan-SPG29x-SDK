####################################################################################################
#
#	Created by S+core IDE V2.6.1		00:20:09	03/11/24
#
####################################################################################################

OUTDIR	= Debug
APPDIR	= C:\Sunplus\S_CORE~1.1

TOOLDIR	= C:\Sunplus\S_CORE~1.1\gnu\bin
INCLUDES =  -I"C:/Users/ppcas/OneDrive/Documents/GitHub/HyperScan-SPG29x-SDK/hyperscan/examples/DEMO/"
LIBFOLDER = 

CC	= "$(TOOLDIR)\score-elf-gcc"
CPP	= "$(TOOLDIR)\score-elf-g++"
AS	= "$(TOOLDIR)\score-elf-as"
AR	= "$(TOOLDIR)\score-elf-ar"
LD	= "$(TOOLDIR)\score-elf-ld"
NM	= "$(TOOLDIR)\score-elf-nm"
RM	= "$(TOOLDIR)\rm"

OBJCOPY	= "$(TOOLDIR)\score-elf-objcopy"
OBJDUMP	= "$(TOOLDIR)\score-elf-objdump"
LDSCRIPT	= "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\hyperscan_Prog.ld"

CCDEFFLAG	= -mscore7 -mel -g -Wall -nostartfiles
CCADDFLAG	= 
ASDEFFLAG	= -Wa,-gdwarf-2  -x assembler-with-cpp
ASADDFLAG	= 
LDDEFFLAG	= -T$(LDSCRIPT)   -lm -lc -lgcc
LDADDFLAG	= -Wl,-Map,$@.map
RESDEFFLAG	= -EL -Tresource.ld  -b binary
RMFLAG		= -rf

BINFILE		= "$(OUTDIR)\hyperscan.elf"


RESFILES	=

OBJFILES	=\
	"$(OUTDIR)\hyperscan_startup.o"\
	"$(OUTDIR)\main.o"\
	"$(OUTDIR)\libgloss.o"\
	"$(OUTDIR)\UART.o"\
	"$(OUTDIR)\TV.o"\
	"$(OUTDIR)\NorFlash.o"\
	"$(OUTDIR)\User_IRQ.o"\
	"$(OUTDIR)\sys_isr.o"\
	"$(OUTDIR)\I2C.o"\
	"$(OUTDIR)\HS_Controller.o"

"$(OUTDIR)\HS_Controller.o" "$(OUTDIR)\HS_Controller.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\hslibs\HS_Controller\HS_Controller.c"
	@echo HS_Controller.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\HS_Controller.d" -MT"$(OUTDIR)\HS_Controller.d" -o "$(OUTDIR)\HS_Controller.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\hslibs\HS_Controller\HS_Controller.c" 

"$(OUTDIR)\I2C.o" "$(OUTDIR)\I2C.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\I2C\I2C.c"
	@echo I2C.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\I2C.d" -MT"$(OUTDIR)\I2C.d" -o "$(OUTDIR)\I2C.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\I2C\I2C.c" 

"$(OUTDIR)\sys_isr.o" "$(OUTDIR)\sys_isr.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\IRQ\sys_isr.c"
	@echo sys_isr.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\sys_isr.d" -MT"$(OUTDIR)\sys_isr.d" -o "$(OUTDIR)\sys_isr.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\IRQ\sys_isr.c" 

"$(OUTDIR)\User_IRQ.o" "$(OUTDIR)\User_IRQ.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\IRQ\User_IRQ.c"
	@echo User_IRQ.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\User_IRQ.d" -MT"$(OUTDIR)\User_IRQ.d" -o "$(OUTDIR)\User_IRQ.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\IRQ\User_IRQ.c" 

"$(OUTDIR)\NorFlash.o" "$(OUTDIR)\NorFlash.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\NorFlash\NorFlash.c"
	@echo NorFlash.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\NorFlash.d" -MT"$(OUTDIR)\NorFlash.d" -o "$(OUTDIR)\NorFlash.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\NorFlash\NorFlash.c" 

"$(OUTDIR)\TV.o" "$(OUTDIR)\TV.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\TV\TV.c"
	@echo TV.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\TV.d" -MT"$(OUTDIR)\TV.d" -o "$(OUTDIR)\TV.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\TV\TV.c" 

"$(OUTDIR)\UART.o" "$(OUTDIR)\UART.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\UART\UART.c"
	@echo UART.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\UART.d" -MT"$(OUTDIR)\UART.d" -o "$(OUTDIR)\UART.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\UART\UART.c" 

"$(OUTDIR)\libgloss.o" "$(OUTDIR)\libgloss.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\libgloss.c"
	@echo libgloss.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\libgloss.d" -MT"$(OUTDIR)\libgloss.d" -o "$(OUTDIR)\libgloss.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\scorelibs\libgloss.c" 

"$(OUTDIR)\main.o" "$(OUTDIR)\main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\main.c"
	@echo main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\main.d" -MT"$(OUTDIR)\main.d" -o "$(OUTDIR)\main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\main.c" 

"$(OUTDIR)\hyperscan_startup.o" "$(OUTDIR)\hyperscan_startup.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\hyperscan_startup.s"
	@echo hyperscan_startup.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\hyperscan_startup.d" -MT"$(OUTDIR)\hyperscan_startup.d" -o "$(OUTDIR)\hyperscan_startup.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\hyperscan_startup.s" 


all : "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	@if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

LINKLIB	= 

$(BINFILE) : $(RESFILES) $(OBJFILES) $(LINKLIB) $(LDSCRIPT) "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DEMO\Resource.h"
			@echo linking...
			@$(CC) $(CCDEFFLAG) $(CCADDFLAG) -B$(TOOLDIR) "Obj.lst" -o $(BINFILE) "Lib.lst" $(LIBFOLDER) $(LDDEFFLAG) $(LDADDFLAG)
			@$(OBJCOPY) -O binary $@ $@.bin
			@echo creat .srec for simulator...
			@$(OBJCOPY) -O srec $@  $@.srec
.PHONY: clean
clean :
	@$(RM) $(RMFLAG) ".\hslibs.fms"
DEPFILES	=\
	"$(OUTDIR)\hyperscan_startup.d"\
	"$(OUTDIR)\main.d"\
	"$(OUTDIR)\libgloss.d"\
	"$(OUTDIR)\UART.d"\
	"$(OUTDIR)\TV.d"\
	"$(OUTDIR)\NorFlash.d"\
	"$(OUTDIR)\User_IRQ.d"\
	"$(OUTDIR)\sys_isr.d"\
	"$(OUTDIR)\I2C.d"\
	"$(OUTDIR)\HS_Controller.d"

ifneq ($(wildcard $(DEPFILES)),)
include $(DEPFILES)
endif

