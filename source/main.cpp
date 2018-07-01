#include "stdafx.h"


int main(int argc, char * argv[])
{
	std::unique_ptr<Root> root = std::make_unique<Root>();
	auto gamemanager = std::make_shared<GameManager>(root);
	//std::thread _workThread(root);
	//_workThread.join();
	
	return 0;
}