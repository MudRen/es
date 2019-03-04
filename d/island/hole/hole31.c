#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "岗哨" );
	set_long(@LONG
在这个巨大的洞穴中，居然有另一个小洞，洞口边还放了许多岩石，
哦～～！是了，原来这儿是蜥蜴人的哨站，平时会轮流派人在此驻守以防
止武士堡或魔族的军队，或者其他可怕的生物趁机偷袭。不过这儿的守备
似乎比其他地方森严耶!	
LONG
		);
	set( "exits",([
			"north" : HOLE"hole25",
			"southeast" : HOLE"hole32"
			]) );
	set( "objects",([
			"guard#2" : HMONSTER"sentry",
			"guard#1" : HMONSTER"sentry"
			]) );
	reset();
#include <replace_room.h>
}
