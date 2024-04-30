// Copyright (c) 2019-2021 CryptoPeseta developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CRYPTOPESETA_SNAPSHOT_H
#define CRYPTOPESETA_SNAPSHOT_H

#include <primitives/transaction.h>
#include <fs.h>

struct SnapshotEntry {
    CScript script;
    CAmount amount;
};

struct SnapshotProvider {
    std::string address;
    std::string path;
};

CScript ReadScriptSnapshot(const std::string& s);
bool FetchSnapshot(fs::path &path, SnapshotProvider provider);
std::vector<SnapshotEntry> LoadSnapshot(fs::path &path);
std::vector<SnapshotEntry> EmptySnapshot();
std::vector<SnapshotEntry> InitSnapshot(const std::string fileName, std::vector<SnapshotProvider> providers);

#endif // CRYPTOPESETA_SNAPSHOT_H
