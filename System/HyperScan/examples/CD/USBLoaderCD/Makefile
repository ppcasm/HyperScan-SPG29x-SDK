####################################################################################################
#
#	Created by S+core IDE V2.6.1		17:03:45	04/03/24
#
####################################################################################################

OUTDIR	= Debug
APPDIR	= C:\Sunplus\S_CORE~1.1

TOOLDIR	= C:\Sunplus\S_CORE~1.1\gnu\bin
INCLUDES =  -I"C:/Users/ppcas/OneDrive/Documents/GitHub/HyperScan-SPG29x-SDK/System/HyperScan/examples/CD/USBLoaderCD/"
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
LDSCRIPT	= "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\hyperscan_Prog.ld"

CCDEFFLAG	= -mscore7 -mel -g -Wall
CCADDFLAG	= 
ASDEFFLAG	= -Wa,-gdwarf-2  -x assembler-with-cpp
ASADDFLAG	= 
LDDEFFLAG	= -T$(LDSCRIPT)   -lm -lc -lgcc
LDADDFLAG	= -Wl,-Map,$@.map
RESDEFFLAG	= -EL -Tresource.ld  -b binary
RMFLAG		= -rf

BINFILE		= "$(OUTDIR)\hyperscan.elf"


RESFILES	=\
	"$(OUTDIR)\RES_CDUSBLDR_BIN.res"

"$(OUTDIR)\RES_CDUSBLDR_BIN.res": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\cdusbldr.bin"
	@echo Compiling resource: cdusbldr.bin
	@$(LD) $(RESDEFFLAG) -o "$(OUTDIR)\RES_CDUSBLDR_BIN.res" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\cdusbldr.bin" 

OBJFILES	=\
	"$(OUTDIR)\hyperscan_startup.o"\
	"$(OUTDIR)\main.o"\
	"$(OUTDIR)\libgloss.o"\
	"$(OUTDIR)\UART.o"\
	"$(OUTDIR)\User_IRQ.o"\
	"$(OUTDIR)\Sys_isr.o"\
	"$(OUTDIR)\Sys_IRQ.o"

"$(OUTDIR)\Sys_IRQ.o" "$(OUTDIR)\Sys_IRQ.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_IRQ.c"
	@echo Sys_IRQ.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\Sys_IRQ.d" -MT"$(OUTDIR)\Sys_IRQ.d" -o "$(OUTDIR)\Sys_IRQ.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_IRQ.c" 

"$(OUTDIR)\Sys_isr.o" "$(OUTDIR)\Sys_isr.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_isr.s"
	@echo Sys_isr.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\Sys_isr.d" -MT"$(OUTDIR)\Sys_isr.d" -o "$(OUTDIR)\Sys_isr.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_isr.s" 

"$(OUTDIR)\User_IRQ.o" "$(OUTDIR)\User_IRQ.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\User_IRQ.c"
	@echo User_IRQ.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\User_IRQ.d" -MT"$(OUTDIR)\User_IRQ.d" -o "$(OUTDIR)\User_IRQ.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\User_IRQ.c" 

"$(OUTDIR)\UART.o" "$(OUTDIR)\UART.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\UART\UART.c"
	@echo UART.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\UART.d" -MT"$(OUTDIR)\UART.d" -o "$(OUTDIR)\UART.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\UART\UART.c" 

"$(OUTDIR)\libgloss.o" "$(OUTDIR)\libgloss.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\libgloss.c"
	@echo libgloss.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\libgloss.d" -MT"$(OUTDIR)\libgloss.d" -o "$(OUTDIR)\libgloss.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\libgloss.c" 

"$(OUTDIR)\main.o" "$(OUTDIR)\main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\main.c"
	@echo main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\main.d" -MT"$(OUTDIR)\main.d" -o "$(OUTDIR)\main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\main.c" 

"$(OUTDIR)\hyperscan_startup.o" "$(OUTDIR)\hyperscan_startup.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\hyperscan_startup.s"
	@echo hyperscan_startup.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\hyperscan_startup.d" -MT"$(OUTDIR)\hyperscan_startup.d" -o "$(OUTDIR)\hyperscan_startup.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\hyperscan_startup.s" 


all : "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	@if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

LINKLIB	= 

$(BINFILE) : $(RESFILES) $(OBJFILES) $(LINKLIB) $(LDSCRIPT) "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\CD\USBLoaderCD\Resource.h"
			@echo linking...
			@$(CC) $(CCDEFFLAG) $(CCADDFLAG) -B$(TOOLDIR) "Obj.lst" -o $(BINFILE) "Lib.lst" $(LIBFOLDER) $(LDDEFFLAG) $(LDADDFLAG)
			@$(OBJDUMP) -G $@ > $@.dbg
			@$(OBJCOPY) -O binary $@ $@.bin
			@echo creat .srec for simulator...
			@$(OBJCOPY) -O srec $@  $@.srec
.PHONY: clean
clean :
	@$(RM) $(RMFLAG) ".\IRQ.fms"
DEPFILES	=\
	"$(OUTDIR)\hyperscan_startup.d"\
	"$(OUTDIR)\main.d"\
	"$(OUTDIR)\libgloss.d"\
	"$(OUTDIR)\UART.d"\
	"$(OUTDIR)\User_IRQ.d"\
	"$(OUTDIR)\Sys_isr.d"\
	"$(OUTDIR)\Sys_IRQ.d"

ifneq ($(wildcard $(DEPFILES)),)
include $(DEPFILES)
endif

