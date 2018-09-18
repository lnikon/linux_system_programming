#include <iostream>
#include <string>

#include <fcntl.h>

class Dir
{
    public:
        explicit Dir(std::string path)
            : m_path(path) {}

        int open(int oflag = O_RDONLY)
        {
            m_last_ret_code = ::open(m_path.c_str(), oflag | m_must_set_flags);
            m_current_fd = m_last_ret_code;

            return m_current_fd;
        }

        int get_ret_code() const
        {
            return m_last_ret_code;
        }

        int get_current_fd() const 
        {
            return m_current_fd;
        }
    private:
        static const int m_must_set_flags = O_DIRECTORY;

        std::string m_path{};
        int m_current_fd{};
        int m_last_ret_code{};
};

int main()
{
    Dir d(".");
    
    d.open();
    int fd = d.get_current_fd();
    int ret_code = d.get_ret_code();

    std::cout << "\nfd = " << fd 
        << "\nret_code = " << ret_code << "\n";
}
