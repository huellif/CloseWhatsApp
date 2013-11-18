symbian {
vendorinfo += "%{\"huellifSoft\"}" ":\"huellifSoft\""

TARGET.UID3 += 0x2007164a

LIBS += -laknnotify -lcone

TARGET.CAPABILITY += PowerMgmt

default_deployment.pkg_prerules -= pkg_depends_webkit
default_deployment.pkg_prerules -= pkg_depends_qt
}

VERSION = 1.3.0

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

CONFIG -= qt


#Belle:
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\platform\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\platform\mw\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\mw\
#INCLUDEPATH += C:\QtSDK\Symbian\SDKs\SymbianSR1Qt474\epoc32\include\bafl\

#s60v5:
#MMP_RULES += "DEBUGGABLE"
INCLUDEPATH += C:\QtSDK\Symbian\SDKs\Symbian1Qt473\epoc32\include\
