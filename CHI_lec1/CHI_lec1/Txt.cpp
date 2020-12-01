#include "Txt.h"

namespace l1 {
	Txt::Txt() : rowCount(0), fileStrings(nullptr) {}

	Txt::Txt(const std::string& fileName) {
		rowCount = readRowCount(fileName);
		fileStrings = new std::string[rowCount];

		std::ifstream in(fileName);
		std::string line;

		if (in.is_open()) {
			for (int i = 0; getline(in, line); ++i) {
				fileStrings[i] = line;
			}
		}

		in.close();
	}

	Txt::Txt(const Txt& other) : rowCount(other.rowCount),
		fileStrings(new std::string[other.rowCount]) {
		for (int i = 0; i < rowCount; ++i) {
			fileStrings[i] = other.fileStrings[i];
		}
	}

	Txt& Txt::operator=(const Txt& other) {
		Txt otherCopy(other);

		std::swap(rowCount, otherCopy.rowCount);
		std::swap(fileStrings, otherCopy.fileStrings);

		return *this;
	}

	Txt::Txt(Txt&& other) noexcept : rowCount(other.rowCount),
		fileStrings(other.fileStrings) {
		other.rowCount = 0;
		other.fileStrings = nullptr;
	}

	Txt& Txt::operator=(Txt&& other) noexcept {
		std::swap(rowCount, other.rowCount);
		std::swap(fileStrings, other.fileStrings);

		return *this;
	}

	Txt::~Txt() {
		delete[] fileStrings;
	}

	size_t Txt::readRowCount(const std::string& fileName) const {
		size_t rowCount = 1;
		std::ifstream in(fileName);
		std::string line;

		if (in.is_open()) {
			while (getline(in, line)) {
				++rowCount;
			}
		}

		in.close();

		return rowCount;
	}

	size_t Txt::size() const {
		return rowCount;
	}
}