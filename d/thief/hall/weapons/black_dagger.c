//#pragma save_binary
#include <mudlib.h>

inherit WEAPON;

void create()
{
       set_name("black dagger","��ɫذ��");
       add("id",({"dagger"}) );
       set_short("��ɫذ��");
       set_long("����һ�Ѻ�ɫ��ذ��, ���ʺ���ҹ��ʹ�á�\n");
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type","dagger");
	set( "min_damage",13);
	set( "max_damage",20);
	set( "weapon_class",16);
        set( "value", ({ 910, "silver"} ) );
	set( "extra_skills",(["backstab":2,]) );
}

