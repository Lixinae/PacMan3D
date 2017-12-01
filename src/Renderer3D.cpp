#include <Renderer3D.h>

#include <GameRepresentation.h>


Renderer3D::Renderer3D() {

}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	std::cout << "begin render" << std::endl;
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		for (auto & position : positions) {  
			std::cout << "element at " << position << std::endl;
		}
	}
	std::cout << "end render" << std::endl;
}
