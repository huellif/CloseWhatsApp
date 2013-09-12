symbian:{
LIBS += -lavkon \
        -apgrfx.lib
TARGET.CAPABILITY += PowerMgmt
TARGET.UID3 = 0x2007164a
vendorinfo = "%{\"huellifSoft\"}" ":\"huellifSoft\""
my_deployment.pkg_prerules = vendorinfo
DEPLOYMENT += my_deployment
DEPLOYMENT.display_name += CloseWhatsApp
VERSION = 1.1.0
}

SOURCES += main.cpp
CONFIG += qtestlib

include(deployment.pri)
qtcAddDeployment()

#gccOption = "OPTION gcce -fpermissive"
#MMP_RULES += gccOption
