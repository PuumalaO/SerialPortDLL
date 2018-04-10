#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QDebug>
#include <QtSerialPort/QSerialPort>

class SerialEngine : public QObject
{
    Q_OBJECT

public:
    SerialEngine();
    ~SerialEngine();
    QString getID();
    void setup();

public slots:
    void readSerialData();

signals:
    void cardRead();

private:
    QSerialPort *serialPort;
    QString id;
};

#endif // SERIALENGINE_H
