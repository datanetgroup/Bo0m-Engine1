#include "Log.h"
#include "../ThirdParty/SPDLOG/include/spdlog/sinks/stdout_color_sinks.h"

//Dieser Include Soll nach Einbindung neu Gesetzt werden so das die Datei gefunden werden kann
//#include "spdlog/sinks/stdout_color_sink.h"

namespace BE {

	////////////////////////////////////////////////////////////////////////////////////
	// Der Code wurde deaktiviert und soll erst wieder Aktiviert werden wenn Log wieder Importiert wird.
	//////////////////////////////////////////////////////////////////////////////////

	std::shared_ptr< spdlog::logger > Log::s_CoreLogger;
	std::shared_ptr< spdlog::logger > Log::s_ClientLogger;

	void Log::init()
	{
		// %T = Timestamp, %n = Name of Logger

		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("BECore");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
	///////////////////////////////////////////////////////////////////////////
}