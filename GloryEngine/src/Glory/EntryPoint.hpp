#pragma once

#ifdef GLORY_PLATFORM_LINUX
extern Glory::Application *Glory::CreateApplication();

int main(int argc, char **argv)
{
    Glory::Logger::Init();
	GLORY_CORE_INFO("Initialized Log!");
	GLORY_INFO("Initialized Log!");
    Glory::Application *app = Glory::CreateApplication();
	GLORY_CORE_INFO("Glory, because  games is the reason we code !");
    app->Run();
    delete app;
}
#endif