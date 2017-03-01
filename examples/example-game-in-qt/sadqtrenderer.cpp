#include "sadqtrenderer.h"
#include "sadqtmainloop.h"
#include "sadqtwindow.h"



sad::qt::Renderer::Renderer() : m_initialized(false), m_widget(NULL)
{
	delete m_main_loop;	
	m_main_loop = new sad::qt::MainLoop();
	m_main_loop->setRenderer(this);

	delete m_window;
	m_window = new sad::qt::Window();
	m_window->setRenderer(this);
}


sad::qt::Renderer::~Renderer()
{

}

bool sad::qt::Renderer::initialized() const
{
	return m_initialized;
}

void sad::qt::Renderer::init(const sad::Settings& _settings)
{
	this->sad::Renderer::init(_settings);
	m_initialized = true;
}

bool sad::qt::Renderer::initRendererBeforeLoop()
{
	return this->sad::Renderer::initRendererBeforeLoop();
}

void sad::qt::Renderer::runOnce()
{
	this->sad::Renderer::runOnce();
}

bool sad::qt::Renderer::run()
{
	return true;
}


void sad::qt::Renderer::deinitRendererAfterLoop()
{
	this->sad::Renderer::deinitRendererAfterLoop();
}

void sad::qt::Renderer::setWidget(sad::qt::OpenGLWidget* widget)
{
	m_widget = widget;
}

sad::qt::OpenGLWidget* sad::qt::Renderer::widget() const
{
	return m_widget;
}

DECLARE_COMMON_TYPE(sad::qt::Renderer);