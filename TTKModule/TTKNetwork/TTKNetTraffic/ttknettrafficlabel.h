#ifndef TTKNETTRAFFICLABEL_H
#define TTKNETTRAFFICLABEL_H

/* =================================================
 * This file is part of the TTK Tiny Tools project
 * Copyright (C) 2015 - 2020 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QLabel>
#include <QThread>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class QProcess;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTKNetTraffic : public QThread
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKNetTraffic)
public:
    /*!
     * Object contsructor.
     */
    explicit TTKNetTraffic(QObject *parent = nullptr);

    virtual ~TTKNetTraffic();

    /*!
     * Set available newtwork name.
     */
    void setAvailableNewtworkName(const QString &name);
    /*!
     * Get newtwork names.
     */
    QStringList getNewtworkNames() const;
    /*!
     * Stop and quit current thread.
     */
    void stopAndQuitThread();
    /*!
     * Strat thread now.
     */
    void start();

Q_SIGNALS:
    /*!
     * Send current upload and download speed data.
     */
    void networkData(ulong upload, ulong download);

private Q_SLOTS:
    /*!
     * Get output recieved data on linux network.
     */
    void outputRecieved();

protected:
    /*!
     * Thread run now.
     */
    virtual void run() override;

protected:
    bool m_run;
    QString m_name;
    QProcess *m_process ;

};

#endif // TTKNETTRAFFICLABEL_H
