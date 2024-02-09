/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <DApplication>

class AppInfo;

#if defined(dApp)
#undef dApp
#endif
#define dApp (static_cast<Application *>(QCoreApplication::instance()))

DWIDGET_USE_NAMESPACE

class Application : public DApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);

    ~Application() override;

    void emitSheetChanged();

signals:
    void sigShowAnnotTextWidget();

    void sigSetPasswdFocus();

protected:
    /**
     * @brief handleQuitAction
     * 通过菜单选项关闭所有
     */
    void handleQuitAction() override;

    /**
     * @brief notify
     * 让无法响应的对象强行响应
     * @param object
     * @param event
     * @return
     */
    bool notify(QObject *object, QEvent *event) override;
};

#endif  // APPLICATION_H_
