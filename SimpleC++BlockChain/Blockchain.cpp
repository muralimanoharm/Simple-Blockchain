
#include "stdafx.h"
#include "Blockchain.h"

Blockchain::Blockchain(int nDifficulty)
{
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = nDifficulty;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}
