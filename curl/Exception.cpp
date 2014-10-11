#include <stdexcept>
#include <string>
#include <curl/curl.h>

#include "Easy.hpp"
#include "Exception.hpp"
#include "Form.hpp"
#include "Share.hpp"

namespace curl
{
	/* Exception */
	Exception::Exception(const std::string& message)
		: std::runtime_error(message)
	{

	}

	/* EasyException */
	EasyException::EasyException(Easy::codeType errorId)
		: Exception(curl_easy_strerror(errorId)), errorId_(errorId)
	{

	}

	Easy::codeType EasyException::getErrorId() const
	{
		return errorId_;
	}

	/* FormException */
    FormException::FormException(Form::codeType errorId)
    	: Exception("CURLFORMcode " + std::to_string(errorId)), errorId_(errorId)
    {

    }

    Form::codeType FormException::getErrorId() const
    {
    	return errorId_;
    }

	/* ShareException */
	ShareException::ShareException(Share::codeType errorId)
		: Exception(curl_share_strerror(errorId)), errorId_(errorId)
	{

	}

	Share::codeType ShareException::getErrorId() const
	{
		return errorId_;
	}
}
