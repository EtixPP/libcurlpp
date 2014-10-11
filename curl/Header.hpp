#ifndef CURL_HEADER_HPP
#define CURL_HEADER_HPP

#include <initializer_list>
#include <string>
#include <curl/curl.h>

namespace curl
{
	/* Header */
	class Header
	{
	public:
		typedef curl_slist handleType;

		Header() = default;
		Header(std::initializer_list<std::string> args);
		~Header();

		Header(const Header&) = delete;
		Header& operator=(const Header&) = delete;

		handleType* getHandle() const;

		void add(const std::string& field);

	private:
		mutable handleType* header_ = nullptr;
	};
}

#endif
