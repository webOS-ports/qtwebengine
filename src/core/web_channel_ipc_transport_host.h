/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WEB_CHANNEL_IPC_TRANSPORT_H
#define WEB_CHANNEL_IPC_TRANSPORT_H


#include <QtWebChannel/QWebChannelAbstractTransport>
#include "content/public/browser/web_contents_observer.h"

#include "qtwebenginecoreglobal.h"
#include <QtCore/QObject>

QT_FORWARD_DECLARE_CLASS(QString)

namespace QtWebEngineCore {

class WebChannelIPCTransportHost : public QWebChannelAbstractTransport
        , public content::WebContentsObserver
{
public:
    WebChannelIPCTransportHost(content::WebContents *, QObject *parent = 0);
    virtual ~WebChannelIPCTransportHost();

    // QWebChannelAbstractTransport
    virtual void sendMessage(const QJsonObject &message) Q_DECL_OVERRIDE;

private:
    bool OnMessageReceived(const IPC::Message& message) Q_DECL_OVERRIDE;
    void onWebChannelMessage(const std::vector<char> &message);
    void onWebChannelMessageSync(const std::vector<char> &message, IPC::Message *reply);

    IPC::Message *_mWaitingReply;
};

} // namespace

#endif // WEB_CHANNEL_IPC_TRANSPORT_H
