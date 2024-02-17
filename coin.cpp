#include "coin.hpp"
#include <random>
#include <set>

Coin::Coin(CoinState const coinInitialState)
{
}

std::string Coin::FlipCoin()
{
    std::set<Coin::CoinState> const coinSet = {eHeads, eTails};

    std::random_device rd;
    std::mt19937 generatror(rd());

    std::uniform_int_distribution<> dis(0, coinSet.size() - 1);
    int index = dis(generatror);
    auto ptr = coinSet.begin();
    std::advance(ptr, index);
    mCoinState = *ptr;
    return GetCoinState();
}

std::string Coin::GetCoinState() const
{
    switch(mCoinState)
    {
        case eHeads:
            return "Heads";
        case eTails:
            return "Tails";
        default:
            return "Well, what are the odds!, the coin is standing on its edge";
            break;
    }
}

Coin::~Coin()
{
}