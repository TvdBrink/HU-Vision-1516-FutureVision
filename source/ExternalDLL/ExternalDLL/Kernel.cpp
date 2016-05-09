#include "Kernel.h"

Kernel Kernel::meanKernel = Kernel({ { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } });

Kernel::Kernel(int size) : size(size)
{
	kernel.resize(size);
	for (auto it = kernel.begin(); it != kernel.end(); ++it) {
		it->resize(size);
	}
}

Kernel::Kernel(std::vector<std::vector<int>> kernel) : kernel(kernel), size(kernel.size())
{

}

Kernel::~Kernel()
{

}

void Kernel::set(int x, int y, int value)
{
	kernel[x][y] = value;
}

void Kernel::set(int i, int value)
{
	int x = i%size;
	int y = (i - x) / size;
	kernel[x][y] = value;
}

int Kernel::get(int x, int y)
{
	return kernel[x][y];
}

int Kernel::get(int i)
{
	int x = i%size;
	int y = (i - x) / size;
	return kernel[x][y];
}

int Kernel::getWidth()
{
	return size;
}

int Kernel::getHeight()
{
	return size;
}
