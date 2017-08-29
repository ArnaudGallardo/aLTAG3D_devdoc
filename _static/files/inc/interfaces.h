#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QString;
class QStringList;
class QJsonObject;
QT_END_NAMESPACE

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual QString author() const = 0;
    virtual QString version() const = 0;
    virtual QString title() const = 0;
    virtual QStringList exportableData() const = 0;
    virtual QStringList formats() const = 0;
    virtual QJsonObject extractData(const QString &filename, const QStringList &dataToExtract, QWidget *parent) = 0;
    virtual QString fileDescription() const = 0;
};

QT_BEGIN_NAMESPACE
#define PluginInterface_iid "fr.cnrs.archeovision.aLTAG3d.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif
