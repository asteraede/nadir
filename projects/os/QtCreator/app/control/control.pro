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
#   File: control.pro
#
# Author: $author$
#   Date: 11/30/2022
#
# os specific QtCreator project .pro file for framework nadir executable control
########################################################################
#
# Debug: nadir/build/os/QtCreator/Debug/bin/control
# Release: nadir/build/os/QtCreator/Release/bin/control
# Profile: nadir/build/os/QtCreator/Profile/bin/control
#
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/control/control.pri)

TARGET = $${control_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${control_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${control_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${control_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${control_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${control_HEADERS} \
$${control_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${control_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${control_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${control_LIBS} \
$${FRAMEWORKS} \

########################################################################

