#include "graph.h"

int main()
{
	Graph g = CreateGraphFromFile("graph.txt");
	if (IsValidGraph(g) == false) {
		cout << "Do thi khong hop le" << endl;
		return 0;
	}
	DisplayGraph(g);
	cout << "So canh cua do thi la: " << CountEdge(g) << endl;
	cout << "So dinh bac le cua do thi la: " << CountVertices(g, 1) << endl;
	cout << "So dinh bac chan cua do thi la: " << CountVertices(g, 0) << endl;
	if (IsConnectedGraph(g)) {
		cout << "Do thi tren la do thi lien thong" << endl;
	}
	else {
		int components = CountConnectedComponents(g);
		cout << "Do thi co " << components << " thanh phan lien thong" << endl;
	}
	cout << "TIM DUONG DI NGAN NHAT TREN DO THI" << endl;
	cout << "Nhap dinh bat dau (0->n-1): ";
	int start_vertex;
	cin >> start_vertex;
	cout << "Chon thuat toan tim duong di ngan nhat: " << endl;
	cout << "1. Dijkstra algorithm" << endl;
	cout << "2. Floyd algorithm" << endl;
	cout << "3. Ford - Bellman algorithm" << endl;
	cout << "Nhap lua chon: ";
	int choice = 0;
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1:
		cout << "Dijkstra algorithm" << endl;
		FindShortestPathDijkstra(g, start_vertex);
		break;
	case 2:
		cout << "Floyd algorithm" << endl;
		FindShortestPathFloyd(g, start_vertex);
		break;
	case 3:
		cout << "Ford - Bellman algorithm" << endl;
		FindShortestPathBellman(g, start_vertex);
		break;
	}
	return 0;
}