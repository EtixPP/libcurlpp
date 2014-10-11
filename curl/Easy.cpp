#include <cstddef>
#include <string>
#include <curl/curl.h>

#include "Easy.hpp"
#include "Exception.hpp"

namespace curl
{
	/* Easy */
	Easy::Easy()
		: handle_(curl_easy_init())
	{

	}

	Easy::~Easy()
	{
		curl_easy_cleanup(handle_);
	}

	Easy::handleType* Easy::getHandle()
	{
		return handle_;
	}

	std::string Easy::escape(const std::string& string)
	{
		char* cEscaped = curl_easy_escape(handle_, string.c_str(), string.size());

		const std::string escaped(cEscaped);

		curl_free(cEscaped);

		return escaped;
	}

	void Easy::pause(int bitmask)
	{
		const codeType error = curl_easy_pause(handle_, bitmask);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}

	void Easy::perform()
	{
		const codeType error = curl_easy_perform(handle_);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}

	void Easy::recv(void* buffer, std::size_t bufferLength, std::size_t* n)
	{
		const codeType error = curl_easy_recv(handle_, buffer, bufferLength, n);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}

	void Easy::reset()
	{
		curl_easy_reset(handle_);
	}

	void Easy::send(const void* buffer, std::size_t bufferLength, std::size_t* n)
	{
		const codeType error = curl_easy_send(handle_, buffer, bufferLength, n);

		if (error != CURLE_OK)
		{
			throw EasyException(error);
		}
	}

	std::string Easy::unescape(const std::string& escapedString)
	{
		int size = 0;
		char* cString = curl_easy_unescape(handle_, escapedString.c_str(), escapedString.size(), &size);

		const std::string string(cString, size);

		curl_free(cString);

		return string;
	}
}

