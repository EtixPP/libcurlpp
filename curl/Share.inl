#ifndef CURL_SHARE_INL
#define CURL_SHARE_INL

#include "Exception.hpp"

class ShareException;

namespace curl
{
	/* Share templates */
	template <typename T>
	void Share::setOpt(optionType option, T arg)
	{
		const codeType error = curl_share_setopt(handle_, option, arg);

		if (error != CURLSHE_OK)
		{
			throw ShareException(error);
		}
	}
}

#endif
