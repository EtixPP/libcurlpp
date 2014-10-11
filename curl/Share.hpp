#ifndef CURL_SHARE_HPP
#define CURL_SHARE_HPP

#include <string>
#include <curl/curl.h>

#include "curl.hpp"

namespace curl
{
	/* Share */
	class Share
	{
	public:
		typedef CURLSHcode codeType;
		typedef CURLSH handleType;
		typedef CURLSHoption optionType;

		Share();
		~Share();

		Share(const Share&) = delete;
		Share& operator=(const Share&) = delete;

		handleType* getHandle();

		template <typename T>
		void setOpt(optionType option, T arg);

	private:
		handleType* handle_ = nullptr;
	};
}

#include "Share.inl"

#endif
