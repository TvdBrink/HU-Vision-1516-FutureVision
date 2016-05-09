#pragma once

#include <vector>

class Kernel
{
private:
	std::vector<std::vector<int>> kernel;
	int size;
public:
	explicit Kernel(int size);
	Kernel(std::vector<std::vector<int>> kernel);
	~Kernel();

	void set(int x, int y, int value);
	void set(int i, int value);

	int get(int x, int y);
	int get(int i);

	int getWidth();
	int getHeight();

	static Kernel meanKernel;
};

