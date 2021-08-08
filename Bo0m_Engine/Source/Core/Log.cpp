#include "../bepch.h"
#include "Log.h"

//Dieser Include Soll nach Einbindung neu Gesetzt werden so das die Datei gefunden werden kann
//#include "spdlog/sinks/stdout_color_sink.h"

namespace BE {

	////////////////////////////////////////////////////////////////////////////////////
	// Der Code wurde deaktiviert und soll erst wieder Aktiviert werden wenn Log wieder Importiert wird.
	//////////////////////////////////////////////////////////////////////////////////
	Ref<spdlog::logger> Log::s_CoreLogger;
	Ref<spdlog::logger> Log::s_ClientLogger;

	void Log::init()
	{
		// %T = Timestamp, %n = Name of Logger

		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("BEngine");
		s_CoreLogger->set_level(spdlog::level::trace);


		s_ClientLogger = spdlog::stdout_color_mt("BEApp");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	///////////////////////////////////////////////////////////////////////////
}