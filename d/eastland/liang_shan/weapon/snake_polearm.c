#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("snake_polearm","�ɰ���ì");
       add("id",({"polearm","snake polearm",}) );
       set_short("�ɰ���ì");
	   set_long(
           "����һ�ѳ��������˵Ĺ�ì��ì����������������һ��Ť�����ߣ�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 45 );
        set("type","polearm");
	set( "min_damage", 30 );
	set( "max_damage", 44 );
	set( "weight", 180 );
	set( "value", ({ 440, "gold" }) );
        set("nosecond",1);
}

