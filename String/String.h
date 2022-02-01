//
//  String.h
//  String
//
//  Created by puneet on 07/11/21.
//

#ifndef String_h
#define String_h

#include <memory>
/// @todo add SSO
template<typename CharT>
class String
{
public:
    String() : m_size(0), m_capacity(0)
    {
        init(m_capacity);
    }
    
    String(const CharT* str, size_t len) : m_size(len), m_capacity(len)
    {
        init(m_capacity, str);
    }
    
    String(const CharT* str) : m_size(0), m_capacity(0)
    {
        if (str)
        {
            m_size = m_capacity = strlen(str);
        }
        init(m_capacity, str);
    }
    
    // copy constructor
    String(const String& str) : String(str.data()) {}
    
    String& operator=(const String& other)
    {
        copy(other.data(), other.size());
        return *this;
    }
    String& operator=(const CharT* other)
    {
        if (!other) throw;
        copy(other, strlen(other));
        return *this;
    }

    
    // move
    String(String&& str) noexcept : m_buf(str.release()), m_size(str.size()), m_capacity(str.capacity())
    {
    }
    
    String& operator=(String&& other) noexcept
    {
        if (data() == other.data()) return *this;
        
        ::free(m_buf);
        m_buf = other.release();
        m_size = other.size();
        m_capacity = other.capacity();
        
        return *this;
    }
    
    ~String() noexcept
    {
        ::free(m_buf);
        m_buf = nullptr;
    }
    
    const CharT* data() const noexcept { return c_str(); }
    CharT* data() noexcept { return c_str(); }
    CharT* mutable_data() noexcept { return m_buf; }
    
    const CharT* c_str() const noexcept { return m_buf; }
    
    auto size() const noexcept { return m_size; }
    auto capacity() const noexcept { return m_capacity; }
    
    CharT* release() noexcept
    {
        auto ret = m_buf;
        m_buf = nullptr;
        return ret;
    }
 
private:
    void copy(const CharT* other, size_t len)
    {
        assert(other != nullptr);
        
        if (other == data()) return;
        
        if (capacity() < len)
        {
            auto new_buf = ::realloc(m_buf, sizeof(CharT) * (len+1));
            if (new_buf == nullptr) throw;
            
            m_buf = (CharT*)new_buf;
            m_capacity = len;
        }
        
        strncpy(m_buf, other, len);
        m_buf[len] = 0;
        m_size = len;
    }
    
    CharT* c_str() noexcept { return m_buf; }
    
    void init(size_t len, const char* str = nullptr)
    {
        m_buf = (CharT*)::malloc(sizeof(CharT) * (1+len));
        if (!m_buf) throw;
        if (str) strncpy(m_buf, str, len);
        m_buf[len] = 0;
    }
    
    
private:
    CharT* m_buf;
    size_t m_size;
    size_t m_capacity;
};

#endif /* String_h */
