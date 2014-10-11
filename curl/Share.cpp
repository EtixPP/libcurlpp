#include <string>
#include <curl/curl.h>

#include "Exception.hpp"
#include "Share.hpp"

namespace curl
{
	/* Share */
	Share::Share()
		: handle_(curl_share_init())
	{

	}

	Share::~Share()
	{
		curl_share_cleanup(handle_);
	}

	Share::handleType* Share::getHandle()
	{
		return handle_;
	}
}
