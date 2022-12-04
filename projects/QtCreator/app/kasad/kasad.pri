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
#   File: kasad.pri
#
# Author: $author$
#   Date: 12/4/2022
#
# generic QtCreator project .pri file for framework nadir executable kasad
########################################################################

########################################################################
# kasad

# kasad TARGET
#
kasad_TARGET = kasad

# kasad INCLUDEPATH
#
kasad_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# kasad DEFINES
#
kasad_DEFINES += \
$${nadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# kasad OBJECTIVE_HEADERS
#
#kasad_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/main.hh \

# kasad OBJECTIVE_SOURCES
#
#kasad_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/main.mm \

########################################################################
# kasad HEADERS
#
kasad_HEADERS += \
$${NADIR_SRC}/xos/io/string/reader.hpp \
$${NADIR_SRC}/xos/io/hex/read_to_string.hpp \
\
$${NADIR_SRC}/xos/app/console/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/base/main.hpp \
$${NADIR_SRC}/xos/app/console/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/client/main.hpp \
$${NADIR_SRC}/xos/app/console/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/server/main.hpp \
\
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/power_main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/power_main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/power_main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/power_main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/power_main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main.hpp \
\
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main.hpp \

# kasad SOURCES
#
kasad_SOURCES += \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main_opt.cpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main.cpp \

########################################################################
# kasad FRAMEWORKS
#
kasad_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# kasad LIBS
#
kasad_LIBS += \
$${nadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

