#ifndef CURL_EASY_INL
#define CURL_EASY_INL

#include "Exception.hpp"

class EasyException;

namespace curl
{
	/* Easy templates */
	template <typename T>
	void Easy::getInfo(infoType info, T arg)
	{
		const codeType error = curl_easy_getinfo(handle_, info, arg);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}

	template <typename T>
	void Easy::setOpt(optionType option, T arg)
	{
		const codeType error = curl_easy_setopt(handle_, option, arg);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}
}

#endif
