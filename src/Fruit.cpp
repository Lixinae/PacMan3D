#include <Fruit.h>


Fruit::Fruit() {

}

GameRepresentation::Model Fruit::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::FRUIT);
}

void Fruit::apply(Bonus::Context &context) {
	context.informations.updateScore(500);
}

bool Fruit::isRequired() const {
	return false;
}

Bonus *Fruit::clone() const {
	return new Fruit(*this);
}

json Fruit::toJSON() const {
	json jsonBonus;
	jsonBonus["type"] = "fruit";
	return jsonBonus;
}
