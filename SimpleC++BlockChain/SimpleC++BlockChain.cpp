// SimpleC++BlockChain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Blockchain.h"
#include <chrono>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Blockchain bChain = Blockchain(atoi(argv[1]));
		chrono::steady_clock::time_point begin = chrono::high_resolution_clock::now();
		cout << "Mining block 1..." << endl;
		bChain.AddBlock(Block(1, "Block 1 Data"));
		chrono::steady_clock::time_point end = chrono::high_resolution_clock::now();
		long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		cout << "Time Taken :" << (ms / 1000) << " Seconds" << endl;

		begin = chrono::high_resolution_clock::now();
		cout << "Mining block 2..." << endl;
		bChain.AddBlock(Block(2, "Block 2 Data"));
		end = chrono::high_resolution_clock::now();
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		cout << "Time Taken :" << (ms / 1000) << " Seconds" << endl;

		begin = chrono::high_resolution_clock::now();
		cout << "Mining block 3..." << endl;
		bChain.AddBlock(Block(3, "Block 3 Data"));
		end = chrono::high_resolution_clock::now();
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		cout << "Time Taken :" << (ms / 1000) << " Seconds" << endl;
	}
	else
	{
		cout << "Wrong Format" << endl;
		cout << "The format is SimpleC++BlockChain.exe difficulty" << endl;
	}
	return 0;
	
}

