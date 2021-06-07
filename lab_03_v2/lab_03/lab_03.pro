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
    base_loader.cpp \
    builder.cpp \
    camera.cpp \
    camera_file_loader.cpp \
    camera_load_solution.cpp \
    camera_loader.cpp \
    canvas.cpp \
    commands.cpp \
    composite.cpp \
    details.cpp \
    draw_manager.cpp \
    draw_solution.cpp \
    drawer.cpp \
    drawer_factory.cpp \
    drawer_solution.cpp \
    edge.cpp \
    elements.cpp \
    facade.cpp \
    factory.cpp \
    load_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    model_file_loader.cpp \
    model_load_solution.cpp \
    model_loader.cpp \
    point.cpp \
    reform_manager.cpp \
    registration.cpp \
    scene.cpp \
    scene_file_loader.cpp \
    scene_load_solution.cpp \
    scene_loader.cpp \
    scene_manager.cpp \
    secretary.cpp \
    solution.cpp \
    solution_manager.cpp \
    transform.cpp \
    transform_manager.cpp \
    transform_matrix.cpp \
    visitor.cpp

HEADERS += \
    base_loader.h \
    base_loader.hpp \
    base_manager.h \
    base_manager.hpp \
    base_object.h \
    builder.h \
    builder.hpp \
    camera.h \
    camera.hpp \
    camera_file_loader.hpp \
    camera_load_solution.h \
    camera_load_solution.hpp \
    camera_loader.h \
    canvas.h \
    canvas.hpp \
    commands.h \
    commands.hpp \
    composite.h \
    composite.hpp \
    details.hpp \
    draw_manager.h \
    draw_manager.hpp \
    draw_solution.h \
    drawer.h \
    drawer.hpp \
    drawer_factory.hpp \
    drawer_solution.hpp \
    edge.h \
    edge.h \
    elements.h \
    error.h \
    errors.hpp \
    facade.h \
    facade.hpp \
    factory.h \
    load_manager.h \
    load_manager.hpp \
    loader.h \
    loaders.hpp \
    mainwindow.h \
    mainwindow.hpp \
    matrix.hpp \
    matrix_base.hpp \
    model.h \
    model.hpp \
    model_file_loader.hpp \
    model_load_solution.h \
    model_load_solution.hpp \
    model_loader.h \
    object.hpp \
    point.h \
    point.h \
    reform_manager.hpp \
    registration.h \
    registration.hpp \
    scene.h \
    scene.hpp \
    scene_file_loader.hpp \
    scene_load_solution.h \
    scene_load_solution.hpp \
    scene_loader.h \
    scene_manager.h \
    scene_manager.hpp \
    secretary.h \
    secretary.hpp \
    solution.h \
    solution.hpp \
    solution_manager.h \
    solution_manager.hpp \
    transform.h \
    transform_manager.h \
    transform_matrix.hpp \
    visitor.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cam.txt \
    config/camera_load.cfg \
    config/drawer.cfg \
    config/model_load.cfg \
    config/scene_load.cfg \
    cube.txt \
    drawer.cfg \
    lab_03.pro.user
