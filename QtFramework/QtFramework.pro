QT += core gui widgets opengl

win32 {
    CONFIG(release, debug|release): LIBS += -L"$$PWD/Dependencies/Lib/GL/" -lglew32 -lglu32 -lopengl32
    CONFIG(debug, debug|release): LIBS += -L"$$PWD/Dependencies/Lib/GL/" -lglew32 -lglu32 -lopengl32
    INCLUDEPATH += "$$PWD/Dependencies/Include"
    DEPENDPATH += "$$PWD/Dependencies/Lib/GL"
}

mac {
    # for GLEW installed into /usr/lib/libGLEW.so or /usr/lib/glew.lib
    # if libraries GLU or OpenGL are required uncomment the commented libraries
    LIBS += -lGLEW #-lGL
}

unix {
    # for GLEW installed into /usr/lib/libGLEW.so or /usr/lib/glew.lib
    # if libraries GLU or OpenGL are required uncomment the commented libraries
    LIBS += -lGLEW -lGL
}

FORMS += \
    GUI/MainWindow.ui \
    GUI/SideWidget.ui

HEADERS += \
    GUI/GLWidget.h \
    GUI/MainWindow.h \
    GUI/SideWidget.h \
    Core/Exceptions.h \
    Core/DCoordinates3.h \
    Core/Matrices.h \
    Core/RealSquareMatrices.h \
    Core/Constants.h \
    Core/GenericCurves3.h \
    Core/LinearCombination3.h \
    Dependencies/Include/GL/glew.h \
    Parametric/ParametricCurves3.h \
    Test/TestFunctions.h \
    Core/CyclicCurves3.h \
    Parametric/ParametricSurfaces3.h \
    Core/Colors4.h \
    Core/HCoordinates3.h \
    Core/Lights.h \
    Core/Materials.h \
    Core/TCoordinates4.h \
    Core/TriangularFaces.h \
    Core/TriangulatedMeshes3.h \
    Core/TensorProductSurfaces3.h \
    Core/ShaderPrograms.h

SOURCES += \
    GUI/GLWidget.cpp \
    GUI/MainWindow.cpp \
    GUI/SideWidget.cpp \
    main.cpp \
    Core/RealSquareMatrices.cpp \
    Core/GenericCurves3.cpp \
    Core/LinearCombination3.cpp \
    Parametric/ParametricCurves3.cpp \
    Test/TestFunctions.cpp \
    Core/CyclicCurves3.cpp \
    Parametric/ParametricSurfaces3.cpp \
    Core/Lights.cpp \
    Core/Materials.cpp \
    Core/TriangulatedMeshes3.cpp \
    Core/TensorProductSurfaces3.cpp \
    Core/ShaderPrograms.cpp

