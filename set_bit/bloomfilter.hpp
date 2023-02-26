#pragma once

namespace yyx {
	template <size_t N>
	class BloomFilter {
	public:

	private:
		const static size_t _ratio;
		BitSet<N> _b;
	};
}