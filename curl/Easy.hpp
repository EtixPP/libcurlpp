#ifndef CURL_EASY_HPP
#define CURL_EASY_HPP

#include <cstddef>
#include <string>
#include <curl/curl.h>

namespace curl
{
	/* Easy */
	class Easy
	{
	public:
		typedef CURLcode codeType;
		typedef CURL handleType;
		typedef CURLINFO infoType;
		typedef CURLoption optionType;

		Easy();
		~Easy();

		Easy(const Easy&) = delete;
		Easy& operator=(const Easy&) = delete;

		handleType* getHandle();

		std::string escape(const std::string& string);
		void pause(int bitmask);
		void perform();
		void recv(void* buffer, std::size_t bufferLength, std::size_t* n);
		void reset();
		void send(const void* buffer, std::size_t bufferLength, std::size_t* n);
		std::string unescape(const std::string& escapedString);

		template <typename T>
		void getInfo(infoType info, T arg);
		template <typename T>
		void setOpt(optionType option, T arg);

	private:
		handleType* handle_ = nullptr;
	};
}

#include "Easy.inl"

#endif
