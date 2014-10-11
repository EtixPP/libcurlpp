#include <cstddef>
#include <ostream>
#include <string>
#include <curl/curl.h>

#include "curl.hpp"

namespace curl
{
	std::string version()
	{
		return curl_version();
	}

	/* global functions */
	namespace global
	{
		void cleanup()
		{
			curl_global_cleanup();
		}

		void init(long flags)
		{
			curl_global_init(flags);
		}
	}

	/* write functions */
	namespace write
	{
		std::size_t nowhere(char* data, std::size_t size, std::size_t nmemb, void*)
		{
			return size * nmemb;
		}

		std::size_t toStream(char* data, std::size_t size, std::size_t nmemb, std::ostream* stream)
		{
			if (!stream)
			{
				return 0;
			}

			stream->write(data, size * nmemb);

			stream->flush();

			return size * nmemb;
		}


		std::size_t toString(char* data, std::size_t size, std::size_t nmemb, std::string* string)
		{
			if (!string)
			{
				return 0;
			}

			string->append(data, size * nmemb);

			return size * nmemb;
		}
	}
}

