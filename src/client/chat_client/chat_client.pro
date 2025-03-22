QT += quick
QT += widgets
QT += core
QT += quickcontrols2  # 添加 QuickControls2 支持
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# FluentUI 配置
unix {
    LIBS += -L/usr/local/lib -lFluentUI
    INCLUDEPATH += /usr/local/include/FluentUI
    # 添加运行时库搜索路径
    QMAKE_RPATHDIR += /usr/local/lib
}

SOURCES += \
    main.cpp \
    src/Socket/Socket.cpp \
    src/ftp/ftp.cpp \
    src/info/AppInfo.cpp \
    src/info/lang/En.cpp \
    src/info/lang/Lang.cpp \
    src/info/lang/Zh.cpp \
    src/md5/md5.cpp \
    src/md5/useMD5.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML2_IMPORT_PATH += /usr/local/imports
QML_IMPORT_PATH += $$PWD
QML_IMPORT_PATH += /usr/local/imports

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        src/Socket/Socket.h \
        src/ftp/ftp.h \
        src/info/AppInfo.h \
        src/info/lang/En.h \
        src/info/lang/Lang.h \
        src/info/lang/Zh.h \
        src/info/stdafx.h \
        src/md5/md5.h \
        src/md5/useMD5.h

DISTFILES +=
