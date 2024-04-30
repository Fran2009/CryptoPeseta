// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CRYPTOPESETA_QT_CRYPTOPESETAADDRESSVALIDATOR_H
#define CRYPTOPESETA_QT_CRYPTOPESETAADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CryptoPesetaAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CryptoPesetaAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** CryptoPeseta address widget validator, checks for a valid cryptopeseta address.
 */
class CryptoPesetaAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CryptoPesetaAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // CRYPTOPESETA_QT_CRYPTOPESETAADDRESSVALIDATOR_H
