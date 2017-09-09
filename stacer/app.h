#ifndef APP_H
#define APP_H

#include <QMainWindow>

// Pages
#include "Pages/Dashboard/dashboard_page.h"
#include "Pages/StartupApps/startup_apps_page.h"
#include "Pages/SystemCleaner/system_cleaner_page.h"
#include "Pages/Services/services_page.h"
#include "Pages/Processes/processes_page.h"
#include "Pages/Uninstaller/uninstaller_page.h"
#include "Pages/Resources/resources_page.h"
#include "Pages/Settings/settings_page.h"

namespace Ui {
    class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

public:

private slots:
    void init();
    void pageClick(QPushButton *btn, QWidget *w, QString title);

    void on_dashBtn_clicked();
    void on_systemCleanerBtn_clicked();
    void on_startupAppsBtn_clicked();
    void on_servicesBtn_clicked();
    void on_uninstallerBtn_clicked();
    void on_resourcesBtn_clicked();
    void on_processesBtn_clicked();
    void on_settingsBtn_clicked();

private:
    Ui::App *ui;

private:
    // Pages
    DashboardPage *dashboardPage;
    StartupAppsPage *startupAppsPage;
    SystemCleanerPage *systemCleanerPage;
    ServicesPage *servicesPage;
    ProcessesPage *processPage;
    UninstallerPage *uninstallerPage;
    ResourcesPage *resourcesPage;
    SettingsPage *settingsPage;
};

#endif // APP_H
