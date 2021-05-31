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
    commands/camera/camera_command.cpp \
    commands/model/model_commands.cpp \
    config/config_reader.cpp \
    draw/factory/qt_factory.cpp \
    draw/qt_draw.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/draw/draw_manager.cpp \
    managers/draw/draw_manager_creator.cpp \
    managers/scene/scene_manager.cpp \
    managers/scene/scene_manager_creator.cpp \
    managers/transform/transform_manager.cpp \
    managers/transform/transform_manager_creator.cpp \
    objects/camera/camera.cpp \
    objects/composite/composite.cpp \
    objects/elements.cpp \
    objects/model/elements/edge/edge.cpp \
    objects/model/elements/elements.cpp \
    objects/model/elements/vertex/vertex.cpp \
    objects/model/model.cpp \
    scene/scene.cpp

HEADERS += \
    base_builder.h \
    base_command.h \
    base_draw.h \
    base_loader.h \
    base_manager.h \
    base_object.h \
    builder/base_builder.h \
    builder/base_model_builder.h \
    builder/model_builder.h \
    commands/base_command.h \
    commands/camera/camera_command.h \
    commands/camera_command.h \
    commands/model/model_commands.h \
    commands/model_commands.h \
    commands/scene/scene_command.h \
    commands/scene_command.h \
    config/abstract_config_reader.h \
    config/config_reader.h \
    config_reader.h \
    draw/abstract_factory.h \
    draw/base_draw.h \
    draw/factory/abstract_factory.h \
    draw/factory/qt_factory.h \
    draw/qt_draw.h \
    facade.h \
    facade/facade.h \
    load_secretary.h \
    loader/base_loader.h \
    loader/base_model_loader.h \
    loader/model/base_model_loader.h \
    mainwindow.h \
    managers/base_manager.h \
    managers/draw/draw_manager.h \
    managers/draw/draw_manager.h \
    managers/draw/draw_manager_creator.h \
    managers/draw_manager.h \
    managers/load/load_manager.h \
    managers/load_manager.h \
    managers/scene/scene_manager.h \
    managers/scene/scene_manager_creator.h \
    managers/transform/transform_manager.h \
    managers/transform/transform_manager_creator.h \
    managers/transform_manager.h \
    model.h \
    model_commands.h \
    objects/base_object.h \
    objects/camera.h \
    objects/camera.h \
    objects/camera/camera.h \
    objects/composite.h \
    objects/composite/composite.h \
    objects/model/elements/edge.h \
    objects/model/elements/edge/edge.h \
    objects/model/elements/elements.h \
    objects/model/elements/vertex/elements.h \
    objects/model/elements/vertex/vertex.h \
    objects/model/model.h \
    objects/vertex.h \
    scene.h \
    scene/scene.h \
    scene_manager.h \
    secretary/load_secretary.h \
    visitor.h \
    visitor/visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
