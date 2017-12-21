#include "EasyImage.h"
#include "ini_configuration.hh"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "IOutputImage.h"
#include "RenderHandler.h"
#include "ColorRectangleHandler.h"
#include "BlocksHandler.h"
#include "EyeHandler.h"
#include "LineHandler.h"
#include "LSystem2DHandler.h"
#include "WireframeHandler.h"
#include "ZBufferedWireframeHandler.h"
#include "ZBufferingHandler.h"
#include "LightingHandler.h"

std::shared_ptr<Engine::IOutputImage> generate_image(const ini::Configuration& configuration)
{
	return RenderHandlers::Render(configuration);
}

void InitializeHandlers()
{
	RenderHandlers::Register(std::make_shared<ColorRectangleHandler>(), "IntroColorRectangle");
	RenderHandlers::Register(std::make_shared<BlocksHandler>(), "IntroBlocks");
	RenderHandlers::Register(std::make_shared<EyeHandler>(), "IntroLines");
	RenderHandlers::Register(std::make_shared<LineHandler>(), "IntroLines2D");
	RenderHandlers::Register(std::make_shared<LSystem2DHandler>(), "2DLSystem");
	RenderHandlers::Register(std::make_shared<WireframeHandler>(), "Wireframe");
	RenderHandlers::Register(std::make_shared<ZBufferedWireframeHandler>(), "ZBufferedWireframe");
	RenderHandlers::Register(std::make_shared<ZBufferingHandler>(), "ZBuffering");
	RenderHandlers::Register(std::make_shared<LightingHandler>(), "LightedZBuffering");
}

int main(int argc, char const* argv[])
{
	InitializeHandlers();

	int retVal = 0;
	try
	{
		// This if statement selects a default command-line argument if none was provided.
		// It does not add to the application's functionality, it's just useful when debugging.
		// The app will crash, however, if the file the default argument refers to does not exist.
		if (argc == 1)
		{
			// This array is never deallocated. That's not strictly necessary, though.
			// Since it is to be released when the program terminates, we can just leak these two pointers
			// and have the OS deallocate them.
			argv = new const char*[2] { argv[0], "textures2.ini" };
			argc = 2;
		}
		for (int i = 1; i < argc; ++i)
		{
			ini::Configuration conf;
			try
			{
				std::ifstream fin(argv[i]);
				fin >> conf;
				fin.close();
			}
			catch (ini::ParseException& ex)
			{
				std::cerr << "Error parsing file: " << argv[i] << ": " << ex.what() << std::endl;
				retVal = 1;
				continue;
			}

			std::shared_ptr<Engine::IOutputImage> image = generate_image(conf);
			if (image->getHeight() > 0 && image->getWidth() > 0)
			{
				std::string fileName(argv[i]);
				std::string::size_type pos = fileName.rfind('.');
				if (pos == std::string::npos)
				{
					//filename does not contain a '.' --> append a '.<suffix>' suffix
					fileName += "." + image->GetExtension();
				}
				else
				{
					fileName = fileName.substr(0, pos) + "." + image->GetExtension();
				}
				try
				{
					std::ofstream f_out(fileName.c_str(), std::ios::trunc | std::ios::out | std::ios::binary);
					f_out << image;

				}
				catch (std::exception& ex)
				{
					std::cerr << "Failed to write image to file: " << ex.what() << std::endl;
					retVal = 1;
				}
			}
			else
			{
				std::cout << "Could not generate image for " << argv[i] << std::endl;
			}
		}
	}
	catch (const std::bad_alloc &exception)
	{
		//When you run out of memory this exception is thrown. When this happens the return value of the program MUST be '100'.
		//Basically this return value tells our automated test scripts to run your engine on a pc with more memory.
		//(Unless of course you are already consuming the maximum allowed amount of memory) 
		//If your engine does NOT adhere to this requirement you risk losing points because then our scripts will 
		//mark the test as failed while in reality it just needed a bit more memory
		std::cerr << "Error: insufficient memory" << std::endl;
		retVal = 100;
	}
	return retVal;
}
