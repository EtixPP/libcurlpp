#ifndef CURL_EXCEPTION_HPP
#define CURL_EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include <curl/curl.h>

#include "Easy.hpp"
#include "Form.hpp"
#include "Share.hpp"

namespace curl
{
	/* Exception */
	class Exception : public std::runtime_error
	{
	public:
		Exception(const std::string& message);
	};

	/* EasyException */
	class EasyException : public Exception
	{
	public:
		EasyException(Easy::codeType errorId);

		Easy::codeType getErrorId() const;

	private:
		const Easy::codeType errorId_;
	};

	/* FormException */
	class FormException : public Exception
	{
	public:
		FormException(Form::codeType errorId);

		Form::codeType getErrorId() const;

	private:
		const Form::codeType errorId_;
	};

	/* ShareException */
	class ShareException : public Exception
	{
	public:
		ShareException(Share::codeType errorId);

		Share::codeType getErrorId() const;

	private:
		const Share::codeType errorId_;
	};
}

#endif
