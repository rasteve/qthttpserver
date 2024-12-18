// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QHTTPSERVERCONFIGURATION_H
#define QHTTPSERVERCONFIGURATION_H

#include <QtHttpServer/qthttpserverglobal.h>

#include <QtCore/qshareddata.h>

QT_BEGIN_NAMESPACE

class QHttpServerConfigurationPrivate;
QT_DECLARE_QESDP_SPECIALIZATION_DTOR_WITH_EXPORT(QHttpServerConfigurationPrivate, Q_HTTPSERVER_EXPORT)

class Q_HTTPSERVER_EXPORT QHttpServerConfiguration
{
public:
    QHttpServerConfiguration();
    QHttpServerConfiguration(const QHttpServerConfiguration &other);
    QHttpServerConfiguration(QHttpServerConfiguration &&other) noexcept = default;
    QHttpServerConfiguration &operator = (const QHttpServerConfiguration &other);

    QT_MOVE_ASSIGNMENT_OPERATOR_IMPL_VIA_PURE_SWAP(QHttpServerConfiguration)
    void swap(QHttpServerConfiguration &other) noexcept { d.swap(other.d); }

    ~QHttpServerConfiguration();

    void setRateLimitPerSecond(unsigned maxRequests);
    unsigned rateLimitPerSecond() const;

private:
    QExplicitlySharedDataPointer<QHttpServerConfigurationPrivate> d;

    friend Q_HTTPSERVER_EXPORT bool
    comparesEqual(const QHttpServerConfiguration &lhs, const QHttpServerConfiguration &rhs) noexcept;
    Q_DECLARE_EQUALITY_COMPARABLE(QHttpServerConfiguration)
};
Q_DECLARE_SHARED(QHttpServerConfiguration)

QT_END_NAMESPACE

#endif // QHTTPSERVERCONFIGURATION_H
