#pragma once

#include "DK4_Common.h"

namespace Kafka
{

    class FileWriter;

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

    enum CITY_DATA_OFFSET
    {
        CD_OFFSET_AVALIBLE = 0,
        CD_OFFSET_FACILITY = 2,
        CD_OFFSET_BUSSINESS = 6,
        CD_OFFSET_MILITARY = 12,
        CD_OFFSET_MARKET = 18,
        CD_OFFSET_SPECIALTY = 24,
        CD_OFFSET_PRODUCTS = 49,
        CD_OFFSET_POPULAR = 87,
        CD_OFFSET_STATUS = 91,
    };

    enum CITY_DATA_LENGTH
    {
        CD_LENGTH_AVALIBLE = 1,
        CD_LENGTH_FACILITY = 2,
        CD_LENGTH_BUSSINESS = 2,
        CD_LENGTH_MILITARY = 2,
        CD_LENGTH_MARKET = 2,
        CD_LENGTH_MARKETTEAM = 1,
        CD_LENGTH_MARKETSHARE = 1,
        CD_LENGTH_SPECIALTY = 5,
        CD_LENGTH_SPECIALTYSTATUS = 1,
        CD_LENGTH_SPECIALTYPRICE = 2,
        CD_LENGTH_SPECIALTYNUMBER = 2,
        CD_LENGTH_PRODUCTS = 2,
        CD_LENGTH_POPULAR = 2,
        CD_LENGTH_STATUS = 1,
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

    class CityData
    {
    public:
        CityData();
        ~CityData();

        void Init( int cityId, Kafka::FileWriter* fileWriter, size_t offset );

        size_t          m_CityId;
        Kafka::FileWriter*     m_FileWriter;
        size_t          m_Offset;

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
