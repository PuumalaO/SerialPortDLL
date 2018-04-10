#include "serialengine.h"
SerialEngine::SerialEngine(){}
SerialEngine::~SerialEngine(){}

void SerialEngine::setup()
{
    qDebug()<<"Setup"<<endl;
    serialPort = new QSerialPort;

    QObject::connect(serialPort, SIGNAL(readyRead()), this, SLOT(readSerialData()));

    serialPort->setPortName("COM11");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->open(QIODevice::ReadOnly);
}

void SerialEngine::readSerialData()
{
    qDebug()<<"Luetaan kortti"<<endl;
    static QByteArray byte;
    byte = serialPort->readAll();

    id = QString(byte).remove("\r").remove("\n").remove("-").remove(">");
    emit cardRead();
}

QString SerialEngine::getID()
{
    return id;
}
