#pragma once

namespace Kafka
{

    class FileWriter;

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


    enum SailorDataOffset
    {
        SD_OFFSET_TEAM = 0,
        SD_OFFSET_BASE = 2,
        SD_OFFSET_EXP = 8,
        SD_OFFSET_HP = 16,
        SD_OFFSET_HEALTH = 18,
        SD_OFFSET_MOOD = 19,
        SD_OFFSET_EQUIP = 20
    };

    enum SailorDataLength
    {
        SD_LENGTH_TEAM = 1,
        SD_LENGTH_BASE = 1,
        SD_LENGTH_EXP = 4,
        SD_LENGTH_HP = 2,
        SD_LENGTH_HEALTH = 1,
        SD_LENGTH_MOOD = 1,
        SD_LENGTH_EQUIP = 1,
    };

    class SailorData
    {
    public:
        SailorData();
        ~SailorData();

        void Init( int sailorId, Kafka::FileWriter* fileWriter, size_t offset );

        size_t          m_SailorId;
        Kafka::FileWriter*     m_FileWriter;
        size_t          m_Offset;

        size_t          m_Team;
        char            m_Base[ BASE_MAX ];
        int             m_Exp[ EXP_MAX ];
        short           m_HP;
        char            m_Health;
        char            m_Mood;
        char            m_Equipment[ EQUIP_MAX ];
    };

} // namespace Dk4
