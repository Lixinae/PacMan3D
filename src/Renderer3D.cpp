#include <Renderer3D.h>

#include <BoardRepresentation.h>


Renderer3D::Renderer3D() {

}
	
void Renderer3D::render(const BoardRepresentation & boardRepr) const {
	std::cout << "begin render" << std::endl;
	for (auto & model : BoardRepresentation::MODELS) {  
		vector<BoardPosition> positions = boardRepr[model];
		for (auto & position : positions) {  
			std::cout << "element at " << position << std::endl;
		}
	}
	std::cout << "end render" << std::endl;
}
