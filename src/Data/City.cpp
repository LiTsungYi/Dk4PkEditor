#include "Pch.h"

#include <Kafka\Stream\FileWriter.h>
#include "Data\City.h"

namespace Dk4
{
    //////////////////////////////////////////////////////////////////////////
    // 港口
    CityData::CityData()
        : m_FileWriter( nullptr )
        , m_Offset( 0 )
        , m_CityId( 0 )
    {}

    CityData::~CityData()
    {
        //cout << "[MESSAGE] ~CityData(" << m_CityId << ")" << endl;
    }

    void CityData::Init( int cityId, Kafka::FileWriter* fileWriter, size_t offset )
    {
        /*
        if ( fileWriter->IsOpened() )
        {
            m_CityId = cityId;
            m_FileWriter = fileWriter;
            m_Offset = offset;

            // 讀取城市能見度
            m_FileWriter->GetByte( offset + CD_OFFSET_AVALIBLE,
                CD_LENGTH_AVALIBLE,
                &m_Avalible,
                sizeof( m_Avalible ) );
            // 讀取城市設施
            m_FileWriter->GetByte( offset + CD_OFFSET_FACILITY,
                CD_LENGTH_FACILITY,
                &m_Facility,
                sizeof( m_Facility ) );
            // 讀取城市發展度
            m_FileWriter->GetByte( offset + CD_OFFSET_BUSSINESS,
                CD_LENGTH_BUSSINESS,
                &m_Bussiness,
                sizeof( m_Bussiness ) );
            // 讀取城市武裝度
            m_FileWriter->GetByte( offset + CD_OFFSET_MILITARY,
                CD_LENGTH_MILITARY,
                &m_Military,
                sizeof( m_Military ) );
            // 讀取城市佔有率
            for ( int i = 0; i < MAX_TEAM_IN_CITY; ++i )
            {
                m_FileWriter->GetByte( offset + CD_OFFSET_MARKET + ( CD_LENGTH_MARKET * i ) + MARKET_TEAM,
                    CD_LENGTH_MARKETTEAM,
                    &( m_MarketShare[ i ].TeamId ),
                    sizeof( m_MarketShare[ i ].TeamId ) );
                m_FileWriter->GetByte( offset + CD_OFFSET_MARKET + ( CD_LENGTH_MARKET * i ) + MARKET_SHARE,
                    CD_LENGTH_MARKETSHARE,
                    &( m_MarketShare[ i ].MarketShare ),
                    sizeof( m_MarketShare[ i ].MarketShare ) );
            }

            // 讀取城市特產
            for ( int i = 0; i < MAX_SPECIALTY; ++i )
            {
                m_FileWriter->GetByte( offset + CD_OFFSET_SPECIALTY + ( CD_LENGTH_SPECIALTY * i ) + SPECIALTY_STATUS,
                    CD_LENGTH_SPECIALTYSTATUS,
                    &( m_SpecialProduct[ i ].Tradeable ),
                    sizeof( m_SpecialProduct[ i ].Tradeable ) );
                m_FileWriter->GetByte( offset + CD_OFFSET_SPECIALTY + ( CD_LENGTH_SPECIALTY * i ) + SPECIALTY_PRICE,
                    CD_LENGTH_SPECIALTYPRICE,
                    &( m_SpecialProduct[ i ].Price ),
                    sizeof( m_SpecialProduct[ i ].Price ) );
                m_FileWriter->GetByte( offset + CD_OFFSET_SPECIALTY + ( CD_LENGTH_SPECIALTY * i ) + SPECIALTY_NUMBER,
                    CD_LENGTH_SPECIALTYNUMBER,
                    &( m_SpecialProduct[ i ].Amount ),
                    sizeof( m_SpecialProduct[ i ].Amount ) );
            }

            //m_FileWriter->GetByte(offset + CD_OFFSET_AVALIBLE, CD_LENGTH_AVALIBLE, &m_Avalible, sizeof(m_Avalible));

            // 讀取城市交易品
            //m_FileWriter->GetByte(offset + CD_OFFSET_AVALIBLE, CD_LENGTH_AVALIBLE, &m_Avalible, sizeof(m_Avalible));

            // 讀取城市流行品
            //m_FileWriter->GetByte(offset + CD_OFFSET_AVALIBLE, CD_LENGTH_AVALIBLE, &m_Avalible, sizeof(m_Avalible));

            // 讀取城市狀態
            //m_FileWriter->GetByte(offset + CD_OFFSET_AVALIBLE, CD_LENGTH_AVALIBLE, &m_Avalible, sizeof(m_Avalible));
        }
        */
    }
} // namespace Dk4
