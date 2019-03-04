#include "../dgnisld.h"

inherit WEAPON;

void create()
{
	set_name("Dragon Killer", "ɱ����");
	add ("id",({ "sword","dragon killer","longblade", }) );
	set_short("a Dragon killer", "ɱ����");
	set_long(
	    "A long sword named \"Dragon Killer\". It can cause much damage\n" 
	"to dragons, dinosaurs as same as its name. But it is a normal long\n"
	"blade to other animals.\n",
	    "һ����Ϊ��֮�ս���֮�����������������������������кܴ��ɱ����\n"
	"��������������࣬��ֻ��һ����ͨ�ĳ�����\n"
	);
	
	set( "weapon_class", 10 );
	set( "type", "longblade" );
	set( "min_damage", 15 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 10, "gold" }) );
	set( "unit", "��" );
}
