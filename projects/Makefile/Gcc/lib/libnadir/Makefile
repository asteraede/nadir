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
# generic Makefile for framework nadir library libnadir
########################################################################
# Depends: rostra;fila;crono

#
# target
#
libnadir_LIBTARGET = libnadir.${LIBEXT}

########################################################################

#
# user c++ flags
#
libnadir_USRCXXFLAGS += \
${nadir_USRCXXFLAGS} \

#
# user defines
#
libnadir_USRDEFINES += \
${nadir_USRDEFINES} \
-DDEFAULT_LOGGING_LEVELS_ERROR \
-DXOS_LIB_NADIR_VERSION_BUILD_DATE=10/14/2022 #${shell tdate} \

#
# user includes
#
libnadir_USRINCLUDES += \
${nadir_USRINCLUDES} \

#
# user libdirs
#
libnadir_USRLIBDIRS += \
${nadir_USRLIBDIRS} \

########################################################################

#
# library .c sources
#
#libnadir_LIB_C_SOURCES += \
#${NADIR_SRC}/xos/lib/nadir/version.c \

#
# library .cc sources
#
#libnadir_LIB_CC_SOURCES += \
#${NADIR_SRC}/xos/lib/nadir/version.cc \

#
# library .cxx sources
#
#libnadir_LIB_CXX_SOURCES += \
#${NADIR_SRC}/xos/lib/nadir/version.cxx \

#
# library .cpp sources
#
libnadir_LIB_CPP_SOURCES += \
${NADIR_SRC}/xos/lib/nadir/version.cpp \

#
# library .m sources
#
#libnadir_LIB_M_SOURCES += \
#${NADIR_SRC}/xos/lib/nadir/version.m \

#
# library .mm sources
#
#libnadir_LIB_MM_SOURCES += \
#${NADIR_SRC}/xos/lib/nadir/version.mm \


########################################################################


