#include <Kafka\Applications\IConsole.h>

namespace Dk4
{
    class Console : public Kafca::IConsole
    {
    public:
        int Run();

    private:
        bool OpenFile();

    };

} // namespace Dk4
