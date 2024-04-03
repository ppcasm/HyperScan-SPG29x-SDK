####################################################################################################
#
#	Created by S+core IDE V2.6.1		05:00:28	04/03/24
#
####################################################################################################

OUTDIR	= Debug
APPDIR	= C:\Sunplus\S_CORE~1.1

TOOLDIR	= C:\Sunplus\S_CORE~1.1\gnu\bin
INCLUDES =  -I"C:/Users/ppcas/OneDrive/Documents/GitHub/HyperScan-SPG29x-SDK/System/HyperScan/examples/USB/DOOM/"
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
LDSCRIPT	= "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hyperscan_Prog.ld"

CCDEFFLAG	= -mscore7 -mel -g -Wall -O2 -D NEW_HEAPSIZE=8*(1024*1024)
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
	"$(OUTDIR)\z_zone.o"\
	"$(OUTDIR)\wi_stuff.o"\
	"$(OUTDIR)\w_wad.o"\
	"$(OUTDIR)\w_main.o"\
	"$(OUTDIR)\w_file_stdc.o"\
	"$(OUTDIR)\w_file.o"\
	"$(OUTDIR)\w_checksum.o"\
	"$(OUTDIR)\v_video.o"\
	"$(OUTDIR)\tables.o"\
	"$(OUTDIR)\statdump.o"\
	"$(OUTDIR)\st_stuff.o"\
	"$(OUTDIR)\st_lib.o"\
	"$(OUTDIR)\sounds.o"\
	"$(OUTDIR)\sha1.o"\
	"$(OUTDIR)\s_sound.o"\
	"$(OUTDIR)\r_things.o"\
	"$(OUTDIR)\r_sky.o"\
	"$(OUTDIR)\r_segs.o"\
	"$(OUTDIR)\r_plane.o"\
	"$(OUTDIR)\r_main.o"\
	"$(OUTDIR)\r_draw.o"\
	"$(OUTDIR)\r_data.o"\
	"$(OUTDIR)\r_bsp.o"\
	"$(OUTDIR)\p_user.o"\
	"$(OUTDIR)\p_tick.o"\
	"$(OUTDIR)\p_telept.o"\
	"$(OUTDIR)\p_switch.o"\
	"$(OUTDIR)\p_spec.o"\
	"$(OUTDIR)\p_sight.o"\
	"$(OUTDIR)\p_setup.o"\
	"$(OUTDIR)\p_saveg.o"\
	"$(OUTDIR)\p_pspr.o"\
	"$(OUTDIR)\p_plats.o"\
	"$(OUTDIR)\p_mobj.o"\
	"$(OUTDIR)\p_maputl.o"\
	"$(OUTDIR)\p_map.o"\
	"$(OUTDIR)\p_lights.o"\
	"$(OUTDIR)\p_inter.o"\
	"$(OUTDIR)\p_floor.o"\
	"$(OUTDIR)\p_enemy.o"\
	"$(OUTDIR)\p_doors.o"\
	"$(OUTDIR)\p_ceilng.o"\
	"$(OUTDIR)\mus2mid.o"\
	"$(OUTDIR)\memio.o"\
	"$(OUTDIR)\m_random.o"\
	"$(OUTDIR)\m_misc.o"\
	"$(OUTDIR)\m_menu.o"\
	"$(OUTDIR)\m_fixed.o"\
	"$(OUTDIR)\m_controls.o"\
	"$(OUTDIR)\m_config.o"\
	"$(OUTDIR)\m_cheat.o"\
	"$(OUTDIR)\m_bbox.o"\
	"$(OUTDIR)\m_argv.o"\
	"$(OUTDIR)\info.o"\
	"$(OUTDIR)\i_video.o"\
	"$(OUTDIR)\i_timer.o"\
	"$(OUTDIR)\i_system.o"\
	"$(OUTDIR)\i_sound.o"\
	"$(OUTDIR)\i_scale.o"\
	"$(OUTDIR)\i_joystick.o"\
	"$(OUTDIR)\i_input.o"\
	"$(OUTDIR)\i_endoom.o"\
	"$(OUTDIR)\i_cdmus.o"\
	"$(OUTDIR)\hu_stuff.o"\
	"$(OUTDIR)\hu_lib.o"\
	"$(OUTDIR)\gusconf.o"\
	"$(OUTDIR)\g_game.o"\
	"$(OUTDIR)\f_wipe.o"\
	"$(OUTDIR)\f_finale.o"\
	"$(OUTDIR)\dummy.o"\
	"$(OUTDIR)\dstrings.o"\
	"$(OUTDIR)\doomstat.o"\
	"$(OUTDIR)\doomgeneric_hyperscan.o"\
	"$(OUTDIR)\doomgeneric.o"\
	"$(OUTDIR)\doomdef.o"\
	"$(OUTDIR)\d_net.o"\
	"$(OUTDIR)\d_mode.o"\
	"$(OUTDIR)\d_main.o"\
	"$(OUTDIR)\d_loop.o"\
	"$(OUTDIR)\d_iwad.o"\
	"$(OUTDIR)\d_items.o"\
	"$(OUTDIR)\d_event.o"\
	"$(OUTDIR)\am_map.o"\
	"$(OUTDIR)\libgloss.o"\
	"$(OUTDIR)\UART.o"\
	"$(OUTDIR)\TV.o"\
	"$(OUTDIR)\NorFlash.o"\
	"$(OUTDIR)\User_IRQ.o"\
	"$(OUTDIR)\Sys_isr.o"\
	"$(OUTDIR)\Sys_IRQ.o"\
	"$(OUTDIR)\I2C.o"\
	"$(OUTDIR)\HS_Controller.o"\
	"$(OUTDIR)\ff.o"\
	"$(OUTDIR)\diskio.o"

"$(OUTDIR)\diskio.o" "$(OUTDIR)\diskio.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\diskio.c"
	@echo diskio.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\diskio.d" -MT"$(OUTDIR)\diskio.d" -o "$(OUTDIR)\diskio.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\diskio.c" 

"$(OUTDIR)\ff.o" "$(OUTDIR)\ff.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\ff.c"
	@echo ff.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\ff.d" -MT"$(OUTDIR)\ff.d" -o "$(OUTDIR)\ff.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\FatFS\ff.c" 

"$(OUTDIR)\HS_Controller.o" "$(OUTDIR)\HS_Controller.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\HS_Controller\HS_Controller.c"
	@echo HS_Controller.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\HS_Controller.d" -MT"$(OUTDIR)\HS_Controller.d" -o "$(OUTDIR)\HS_Controller.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\hslibs\HS_Controller\HS_Controller.c" 

"$(OUTDIR)\I2C.o" "$(OUTDIR)\I2C.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\I2C\I2C.c"
	@echo I2C.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\I2C.d" -MT"$(OUTDIR)\I2C.d" -o "$(OUTDIR)\I2C.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\I2C\I2C.c" 

"$(OUTDIR)\Sys_IRQ.o" "$(OUTDIR)\Sys_IRQ.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_IRQ.c"
	@echo Sys_IRQ.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\Sys_IRQ.d" -MT"$(OUTDIR)\Sys_IRQ.d" -o "$(OUTDIR)\Sys_IRQ.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_IRQ.c" 

"$(OUTDIR)\Sys_isr.o" "$(OUTDIR)\Sys_isr.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_isr.s"
	@echo Sys_isr.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\Sys_isr.d" -MT"$(OUTDIR)\Sys_isr.d" -o "$(OUTDIR)\Sys_isr.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\Sys_isr.s" 

"$(OUTDIR)\User_IRQ.o" "$(OUTDIR)\User_IRQ.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\User_IRQ.c"
	@echo User_IRQ.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\User_IRQ.d" -MT"$(OUTDIR)\User_IRQ.d" -o "$(OUTDIR)\User_IRQ.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\IRQ\User_IRQ.c" 

"$(OUTDIR)\NorFlash.o" "$(OUTDIR)\NorFlash.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\NorFlash\NorFlash.c"
	@echo NorFlash.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\NorFlash.d" -MT"$(OUTDIR)\NorFlash.d" -o "$(OUTDIR)\NorFlash.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\NorFlash\NorFlash.c" 

"$(OUTDIR)\TV.o" "$(OUTDIR)\TV.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\TV\TV.c"
	@echo TV.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\TV.d" -MT"$(OUTDIR)\TV.d" -o "$(OUTDIR)\TV.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\TV\TV.c" 

"$(OUTDIR)\UART.o" "$(OUTDIR)\UART.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\UART\UART.c"
	@echo UART.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\UART.d" -MT"$(OUTDIR)\UART.d" -o "$(OUTDIR)\UART.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\UART\UART.c" 

"$(OUTDIR)\libgloss.o" "$(OUTDIR)\libgloss.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\libgloss.c"
	@echo libgloss.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\libgloss.d" -MT"$(OUTDIR)\libgloss.d" -o "$(OUTDIR)\libgloss.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\SPG290\scorelibs\libgloss.c" 

"$(OUTDIR)\am_map.o" "$(OUTDIR)\am_map.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\am_map.c"
	@echo am_map.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\am_map.d" -MT"$(OUTDIR)\am_map.d" -o "$(OUTDIR)\am_map.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\am_map.c" 

"$(OUTDIR)\d_event.o" "$(OUTDIR)\d_event.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_event.c"
	@echo d_event.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_event.d" -MT"$(OUTDIR)\d_event.d" -o "$(OUTDIR)\d_event.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_event.c" 

"$(OUTDIR)\d_items.o" "$(OUTDIR)\d_items.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_items.c"
	@echo d_items.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_items.d" -MT"$(OUTDIR)\d_items.d" -o "$(OUTDIR)\d_items.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_items.c" 

"$(OUTDIR)\d_iwad.o" "$(OUTDIR)\d_iwad.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_iwad.c"
	@echo d_iwad.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_iwad.d" -MT"$(OUTDIR)\d_iwad.d" -o "$(OUTDIR)\d_iwad.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_iwad.c" 

"$(OUTDIR)\d_loop.o" "$(OUTDIR)\d_loop.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_loop.c"
	@echo d_loop.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_loop.d" -MT"$(OUTDIR)\d_loop.d" -o "$(OUTDIR)\d_loop.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_loop.c" 

"$(OUTDIR)\d_main.o" "$(OUTDIR)\d_main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_main.c"
	@echo d_main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_main.d" -MT"$(OUTDIR)\d_main.d" -o "$(OUTDIR)\d_main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_main.c" 

"$(OUTDIR)\d_mode.o" "$(OUTDIR)\d_mode.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_mode.c"
	@echo d_mode.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_mode.d" -MT"$(OUTDIR)\d_mode.d" -o "$(OUTDIR)\d_mode.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_mode.c" 

"$(OUTDIR)\d_net.o" "$(OUTDIR)\d_net.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_net.c"
	@echo d_net.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\d_net.d" -MT"$(OUTDIR)\d_net.d" -o "$(OUTDIR)\d_net.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\d_net.c" 

"$(OUTDIR)\doomdef.o" "$(OUTDIR)\doomdef.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomdef.c"
	@echo doomdef.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\doomdef.d" -MT"$(OUTDIR)\doomdef.d" -o "$(OUTDIR)\doomdef.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomdef.c" 

"$(OUTDIR)\doomgeneric.o" "$(OUTDIR)\doomgeneric.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomgeneric.c"
	@echo doomgeneric.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\doomgeneric.d" -MT"$(OUTDIR)\doomgeneric.d" -o "$(OUTDIR)\doomgeneric.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomgeneric.c" 

"$(OUTDIR)\doomgeneric_hyperscan.o" "$(OUTDIR)\doomgeneric_hyperscan.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomgeneric_hyperscan.c"
	@echo doomgeneric_hyperscan.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\doomgeneric_hyperscan.d" -MT"$(OUTDIR)\doomgeneric_hyperscan.d" -o "$(OUTDIR)\doomgeneric_hyperscan.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomgeneric_hyperscan.c" 

"$(OUTDIR)\doomstat.o" "$(OUTDIR)\doomstat.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomstat.c"
	@echo doomstat.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\doomstat.d" -MT"$(OUTDIR)\doomstat.d" -o "$(OUTDIR)\doomstat.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\doomstat.c" 

"$(OUTDIR)\dstrings.o" "$(OUTDIR)\dstrings.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\dstrings.c"
	@echo dstrings.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\dstrings.d" -MT"$(OUTDIR)\dstrings.d" -o "$(OUTDIR)\dstrings.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\dstrings.c" 

"$(OUTDIR)\dummy.o" "$(OUTDIR)\dummy.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\dummy.c"
	@echo dummy.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\dummy.d" -MT"$(OUTDIR)\dummy.d" -o "$(OUTDIR)\dummy.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\dummy.c" 

"$(OUTDIR)\f_finale.o" "$(OUTDIR)\f_finale.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\f_finale.c"
	@echo f_finale.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\f_finale.d" -MT"$(OUTDIR)\f_finale.d" -o "$(OUTDIR)\f_finale.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\f_finale.c" 

"$(OUTDIR)\f_wipe.o" "$(OUTDIR)\f_wipe.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\f_wipe.c"
	@echo f_wipe.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\f_wipe.d" -MT"$(OUTDIR)\f_wipe.d" -o "$(OUTDIR)\f_wipe.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\f_wipe.c" 

"$(OUTDIR)\g_game.o" "$(OUTDIR)\g_game.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\g_game.c"
	@echo g_game.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\g_game.d" -MT"$(OUTDIR)\g_game.d" -o "$(OUTDIR)\g_game.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\g_game.c" 

"$(OUTDIR)\gusconf.o" "$(OUTDIR)\gusconf.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\gusconf.c"
	@echo gusconf.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\gusconf.d" -MT"$(OUTDIR)\gusconf.d" -o "$(OUTDIR)\gusconf.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\gusconf.c" 

"$(OUTDIR)\hu_lib.o" "$(OUTDIR)\hu_lib.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hu_lib.c"
	@echo hu_lib.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\hu_lib.d" -MT"$(OUTDIR)\hu_lib.d" -o "$(OUTDIR)\hu_lib.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hu_lib.c" 

"$(OUTDIR)\hu_stuff.o" "$(OUTDIR)\hu_stuff.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hu_stuff.c"
	@echo hu_stuff.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\hu_stuff.d" -MT"$(OUTDIR)\hu_stuff.d" -o "$(OUTDIR)\hu_stuff.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hu_stuff.c" 

"$(OUTDIR)\i_cdmus.o" "$(OUTDIR)\i_cdmus.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_cdmus.c"
	@echo i_cdmus.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_cdmus.d" -MT"$(OUTDIR)\i_cdmus.d" -o "$(OUTDIR)\i_cdmus.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_cdmus.c" 

"$(OUTDIR)\i_endoom.o" "$(OUTDIR)\i_endoom.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_endoom.c"
	@echo i_endoom.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_endoom.d" -MT"$(OUTDIR)\i_endoom.d" -o "$(OUTDIR)\i_endoom.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_endoom.c" 

"$(OUTDIR)\i_input.o" "$(OUTDIR)\i_input.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_input.c"
	@echo i_input.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_input.d" -MT"$(OUTDIR)\i_input.d" -o "$(OUTDIR)\i_input.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_input.c" 

"$(OUTDIR)\i_joystick.o" "$(OUTDIR)\i_joystick.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_joystick.c"
	@echo i_joystick.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_joystick.d" -MT"$(OUTDIR)\i_joystick.d" -o "$(OUTDIR)\i_joystick.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_joystick.c" 

"$(OUTDIR)\i_scale.o" "$(OUTDIR)\i_scale.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_scale.c"
	@echo i_scale.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_scale.d" -MT"$(OUTDIR)\i_scale.d" -o "$(OUTDIR)\i_scale.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_scale.c" 

"$(OUTDIR)\i_sound.o" "$(OUTDIR)\i_sound.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_sound.c"
	@echo i_sound.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_sound.d" -MT"$(OUTDIR)\i_sound.d" -o "$(OUTDIR)\i_sound.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_sound.c" 

"$(OUTDIR)\i_system.o" "$(OUTDIR)\i_system.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_system.c"
	@echo i_system.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_system.d" -MT"$(OUTDIR)\i_system.d" -o "$(OUTDIR)\i_system.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_system.c" 

"$(OUTDIR)\i_timer.o" "$(OUTDIR)\i_timer.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_timer.c"
	@echo i_timer.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_timer.d" -MT"$(OUTDIR)\i_timer.d" -o "$(OUTDIR)\i_timer.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_timer.c" 

"$(OUTDIR)\i_video.o" "$(OUTDIR)\i_video.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_video.c"
	@echo i_video.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\i_video.d" -MT"$(OUTDIR)\i_video.d" -o "$(OUTDIR)\i_video.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\i_video.c" 

"$(OUTDIR)\info.o" "$(OUTDIR)\info.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\info.c"
	@echo info.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\info.d" -MT"$(OUTDIR)\info.d" -o "$(OUTDIR)\info.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\info.c" 

"$(OUTDIR)\m_argv.o" "$(OUTDIR)\m_argv.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_argv.c"
	@echo m_argv.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_argv.d" -MT"$(OUTDIR)\m_argv.d" -o "$(OUTDIR)\m_argv.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_argv.c" 

"$(OUTDIR)\m_bbox.o" "$(OUTDIR)\m_bbox.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_bbox.c"
	@echo m_bbox.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_bbox.d" -MT"$(OUTDIR)\m_bbox.d" -o "$(OUTDIR)\m_bbox.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_bbox.c" 

"$(OUTDIR)\m_cheat.o" "$(OUTDIR)\m_cheat.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_cheat.c"
	@echo m_cheat.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_cheat.d" -MT"$(OUTDIR)\m_cheat.d" -o "$(OUTDIR)\m_cheat.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_cheat.c" 

"$(OUTDIR)\m_config.o" "$(OUTDIR)\m_config.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_config.c"
	@echo m_config.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_config.d" -MT"$(OUTDIR)\m_config.d" -o "$(OUTDIR)\m_config.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_config.c" 

"$(OUTDIR)\m_controls.o" "$(OUTDIR)\m_controls.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_controls.c"
	@echo m_controls.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_controls.d" -MT"$(OUTDIR)\m_controls.d" -o "$(OUTDIR)\m_controls.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_controls.c" 

"$(OUTDIR)\m_fixed.o" "$(OUTDIR)\m_fixed.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_fixed.c"
	@echo m_fixed.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_fixed.d" -MT"$(OUTDIR)\m_fixed.d" -o "$(OUTDIR)\m_fixed.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_fixed.c" 

"$(OUTDIR)\m_menu.o" "$(OUTDIR)\m_menu.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_menu.c"
	@echo m_menu.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_menu.d" -MT"$(OUTDIR)\m_menu.d" -o "$(OUTDIR)\m_menu.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_menu.c" 

"$(OUTDIR)\m_misc.o" "$(OUTDIR)\m_misc.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_misc.c"
	@echo m_misc.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_misc.d" -MT"$(OUTDIR)\m_misc.d" -o "$(OUTDIR)\m_misc.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_misc.c" 

"$(OUTDIR)\m_random.o" "$(OUTDIR)\m_random.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_random.c"
	@echo m_random.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\m_random.d" -MT"$(OUTDIR)\m_random.d" -o "$(OUTDIR)\m_random.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\m_random.c" 

"$(OUTDIR)\memio.o" "$(OUTDIR)\memio.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\memio.c"
	@echo memio.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\memio.d" -MT"$(OUTDIR)\memio.d" -o "$(OUTDIR)\memio.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\memio.c" 

"$(OUTDIR)\mus2mid.o" "$(OUTDIR)\mus2mid.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\mus2mid.c"
	@echo mus2mid.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\mus2mid.d" -MT"$(OUTDIR)\mus2mid.d" -o "$(OUTDIR)\mus2mid.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\mus2mid.c" 

"$(OUTDIR)\p_ceilng.o" "$(OUTDIR)\p_ceilng.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_ceilng.c"
	@echo p_ceilng.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_ceilng.d" -MT"$(OUTDIR)\p_ceilng.d" -o "$(OUTDIR)\p_ceilng.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_ceilng.c" 

"$(OUTDIR)\p_doors.o" "$(OUTDIR)\p_doors.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_doors.c"
	@echo p_doors.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_doors.d" -MT"$(OUTDIR)\p_doors.d" -o "$(OUTDIR)\p_doors.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_doors.c" 

"$(OUTDIR)\p_enemy.o" "$(OUTDIR)\p_enemy.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_enemy.c"
	@echo p_enemy.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_enemy.d" -MT"$(OUTDIR)\p_enemy.d" -o "$(OUTDIR)\p_enemy.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_enemy.c" 

"$(OUTDIR)\p_floor.o" "$(OUTDIR)\p_floor.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_floor.c"
	@echo p_floor.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_floor.d" -MT"$(OUTDIR)\p_floor.d" -o "$(OUTDIR)\p_floor.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_floor.c" 

"$(OUTDIR)\p_inter.o" "$(OUTDIR)\p_inter.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_inter.c"
	@echo p_inter.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_inter.d" -MT"$(OUTDIR)\p_inter.d" -o "$(OUTDIR)\p_inter.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_inter.c" 

"$(OUTDIR)\p_lights.o" "$(OUTDIR)\p_lights.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_lights.c"
	@echo p_lights.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_lights.d" -MT"$(OUTDIR)\p_lights.d" -o "$(OUTDIR)\p_lights.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_lights.c" 

"$(OUTDIR)\p_map.o" "$(OUTDIR)\p_map.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_map.c"
	@echo p_map.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_map.d" -MT"$(OUTDIR)\p_map.d" -o "$(OUTDIR)\p_map.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_map.c" 

"$(OUTDIR)\p_maputl.o" "$(OUTDIR)\p_maputl.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_maputl.c"
	@echo p_maputl.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_maputl.d" -MT"$(OUTDIR)\p_maputl.d" -o "$(OUTDIR)\p_maputl.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_maputl.c" 

"$(OUTDIR)\p_mobj.o" "$(OUTDIR)\p_mobj.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_mobj.c"
	@echo p_mobj.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_mobj.d" -MT"$(OUTDIR)\p_mobj.d" -o "$(OUTDIR)\p_mobj.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_mobj.c" 

"$(OUTDIR)\p_plats.o" "$(OUTDIR)\p_plats.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_plats.c"
	@echo p_plats.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_plats.d" -MT"$(OUTDIR)\p_plats.d" -o "$(OUTDIR)\p_plats.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_plats.c" 

"$(OUTDIR)\p_pspr.o" "$(OUTDIR)\p_pspr.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_pspr.c"
	@echo p_pspr.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_pspr.d" -MT"$(OUTDIR)\p_pspr.d" -o "$(OUTDIR)\p_pspr.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_pspr.c" 

"$(OUTDIR)\p_saveg.o" "$(OUTDIR)\p_saveg.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_saveg.c"
	@echo p_saveg.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_saveg.d" -MT"$(OUTDIR)\p_saveg.d" -o "$(OUTDIR)\p_saveg.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_saveg.c" 

"$(OUTDIR)\p_setup.o" "$(OUTDIR)\p_setup.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_setup.c"
	@echo p_setup.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_setup.d" -MT"$(OUTDIR)\p_setup.d" -o "$(OUTDIR)\p_setup.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_setup.c" 

"$(OUTDIR)\p_sight.o" "$(OUTDIR)\p_sight.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_sight.c"
	@echo p_sight.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_sight.d" -MT"$(OUTDIR)\p_sight.d" -o "$(OUTDIR)\p_sight.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_sight.c" 

"$(OUTDIR)\p_spec.o" "$(OUTDIR)\p_spec.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_spec.c"
	@echo p_spec.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_spec.d" -MT"$(OUTDIR)\p_spec.d" -o "$(OUTDIR)\p_spec.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_spec.c" 

"$(OUTDIR)\p_switch.o" "$(OUTDIR)\p_switch.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_switch.c"
	@echo p_switch.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_switch.d" -MT"$(OUTDIR)\p_switch.d" -o "$(OUTDIR)\p_switch.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_switch.c" 

"$(OUTDIR)\p_telept.o" "$(OUTDIR)\p_telept.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_telept.c"
	@echo p_telept.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_telept.d" -MT"$(OUTDIR)\p_telept.d" -o "$(OUTDIR)\p_telept.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_telept.c" 

"$(OUTDIR)\p_tick.o" "$(OUTDIR)\p_tick.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_tick.c"
	@echo p_tick.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_tick.d" -MT"$(OUTDIR)\p_tick.d" -o "$(OUTDIR)\p_tick.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_tick.c" 

"$(OUTDIR)\p_user.o" "$(OUTDIR)\p_user.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_user.c"
	@echo p_user.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\p_user.d" -MT"$(OUTDIR)\p_user.d" -o "$(OUTDIR)\p_user.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\p_user.c" 

"$(OUTDIR)\r_bsp.o" "$(OUTDIR)\r_bsp.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_bsp.c"
	@echo r_bsp.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_bsp.d" -MT"$(OUTDIR)\r_bsp.d" -o "$(OUTDIR)\r_bsp.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_bsp.c" 

"$(OUTDIR)\r_data.o" "$(OUTDIR)\r_data.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_data.c"
	@echo r_data.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_data.d" -MT"$(OUTDIR)\r_data.d" -o "$(OUTDIR)\r_data.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_data.c" 

"$(OUTDIR)\r_draw.o" "$(OUTDIR)\r_draw.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_draw.c"
	@echo r_draw.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_draw.d" -MT"$(OUTDIR)\r_draw.d" -o "$(OUTDIR)\r_draw.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_draw.c" 

"$(OUTDIR)\r_main.o" "$(OUTDIR)\r_main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_main.c"
	@echo r_main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_main.d" -MT"$(OUTDIR)\r_main.d" -o "$(OUTDIR)\r_main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_main.c" 

"$(OUTDIR)\r_plane.o" "$(OUTDIR)\r_plane.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_plane.c"
	@echo r_plane.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_plane.d" -MT"$(OUTDIR)\r_plane.d" -o "$(OUTDIR)\r_plane.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_plane.c" 

"$(OUTDIR)\r_segs.o" "$(OUTDIR)\r_segs.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_segs.c"
	@echo r_segs.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_segs.d" -MT"$(OUTDIR)\r_segs.d" -o "$(OUTDIR)\r_segs.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_segs.c" 

"$(OUTDIR)\r_sky.o" "$(OUTDIR)\r_sky.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_sky.c"
	@echo r_sky.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_sky.d" -MT"$(OUTDIR)\r_sky.d" -o "$(OUTDIR)\r_sky.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_sky.c" 

"$(OUTDIR)\r_things.o" "$(OUTDIR)\r_things.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_things.c"
	@echo r_things.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\r_things.d" -MT"$(OUTDIR)\r_things.d" -o "$(OUTDIR)\r_things.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\r_things.c" 

"$(OUTDIR)\s_sound.o" "$(OUTDIR)\s_sound.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\s_sound.c"
	@echo s_sound.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\s_sound.d" -MT"$(OUTDIR)\s_sound.d" -o "$(OUTDIR)\s_sound.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\s_sound.c" 

"$(OUTDIR)\sha1.o" "$(OUTDIR)\sha1.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\sha1.c"
	@echo sha1.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\sha1.d" -MT"$(OUTDIR)\sha1.d" -o "$(OUTDIR)\sha1.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\sha1.c" 

"$(OUTDIR)\sounds.o" "$(OUTDIR)\sounds.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\sounds.c"
	@echo sounds.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\sounds.d" -MT"$(OUTDIR)\sounds.d" -o "$(OUTDIR)\sounds.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\sounds.c" 

"$(OUTDIR)\st_lib.o" "$(OUTDIR)\st_lib.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\st_lib.c"
	@echo st_lib.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\st_lib.d" -MT"$(OUTDIR)\st_lib.d" -o "$(OUTDIR)\st_lib.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\st_lib.c" 

"$(OUTDIR)\st_stuff.o" "$(OUTDIR)\st_stuff.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\st_stuff.c"
	@echo st_stuff.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\st_stuff.d" -MT"$(OUTDIR)\st_stuff.d" -o "$(OUTDIR)\st_stuff.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\st_stuff.c" 

"$(OUTDIR)\statdump.o" "$(OUTDIR)\statdump.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\statdump.c"
	@echo statdump.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\statdump.d" -MT"$(OUTDIR)\statdump.d" -o "$(OUTDIR)\statdump.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\statdump.c" 

"$(OUTDIR)\tables.o" "$(OUTDIR)\tables.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\tables.c"
	@echo tables.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\tables.d" -MT"$(OUTDIR)\tables.d" -o "$(OUTDIR)\tables.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\tables.c" 

"$(OUTDIR)\v_video.o" "$(OUTDIR)\v_video.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\v_video.c"
	@echo v_video.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\v_video.d" -MT"$(OUTDIR)\v_video.d" -o "$(OUTDIR)\v_video.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\v_video.c" 

"$(OUTDIR)\w_checksum.o" "$(OUTDIR)\w_checksum.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_checksum.c"
	@echo w_checksum.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\w_checksum.d" -MT"$(OUTDIR)\w_checksum.d" -o "$(OUTDIR)\w_checksum.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_checksum.c" 

"$(OUTDIR)\w_file.o" "$(OUTDIR)\w_file.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_file.c"
	@echo w_file.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\w_file.d" -MT"$(OUTDIR)\w_file.d" -o "$(OUTDIR)\w_file.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_file.c" 

"$(OUTDIR)\w_file_stdc.o" "$(OUTDIR)\w_file_stdc.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_file_stdc.c"
	@echo w_file_stdc.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\w_file_stdc.d" -MT"$(OUTDIR)\w_file_stdc.d" -o "$(OUTDIR)\w_file_stdc.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_file_stdc.c" 

"$(OUTDIR)\w_main.o" "$(OUTDIR)\w_main.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_main.c"
	@echo w_main.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\w_main.d" -MT"$(OUTDIR)\w_main.d" -o "$(OUTDIR)\w_main.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_main.c" 

"$(OUTDIR)\w_wad.o" "$(OUTDIR)\w_wad.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_wad.c"
	@echo w_wad.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\w_wad.d" -MT"$(OUTDIR)\w_wad.d" -o "$(OUTDIR)\w_wad.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\w_wad.c" 

"$(OUTDIR)\wi_stuff.o" "$(OUTDIR)\wi_stuff.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\wi_stuff.c"
	@echo wi_stuff.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\wi_stuff.d" -MT"$(OUTDIR)\wi_stuff.d" -o "$(OUTDIR)\wi_stuff.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\wi_stuff.c" 

"$(OUTDIR)\z_zone.o" "$(OUTDIR)\z_zone.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\z_zone.c"
	@echo z_zone.c
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) -MMD -MP -MF"$(OUTDIR)\z_zone.d" -MT"$(OUTDIR)\z_zone.d" -o "$(OUTDIR)\z_zone.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\z_zone.c" 

"$(OUTDIR)\hyperscan_startup.o" "$(OUTDIR)\hyperscan_startup.d": "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hyperscan_startup.s"
	@echo hyperscan_startup.s
	@$(CC) -c $(CCDEFFLAG) $(CCADDFLAG) -B $(TOOLDIR) $(INCLUDES) $(ASDEFFLAG) $(ASADDFLAG) -MMD -MP -MF"$(OUTDIR)\hyperscan_startup.d" -MT"$(OUTDIR)\hyperscan_startup.d" -o "$(OUTDIR)\hyperscan_startup.o" "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\hyperscan_startup.s" 


all : "$(OUTDIR)" $(BINFILE)

"$(OUTDIR)" :
	@if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

LINKLIB	= 

$(BINFILE) : $(RESFILES) $(OBJFILES) $(LINKLIB) $(LDSCRIPT) "C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\System\HyperScan\examples\USB\DOOM\Resource.h"
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
	"$(OUTDIR)\z_zone.d"\
	"$(OUTDIR)\wi_stuff.d"\
	"$(OUTDIR)\w_wad.d"\
	"$(OUTDIR)\w_main.d"\
	"$(OUTDIR)\w_file_stdc.d"\
	"$(OUTDIR)\w_file.d"\
	"$(OUTDIR)\w_checksum.d"\
	"$(OUTDIR)\v_video.d"\
	"$(OUTDIR)\tables.d"\
	"$(OUTDIR)\statdump.d"\
	"$(OUTDIR)\st_stuff.d"\
	"$(OUTDIR)\st_lib.d"\
	"$(OUTDIR)\sounds.d"\
	"$(OUTDIR)\sha1.d"\
	"$(OUTDIR)\s_sound.d"\
	"$(OUTDIR)\r_things.d"\
	"$(OUTDIR)\r_sky.d"\
	"$(OUTDIR)\r_segs.d"\
	"$(OUTDIR)\r_plane.d"\
	"$(OUTDIR)\r_main.d"\
	"$(OUTDIR)\r_draw.d"\
	"$(OUTDIR)\r_data.d"\
	"$(OUTDIR)\r_bsp.d"\
	"$(OUTDIR)\p_user.d"\
	"$(OUTDIR)\p_tick.d"\
	"$(OUTDIR)\p_telept.d"\
	"$(OUTDIR)\p_switch.d"\
	"$(OUTDIR)\p_spec.d"\
	"$(OUTDIR)\p_sight.d"\
	"$(OUTDIR)\p_setup.d"\
	"$(OUTDIR)\p_saveg.d"\
	"$(OUTDIR)\p_pspr.d"\
	"$(OUTDIR)\p_plats.d"\
	"$(OUTDIR)\p_mobj.d"\
	"$(OUTDIR)\p_maputl.d"\
	"$(OUTDIR)\p_map.d"\
	"$(OUTDIR)\p_lights.d"\
	"$(OUTDIR)\p_inter.d"\
	"$(OUTDIR)\p_floor.d"\
	"$(OUTDIR)\p_enemy.d"\
	"$(OUTDIR)\p_doors.d"\
	"$(OUTDIR)\p_ceilng.d"\
	"$(OUTDIR)\mus2mid.d"\
	"$(OUTDIR)\memio.d"\
	"$(OUTDIR)\m_random.d"\
	"$(OUTDIR)\m_misc.d"\
	"$(OUTDIR)\m_menu.d"\
	"$(OUTDIR)\m_fixed.d"\
	"$(OUTDIR)\m_controls.d"\
	"$(OUTDIR)\m_config.d"\
	"$(OUTDIR)\m_cheat.d"\
	"$(OUTDIR)\m_bbox.d"\
	"$(OUTDIR)\m_argv.d"\
	"$(OUTDIR)\info.d"\
	"$(OUTDIR)\i_video.d"\
	"$(OUTDIR)\i_timer.d"\
	"$(OUTDIR)\i_system.d"\
	"$(OUTDIR)\i_sound.d"\
	"$(OUTDIR)\i_scale.d"\
	"$(OUTDIR)\i_joystick.d"\
	"$(OUTDIR)\i_input.d"\
	"$(OUTDIR)\i_endoom.d"\
	"$(OUTDIR)\i_cdmus.d"\
	"$(OUTDIR)\hu_stuff.d"\
	"$(OUTDIR)\hu_lib.d"\
	"$(OUTDIR)\gusconf.d"\
	"$(OUTDIR)\g_game.d"\
	"$(OUTDIR)\f_wipe.d"\
	"$(OUTDIR)\f_finale.d"\
	"$(OUTDIR)\dummy.d"\
	"$(OUTDIR)\dstrings.d"\
	"$(OUTDIR)\doomstat.d"\
	"$(OUTDIR)\doomgeneric_hyperscan.d"\
	"$(OUTDIR)\doomgeneric.d"\
	"$(OUTDIR)\doomdef.d"\
	"$(OUTDIR)\d_net.d"\
	"$(OUTDIR)\d_mode.d"\
	"$(OUTDIR)\d_main.d"\
	"$(OUTDIR)\d_loop.d"\
	"$(OUTDIR)\d_iwad.d"\
	"$(OUTDIR)\d_items.d"\
	"$(OUTDIR)\d_event.d"\
	"$(OUTDIR)\am_map.d"\
	"$(OUTDIR)\libgloss.d"\
	"$(OUTDIR)\UART.d"\
	"$(OUTDIR)\TV.d"\
	"$(OUTDIR)\NorFlash.d"\
	"$(OUTDIR)\User_IRQ.d"\
	"$(OUTDIR)\Sys_isr.d"\
	"$(OUTDIR)\Sys_IRQ.d"\
	"$(OUTDIR)\I2C.d"\
	"$(OUTDIR)\HS_Controller.d"\
	"$(OUTDIR)\ff.d"\
	"$(OUTDIR)\diskio.d"

ifneq ($(wildcard $(DEPFILES)),)
include $(DEPFILES)
endif

