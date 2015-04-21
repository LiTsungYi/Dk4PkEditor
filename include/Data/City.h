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

    class CityData : public Kafka::ISerializable
    {
    public:
        CityData();
        ~CityData();

        virtual void WriteToStream( std::shared_ptr<Kafka::IOutputStream> stream );
        virtual void ReadFromStream( std::shared_ptr<Kafka::IInputStream> stream );

        size_t          m_CityId;

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
