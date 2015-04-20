#include "Pch.h"

#include <Kafka\Stream\FileWriter.h>
#include "Data\Sailor.h"

namespace Dk4
{

    //////////////////////////////////////////////////////////////////////////
    // 海員
    SailorData::SailorData()
        : m_FileWriter( nullptr )
        , m_Offset( 0 )
        , m_SailorId( 0 )
        , m_Team( 0 )
        , m_HP( 0 )
        , m_Health( 0 )
        , m_Mood( 0 )
    {
        for ( int i = 0; i < BASE_MAX; ++i )
        {
            m_Base[ i ] = 0;
        }

        for ( int i = 0; i < EXP_MAX; ++i )
        {
            m_Exp[ i ] = 0;
        }

        for ( int i = 0; i < EQUIP_MAX; ++i )
        {
            m_Equipment[ i ] = 0;
        }
    }

    SailorData::~SailorData()
    {
        //cout << "[MESSAGE] ~SailorData(" << m_SailorId << ")" << endl;
    }

    void SailorData::Init( int sailorId, Kafka::FileWriter* fileWriter, size_t offset )
    {
        /*
        if ( fileWriter->IsOpened() )
        {
            m_SailorId = sailorId;
            m_FileWriter = fileWriter;
            m_Offset = offset;

            // 讀取海員所屬勢力
            m_FileWriter->GetByte( offset + SD_OFFSET_TEAM,
                SD_LENGTH_TEAM,
                &m_Team,
                sizeof( m_Team ) );
            // 讀取海員基本能力
            m_FileWriter->GetByte( offset + SD_OFFSET_BASE,
                SD_LENGTH_BASE * BASE_MAX,
                m_Base,
                sizeof( m_Base ) );
            // 讀取海員經驗
            m_FileWriter->GetByte( offset + SD_OFFSET_EXP,
                SD_LENGTH_EXP * EXP_MAX,
                m_Exp,
                sizeof( m_Exp ) );
            // 讀取海員生命力
            m_FileWriter->GetByte( offset + SD_OFFSET_HP,
                SD_LENGTH_HP,
                &m_HP,
                sizeof( m_HP ) );
            // 讀取海員健康
            m_FileWriter->GetByte( offset + SD_OFFSET_HEALTH,
                SD_LENGTH_HEALTH,
                &m_Health,
                sizeof( m_Health ) );
            // 讀取海員心情
            m_FileWriter->GetByte( offset + SD_OFFSET_MOOD,
                SD_LENGTH_MOOD,
                &m_Mood,
                sizeof( m_Mood ) );
            // 讀取海員裝備
            m_FileWriter->GetByte( offset + SD_OFFSET_EQUIP,
                SD_LENGTH_EQUIP * EQUIP_MAX,
                m_Equipment,
                sizeof( m_Equipment ) );
        }
        */
        return;
    }

} // namespace Dk4
