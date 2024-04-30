// Copyright (c) 2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//! @file
//! @brief Common init functions shared by cryptopeseta-node, cryptopeseta-wallet, etc.

#ifndef CRYPTOPESETA_INIT_COMMON_H
#define CRYPTOPESETA_INIT_COMMON_H

class ArgsManager;

namespace init {
void SetGlobals();
void UnsetGlobals();
/**
 *  Ensure a usable environment with all
 *  necessary library support.
 */
bool SanityChecks();
void AddLoggingArgs(ArgsManager& args);
void SetLoggingOptions(const ArgsManager& args);
void SetLoggingCategories(const ArgsManager& args);
bool StartLogging(const ArgsManager& args);
void LogPackageVersion();
} // namespace init

#endif // CRYPTOPESETA_INIT_COMMON_H
