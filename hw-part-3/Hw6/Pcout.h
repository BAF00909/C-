#pragma once


static std::mutex mtx_cout;


struct pcout
{
    std::unique_lock<std::mutex> lk;
    pcout() : lk(std::unique_lock<std::mutex>(mtx_cout)){}

    template<typename T>
    pcout& operator<<(const T& _t)
    {
        std::cout << _t;
        return *this;
    }

    pcout& operator<<(std::ostream& (*fp)(std::ostream&))
    {
        std::cout << fp;
        return *this;
    }
};
