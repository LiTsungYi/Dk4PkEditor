#include "Pch.h"

#include "Application.h"

namespace Dk4
{
    int Console::Run()
    {
        if ( !OpenFile() )
        {
            std::string title( "開啟檔案失敗" );
            std::string message( "World" );

            tinyfd_messageBox( title.c_str(), message.c_str(), "ok", "info", 0 );
        }


        return 0;
    }

    bool Console::OpenFile()
    {
        const char* filters[] =
        {
            "savdat*.dk4"
        };
        const char* file = tinyfd_openFileDialog( "選擇記錄檔", "", 1, filters, 0 );
        return ( file != nullptr );
    }

} // namespace Dk4
