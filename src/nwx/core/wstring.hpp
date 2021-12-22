/**

    Declaration for class wstring.

*/


#ifndef NWX_CORE_WSTRING
#define NWX_CORE_WSTRING


#include <string>


namespace nwx
{
    namespace core
    {
        class wstring
        {
        public:
            wstring( const std::string& utf8_str );
            wstring( const wchar_t* wchar_str );
            wstring( size_t num_chars );
            ~wstring();

            wstring()                            = delete;
            wstring( wstring&& )                 = delete;
            wstring( const wstring& )            = delete;
            wstring& operator=( wstring&& )      = delete;
            wstring& operator=( const wstring& ) = delete;

            wchar_t* lpwstr();
            const wchar_t* lpcwstr();
            std::string utf8();

            size_t size() const;

            static std::string utf8_encode( const wchar_t* wstr );
            static std::string utf8_encode( const std::wstring& wstr );

        private:
            std::wstring m_wchar_data;
        };
    }
}


#endif // NWX_CORE_WIDE_STRING
