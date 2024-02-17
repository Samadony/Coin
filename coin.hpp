#include <string>

class Coin
{
public:
    enum CoinState
    {
        eHeads = 0,
        eTails,
        eCointStatesCount
    };

    Coin(CoinState const coinInitialState = eHeads);
    std::string FlipCoin();
    std::string GetCoinState() const;
    ~Coin();

private:
    CoinState mCoinState;

};