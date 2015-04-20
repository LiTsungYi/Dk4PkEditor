#pragma once

#include "DK4_Common.h"

namespace Kafka
{

    class FileWriter;

} // namespace Kafka

namespace Dk4
{

    //////////////////////////////////////////////////////////////////////////
    // ��f

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

    struct Market       // �����v
    {
        char   TeamId;          // �դO�N��
        char   MarketShare;     // �����v
    };

    struct Specialty    // �S��
    {
        //unsigned char   ProductId;      // 
        char   Tradeable;       // 0: ���i���, 1: �i�H���
        short  Price;           // ����
        short  Amount;          // �ƶq
    };

    struct Popular      // �y��~
    {
        char   ProductId;       // �y��f�~
        char   PopularStage;    // �y�涥�q
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

        char            m_Avalible;                         // 0: �|���}��, 1: ��u����, 3: �w����
        short           m_Facility;                         // �]�I
        short           m_Bussiness;                        // �o�i��
        short           m_Military;                         // �Z�˫�
        Market          m_MarketShare[ MAX_TEAM_IN_CITY ];    // �����v
        Specialty       m_SpecialProduct[ MAX_SPECIALTY ];    // �S��
        short           m_Products[ MAX_PRODUCT ];            // ����~
        Popular         m_Popular[ MAX_POPULAR ];             // �y��~
        short           m_Status;                           // �������A
    };

} // namespace Dk4
