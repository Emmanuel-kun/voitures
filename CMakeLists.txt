cmake_minimum_required(VERSION 3.25)
project(Voitures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        sql
        REQUIRED)

add_executable(Voitures main.cpp entity/Voiture.cpp entity/Voiture.h entity/Client.cpp entity/Client.h dao/BaseDAO.cpp dao/BaseDAO.h dao/VoitureDAO.cpp dao/VoitureDAO.h dao/LocationDAO.cpp dao/LocationDAO.h dao/ClientDAO.cpp dao/ClientDAO.h entity/Location.cpp entity/Location.h pages/mainwindow.cpp pages/mainwindow.h pages/mainwindow.ui pages/vuevoitures.cpp pages/vuevoitures.h pages/vuevoitures.ui pages/vuelocation.cpp pages/vuelocation.h pages/vuelocation.ui pages/vueclient.cpp pages/vueclient.h pages/vueclient.ui widget/listeclient.cpp widget/listeclient.h widget/listeclient.ui widget/listevoiture.cpp widget/listevoiture.h widget/listevoiture.ui)
target_link_libraries(Voitures
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        )

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Sql)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
