// Dk4PkEditor.cpp : Defines the entry point for the console application.
//

#include "Pch.h"

#include <Windows.h>
#include <codecvt>
#include <conio.h>
#include <iostream>
#include <locale>
#include <string>
#include <Kafka\Stream\FileWriter.h>
#include "TinyFileDialogs\tinyfiledialogs.h"
#include "Application.h"
#include "DK4_Common.h"
#include "Data\Sailor.h"
#include "Data\City.h"

namespace Dk4
{
    using std::cin;
    using std::cout;
    using std::endl;

} // namespace Dk4

using namespace Dk4;

int main( int argc, char* argv[] )
{
    Dk4::Console console;
    return console.Run();

    /*
    int myTeamId = 0;
    char input = 0;
    Kafka::FileWriter saveFile;

    const size_t BUFFER_SIZE = 64;
    char* buffer = new char[ BUFFER_SIZE ];
    buffer = static_cast< char* >( SecureZeroMemory( buffer, BUFFER_SIZE ) );

    // �}�Ҭ�����
    cout << "��ܶ}�Ҫ��ɮ� 0-7: ";
    cin >> input;

    saveFile.OpenFile( atoi( &input ) );

    // �ˬd�����ɬO�_�}��
    if ( saveFile.IsOpened() )
    {
        cout << "File opened" << endl;

        size_t readBytes;

        readBytes = saveFile.GetByte( 0, VALIDATE_STRING_SIZE, buffer, BUFFER_SIZE );

        // ���ҬO�_���j����|������
        if ( 0 == readBytes )
        {
            cout << "Read nothing!" << endl;
        }
        else
        {
            if ( 0 == strcmp( buffer, VALIDATE_STRING.c_str() ) )
            {
                // ���ҳq�L
                cout << "File validate success!" << endl;

                // ���o�D�����
                SailorData sailorLeader;
                sailorLeader.Init( -1, &saveFile, SAILOR_LEADER_OFFSET );

                myTeamId = sailorLeader.m_Team;

                cout << "�D�����դO���G" << TEAM_NAME[ myTeamId ] << endl;

                // ���o�������
                SailorData* sailorData = new SailorData[ SAILOR_NUMBER ];

                for ( int i = 0, offset = SAILOR_OFFSET; i < SAILOR_NUMBER; ++i, offset += SAILOR_DATA_SIZE )
                {
                    sailorData[ i ].Init( i, &saveFile, offset );

                    cout << SAILOR_NAME[ i ] << " �ثe�� " << TEAM_NAME[ sailorData[ i ].m_Team ] << " ������" << endl;

                    if ( i <= NON_NPC_SAILOR_NUMBER )
                    {
                        // �ˬd�O�_�����դO����
                        if ( sailorData[ i ].m_Team != myTeamId )
                        {
                            cout << "�O�_�ܽ� " << SAILOR_NAME[ i ] << " �[�J�ڭx�H (y/n)";
                            cin >> input;
                            if ( 'y' == input )
                            {
                                // �ܽХ[�J
                                saveFile.SetByte( offset, 1, &myTeamId, sizeof( int ) );
                            }
                        }
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
                            if ( sailorData[ i ].m_Team == TEAM_JOINABLE )
                            {
                                cout << "�O�_�ܽ� " << SAILOR_NAME[ i ] << " �[�J�ڭx�H (y/n)";
                                cin >> input;
                                if ( 'y' == input )
                                {
                                    // �ܽХ[�J
                                    saveFile.SetByte( offset, 1, &myTeamId, sizeof( int ) );
                                }
                            }
                        }
                        break;
                        }
                    }
                }

                // ���o��f���
                CityData* cityData = new CityData[ CITY_NUMBER ];

                for ( int i = 0, offset = CITY_OFFSET; i < CITY_NUMBER; ++i, offset += CITY_DATA_SIZE )
                {
                    cityData[ i ].Init( i, &saveFile, offset );

                    cout << CITY_NAME[ i ] << " [��:" << cityData[ i ].m_Bussiness
                        << "/�Z:" << cityData[ i ].m_Military << "]" << endl;

                    for ( int j = 0; j<MAX_TEAM_IN_CITY; ++j )
                    {
                        if ( 0 <= cityData[ i ].m_MarketShare[ j ].TeamId &&
                            ( TEAM_NUMBER - 2 ) > cityData[ i ].m_MarketShare[ j ].TeamId )
                        {
                            int marketShare = cityData[ i ].m_MarketShare[ j ].MarketShare;
                            cout << TEAM_NAME[ cityData[ i ].m_MarketShare[ j ].TeamId ] <<
                                marketShare << "% ";
                        }
                    }
                    cout << endl;

                    if ( i > 50 )
                    {
                        cout << endl;
                    }

                    for ( int j = 0; j < MAX_SPECIALTY; ++j )
                    {
                        if ( 0 != cityData[ i ].m_SpecialProduct[ j ].Price )
                        {
                            if ( cityData[ i ].m_SpecialProduct[ j ].Tradeable )
                            {
                                saveFile.SetByte( cityData[ i ].m_Offset + CD_OFFSET_SPECIALTY + ( CD_LENGTH_SPECIALTY * j ) + SPECIALTY_STATUS,
                                    1,
                                    &SPECIALTY_TRADEABLE,
                                    sizeof( SPECIALTY_TRADEABLE ) );
                            }
                            cout << cityData[ i ].m_SpecialProduct[ j ].Price << " x" <<
                                cityData[ i ].m_SpecialProduct[ j ].Amount << endl;
                        }
                    }
                }

                // �}�P�s��
                for ( int i = 0; i < NEW_CITY_NUMBER; ++i )
                {
                    char newCityOpend;
                    size_t offset = NEW_CITY_OFFSET[ i ];

                    saveFile.GetByte( NEW_CITY_OFFSET[ i ], 1, &newCityOpend, sizeof( newCityOpend ) );
                    cout << "��f " << NEW_CITY_NAME[ i ] << " (" << static_cast< int >( newCityOpend ) << ")" << endl;
                    if ( CITY_OPENED != newCityOpend )
                    {
                        // �ˬd��f�O�_�w�g�}��
                        cout << "�O�_�}�P��f " << NEW_CITY_NAME[ i ] << " �H (y/n)";
                        cin >> input;
                        if ( 'y' == input )
                        {
                            // �}�P��f
                            saveFile.SetByte( offset, 1, &CITY_OPENED, sizeof( CITY_OPENED ) );
                            saveFile.SetByte( offset + CD_LENGTH_FACILITY, 2, &CITY_HOUSE_ALL, sizeof( CITY_HOUSE_ALL ) );
                        }
                    }
                }

                char myOwnValue = 0x0C;
                char value;
                for ( int i = 0, offset = ITEM_OFFSET; i < ITEM_NUMBER; ++i, offset += sizeof( short ) )
                {
                    saveFile.GetByte( offset + sizeof( char ), sizeof( char ), &value, sizeof( value ) );
                    cout << "�O�_�����D�� " << ITEM_NAME[ i ] << " �H (y/n)";
                    cin >> input;
                    if ( 'y' == input )
                    {
                        saveFile.SetByte( offset + sizeof( char ), sizeof( char ), &myOwnValue, sizeof( myOwnValue ) );
                    }
                }

                delete[] sailorData;
                delete[] cityData;
            }
        }
    }
    else
    {
        cout << "File closed" << endl;
    }

    saveFile.CloseFile();
    _getch();

    delete[] buffer;
    */

    return 0;
}
