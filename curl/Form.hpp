#ifndef CURL_FORM_HPP
#define CURL_FORM_HPP

#include <string>
#include <curl/curl.h>

namespace curl
{
	/* Form */
	class Form
	{
	public:
		typedef CURLFORMcode codeType;
		typedef curl_httppost handleType;

		Form() = default;
		~Form();

		Form(const Form&) = delete;
		Form& operator=(const Form&) = delete;

		handleType* getHandle();

		void addContent(const std::string& name, const std::string& content);
		void addContent(const std::string& name, const std::string& content, const std::string& type);
		void addFile(const std::string& name, const std::string& fileName);
		void addFile(const std::string& name, const std::string& fileName, const std::string& type);

	private:
		handleType* last_ = nullptr;
		handleType* post_ = nullptr;
	};
}

#endif
