########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 10/14/2022
#
# generic Makefile for framework nadir executable nadir
########################################################################
# Depends: rostra;fila;crono

#
# target
#
nadir_exe_EXETARGET = nadir

########################################################################

#
# user c++ flags
#
nadir_exe_USRCXXFLAGS += \
${nadir_USRCXXFLAGS} \

#
# user defines
#
nadir_exe_USRDEFINES += \
${nadir_USRDEFINES} \
-DDEFAULT_LOGGING_LEVELS_ERROR \
-DXOS_CONSOLE_MAIN_MAIN \

#
# user includes
#
nadir_exe_USRINCLUDES += \
${nadir_USRINCLUDES} \

#
# user libdirs
#
nadir_exe_USRLIBDIRS += \
${nadir_USRLIBDIRS} \

########################################################################

#
# executable .c sources
#
#nadir_exe_EXE_C_SOURCES += \
#${NADIR_SRC}/xos/app/console/nadir/main.c \

#
# executable .cc sources
#
#nadir_exe_EXE_CC_SOURCES += \
#${NADIR_SRC}/xos/app/console/nadir/main.cc \

#
# executable .cxx sources
#
#nadir_exe_EXE_CXX_SOURCES += \
#${NADIR_SRC}/xos/app/console/nadir/main.cxx \

#
# executable .cpp sources
#
nadir_exe_EXE_CPP_SOURCES += \
${NADIR_SRC}/xos/app/console/nadir/main_opt.cpp \
${NADIR_SRC}/xos/app/console/nadir/main.cpp \

#
# executable .m sources
#
#nadir_exe_EXE_M_SOURCES += \
#${NADIR_SRC}/xos/app/console/nadir/main.m \

#
# executable .mm sources
#
#nadir_exe_EXE_MM_SOURCES += \
#${NADIR_SRC}/xos/app/console/nadir/main.mm \


########################################################################

#
# executable libraries
#
nadir_exe_LIBS += \
${nadir_LIBS}

