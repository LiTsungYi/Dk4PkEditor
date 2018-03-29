#include "Pch.h"

#include <cassert>
#include <Kafka\Stream\OutputFileStream.h>
#include <Kafka\Stream\InputFileStream.h>
#include "TinyFileDialogs\tinyfiledialogs.h"
#include "Application.h"
#include "DK4_Common.h"
#include "Data\Sailor.h"

namespace Dk4
{
    int Console::Run()
    {
        if ( !OpenFile() )
        {
            std::string title( "���~!" );
            std::string message( "�}���ɮץ���" );

            tinyfd_messageBox( title.c_str(), message.c_str(), "ok", "error", 0 );
            return 0;
        }

        if ( !ValidateFile() )
        {
            std::string title( "���~!" );
            std::string message( "�ɮ����ҥ���" );

            tinyfd_messageBox( title.c_str(), message.c_str(), "ok", "error", 0 );
            return 0;
        }

        LoadLeader();
        LoadSailors();
        LoadCities();
        LoadItems();

        return 0;
    }

    bool Console::OpenFile()
    {
        const char* filters[] =
        {
            "*.dk4"
        };
        std::string fileName = tinyfd_openFileDialog( "��ܰO����", "", 1, filters, 0 );
        if ( fileName.length() == 0 )
        {
            return false;
        }

        m_stream = std::shared_ptr< Kafka::InputFileStream >( new Kafka::InputFileStream( fileName, true ) );
        return m_stream && m_stream->CanRead();
    }

    bool Console::ValidateFile()
    {
        const std::string VALIDATE_STRING( "DAIKOUKAI4PKW9 1" );
        std::string readString = m_stream->ReadString( VALIDATE_STRING.length() );
        return readString == VALIDATE_STRING;
    }

    void Console::LoadLeader()
    {
        SailorData sailorLeader;
        m_stream->Seek( SAILOR_LEADER_OFFSET );
        sailorLeader.ReadFromStream( m_stream );

        std::string title( "�D�����դO" );
        m_teamId = sailorLeader.m_Team;
        tinyfd_messageBox( title.c_str(), TEAM_NAME[ m_teamId ].c_str(), "ok", "error", 0 );
    }

    void Console::LoadSailors()
    {
        m_stream->Seek( SAILOR_OFFSET );
        for ( int i = 0; i < SAILOR_NUMBER; ++i )
        {
            m_sailorData[ i ].m_SailorId = i;
            m_sailorData[ i ].ReadFromStream( m_stream );
            if ( i <= NON_NPC_SAILOR_NUMBER )
            {
                // �ˬd�O�_�����դO����
                if ( m_sailorData[ i ].m_Team != m_teamId )
                {
                    std::string title2( "�O�_�ܽ�" );
                    tinyfd_messageBox( title2.c_str(), SAILOR_NAME[ i ].c_str(), "ok", "error", 0 );
                }
                else
                {
                    switch ( i )
                    {
                    case 39: // ��i���D�J�Q�ּw
                    case 42: // ���wù�D�w�D�ھ|�}��
                    case 44: // ���w�i�D���������D�ڮL
                    case 45: // �ڤڬ��F�D�k�����D���p�B
                    case 52: // ���R�D�Ӯq
                    case 54: // �}�ںq�D�w�D�J���d�S
                    case 66: // ���D���C�}
                    case 72: // ��D������
                    {
                        // �ˬd�O�_���դO�w�g���`
                        if ( m_sailorData[ i ].m_Team == TEAM_JOINABLE )
                        {
                            std::string title2( "�O�_�ܽ�" );
                            tinyfd_messageBox( title2.c_str(), SAILOR_NAME[ i ].c_str(), "ok", "error", 0 );
                        }
                    }
                    break;
                    }
                }
            }
        }
    }

    void Console::LoadCities()
    {
        m_stream->Seek( CITY_OFFSET );
        for ( int i = 0; i < CITY_NUMBER; ++i )
        {
            m_cityData[ i ].m_CityId = i;
            m_cityData[ i ].ReadFromStream( m_stream );
        }
    }

    void Console::LoadItems()
    {
        // char myOwnValue = 0x0C;
        m_stream->Seek( ITEM_OFFSET );
        for ( int i = 0; i < ITEM_NUMBER; ++i )
        {
            m_itemData[ i ].m_itemId = i;
            m_itemData[ i ].ReadFromStream( m_stream );
        }
    }
} // namespace Dk4
