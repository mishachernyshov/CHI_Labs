#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace l1 {
	class Txt {
	public:
		Txt();
		Txt(const std::string&);
		Txt(const Txt&);
		Txt& operator=(const Txt&);
		Txt(Txt&&) noexcept;
		Txt& operator=(Txt&&)noexcept;
		~Txt();
		size_t size() const;
	private:
		size_t readRowCount(const std::string&) const;
		std::string* fileStrings;
		size_t rowCount;
	};
}