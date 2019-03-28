#include <iostream>
#include <string>

using namespace std;

int main()
{
	int command_num, i, place;
	string current_dir(""), command, path("");
	bool new_root;
//**********************************************

	cin >> command_num;
	for (i = 0; i < command_num; i++)
	{
		cin >> command;
		if (command == "pwd")
			cout << ((current_dir.length() == 0)? "":"/"+current_dir) + '/' << endl;   // Putting the first and the last '/' manually
		else 
		{                                              //                                                           ^
			new_root = false;                          //                                                           ^
			cin >> path;                               //                                                           ^
			if (path[0] == '/') {                      // removing the first slash if exist as it is added manually |
				path.erase(0, 1);
				new_root = true;
			}
			if (path.find("..") == -1)                 // if there isno ".." so no modification happens 
			{
				if (new_root)
					current_dir = path;
				else
				current_dir =  current_dir + ((current_dir.length() != 0) ? "/" : "") + path;
			}

			else
			{
				while (path.find("..") != -1)
				{
					if (new_root)                          // if there is a new root so previous directory is no longer needed
					{
						current_dir.clear();
						new_root = false;
					}

					place = path.find("..");               // Locating the ".." in the path  (index Returned)

					if (place != 0)
					{                                     // adding path before ".." to directory then erasing path -->>".."
						current_dir = current_dir + ((current_dir.length() != 0)? "/":"") + path.substr(0, place - 1);
						if (current_dir.find("/") != -1)
							current_dir.erase(current_dir.rfind('/'), current_dir.length() - current_dir.rfind('/'));
						else
							current_dir.clear();
						path.erase(0, place + 3);
					}

					else              // if in the first position no more path added till now just one step back (parent) 
					{                 // for the current directory then erase the ".." with its '/' if exists from the path
						if (current_dir.find("/") != -1)
						current_dir.erase(current_dir.rfind('/'), current_dir.length() - current_dir.rfind('/'));
						else
							current_dir.clear();
						path.erase(0, (path.length() == 2) ? 2 : 3);
					}
				}

				if (path.length() != 0)                 // if the length != 0 then there is still some directories left withou ".."
					current_dir = current_dir + ((current_dir.length() != 0) ? "/" : "") + path;    // Need to add them (slash '/' added before them)
			}

		}

	}

	return 0;
}