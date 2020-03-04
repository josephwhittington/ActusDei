#include "Utils.h"

std::queue<ADUtils::AD_ERROR> ADUtils::ADLog::errors;

//************************************ 
// Returns:   std::queue<ADUtils::ERROR>
// Desc:      Returns the error queue - don't use often, here for emergencies
// @PARAMS
// ADUtils::ERROR err -> type specifying error type
//************************************
void ADUtils::ADLog::EnqueueError(AD_ERROR err)
{
	ADUtils::ADLog::errors.push(err);
}

//************************************ 
// Returns:   std::queue<ADUtils::ERROR>
// Desc:      Returns the error queue - don't use often, here for emergencies
//************************************
std::queue<ADUtils::AD_ERROR> ADUtils::ADLog::GetErrorQueue()
{
	return ADUtils::ADLog::errors;
}

//************************************ 
// Returns:   bool
// Desc:      Returns true if error queue has an error
//************************************
bool ADUtils::ADLog::HasErrors()
{
	return ADUtils::ADLog::errors.size() > 0 ? true : false;
}

void ADUtils::ADLog::LogErrors()
{
	while (ADUtils::ADLog::HasErrors())
	{
		ADUtils::ADLog::DequeueError();
	}
}

//************************************ 
// Returns:   void
// Desc:      Processes exactly one error from the error queue
//************************************
void ADUtils::ADLog::DequeueError()
{
	AD_ERROR err = ADUtils::ADLog::errors.front();

	switch (err)
	{
	case ADUtils::AD_ERROR::SYSTEM_INIT_ERROR:
	{
		std::ofstream err_log("error.log", std::ios::out | std::ios::app);
		if (err_log.is_open())
		{
			err_log << "Failed to initialize Windows\n";
			err_log.close();
		}
	}
	default:
		break;
	}
	ADUtils::ADLog::errors.pop();
}