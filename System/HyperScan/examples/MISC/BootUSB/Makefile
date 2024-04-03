####################################################################################################
#
#	Created by S+core IDE V2.6.1		17:06:18	04/03/24
#
####################################################################################################

OUTDIR	= Debug
APPDIR	= C:\Sunplus\S_CORE~1.1

TOOLDIR	= C:\Sunplus\S_CORE~1.1\gnu\bin
INCLUDES =  -I"C:/Users/ppcas/OneDrive/Documents/GitHub/HyperScan-SPG29x-SDK/System/HyperScan/examples/MISC/BootUSB/"
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
LDSCRIPT	= "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\hyperscan_Prog.ld"

CCDEFFLAG	= -mscore7 -mel -g -Wall -nostdlib -O2
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
	"$(OUTDIR)\ff.o"\
	"$(OUTDIR)\diskio.o"

"$(OUTDIR)\diskio.o" "$(OUTDIR)\diskio.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\diskio.c"
	@echo diskio.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\diskio.d" -MT"$(OUTDIR)\diskio.d" -o "$(OUTDIR)\diskio.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\diskio.c" 

"$(OUTDIR)\ff.o" "$(OUTDIR)\ff.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\ff.c"
	@echo ff.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\ff.d" -MT"$(OUTDIR)\ff.d" -o "$(OUTDIR)\ff.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\ff.c" 

"$(OUTDIR)\main.o" "$(OUTDIR)\main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\main.c"
	@echo main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\main.d" -MT"$(OUTDIR)\main.d" -o "$(OUTDIR)\main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\main.c" 

"$(OUTDIR)\hyperscan_startup.o" "$(OUTDIR)\hyperscan_startup.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\hyperscan_startup.s"
	@echo hyperscan_startup.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\hyperscan_startup.d" -MT"$(OUTDIR)\hyperscan_startup.d" -o "$(OUTDIR)\hyperscan_startup.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\hyperscan_startup.s" 


all : "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	@if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

LINKLIB	= 

$(BINFILE) : $(RESFILES) $(OBJFILES) $(LINKLIB) $(LDSCRIPT) "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\MISC\BootUSB\Resource.h"
			@echo linking...
			@$(CC) $(CCDEFFLAG) $(CCADDFLAG) -B$(TOOLDIR) "Obj.lst" -o $(BINFILE) "Lib.lst" $(LIBFOLDER) $(LDDEFFLAG) $(LDADDFLAG)
			@$(OBJCOPY) -O binary $@ $@.bin
			@echo creat .srec for simulator...
			@$(OBJCOPY) -O srec $@  $@.srec
.PHONY: clean
clean :
	@$(RM) $(RMFLAG) ".\FatFS.fms"
DEPFILES	=\
	"$(OUTDIR)\hyperscan_startup.d"\
	"$(OUTDIR)\main.d"\
	"$(OUTDIR)\ff.d"\
	"$(OUTDIR)\diskio.d"

ifneq ($(wildcard $(DEPFILES)),)
include $(DEPFILES)
endif

