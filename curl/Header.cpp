#include <string>
#include <curl/curl.h>

#include "Header.hpp"

namespace curl
{
	/* Header */
	Header::Header(std::initializer_list<std::string> args)
	{
		for (const auto& arg : args)
		{
			add(arg);
		}
	}

	Header::~Header()
	{
		curl_slist_free_all(header_);
	}

	Header::handleType* Header::getHandle() const
	{
		return header_;
	}

	void Header::add(const std::string& field)
	{
		header_ = curl_slist_append(header_, field.c_str());
	}
}
