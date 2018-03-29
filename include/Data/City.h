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

    enum CityAvailable
    {
        Unknown = 0, // ��T����
        Known = 1, // ��T�w��
        New = 3, // �s��}�P
    };

    enum CityFacility
    {
        Inn = 0x0001, // ���]
        Secret = 0x0002, // ���
        Chuch = 0x0004, // �а�
        Gate = 0x0008, // ����
        Place = 0x0100, // �s��
        Trade = 0x0200, // �����
        Ship = 0x0400, // �y��t
        Port = 0x0800, // �X�Y
        Wine = 0x1000, // �s�]
        Guild = 0x2000, // �P�~���|
        Pla = 0x4000, // ���c
        Gov = 0x8000, // �`����
    };

    enum Tradeability
    {
        CannotTrade = 0,
        CanTrade = 1,
    };

    enum CityStatus
    {
        War = 0x00, // �Ԫ�
        Sick = 0x01, // �e�f
        Food = 0x02, // ����
        Good = 0x03, // �n����
        Bad = 0x04, // ������
        NotEnough1 = 0x05, // �S�w�f�~����
        NotEnough2 = 0x06, // �S�w�f�~����
        NotEnough3 = 0x07, // �S�w�f�~����
        NotEnough4 = 0x08, // �S�w�f�~����
        NotEnough5 = 0x09, // �S�w�f�~����
        NotEnough6 = 0x0A, // �S�w�f�~����
        Normal = 0x0C, // ���`
    };

    struct Market       // �����v
    {
        char   TeamId;          // �դO�N��
        char   MarketShare;     // �����v
    };

    struct Specialty // �S��
    {
        Tradeability Tradeable; // 0: ���i���, 1: �i�H���
        short Price; // ����
        short Amount; // �ƶq
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

        CityAvailable m_Avalible;
        CityFacility m_Facility; // �]�I
        short m_Bussiness; // �o�i��
        short m_Military; // �Z�˫�
        Market m_MarketShare[ MAX_TEAM_IN_CITY ]; // �����v
        Specialty m_SpecialProduct[ MAX_SPECIALTY ]; // �S��
        short m_Products[ MAX_PRODUCT ]; // ����~
        Popular m_Popular[ MAX_POPULAR ]; // �y��~
        short m_Status; // �������A
    };

} // namespace Dk4
