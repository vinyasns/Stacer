#include "tool_manager.h"

ToolManager *ToolManager::_instance = NULL;

ToolManager *ToolManager::ins()
{
    if(_instance == NULL)
        _instance = new ToolManager;

    return _instance;
}

ToolManager::ToolManager()
{

}

/******************
 * SERVICES
 *****************/
QList<Service> ToolManager::getServices() const
{
    return ServiceTool::getServicesWithSystemctl();
}

bool ToolManager::changeServiceStatus(const QString &sname, bool status) const
{
    return ServiceTool::changeServiceStatus(sname, status);
}

bool ToolManager::changeServiceActive(const QString &sname, bool status) const
{
    return ServiceTool::changeServiceActive(sname, status);
}

bool ToolManager::serviceIsActive(const QString &sname) const
{
    return ServiceTool::serviceIsActive(sname);
}

bool ToolManager::serviceIsEnabled(const QString &sname) const
{
    return ServiceTool::serviceIsEnabled(sname);
}

/******************
 * PACKAGES
 *****************/
QStringList ToolManager::getPackages() const
{
    switch (PackageTool::currentPackageTool) {
    case PackageTool::PackageTools::APT:
        return PackageTool::getDpkgPackages();
        break;
    case PackageTool::PackageTools::YUM:
    case PackageTool::PackageTools::DNF:
        return PackageTool::getRpmPackages();
        break;
    case PackageTool::PackageTools::PACMAN:
        return PackageTool::getPacmanPackages();
        break;
    default:
        return QStringList();
        break;
    }
}

QFileInfoList ToolManager::getPackageCaches() const
{
    switch (PackageTool::currentPackageTool) {
    case PackageTool::PackageTools::APT:
        return PackageTool::getDpkgPackageCaches();
        break;
    case PackageTool::PackageTools::YUM:
    case PackageTool::PackageTools::DNF:
        return PackageTool::getPacmanPackageCaches();
        break;
    case PackageTool::PackageTools::PACMAN:
        return PackageTool::getPacmanPackageCaches();
        break;
    default:
        return QFileInfoList();
        break;
    }
}

void ToolManager::uninstallPackages(const QStringList &packages)
{
    uninstallStarted();

    switch (PackageTool::currentPackageTool) {
    case PackageTool::PackageTools::APT:
        PackageTool::dpkgRemovePackages(packages);
        break;
    case PackageTool::PackageTools::YUM:
        PackageTool::yumRemovePackages(packages);
        break;
    case PackageTool::PackageTools::DNF:
        PackageTool::dnfRemovePackages(packages);
        break;
    case PackageTool::PackageTools::PACMAN:
        PackageTool::pacmanRemovePackages(packages);
        break;
    default:
        break;
    }

    uninstallFinished();
}

