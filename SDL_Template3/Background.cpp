#include "Background.h"
#include "globals.h"

Background::Background(){
	Sprite * Cloud0;
	Sprite * Cloud1;
	Sprite * Cloud2;
	Sprite * Cloud3;
	Sprite * Cloud4;
	Sprite * Island;
	Sprite * Sky;
	Sprite * Sea;
	Sprite * Waves;

	Cloud0 = new Sprite("layers_0000_Cloud1.png", { 40, 0, 130, 65 });
	Cloud1 = new Sprite("layers_0001_Cloud2.png", { 730, 20, 120, 77 });
	Cloud2 = new Sprite("layers_0002_cloud3.png", { 300, 55, 116, 60 });
	Cloud3 = new Sprite("layers_0003_cloud4.png", { 440, 65, 156, 92 });
	Cloud4 = new Sprite("layers_0004_cloud5.png", { 1000, 86, 250, 128 });
	Island = new Sprite("layers_0005_island_and_sun.png", { 370, DISPLAY_HEIGHT-635, 433, 426 });
	Sea = new Sprite("layers_0011_background.png", { 0, 0 , DISPLAY_WIDTH, DISPLAY_HEIGHT });
	Waves = new Sprite("layers_0009_wave.png", { 0, DISPLAY_HEIGHT - 146, DISPLAY_WIDTH, 146 });
	Sky = new Sprite("layers_0010_sky.png", { 0, 0, DISPLAY_WIDTH, 375 });

	background_objects.push_back(Sea);
	background_objects.push_back(Sky);
	background_objects.push_back(Cloud0);
	background_objects.push_back(Cloud1);
	background_objects.push_back(Cloud2);
	background_objects.push_back(Cloud3);
	background_objects.push_back(Cloud4);
	background_objects.push_back(Waves);
	background_objects.push_back(Island);


}

void Background::render(){

	for (auto object : background_objects)
	{
		object->render();
	}

}