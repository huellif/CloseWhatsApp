LIBS += -lapgrfx -laknnotify -lcone

TARGET.CAPABILITY += PowerMgmt

TARGET.UID3 = 0x2007164a

vendorinfo = "%{\"huellifSoft\"}" ":\"huellifSoft\""
my_deployment.pkg_prerules = vendorinfo
DEPLOYMENT += my_deployment
DEPLOYMENT.display_name += CloseWhatsApp

VERSION = 1.3.0

#MMP_RULES += "DEBUGGABLE"

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

CONFIG -= qt
default_deployment.pkg_prerules -= pkg_depends_webkit
default_deployment.pkg_prerules -= pkg_depends_qt

#Belle:
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\platform\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\platform\mw\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\mw\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\bafl\

#s60v5:
INCLUDEPATH += C:\QtSDK\Symbian\SDKs\Symbian1Qt473\epoc32\include\

symbian {
    vendorinfo += "%{\"huellifSoft\"}" ":\"huellifSoft\""

    TARGET.UID3 += 0x2007164a
}
