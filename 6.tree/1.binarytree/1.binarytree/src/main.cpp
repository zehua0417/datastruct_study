#include"../include/BinaryTree.h"
#include"../include/header.h"

int main(void) {
	BinaryTree<int> tree;
	std::string cmd;
	while (true) {
		cmd = " ";
		std::cout << ">_@ ~$ ";
		std::cin >> cmd;
		if (cmd == "man") {
			std::cout << "************************" << std::endl;
			std::cout << "*welcome to binary tree*" << std::endl;
			std::cout << "************************" << std::endl;
			std::cout << "** cmd: " << std::endl;
			std::cout << "** insert <num>" << std::endl;
			std::cout << "** input" << std::endl;
			std::cout << "** preorder" << std::endl;
			std::cout << "** inorder" << std::endl;
			std::cout << "** postorder" << std::endl;
			std::cout << "** man" << std::endl;
			std::cout << "************************" << std::endl;
		}
		else if (cmd == "insert") {
			int input = 0;
			std::cin >> input;
			tree.insert(input);
		}
		else if (cmd == "input") {
			std::cout << "please input numbers end wuth -999" << std::endl;
			while (true) {
				int input = 0;
				std::cin >> input;
				if (input == -999) {
					break;
				}
				tree.insert(input);
			}
		}
		else if (cmd == "preorder") {
			tree.postOrderTraversal(tree.root);
			printf("\n");
		}
		else if (cmd == "inorder") {
			tree.inOrderTraversal(tree.root);
			printf("\n");
		}
		else if (cmd == "postorder") {
			tree.postOrderTraversal(tree.root);
			printf("\n");
		}
		else if (cmd == "levelorder") {
			tree.levelOrderTraversal(tree.root);
			printf("\n");
		}
		else {
			std::cout << "command not found" << std::endl;
		}
	}
	return 0;
}
