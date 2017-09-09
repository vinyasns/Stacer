#ifndef TOOL_MANAGER_H
#define TOOL_MANAGER_H

#include <QObject>
#include <QDebug>

#include <Tools/service_tool.h>
#include <Tools/package_tool.h>

class ToolManager : public QObject
{
    Q_OBJECT

public:
    static ToolManager *ins();

public:
    QList<Service> getServices() const;
    QStringList getPackages() const;

    QFileInfoList getPackageCaches() const;
public slots:
    bool changeServiceStatus(const QString &sname, bool status) const;
    bool changeServiceActive(const QString &sname, bool status) const;
    bool serviceIsActive(const QString &sname) const;
    bool serviceIsEnabled(const QString &sname) const;
    void uninstallPackages(const QStringList &packages);

signals:
    void uninstallFinished();
    void uninstallStarted();

private:
    ToolManager();
    static ToolManager *_instance;
};

#endif // TOOL_MANAGER_H
