#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black kernel", "�ں�" );
	add( "id", ({ "kernel" }) ); 
   set_short( "�ں�" );
	set_long(
		"����һ����ɫ��ڣ���״��ƻ���˵������Ʒ���������ϸо����µġ�\n"
	);
	set( "type", "kernel" );
	set( "material", "stone");
	set( "weight", 40 );
	set( "defense_bonus", 4 );
	set( "extra_skills", (["depoison":30]) );
	set( "value", ({ 820, "silver" }) );
}
