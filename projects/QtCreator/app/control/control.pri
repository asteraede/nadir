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
#   File: control.pri
#
# Author: $author$
#   Date: 11/30/2022
#
# generic QtCreator project .pri file for framework nadir executable control
########################################################################

########################################################################
# control

# control TARGET
#
control_TARGET = control

# control INCLUDEPATH
#
control_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# control DEFINES
#
control_DEFINES += \
$${nadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# control OBJECTIVE_HEADERS
#
#control_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/main.hh \

# control OBJECTIVE_SOURCES
#
#control_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/main.mm \

########################################################################
# control HEADERS
#
control_HEADERS += \
$${NADIR_SRC}/xos/app/console/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/base/main.hpp \
$${NADIR_SRC}/xos/app/console/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/client/main.hpp \
$${NADIR_SRC}/xos/app/console/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/server/main.hpp \
\
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/base/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main.hpp \

# control SOURCES
#
control_SOURCES += \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main_opt.cpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/client/main.cpp \

########################################################################
# control FRAMEWORKS
#
control_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# control LIBS
#
control_LIBS += \
$${nadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

