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
#   File: controld.pri
#
# Author: $author$
#   Date: 12/1/2022
#
# generic QtCreator project .pri file for framework nadir executable controld
########################################################################

########################################################################
# controld

# controld TARGET
#
controld_TARGET = controld

# controld INCLUDEPATH
#
controld_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# controld DEFINES
#
controld_DEFINES += \
$${nadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# controld OBJECTIVE_HEADERS
#
#controld_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/main.hh \

# controld OBJECTIVE_SOURCES
#
#controld_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/protocol/home/control/main.mm \

########################################################################
# controld HEADERS
#
controld_HEADERS += \
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

# controld SOURCES
#
controld_SOURCES += \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main_opt.cpp \
$${NADIR_SRC}/xos/app/console/protocol/home/control/server/main.cpp \

########################################################################
# controld FRAMEWORKS
#
controld_FRAMEWORKS += \
$${nadir_FRAMEWORKS} \

# controld LIBS
#
controld_LIBS += \
$${nadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

