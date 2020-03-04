#pragma once
#include <queue>
#include <fstream>

namespace ADUtils
{
	// Warning types
	enum class WARNING{
		NONE
	};
	// Error Types
	enum class AD_ERROR{
		SYSTEM_INIT_ERROR = 0 // Windows initialization failed
	};

	// logging class
	class ADLog
	{
	public:
		ADLog() = default;
		~ADLog() = default;

		static void EnqueueError(AD_ERROR err);
		static std::queue<AD_ERROR> GetErrorQueue();
		static bool HasErrors();
		static void LogErrors();

	private:
		static void DequeueError();
	private:
		static std::queue<AD_ERROR> errors;
	};
};