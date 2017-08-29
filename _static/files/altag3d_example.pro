#-------------------------------------------------
#
# Exemple de fichier .pro pour un plugin altag3d
# inspiré de la documentation Qt
#
#-------------------------------------------------

TEMPLATE      = lib
CONFIG       += plugin
QT           += widgets
INCLUDEPATH  += inc
HEADERS       = exampleplugin.h \
                inc/interfaces.h
SOURCES       = exampleplugin.cpp
TARGET        = altag3d_example_plugin
DESTDIR       = ../plugins

target.path = ../../plugins
INSTALLS += target

CONFIG += install_ok  # Do not cargo-cult this!
uikit: CONFIG += debug_and_release
