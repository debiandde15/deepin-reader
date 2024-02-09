/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     leiyu <leiyu@uniontech.com>
*
* Maintainer: leiyu <leiyu@uniontech.com>
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
#ifndef PAGESEARCHTHREAD_H
#define PAGESEARCHTHREAD_H

#include "Model.h"

#include <QThread>

class BrowserPage;
class DocSheet;
class PageSearchThread : public QThread
{
    Q_OBJECT
public:
    explicit PageSearchThread(QObject *parent = nullptr);

    virtual ~PageSearchThread() override;

public:
    void startSearch(DocSheet *sheet, QString text);

    void stopSearch();

signals:
    void sigSearchReady(const deepin_reader::SearchResult &res);

    /**
     * @brief sigSearchResultNotEmpty
     * 搜索结果不为空信号
     */
    void sigSearchResultNotEmpty();

protected:
    void run() override;

private:
    /**
     * @brief initCJKtoKangxi
     * 由于docx转换工具会将部分CJK字体转为康熙字典部首字体，需要在搜索时再搜索一遍这些康熙字典部首字体
     * 该函数会根据CJK与康熙字典部首匹配文件初始化m_cjktokangximap
     */
    void initCJKtoKangxi();

private:
    bool m_quit = false;
    int m_startIndex = 0;
    QString m_searchText;
    DocSheet *m_sheet = nullptr;
    static QMap<QChar, QChar> m_cjktokangximap;
};

#endif // PAGESEARCHTHREAD_H
