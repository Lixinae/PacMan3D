#include <AbstractModel3D.h>

#include <Utils.h>

using namespace std;
using namespace glimac;
using namespace glm;

const string AbstractModel3D::VERTEX_SHADER_3D = Utils::SHADER_PATH + "/" + "3D.vs.glsl";
//const string AbstractModel3D::VERTEX_SHADER_3D = "shaders/3D.vs.glsl";
const GLuint AbstractModel3D::VERTEX_ATTR_POSITION = 0;
const GLuint AbstractModel3D::VERTEX_ATTR_NORMAL = 1;
const GLuint AbstractModel3D::VERTEX_ATTR_TEXTURE = 2;

const GLchar * AbstractModel3D::VERTEX_UNIFORM_MVP_MATRIX = "uMVPMatrix";
const GLchar * AbstractModel3D::VERTEX_UNIFORM_MV_MATRIX = "uMVMatrix";
const GLchar * AbstractModel3D::VERTEX_UNIFORM_NORMAL_MATRIX = "uNormalMatrix";


void AbstractModel3D::initPoints(Mesh mesh) {
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	_size = mesh.getVertexCount();
	glBufferData(GL_ARRAY_BUFFER, _size*sizeof(ShapeVertex), mesh.getDataPointer(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	// TODO May change when load extern 3d file
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position)); 
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal)); 
	glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords)); 
	// ...
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void AbstractModel3D::initProgram(const string & fragmentShader) {
	_program = loadProgram(VERTEX_SHADER_3D, fragmentShader);
	_uMVPmatrix = glGetUniformLocation(_program.getGLId(), VERTEX_UNIFORM_MVP_MATRIX);
    _uMVmatrix = glGetUniformLocation(_program.getGLId(), VERTEX_UNIFORM_MV_MATRIX);
    _uNormalmatrix = glGetUniformLocation(_program.getGLId(), VERTEX_UNIFORM_NORMAL_MATRIX);
}
	
AbstractModel3D::AbstractModel3D(const string & mesh, const string & fragmentShader) {
	initPoints(Mesh::fromOBJFile(mesh));
	initProgram(fragmentShader);
}

AbstractModel3D::~AbstractModel3D()  {
	glDeleteBuffers(1, &_vbo);
	glDeleteVertexArrays(1, &_vao);
}

void AbstractModel3D::bind() {
	_program.use();
	glBindVertexArray(_vao);
}

void AbstractModel3D::unbind() {
	glBindVertexArray(0);
}

GLsizei AbstractModel3D::count() const {
	return _size;
}

void AbstractModel3D::setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix) {
	glUniformMatrix4fv(_uMVPmatrix, 1, GL_FALSE, value_ptr(ProjMatrix * MVMatrix));
	glUniformMatrix4fv(_uMVmatrix, 1, GL_FALSE, value_ptr(MVMatrix));
	glUniformMatrix4fv(_uNormalmatrix, 1, GL_FALSE, value_ptr(transpose(inverse(MVMatrix))));
}

