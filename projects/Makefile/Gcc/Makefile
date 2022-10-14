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
# generic Makefile for framework nadir
########################################################################
# Depends: rostra;fila;crono

OTHER_VERSION_PKG = ${PKG}
OTHER_DEPENDS_PKG = ${PKG}/..
OTHER_THIRDPARTY_NAME = thirdparty
OTHER_THIRDPARTY_VERSION_PKG = ${OTHER_VERSION_PKG}/${OTHER_THIRDPARTY_NAME}

NADIR_PKG = ${PKG}
NADIR_SRC = ${NADIR_PKG}/source
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = ${ROSTRA_VERSION_MAJOR}.${ROSTRA_VERSION_MINOR}.${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = ${ROSTRA_NAME}
ROSTRA_VERSION_DIR = ${ROSTRA_GROUP}/${ROSTRA_NAME}-${ROSTRA_VERSION}
ROSTRA_DEPENDS_DIR = ${ROSTRA_NAME}

#ROSTRA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${ROSTRA_VERSION_DIR}
#ROSTRA_PKG = ${OTHER_VERSION_PKG}/${ROSTRA_VERSION_DIR}
ROSTRA_PKG = ${OTHER_DEPENDS_PKG}/${ROSTRA_DEPENDS_DIR}
#ROSTRA_SRC = ${ROSTRA_PKG}/source/${BN_GROUP}/${BN_NAME}
ROSTRA_SRC = ${ROSTRA_PKG}/source
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin

# rostra USRDEFINES
#
rostra_USRDEFINES += \

# rostra USRINCLUDES
#
rostra_USRINCLUDES += \
-I${ROSTRA_SRC} \

# rostra USRCXXFLAGS
#
rostra_USRCXXFLAGS += \

# rostra USRLIBDIRS
#
rostra_USRLIBDIRS += \
-L${ROSTRA_LIB} \

# rostra LIBS
#
rostra_LIBS += \
-lrostra \

# rostra FRAMEWORKS
#
rostra_FRAMEWORKS += \

########################################################################
# fila
FILA_VERSION_MAJOR = 0
FILA_VERSION_MINOR = 0
FILA_VERSION_RELEASE = 0
FILA_VERSION = ${FILA_VERSION_MAJOR}.${FILA_VERSION_MINOR}.${FILA_VERSION_RELEASE}
FILA_NAME = fila
FILA_GROUP = ${FILA_NAME}
FILA_VERSION_DIR = ${FILA_GROUP}/${FILA_NAME}-${FILA_VERSION}
FILA_DEPENDS_DIR = ${FILA_NAME}

#FILA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${FILA_VERSION_DIR}
#FILA_PKG = ${OTHER_VERSION_PKG}/${FILA_VERSION_DIR}
FILA_PKG = ${OTHER_DEPENDS_PKG}/${FILA_DEPENDS_DIR}
#FILA_SRC = ${FILA_PKG}/source/${BN_GROUP}/${BN_NAME}
FILA_SRC = ${FILA_PKG}/source
FILA_BLD = ${FILA_PKG}/${BLD}/${BUILD_TYPE}
FILA_LIB = ${FILA_BLD}/lib
FILA_BIN = ${FILA_BLD}/bin

# fila USRDEFINES
#
fila_USRDEFINES += \

# fila USRINCLUDES
#
fila_USRINCLUDES += \
-I${FILA_SRC} \

# fila USRCXXFLAGS
#
fila_USRCXXFLAGS += \

# fila USRLIBDIRS
#
fila_USRLIBDIRS += \
-L${FILA_LIB} \

# fila LIBS
#
fila_LIBS += \
-lfila \

# fila FRAMEWORKS
#
fila_FRAMEWORKS += \

########################################################################
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = ${CRONO_VERSION_MAJOR}.${CRONO_VERSION_MINOR}.${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = ${CRONO_NAME}
CRONO_VERSION_DIR = ${CRONO_GROUP}/${CRONO_NAME}-${CRONO_VERSION}
CRONO_DEPENDS_DIR = ${CRONO_NAME}

#CRONO_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${CRONO_VERSION_DIR}
#CRONO_PKG = ${OTHER_VERSION_PKG}/${CRONO_VERSION_DIR}
CRONO_PKG = ${OTHER_DEPENDS_PKG}/${CRONO_DEPENDS_DIR}
#CRONO_SRC = ${CRONO_PKG}/source/${BN_GROUP}/${BN_NAME}
CRONO_SRC = ${CRONO_PKG}/source
CRONO_BLD = ${CRONO_PKG}/${BLD}/${BUILD_TYPE}
CRONO_LIB = ${CRONO_BLD}/lib
CRONO_BIN = ${CRONO_BLD}/bin

# crono USRDEFINES
#
crono_USRDEFINES += \

# crono USRINCLUDES
#
crono_USRINCLUDES += \
-I${CRONO_SRC} \

# crono USRCXXFLAGS
#
crono_USRCXXFLAGS += \

# crono USRLIBDIRS
#
crono_USRLIBDIRS += \
-L${CRONO_LIB} \

# crono LIBS
#
crono_LIBS += \
-lcrono \

# crono FRAMEWORKS
#
crono_FRAMEWORKS += \

########################################################################
# nadir

# nadir USRDEFINES
#
nadir_USRDEFINES += \
${rostra_USRDEFINES} \
${fila_USRDEFINES} \
${crono_USRDEFINES} \
${build_nadir_USRDEFINES} \

# nadir USRINCLUDES
#
nadir_USRINCLUDES += \
-I${NADIR_SRC} \
${crono_USRINCLUDES} \
${fila_USRINCLUDES} \
${rostra_USRINCLUDES} \
${build_nadir_USRINCLUDES} \

# nadir USRCXXFLAGS
#
nadir_USRCXXFLAGS += \
${rostra_USRCXXFLAGS} \
${fila_USRCXXFLAGS} \
${crono_USRCXXFLAGS} \
${build_nadir_USRCXXFLAGS} \

# nadir USRLIBDIRS
#
nadir_USRLIBDIRS += \
-L${NADIR_LIB} \
${crono_USRLIBDIRS} \
${fila_USRLIBDIRS} \
${rostra_USRLIBDIRS} \
${build_nadir_USRLIBDIRS} \

# nadir LIBS
#
nadir_LIBS += \
-lnadir \
${crono_LIBS} \
${fila_LIBS} \
${rostra_LIBS} \
${build_nadir_LIBS} \

########################################################################
