#pragma once

namespace Kafka
{

    class FileWriter;

} // namespace Kafka

namespace Dk4
{
    //////////////////////////////////////////////////////////////////////////
    // 海員 
    enum BaseSkill
    {
        BASE_CON,       // 體力
        BASE_AGI,       // 敏捷
        BASE_CRM,       // 魅力
        BASE_INT,       // 智力
        BASE_SPI,       // 精神
        BASE_LUK,       // 運氣
        BASE_MAX        // 技能數
    };

    enum Exp
    {
        EXP_1,          // 商業
        EXP_2,          // 軍事
        EXP_MAX         // 總數
    };

    enum Equipment
    {
        EQUIP_WEAPON,   // 武器
        EQUIP_ARMOR,    // 防具
        EQUIP_ITEM_1,   // 道具１
        EQUIP_ITEM_2,   // 道具２
        EQUIP_ITEM_3,   // 道具３
        EQUIP_MAX       // 總數
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
