#pragma once

#include <Kafka\Stream\ISerializable.h>

namespace Kafka
{
    struct IOutputStream;
    struct IInputStream;
} // namespace Kafka

namespace Dk4
{
    //////////////////////////////////////////////////////////////////////////
    // ���� 
    enum BaseSkill
    {
        BASE_CON,       // ��O
        BASE_AGI,       // �ӱ�
        BASE_CRM,       // �y�O
        BASE_INT,       // ���O
        BASE_SPI,       // �믫
        BASE_LUK,       // �B��
        BASE_MAX        // �ޯ��
    };

    enum Exp
    {
        EXP_1,          // �ӷ~
        EXP_2,          // �x��
        EXP_MAX         // �`��
    };

    enum Equipment
    {
        EQUIP_WEAPON,   // �Z��
        EQUIP_ARMOR,    // ����
        EQUIP_ITEM_1,   // �D�㢰
        EQUIP_ITEM_2,   // �D�㢱
        EQUIP_ITEM_3,   // �D�㢲
        EQUIP_MAX       // �`��
    };

    class SailorData : public Kafka::ISerializable
    {
    public:
        SailorData();
        ~SailorData();

        virtual void WriteToStream( std::shared_ptr<Kafka::IOutputStream> stream );
        virtual void ReadFromStream( std::shared_ptr<Kafka::IInputStream> stream );

        size_t m_SailorId;

        char m_Team;
        char m_Base[ BASE_MAX ];
        int m_Exp[ EXP_MAX ];
        short m_HP;
        char m_Health;
        char m_Mood;
        char m_Equipment[ EQUIP_MAX ];
    };

} // namespace Dk4
