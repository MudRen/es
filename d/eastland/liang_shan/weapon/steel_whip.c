#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("steel whip","ˮĥ�ˡ��ֱ�");
       add("id",({"whip","steel_whip",}) );
       set_short("ˮĥ�ˡ��ֱ�");
	   set_long(
           "����һ������������Ƴɵĸֱޣ���Ϊ̫����Ӳ���������죬ֻ����\n"
	   "ˮɳ������ĥ�������ǰ˽��ι��죬���ر�ͻ�������򵽿��ܺ�ʹ��\n"
	
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 40 );
        set("type","whip");
	set( "min_damage", 25 );
	set( "max_damage", 35 );
	set( "weight", 150 );
	set( "value", ({ 410, "gold" }) );
        set_c_verbs(({
    "%s���һӳ�һ�ɾ��磬����%s",
    "%s����һ�ӣ�����%s",
    "%s�ɿ����������%s",}));
    set("extra_skills",(["anatomlogy": 10 ]));
}

