#include "dll_serialport.h"

void DLL_SerialPort::serialHandler()
{
    qDebug()<<"Serialhandler";
    id = serialEngine->getID();
    emit cardIDReady();
}

QString DLL_SerialPort::cardID()
{
    return id;
}

void DLL_SerialPort::runSetup()
{
    qDebug()<<"DLL setup"<<endl;
    serialEngine = new SerialEngine;
    QObject::connect(serialEngine, SIGNAL(cardRead()), this, SLOT(serialHandler()));
    id = "Not set";
    serialEngine->setup();
}

