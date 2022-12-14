/*
  SPDX-FileCopyrightText: 2002 Marc Mutz <mutz@kde.org>

  SPDX-License-Identifier: LGPL-2.0-or-later
*/
/**
  @file
  This file is part of the API for handling user identities and defines the
  IdentityCombo class.

  @brief
  A combo box that always shows the up-to-date identity list.

  @author Marc Mutz \<mutz@kde.org\>
 */

#pragma once

#include "kidentitymanagement_export.h"
#include <QComboBox>

namespace KIdentityManagement
{
class IdentityComboPrivate;
class IdentityManager;
class Identity;
/**
 * @brief The IdentityCombo class
 * @author Marc Mutz \<mutz@kde.org\>
 */
class KIDENTITYMANAGEMENT_EXPORT IdentityCombo : public QComboBox
{
    Q_OBJECT
public:
    explicit IdentityCombo(IdentityManager *manager, QWidget *parent = nullptr);

    ~IdentityCombo();
    Q_REQUIRED_RESULT QString currentIdentityName() const;
    Q_REQUIRED_RESULT uint currentIdentity() const;
    void setCurrentIdentity(const QString &identityName);
    void setCurrentIdentity(const Identity &identity);
    void setCurrentIdentity(uint uoid);
    /**
      Returns the IdentityManager used in this combo box.
      @since 4.5
    */
    Q_REQUIRED_RESULT IdentityManager *identityManager() const;

Q_SIGNALS:

    /**
      @em Really emitted whenever the current identity changes. Either
      by user intervention or on setCurrentIdentity() or if the
      current identity disappears.

      You might also want to listen to IdentityManager::changed,
      IdentityManager::deleted and IdentityManager::added.
    */
    void identityChanged(uint uoid);
    void identityDeleted(uint uoid);
    void invalidIdentity();

public Q_SLOTS:
    /**
      Connected to IdentityManager::changed(). Reloads the list of identities.
    */
    void slotIdentityManagerChanged();

protected Q_SLOTS:
    void slotEmitChanged(int);
    void slotUpdateTooltip(uint uoid);

private:
    //@cond PRIVATE
    IdentityComboPrivate *const d;
    //@endcond
};
}

