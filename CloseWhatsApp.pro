symbian {
TARGET.UID3 += 0x2007164a

LIBS += -laknnotify

TARGET.CAPABILITY += PowerMgmt

default_deployment.pkg_prerules -= pkg_depends_webkit
default_deployment.pkg_prerules -= pkg_depends_qt

    my_deployment.pkg_prerules += vendorinfo

    DEPLOYMENT += my_deployment

    vendorinfo += "%{\"huellifSoft\"}" ":\"huellifSoft\""
}

VERSION = 1.4.0

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
