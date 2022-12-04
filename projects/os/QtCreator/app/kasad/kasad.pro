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
#   File: kasad.pro
#
# Author: $author$
#   Date: 12/4/2022
#
# os specific QtCreator project .pro file for framework nadir executable kasad
########################################################################
#
# Debug: nadir/build/os/QtCreator/Debug/bin/kasad
# Release: nadir/build/os/QtCreator/Release/bin/kasad
# Profile: nadir/build/os/QtCreator/Profile/bin/kasad
#
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/kasad/kasad.pri)

TARGET = $${kasad_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${kasad_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${kasad_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${kasad_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${kasad_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${kasad_HEADERS} \
$${kasad_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${kasad_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${kasad_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${kasad_LIBS} \
$${FRAMEWORKS} \

########################################################################

