// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CRYPTOPESETA_SCRIPT_CRYPTOPESETACONSENSUS_H
#define CRYPTOPESETA_SCRIPT_CRYPTOPESETACONSENSUS_H

#include <stdint.h>

#if defined(BUILD_CRYPTOPESETA_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/cryptopeseta-config.h>
  #if defined(_WIN32)
    #if defined(HAVE_DLLEXPORT_ATTRIBUTE)
      #define EXPORT_SYMBOL __declspec(dllexport)
    #else
      #define EXPORT_SYMBOL
    #endif
  #elif defined(HAVE_DEFAULT_VISIBILITY_ATTRIBUTE)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBCRYPTOPESETACONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CRYPTOPESETACONSENSUS_API_VER 1

typedef enum cryptopesetaconsensus_error_t
{
    cryptopesetaconsensus_ERR_OK = 0,
    cryptopesetaconsensus_ERR_TX_INDEX,
    cryptopesetaconsensus_ERR_TX_SIZE_MISMATCH,
    cryptopesetaconsensus_ERR_TX_DESERIALIZE,
    cryptopesetaconsensus_ERR_AMOUNT_REQUIRED,
    cryptopesetaconsensus_ERR_INVALID_FLAGS,
} cryptopesetaconsensus_error;

/** Script verification flags */
enum
{
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_P2SH | cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | cryptopesetaconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int cryptopesetaconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, cryptopesetaconsensus_error* err);

EXPORT_SYMBOL int cryptopesetaconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, cryptopesetaconsensus_error* err);

EXPORT_SYMBOL unsigned int cryptopesetaconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // CRYPTOPESETA_SCRIPT_CRYPTOPESETACONSENSUS_H
