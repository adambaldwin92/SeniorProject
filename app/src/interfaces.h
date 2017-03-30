#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>

/* List classes that are used i.e. :
 * QT_BEGIN_NAMESPACE
 *  class QImage;
 *  class QPainter;
 *  class QWidget;
 * QT_END_NAMESPACE
 */

class ClientInterface
{
public:
    virtual ~ClientInterface() {}

    virtual void someAbstractMethod() = 0;
};

class ServerInterface
{
public:
    virtual ~ServerInterface() {}

    virtual void someAbstractMethod() = 0;
};

class ThreadInterface
{
public:
    virtual ~ThreadInterface() {}

    virtual void someAbstractMethod() = 0;
};

class CameraInterface
{
public:
    virtual ~CameraInterface() {}

    virtual void someAbstractMethod() = 0;
};

QT_BEGIN_NAMESPACE

#define ClientInterface_iid "SeniorProject.ClientInterface"
Q_DECLARE_INTERFACE(ClientInterface, ClientInterface_iid)

#define ServerInterface_iid "SeniorProject.ServerInterface"
Q_DECLARE_INTERFACE(ServerInterface, ServerInterface_iid)

#define ThreadInterface_iid "SeniorProject.ThreadInterface"
Q_DECLARE_INTERFACE(ThreadInterface, ThreadInterface_iid)

#define CameraInterface_iid "SeniorProject.CameraInterface"
Q_DECLARE_INTERFACE(CameraInterface, CameraInterface_iid)

#define PowerInterface_iid "SeniorProject.PowerInterface"
Q_DECLARE_INTERFACE(PowerInterface, PowerInterface_iid)


QT_END_NAMESPACE

#endif // INTERFACES_H
