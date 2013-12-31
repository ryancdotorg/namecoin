// Copyright (c) 2010-2011 Vincent Durham
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

class CHooks
{
public:
    virtual bool IsStandard(const CScript& scriptPubKey) = 0;
    virtual void AddToWallet(CWalletTx& tx) = 0;
    virtual bool CheckTransaction(const CTransaction& tx) = 0;
    virtual bool ConnectInputs(CTxDB& txdb,
            map<uint256, CTxIndex>& mapTestPool,
            const CTransaction& tx,
            std::vector<CTransaction>& vTxPrev,
            std::vector<CTxIndex>& vTxindex,
            CBlockIndex* pindexBlock,
            CDiskTxPos& txPos,
            bool fBlock,
            bool fMiner) = 0;
    virtual bool DisconnectInputs(CTxDB& txdb,
            const CTransaction& tx,
            CBlockIndex* pindexBlock) = 0;
    virtual bool ConnectBlock(CBlock& block, CTxDB& txdb, CBlockIndex* pindex) = 0;
    virtual bool DisconnectBlock(CBlock& block, CTxDB& txdb, CBlockIndex* pindex) = 0;
    virtual bool ExtractAddress(const CScript& script, std::string& address) = 0;
    virtual bool GenesisBlock(CBlock& block) = 0;
    virtual bool Lockin(int nHeight, uint256 hash) = 0;
    virtual int LockinHeight() = 0;
    virtual std::string IrcPrefix() = 0;
    virtual void MessageStart(char* pchMessageStart) = 0;
    virtual void AcceptToMemoryPool(CTxDB& txdb, const CTransaction& tx) = 0;

    /* These are for display and wallet management purposes.  Not for use to decide
     * whether to spend a coin. */
    virtual bool IsMine(const CTransaction& tx) = 0;
    virtual bool IsMine(const CTransaction& tx, const CTxOut& txout) = 0;
};

extern CHooks* InitHook();
extern std::string GetDefaultDataDirSuffix();
