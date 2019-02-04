#include "stdafx.h"
#include "Block.h"
#include <time.h>


Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 1;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
	char *cstr = new char[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }while (sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << sHash << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    return sha256(ss.str());
}
