#include "Renderer.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"

#include <iostream>

namespace cmengine
{
	/// <summary>
	/// Initializes the renderer with the vertex and fragment shaders, and then defines a basic object for use in testing
	/// </summary>
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
		"	gl_FragColor = vec4(0, 0, 1, 1);									"\
		"}																		"\
		"																		"\
		"\n#endif\n																";

		shader = getCore()->context->createShader();
		shader->parse(src);

		shape = getCore()->context->createBuffer();
		shape->add(rend::vec2(0, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));
	}

	/// <summary>
	/// Tells the engine what it needs to render and how, such as setting the projection and model matrices as well as the shape's position defined in onInitialize 
	/// </summary>
	void Renderer::onRender()
	{
		shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 1000.0f));
		shader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
		shader->setAttribute("a_Position", shape);
		shader->render();
	}
}