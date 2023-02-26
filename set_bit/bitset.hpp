#pragma once 

namespace yyx {
	template<size_t N>
	class BitSet {
	public:
		BitSet()
		{
			_bits.resize(N/8+1);
		}
		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] |= (1 << j);
		}
		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] &= ~(1 << j);
		}
		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return _bits[i] & (1 << j);
		}

	private:
		vector<char> _bits;
	};
}