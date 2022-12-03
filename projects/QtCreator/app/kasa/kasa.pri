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
#   File: kasa.pri
#
# Author: $author$
#   Date: 12/3/2022
#
# generic QtCreator project .pri file for framework nadir executable kasa
########################################################################

########################################################################
# kasa

# kasa TARGET
#
kasa_TARGET = kasa

# kasa INCLUDEPATH
#
kasa_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# kasa DEFINES
#
kasa_DEFINES += \
$${nadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# kasa OBJECTIVE_HEADERS
#
#kasa_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main.hh \

# kasa OBJECTIVE_SOURCES
#
#kasa_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main.mm \

########################################################################
# kasa HEADERS
#
kasa_HEADERS += \
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
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/base/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/server/main.hpp \

# kasa SOURCES
#
kasa_SOURCES += \
$${NADIR_SRC}/xos/io/string/reader.cpp \
$${NADIR_SRC}/xos/io/hex/read_to_string.cpp \
\
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main_opt.cpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/kasa/client/main.cpp \

########################################################################
# kasa FRAMEWORKS
#
kasa_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# kasa LIBS
#
kasa_LIBS += \
$${nadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

