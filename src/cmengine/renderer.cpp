#include "Renderer.h"
#include "Core.h"
//#include "Transform.h"
#include "Entity.h"

namespace cmengine
{

	void Renderer::onInitialize()
	{
		const char* src =
		"\n#ifdef VERTEX\n														"\
		"attribute vec2 a_Position;												"\
		"uniform mat4 u_Projection;												"\
		"uniform mat4 u_Model;													"\
		"																		"\
		"void main()															"\
		"{																		"\
		"	gl_Position = u_Projection * u_Model * vec4(a_Position, 0, 1);		"\
		"}																		"\
		"																		"\
		"\n#endif\n																"\
		"\n#ifdef FRAGMENT\n													"\
		"																		"\
		"void main()															"\
		"{																		"\
		"	gl_FragColor = vec4(1, 0, 0, 1);									"\
		"}																		"\
		"																		"\
		"\n#endif\n																";

		shader = getCore()->context->createShader();
		//std::shared_ptr<Shader> shader = context->createShader();
		shader->parse(src);

		//std::shared_ptr<Buffer> shape = context->createBuffer();
		shape = getCore()->context->createBuffer();
		shape->add(rend::vec2(0, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));
	}

	void Renderer::onRender()
	{
		shader->setAttribute("a_Position", shape);
		shader->render();
	}
}