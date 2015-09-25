#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T12:20:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tareas2Do_parcial
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    nodo.cpp \
    arista.cpp \
    grafo.cpp \
    listaaristas.cpp \
    dijks.cpp \
    floyd.cpp \
    prim.cpp \
    kruskal.cpp \
    nodoc.cpp \
    cola.cpp \
    sorts.cpp \
    sortsgraph.cpp \
    dijksttable.cpp \
    recorridos.cpp \
    floydgraph.cpp \
    kruskalgraph.cpp \
    primgraph.cpp

HEADERS  += widget.h \
    nodo.h \
    arista.h \
    grafo.h \
    listaaristas.h \
    dijks.h \
    floyd.h \
    prim.h \
    kruskal.h \
    nodoc.h \
    cola.h \
    sorts.h \
    sortsgraph.h \
    dijksttable.h \
    recorridos.h \
    floydgraph.h \
    kruskalgraph.h \
    primgraph.h

FORMS    += widget.ui \
    sortsgraph.ui \
    dijksttable.ui \
    recorridos.ui \
    floydgraph.ui \
    kruskalgraph.ui \
    primgraph.ui
