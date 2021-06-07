QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder.cpp \
    camera.cpp \
    camera_load_solution.cpp \
    camera_loader.cpp \
    canvas.cpp \
    commands.cpp \
    composite.cpp \
    draw_manager.cpp \
    drawer.cpp \
    drawer_solution.cpp \
    edge.cpp \
    elements.cpp \
    facade.cpp \
    factory.cpp \
    load_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    model_load_solution.cpp \
    model_loader.cpp \
    point.cpp \
    registration.cpp \
    scene.cpp \
    scene_load_solution.cpp \
    scene_loader.cpp \
    scene_manager.cpp \
    secretary.cpp \
    solution.cpp \
    solution_manager.cpp \
    transform_manager.cpp \
    transform_matrix.cpp \
    visitor.cpp

HEADERS += \
    base_loader.h \
    base_manager.h \
    base_object.h \
    builder.h \
    camera.h \
    camera_load_solution.h \
    camera_loader.h \
    canvas.h \
    commands.h \
    composite.h \
    draw_manager.h \
    drawer.h \
    drawer_solution.h \
    edge.h \
    elements.h \
    errors.h \
    facade.h \
    factory.h \
    load_manager.h \
    loaders.h \
    mainwindow.h \
    matrix.hpp \
    matrix_base.hpp \
    model.h \
    model_load_solution.h \
    model_loader.h \
    point.h \
    registration.h \
    scene.h \
    scene_load_solution.h \
    scene_loader.h \
    scene_manager.h \
    secretary.h \
    solution.h \
    solution_manager.h \
    transform_manager.h \
    transform_matrix.h \
    visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
