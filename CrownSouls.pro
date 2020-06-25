QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/core/armor.cpp \
    model/core/armor_bodyarmor.cpp \
    model/core/inventoryitem.cpp \
    main.cpp \
    model/core/shield_defenseshield.cpp \
    model/core/weapon_attackweapon.cpp \
    model/core/weaponarmor_gloves.cpp \
    model/core/weaponshield_attackshield.cpp \
    view/mainwindow.cpp \
    model/core/ring.cpp \
    model/core/shield.cpp \
    model/core/weapon.cpp \
    model/core/weaponarmor.cpp \
    model/core/weaponshield.cpp

HEADERS += \
    model/core/armor.h \
    model/core/armor_bodyarmor.h \
    model/core/inventoryitem.h \
    model/core/shield_defenseshield.h \
    model/core/weapon_attackweapon.h \
    model/core/weaponarmor_gloves.h \
    model/core/weaponshield_attackshield.h \
    model/inventory.hpp \
    view/mainwindow.h \
    model/core/ring.h \
    model/core/shield.h \
    model/core/weapon.h \
    model/core/weaponarmor.h \
    model/core/weaponshield.h

FORMS += \
    style/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
