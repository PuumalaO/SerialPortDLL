#ifndef DLL_SERIALPORT_H
#define DLL_SERIALPORT_H

#include <QObject>
#include <QDebug>
#include "dll_serialport_global.h"
#include "serialengine.h"

class DLL_SERIALPORTSHARED_EXPORT DLL_SerialPort : public QObject
{
    Q_OBJECT

public:
    QString cardID();
    void runSetup();

public slots:
    void serialHandler();

signals:
    void cardIDReady();

private:
    SerialEngine *serialEngine;
    QString id;

};

#endif // DLL_SERIALPORT_H
