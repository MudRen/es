////#pragma save_binary
#include <mudlib.h>

inherit WEAPON;

void create()
{
       set_name("scalpel","���ʵ�");
       add("id",({"scalpel",}) );
       set_short("���ʵ�");
       set_long(
     	 "һ�ѽ��ʵ�,������������ʬ��.Ҳ���Ե�����������\n"
     	);
	
	set( "unit", "��" );
	set( "weight", 30 );
	set( "type","dagger");
	set( "min_damage",15);
	set( "max_damage",20);
	set( "weapon_class",20);
        set( "value", ({ 1000, "silver"} ) );

}
