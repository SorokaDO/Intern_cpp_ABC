
#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <string>

template <typename Result, typename ...Args>

class Cache
{
public:
	std::map<std::tuple<Args...>, Result>m;
	std::function<Result(Args...)>f;
	Cache(std::function<Result(Args...)> f_) : f(f_) {}
	Result find(Args... args)
	{
		auto t = std::make_tuple(args...);
		auto ft = m.find(t);
		if (ft != m.end())
		{
			return m[t];
		}
		Result r = f(std::forward<Args...>(args...));
		m.insert(std::make_pair(t, r));
		return r;
	}
};

std::string getIpInp(std::string const& s)
{
	return s;
}

std::string getIp(std::string const& s)
{
	static Cache<std::string, const std::string> cache(&getIpInp);
	return cache.find(s);
}

int main()
{
	std::string s1, s2 = "string 2";
	std::cout << getIp("string 1") << std::endl;
	std::cout << getIp(s2) << std::endl;
	std::cout << "Enter string:";
	std::cin >> s1;
	std::cout << "Result: " << getIp(s1) << std::endl;
	return 0;
}
