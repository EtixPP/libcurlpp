#include <string>
#include <curl/curl.h>

#include "Exception.hpp"
#include "Form.hpp"

namespace curl
{
	/* Form */
	Form::~Form()
	{
		curl_formfree(post_);
	}

	Form::handleType* Form::getHandle()
	{
		return post_;
	}

	void Form::addContent(const std::string& name, const std::string& content)
	{
		const codeType error = curl_formadd(&post_, &last_, CURLFORM_COPYNAME, name.c_str(), CURLFORM_COPYCONTENTS,
												content.c_str(), CURLFORM_END);

		if (error != CURL_FORMADD_OK)
		{
			throw FormException(error);
		}
	}

	void Form::addContent(const std::string& name, const std::string& content, const std::string& type)
	{
		const codeType error = curl_formadd(&post_, &last_, CURLFORM_COPYNAME, name.c_str(), CURLFORM_COPYCONTENTS,
												content.c_str(), CURLFORM_CONTENTTYPE, type.c_str(), CURLFORM_END);

		if (error != CURL_FORMADD_OK)
		{
			throw FormException(error);
		}
	}

	void Form::addFile(const std::string& name, const std::string& fileName)
	{
		const codeType error = curl_formadd(&post_, &last_, CURLFORM_COPYNAME, name.c_str(), CURLFORM_FILE,
												fileName.c_str(), CURLFORM_END);

		if (error != CURL_FORMADD_OK)
		{
			throw FormException(error);
		}
	}

	void Form::addFile(const std::string& name, const std::string& fileName, const std::string& type)
	{
		const codeType error = curl_formadd(&post_, &last_, CURLFORM_COPYNAME, name.c_str(), CURLFORM_FILE,
												fileName.c_str(), CURLFORM_CONTENTTYPE, type.c_str(), CURLFORM_END);

		if (error != CURL_FORMADD_OK)
		{
			throw FormException(error);
		}
	}
}
