symbian:{
LIBS += -lavkon -apgrfx.lib -laknnotify -leiksrv
TARGET.CAPABILITY += PowerMgmt
TARGET.UID3 = 0x2007164a
vendorinfo = "%{\"huellifSoft\"}" ":\"huellifSoft\""
my_deployment.pkg_prerules = vendorinfo
DEPLOYMENT += my_deployment
DEPLOYMENT.display_name += CloseWhatsApp
VERSION = 1.2.0
#MMP_RULES += "DEBUGGABLE"
}

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()
