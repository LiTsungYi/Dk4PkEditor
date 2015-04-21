#pragma once

#include <Kafka\Stream\ISerializable.h>
#include "DK4_Common.h"

namespace Kafka
{
    struct IOutputStream;
    struct IInputStream;
} // namespace Kafka

namespace Dk4
{

    //////////////////////////////////////////////////////////////////////////
    // 港口

    enum tagMarket
    {
        MARKET_TEAM = 0,
        MARKET_SHARE = 1,
    };

    enum tagSpecialty
    {
        SPECIALTY_STATUS = 0,
        SPECIALTY_PRICE = 1,
        SPECIALTY_NUMBER = 3,
    };


    struct Market       // 佔有率
    {
        char   TeamId;          // 勢力代號
        char   MarketShare;     // 佔有率
    };

    struct Specialty    // 特產
    {
        //unsigned char   ProductId;      // 
        char   Tradeable;       // 0: 不可交易, 1: 可以交易
        short  Price;           // 價格
        short  Amount;          // 數量
    };

    struct Popular      // 流行品
    {
        char   ProductId;       // 流行貨品
        char   PopularStage;    // 流行階段
    };

    class CityData : public Kafka::ISerializable
    {
    public:
        CityData();
        ~CityData();

        virtual void WriteToStream( std::shared_ptr<Kafka::IOutputStream> stream );
        virtual void ReadFromStream( std::shared_ptr<Kafka::IInputStream> stream );

        size_t          m_CityId;

        char            m_Avalible;                         // 0: 尚未開港, 1: 航線未知, 3: 已知港
        short           m_Facility;                         // 設施
        short           m_Bussiness;                        // 發展度
        short           m_Military;                         // 武裝度
        Market          m_MarketShare[ MAX_TEAM_IN_CITY ];    // 佔有率
        Specialty       m_SpecialProduct[ MAX_SPECIALTY ];    // 特產
        short           m_Products[ MAX_PRODUCT ];            // 交易品
        Popular         m_Popular[ MAX_POPULAR ];             // 流行品
        short           m_Status;                           // 城市狀態
    };

} // namespace Dk4
