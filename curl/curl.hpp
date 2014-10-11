#ifndef CURL_CURL_HPP
#define CURL_CURL_HPP

#include <cstddef>
#include <ostream>
#include <string>
#include <curl/curl.h>

#include "Easy.hpp"
#include "Exception.hpp"
#include "Form.hpp"
#include "Header.hpp"
#include "Share.hpp"

namespace curl
{
	std::string version();

	/* global functions */
	namespace global
	{
		void cleanup();
		void init(long flags = CURL_GLOBAL_DEFAULT);
	}

	/* write functions */
	namespace write
	{
		std::size_t nowhere(char* data, std::size_t size, std::size_t nmemb, void*);
		std::size_t toStream(char* data, std::size_t size, std::size_t nmemb, std::ostream* stream);
		std::size_t toString(char* data, std::size_t size, std::size_t nmemb, std::string* string);
	}
}

#endif
